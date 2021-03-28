#pragma once
#include "Player.h"


class Enemigo : public Player
{

public:
	
	Enemigo();
	void init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram) override;
	void update(int deltaTime)=0;
	void free();

	bool playerContact(glm::ivec2 PlayerPosition);

	virtual string typeOf() = 0;

	virtual void setPosTarget(glm::ivec2) = 0;
	
	void setPuedeCollisionar(bool value);
	void setCollisioning(bool value);
	bool getCollisioning();
	bool getPuedeColisionar();
	bool getMoveRight();
	void setMoveRight(bool value);

private:

	bool MoveRight;
	bool puedeColisionar;
	bool collisioning;
};

