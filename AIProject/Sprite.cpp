#include "Sprite.h"

#include <cmath>

Sprite::Sprite()
{
	mVboId = 0;
	glGenBuffers(1, &mVboId);
}


Sprite::~Sprite()
{
	if (mVboId != 0)
		glDeleteBuffers(1, &mVboId);
}

void Sprite::Init(float x, float y, float width, float height, float angle)
{
	mX = x;
	mY = y;
	mWidth = width;
	mHeight = height;

	float s = sin(angle);
	float c = cos(angle);

	float x1 = 0;
	float y1 = height / 2;
	float x2 = -width / 2;
	float y2 = -height / 2;
	float x3 = width / 2;
	float y3 = -height / 2;

	float vertexData[6];

	vertexData[0] = x + (x1 * c - y1 * s);
	vertexData[1] = y + (x1 * s + y1 * c);
	vertexData[2] = x + (x2 * c - y2 * s);
	vertexData[3] = y + (x2 * s + y2 * c);
	vertexData[4] = x + (x3 * c - y3 * s);
	vertexData[5] = y + (x3 * s + y3 * c);
	

	glBindBuffer(GL_ARRAY_BUFFER, mVboId);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::Update(float x, float y, float angle)
{
	float s = sin(angle);
	float c = cos(angle);

	float x1 = 0;
	float y1 = mHeight / 2;
	float x2 = -mWidth / 2;
	float y2 = -mHeight / 2;
	float x3 = mWidth / 2;
	float y3 = -mHeight / 2;

	float vertexData[6];

	vertexData[0] = x + (x1 * c - y1 * s);
	vertexData[1] = y + (x1 * s + y1 * c);
	vertexData[2] = x + (x2 * c - y2 * s);
	vertexData[3] = y + (x2 * s + y2 * c);
	vertexData[4] = x + (x3 * c - y3 * s);
	vertexData[5] = y + (x3 * s + y3 * c);

	glBindBuffer(GL_ARRAY_BUFFER, mVboId);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertexData), vertexData);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::Draw()
{
	glBindBuffer(GL_ARRAY_BUFFER, mVboId);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}