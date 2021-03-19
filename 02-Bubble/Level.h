#pragma once
#include "Scene.h"

class Level
{

public:

	Level();
	static Level* createLevel();
	void init();
	void update(float deltaTime);
	void render();

	void restart();

private:
	//Deber� ser un vector con un m�nimo de 3 escenas
	Scene* scene;
	
};

