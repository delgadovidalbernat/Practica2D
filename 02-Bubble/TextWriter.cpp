#include "TextWriter.h"

TextWriter::TextWriter()
{
	
}

void TextWriter::init(ShaderProgram& program)
{

	//tamano del cuadrado
	glm::vec2 geom[2] = { glm::vec2(0.f, 0.f), glm::vec2(128.f, 128.f) };
	//coord de la textura a pintar dentro de la imagen
	glm::vec2 texCoords[2] = { glm::vec2(0.f, 0.f), glm::vec2(0.15f, 0.15f) };

	tex.loadFromFile("images/bitmapFont.png", TEXTURE_PIXEL_FORMAT_RGBA);

	float vertices[24] = { geom[0].x, geom[0].y, texCoords[0].x, texCoords[0].y,
												geom[1].x, geom[0].y, texCoords[1].x, texCoords[0].y,
												geom[1].x, geom[1].y, texCoords[1].x, texCoords[1].y,
												geom[0].x, geom[0].y, texCoords[0].x, texCoords[0].y,
												geom[1].x, geom[1].y, texCoords[1].x, texCoords[1].y,
												geom[0].x, geom[1].y, texCoords[0].x, texCoords[1].y };

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 24 * sizeof(float), vertices, GL_STATIC_DRAW);
	posLocation = program.bindVertexAttribute("position", 2, 4 * sizeof(float), 0);
	texCoordLocation = program.bindVertexAttribute("texCoord", 2, 4 * sizeof(float), (void*)(2 * sizeof(float)));

}

void TextWriter::render()
{

	glEnable(GL_TEXTURE_2D);
	tex.use();
	glBindVertexArray(vao);
	glEnableVertexAttribArray(posLocation);
	glEnableVertexAttribArray(texCoordLocation);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisable(GL_TEXTURE_2D);
}
