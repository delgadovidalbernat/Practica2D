#include "Level.h"

Level::Level()
{
	scene = Scene::createScene();
}

void Level::init()
{
	scene->init();
}

void Level::update(float deltaTime)
{
	scene->update(deltaTime);
}

void Level::render()
{
	scene->render();
}

