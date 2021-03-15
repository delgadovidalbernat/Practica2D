#pragma once
#include "Player.h"

class Enemigo : public Player
{

public:
	
	Enemigo();
	void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram) override;
	void update(int deltaTime) override;


private:

	bool MoveRight;
};

