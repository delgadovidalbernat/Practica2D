#include "Menu.h"

#include <GL/freeglut_std.h>
#include <glm/gtc/matrix_transform.inl>


#include "Game.h"


Menu::Menu()
{
	
}

void Menu::buildMenu(ShaderProgram &program)
{
	openMenu = false;
	texProgram = program;
	projection = glm::ortho(0.f, float(SCREEN_WIDTH - 1), float(SCREEN_HEIGHT - 1), 0.f);
	writer.init(program);
}

void Menu::render()
{
	//limpiar la pantalla de color negro
	glClearColor(0.f, 0.f, 0.f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Configurar el shader por defecto para que las otras texturas que usan el shader no afecten a este
	texProgram.setUniformMatrix4f("projection", projection);
	texProgram.setUniform4f("color", 1.0f, 1.0f, 1.0f, 1.0f);
	texProgram.setUniform2f("texCoordDispl", 0.f, 0.f);

	//Declarar modelview para mover el cuadrado con la textura por el mapa
	modelview = glm::mat4(1.0f);
	texProgram.setUniformMatrix4f("modelview", modelview);

	//Pintar el menu
	writer.render();
	
	//poner color de fondo original
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
}


