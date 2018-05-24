#include <string>
#include <iostream>

#include "GraphicsEngine.h"

void FatalError(std::string errorMsg)
{
	std::cout << errorMsg << std::endl;
	std::cout << "Press any key to quit,...";
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
}

GraphicsEngine::GraphicsEngine()
{
	mWindow = nullptr;
	mWidth = 480;
	mHeight = 480;
	show = true;
	InitSystems();
}


GraphicsEngine::~GraphicsEngine()
{
}

void GraphicsEngine::InitSystems()
{
	SDL_Init(SDL_INIT_EVERYTHING);

	mWindow = SDL_CreateWindow("Genetic Algorithm", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, mWidth, mHeight, SDL_WINDOW_OPENGL);
	if (mWindow == nullptr)
		FatalError("SDL Window could not be initialised!");

	SDL_GLContext glContext = SDL_GL_CreateContext(mWindow);
	if (glContext == nullptr)
		FatalError("GlContext could not be created!");

	GLenum glewError = glewInit();
	if (glewError != GLEW_OK)
		FatalError("Glew could not be initialised!");

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	glClearColor(0.2, 0, 0.5, 1.0);
}

void GraphicsEngine::Draw()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GraphicsEngine::SwapBuffers()
{
	if(show)
		SDL_GL_SwapWindow(mWindow);
}

void GraphicsEngine::ProcessInput()
{
	SDL_Event evnt;

	while (SDL_PollEvent(&evnt))
	{
		switch (evnt.type)
		{
		case SDL_KEYDOWN:
			show = !show;
			break;
		case SDL_QUIT:
			SDL_Quit();
			break;
		}
	}
}

void GraphicsEngine::AddSprite(float x, float y, float width, float height)
{
}
