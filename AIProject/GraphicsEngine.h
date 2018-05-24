#pragma once
#include <SDL.h>
#include <glew.h>

#include "Agent.h"

class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();

	void InitSystems();

	void Draw();
	void SwapBuffers();
	void ProcessInput();

	void AddSprite(float x, float y, float width, float height);

private:
	SDL_Window * mWindow;
	int mWidth;
	int mHeight;
	bool show;
};