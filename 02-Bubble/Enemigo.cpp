#include "Enemigo.h"

enum PlayerAnims
{
	STAND_LEFT, STAND_RIGHT, MOVE_LEFT, MOVE_RIGHT
};

Enemigo::Enemigo()
{

}

void Enemigo::init(const glm::ivec2& tileMapPos, ShaderProgram& shaderProgram)
{
	
	MoveRight = false;
	bJumping = false;
	spritesheet.loadFromFile("images/bub.png", TEXTURE_PIXEL_FORMAT_RGBA);
	sprite = Sprite::createSprite(glm::ivec2(32, 32), glm::vec2(0.25, 0.25), &spritesheet, &shaderProgram);
	sprite->setNumberAnimations(4);

	sprite->setAnimationSpeed(STAND_LEFT, 8);
	sprite->addKeyframe(STAND_LEFT, glm::vec2(0.f, 0.f));

	sprite->setAnimationSpeed(STAND_RIGHT, 8);
	sprite->addKeyframe(STAND_RIGHT, glm::vec2(0.25f, 0.f));

	sprite->setAnimationSpeed(MOVE_LEFT, 8);
	sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.f, 0.f));
	sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.f, 0.25f));
	sprite->addKeyframe(MOVE_LEFT, glm::vec2(0.f, 0.5f));

	sprite->setAnimationSpeed(MOVE_RIGHT, 8);
	sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.25, 0.f));
	sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.25, 0.25f));
	sprite->addKeyframe(MOVE_RIGHT, glm::vec2(0.25, 0.5f));

	sprite->changeAnimation(0);
	tileMapDispl = tileMapPos;
	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));

}

void Enemigo::update(int deltaTime)
{

	sprite->update(deltaTime);

	if (!MoveRight)
	{

		if (sprite->animation() != MOVE_LEFT)
			sprite->changeAnimation(MOVE_LEFT);

		posPlayer.x -= 2;
		
		if (map->collisionMoveLeft(posPlayer, glm::ivec2(32, 32)))
		{
			MoveRight = true;
			posPlayer.x += 2;
			sprite->changeAnimation(MOVE_RIGHT);
			
		}
		
	}else
	{

		if (sprite->animation() != MOVE_RIGHT)
			sprite->changeAnimation(MOVE_RIGHT);

		posPlayer.x += 2;

		if (map->collisionMoveRight(posPlayer, glm::ivec2(32, 32)))
		{

			MoveRight = false;
			posPlayer.x -= 2;
			sprite->changeAnimation(MOVE_LEFT);

		}
		
	}
		
		

	sprite->setPosition(glm::vec2(float(tileMapDispl.x + posPlayer.x), float(tileMapDispl.y + posPlayer.y)));
	
}
