#include "Menu.h"

#include <GL/freeglut_std.h>


Menu::Menu()
{
	
}

void Menu::buildMenu(ShaderProgram &program)
{
	openMenu = false;
	t.init(program);
}

void Menu::render()
{
	
	t.render();

}


