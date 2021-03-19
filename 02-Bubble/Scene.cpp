#include <iostream>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include "Scene.h"
#include "Game.h"
#include "Menu.h"


#define SCREEN_X 32
#define SCREEN_Y 16

#define INIT_PLAYER_X_TILES 4
#define INIT_PLAYER_Y_TILES 25


Scene* Scene::createScene()
{
	return new Scene();
}

Scene::Scene()
{
	
	for (auto m : maps)
	{
		m = NULL;
	}
	player = NULL;

}

Scene::~Scene()
{
	for (auto m : maps)
	{
		if (m != NULL)
			delete m;
	}
	if(player != NULL)
		delete player;

}


void Scene::init()
{

	pantalla = numPantalla::primer;
	initShaders();

	//el 3 se debe a que 6-1 = 5 que soin los mapas que ahora mismo tenemos en la carpeta
	for (int i = 1; i<6; i++)
	{
		string pathMap = "levels/level0" + std::to_string(i) + ".txt";
		maps.push_back(TileMap::createTileMap(pathMap, glm::vec2(SCREEN_X, SCREEN_Y), texProgram));
	}
	
	player = new Player();
	player->init(glm::ivec2(SCREEN_X, SCREEN_Y), texProgram);
	player->setPosition(glm::vec2(INIT_PLAYER_X_TILES * maps[0]->getTileSize(), INIT_PLAYER_Y_TILES * maps[0]->getTileSize()));
	player->setTileMap(maps[0]);
	
	projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
	currentTime = 0.0f;
	Menu::instance().buildMenu(texProgram);
	Menu::instance().openMenuFunc();
}

void Scene::update(int deltaTime)
{
	currentTime += deltaTime;
	player->update(deltaTime);
	maps[pantalla]->update(deltaTime);

	

	//Si el jugador se pone en esa posicion bWin se pone a true y se activa el mecanismo de partida ganada, por detras se
	//pone al jugador en la posicion del principio
	if (player->getPosPlayer().x == (34*maps[pantalla]->getTileSize()))
	{
		if (pantalla < maps.size()-1)
		{
			++pantalla;
		}
		//Game::instance().setbWin(true);
		glm::ivec2 pos = player->getPosPlayer();
		player->setPosition(glm::vec2(0, player->getPosPlayer().y));
		
		//voy a tener un vector de mapas que segun posicion se intercanvien para dar la sensacion de continuidad
		//no es necessario limpiarlpos de memoria ya que necessito guardar el estado anterior en el que los dejo el jugador
		//asi a la par de ahorrar render doy sensacion de permanencia.
		player->setTileMap(maps[pantalla]);
		
	}else if(player->getPosPlayer().x == (0 * maps[pantalla]->getTileSize()))
	{
		if (pantalla > numPantalla::primer)
		{
			--pantalla;
		}
		
		glm::ivec2 pos = player->getPosPlayer();
		player->setPosition(glm::vec2(34 * maps[pantalla]->getTileSize(), player->getPosPlayer().y));

		//voy a tener un vector de mapas que segun posicion se intercanvien para dar la sensacion de continuidad
		//no es necessario limpiarlpos de memoria ya que necessito guardar el estado anterior en el que los dejo el jugador
		//asi a la par de ahorrar render doy sensacion de permanencia.
		player->setTileMap(maps[pantalla]);
		
	}

	vector<Enemigo*> enemys = maps[pantalla]->getEnemys();
	
	for (auto e : enemys)
	{

		if (e != NULL) {

			if (e->playerContact(player->getPosPlayer()))
			{
				player->addHealth(-25.f);
				//Game::instance().setbWin(true);
			}
			
		}
	}
	
}

void Scene::render()
{
	glm::mat4 modelview;

	texProgram.use();
	texProgram.setUniformMatrix4f("projection", projection);
	texProgram.setUniform4f("color", 1.0f, 1.0f, 1.0f, 1.0f);
	modelview = glm::mat4(1.0f);
	texProgram.setUniformMatrix4f("modelview", modelview);
	texProgram.setUniform2f("texCoordDispl", 0.f, 0.f);
	maps[pantalla]->render();
	player->render();

	bool openMenu = Menu::instance().getOpenMenu();
	
	if (openMenu)
	{

		Menu::instance().render();
	}
	
}

void Scene::reloadMap()
{

	for (auto m : maps)
		m->free();

	int sizeMaps = maps.size();
	for(int i = 0; i<sizeMaps; i++)
	{
		maps.pop_back();
	}

	for (int i = 1; i < 6; i++)
	{
		string pathMap = "levels/level0" + std::to_string(i) + ".txt";
		maps.push_back(TileMap::createTileMap(pathMap, glm::vec2(SCREEN_X, SCREEN_Y), texProgram));
	}

	player->restart();
}

void Scene::restart()
{
	reloadMap();
	player->setPosition(glm::vec2(INIT_PLAYER_X_TILES * maps[0]->getTileSize(), INIT_PLAYER_Y_TILES * maps[0]->getTileSize()));
	pantalla = numPantalla::primer;
	player->setTileMap(maps[pantalla]);

}


void Scene::initShaders()
{
	Shader vShader, fShader;

	vShader.initFromFile(VERTEX_SHADER, "shaders/texture.vert");
	if(!vShader.isCompiled())
	{
		cout << "Vertex Shader Error" << endl;
		cout << "" << vShader.log() << endl << endl;
	}
	fShader.initFromFile(FRAGMENT_SHADER, "shaders/texture.frag");
	if(!fShader.isCompiled())
	{
		cout << "Fragment Shader Error" << endl;
		cout << "" << fShader.log() << endl << endl;
	}
	texProgram.init();
	texProgram.addShader(vShader);
	texProgram.addShader(fShader);
	texProgram.link();
	if(!texProgram.isLinked())
	{
		cout << "Shader Linking Error" << endl;
		cout << "" << texProgram.log() << endl << endl;
	}
	texProgram.bindFragmentOutput("outColor");
	vShader.free();
	fShader.free();
}



