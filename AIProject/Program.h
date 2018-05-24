#pragma once
#include "GraphicsEngine.h"
#include "Agent.h"
#include "RandomGen.h"

class Program
{
public:
	Program();
	~Program();

	//Our main loop
	void Run();
	
	//Updates all the agents, returns true if all agents are dead
	bool UpdateAgents();

	//Returns true if someone reached the target.
	bool AgentReachedTarget();

	//Creates the next generation.
	void CreateNextGen();

	//Calculates the total fitness
	float CalculateFitnessSum();

	//Selects a parent based on the fitness the fitness.
	Agent SelectParent(float sum);

	//Selects the best agent of the generation.
	Agent SelectChampion();

private:
	GraphicsEngine mGe;
	Agent mAgents[100];
	Position mTarget;
	Sprite mTargetSprite;
	float GenChampFit;
	int gen;
};

