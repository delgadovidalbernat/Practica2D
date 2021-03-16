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
	//Deberà ser un vector con un mínimo de 3 escenas
	Scene* scene;
	
};

