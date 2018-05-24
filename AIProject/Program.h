#pragma once
#include "GraphicsEngine.h"
#include "Agent.h"
#include "RandomGen.h"

class Program
{
public:
	Program();
	~Program();

	void Run();
	bool UpdateAgents();
	bool AgentReachedTarget();
	void CreateNextGen();

	float CalculateFitnessSum();
	Agent SelectParent(float sum);
	Agent SelectChampion();

private:
	GraphicsEngine mGe;
	Agent mAgents[100];
	Position mTarget;
	Sprite mTargetSprite;
	float GenChampFit;
	int gen;
};

