#pragma once
#include <SDL.h>
#include <glew.h>

#include "Agent.h"

//This class is used to handle the graphics side of the application.

class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();

	void InitSystems();

	void Draw();
	void SwapBuffers();
	void ProcessInput();

private:
	SDL_Window * mWindow;
	int mWidth;
	int mHeight;
	bool show;
};