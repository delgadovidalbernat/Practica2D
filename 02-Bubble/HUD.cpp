#include "HUD.h"

#include <glm/gtc/matrix_transform.inl>

#include "Game.h"


HUD::HUD()
{
	
}

void HUD::buildHUD(ShaderProgram& program)
{
	healthAmount = 100.f;
	experienceAmount = 0.f;
	
	distanceAmongWords = 60.f;
	texProgram = program;
	projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);

	TxtManager[0] = TextManager::CreateTextManager(program, "HEALTH", glm::vec2((SCREEN_WIDTH - 850.f) * 0.5f, -500.f));
	TxtManager[1] = TextManager::CreateTextManager(program, "EXPERIENCE", glm::vec2((SCREEN_WIDTH + 700.f) * 0.5f, -500.f));

	health = Quad::createQuad(0, 0, healthAmount * 4.f, 50.f, texProgram);
}

void HUD::updateHealth(float amount)
{
	if (amount < 0) amount = 0;

	healthAmount = amount;
	health->free();
	health = Quad::createQuad(0, 0, (amount) * 4.f, 50.f, texProgram);

}

void HUD::updateExperience()
{
}

void HUD::render()
{

	glClearColor(0.f, 0.f, 0.f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Configurar el shader por defecto para que las otras texturas que usan el shader no afecten a este
	texProgram.setUniformMatrix4f("projection", projection);
	texProgram.setUniform4f("color", 1.0f, 1.0f, 1.0f, 1.0f);
	texProgram.setUniform2f("texCoordDispl", 0.f, 0.f);

	//dibujo el rectangulo que representa la vida
	
	texProgram.setUniform4f("color", 1.0f, .0f, .0f, 1.0f);
	modelview = glm::mat4(1.0f);
	modelview = glm::translate(modelview, glm::vec3(-50.f, 0.f, 0.f));
	modelview = glm::translate(modelview, glm::vec3(((SCREEN_WIDTH - 200.f) * 0.5f) + 50, SCREEN_HEIGHT - 392, 0.f));
	modelview = glm::scale(modelview, glm::vec3(0.3f, 0.3f, 1.f));
	modelview = glm::translate(modelview, glm::vec3(-(SCREEN_WIDTH - 200.f) * 0.5f, -SCREEN_HEIGHT * 0.5f, 0.f));
	texProgram.setUniformMatrix4f("modelview", modelview);
	health->render();
	
	texProgram.setUniform4f("color", 1.0f, 1.0f, 1.0f, 1.0f);
	//Declarar modelview para mover el cuadrado con la textura por el mapa

	modelview = glm::mat4(1.0f);
	modelview = glm::translate(modelview, glm::vec3(-50.f, 0.f, 0.f));
	modelview = glm::translate(modelview, glm::vec3((SCREEN_WIDTH - 200.f) * 0.5f, SCREEN_HEIGHT * 0.5f, 0.f));
	modelview = glm::scale(modelview, glm::vec3(0.3f, 0.3f, 1.f));
	modelview = glm::translate(modelview, glm::vec3(-(SCREEN_WIDTH - 200.f) * 0.5f, -SCREEN_HEIGHT * 0.5f, 0.f));


	texProgram.setUniformMatrix4f("modelview", modelview);
	TxtManager[0]->print();
	TxtManager[1]->print();

}

