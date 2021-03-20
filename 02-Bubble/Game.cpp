#include <GL/glew.h>
#include <GL/glut.h>
#include "Game.h"

#include "Menu.h"


void Game::init()
{
	bPlay = true;
	bLose = false;
	bWin = false;
	godMode = false;
	glClearColor(0.f, 0.f, 0.f, 1.0f);
	level.init();


}

bool Game::update(int deltaTime)
{
	if (!Menu::instance().getOpenMenu())
	{
		level.update(deltaTime);
	}else
	{

		//Menu::instance().update(deltaTime);
	}

	if (bWin)
	{

		Menu::instance().openMenuFunc();

		level.restart();
	}

	if (bLose)
	{

		Menu::instance().openMenuFunc();

		level.restart();
	}
	
	return bPlay;
}

void Game::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	level.render();
}

void Game::keyPressed(int key)
{
	if (key == 27) // Escape code
		bPlay = false;
	/* Este fragmento comentado da la posibilidad de abrir y cerrar el menu con el espacio en cualquier momento
	if (key == 32)
		if (!Menu::instance().getOpenMenu()) {
			Menu::instance().setOpenMenu(true);
			keyReleased(key);
		}
		else 
			Menu::instance().setOpenMenu(false);
	*/
	if (Menu::instance().getOpenMenu() && key == 13)//13 es el ascii de enter
	{
		Menu::instance().pressEnter();
	}
	
	keys[key] = true;
}

void Game::keyReleased(int key)
{
	keys[key] = false;
}

void Game::specialKeyPressed(int key)
{
	specialKeys[key] = true;

	if (Menu::instance().getOpenMenu() && key == GLUT_KEY_UP)
	{
		Menu::instance().addOptionMenu(-1);
	}
	if (Menu::instance().getOpenMenu() && key == GLUT_KEY_DOWN)
	{
		Menu::instance().addOptionMenu(1);
	}
	
}

void Game::specialKeyReleased(int key)
{
	specialKeys[key] = false;
}

void Game::mouseMove(int x, int y)
{
}

void Game::mousePress(int button)
{
}

void Game::mouseRelease(int button)
{
}

bool Game::getKey(int key) const
{
	return keys[key];
}

bool Game::getSpecialKey(int key) const
{
	return specialKeys[key];
}

bool Game::getGodMode()
{
	return godMode;
}

void Game::setGodMode(bool bGodMode)
{
	godMode = bGodMode;
}

void Game::setBLose(bool b)
{
	bLose = b;
}

bool Game::getBLose()
{
	return bLose;
}

void Game::setbWin(bool bWin)
{
	this->bWin = bWin;
}




