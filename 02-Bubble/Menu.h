#pragma once
#include <GL/glew.h>
#include <glm/vec2.hpp>


#include "OptionsMenu.h"
#include "Texture.h"
#include "ShaderProgram.h"
#include "TextManager.h"
#include "TextWriter.h"

enum options
{
	Play,
	CONTROLS,
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
	void  openMenuFunc();

	void setOpenMenu(bool openMenu) { this->openMenu = openMenu;  }
	bool getOpenMenu() { return openMenu; }
	void update(float deltaTime);
	void setOptionMenu(options o);
	void addOptionMenu(int addition);

	void pressEnter();
	void functionPLAY();
	void functionOPTIONS();
	void functionEXIT();

private:

	void renderMenu();
	
	TextManager* TxtManager[3];
	glm::mat4 projection;
	glm::mat4 modelview;
	ShaderProgram texProgram;
	bool openMenu;
	bool openOptionsMenu;
	int optionSelected;
	float distanceAmongWords;
	OptionsMenu optionsMenu;
	
};

