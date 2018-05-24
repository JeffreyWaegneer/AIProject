#pragma once

#include <glew.h>
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