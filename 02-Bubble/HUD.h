#pragma once
#include "TextManager.h"
class ShaderProgram;

class HUD
{

public:

	HUD();
	void buildHUD(ShaderProgram& program);

	void render();
	
private:

	TextManager* TxtManager[2];
	glm::mat4 projection;
	glm::mat4 modelview;
	ShaderProgram texProgram;
	float distanceAmongWords;
	
};

