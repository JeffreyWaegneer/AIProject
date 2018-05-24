#pragma once

#include <glew.h>

//Class is mostly used for the graphical side of an agent.

 class Sprite
{
public:
	Sprite();
	~Sprite();

	void Init(float x, float y, float width, float height, float angle);
	void Update(float x, float y, float angle);
	void Draw();

private:
	float mX, mY, mHeight, mWidth;
	GLuint mVboId;
};