#pragma once
#include <GL/glew.h>
#include <glm/vec2.hpp>

#include "Texture.h"
#include "ShaderProgram.h"
#include "TextManager.h"
#include "TextWriter.h"

enum options
{
	Play,
	Exit
};

class Menu
{
public:
	
	Menu();

	static Menu& instance()
	{
		static Menu menu;

		return menu;
	}

	
	void  buildMenu(ShaderProgram& program);
	void  render();

	void setOpenMenu(bool openMenu) { this->openMenu = openMenu;  }
	bool getOpenMenu() { return openMenu; }

private:
	
	TextManager* TxtManager[2];
	glm::mat4 projection;
	glm::mat4 modelview;
	ShaderProgram texProgram;
	bool openMenu;
	
};

