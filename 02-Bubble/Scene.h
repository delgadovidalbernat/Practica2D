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

	primer, segon, tercer, cuart, cinque
};

class Scene
{

public:
	Scene();
	~Scene();

	void init();
	void update(int deltaTime);
	void render();
	void free();

private:
	void initShaders();

private:
	TileMap *map;
	Player *player;
	Enemigo *enemy;
	ShaderProgram texProgram;
	float currentTime;
	glm::mat4 projection;
	numPantalla pantalla;
	
};


#endif // _SCENE_INCLUDE

