#pragma once
#include "Texture.h"
#include "ShaderProgram.h";

class TextWriter
{
public:
	
	TextWriter();
	void init(ShaderProgram& program);
	void render();
	void usarLetra(ShaderProgram& program, char letra);

private:

	GLuint vao;
	GLuint vbo;
	GLint posLocation, texCoordLocation;
	Texture tex;

};

