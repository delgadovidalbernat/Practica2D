#pragma once
#include "Scene.h"

class Level
{

public:

	Level();
	void init();
	void update(float deltaTime);
	void render();

private:
	//Deber� ser un vector con un m�nimo de 3 escenas
	Scene* scene;
	
};

