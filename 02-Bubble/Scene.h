#ifndef _SCENE_INCLUDE
#define _SCENE_INCLUDE


#include <glm/glm.hpp>

#include "Enemigo.h"
#include "ShaderProgram.h"
#include "TileMap.h"
#include "Player.h"


// Scene contains all the entities of our game.
// It is responsible for updating and render them.

enum numPantalla
{

	primer = 0, segon, tercer, cuart, cinque
};

class Scene
{

public:

	static Scene* createScene();
	Scene();
	~Scene();

	void init();
	void update(int deltaTime);
	void render();
	void reloadMap();
	void restart();
	
private:
	void initShaders();

private:
	vector<TileMap*> maps;
	Player *player;
	ShaderProgram texProgram;
	float currentTime;
	glm::mat4 projection;
	int pantalla;
	
	
};


#endif // _SCENE_INCLUDE

