#pragma once
#include "Quad.h"
#include "TextManager.h"
class ShaderProgram;

class HUD
{

public:

	HUD();
	void buildHUD(ShaderProgram& program);
	void updateHealth(float amount);
	void updateExperience();

	void render();
	void renderFriends();
	
private:

	TextManager* TxtManager[3];
	glm::mat4 projection;
	glm::mat4 modelview;
	ShaderProgram texProgram;
	float distanceAmongWords;
	float dispanceAmongFriendsIcon;

	float healthAmount;
	float experienceAmount;
	
	Quad* health;
	Quad* friends;
	
};

