#include "Program.h"

#include <iostream>

Program::Program()
{
	mTarget.x = 0.f;
	mTarget.y = 0.8f;
	mTargetSprite.Init(mTarget.x, mTarget.y, 0.01f, 0.01f, 0.f);
	for (int i = 0; i < 100; i++)
		mAgents[i].SetTarget(mTarget);
	GenChampFit = 0.f;
	gen = 0;
}


Program::~Program()
{
}

void Program::Run()
{
	while (true)
	{
		mGe.ProcessInput();
		mGe.Draw();
		if (!UpdateAgents() && !AgentReachedTarget())
		{
			mTargetSprite.Draw();
			for (int i = 0; i < 100; i++)
			{
				mAgents[i].Draw();
			}
		}
		else
			CreateNextGen();
		mGe.SwapBuffers();
	}
}

bool Program::UpdateAgents()
{
	bool allDead = true;
		
	for (int i = 0; i < 100; i++)
	{
		if (!mAgents[i].Update())
			allDead = false;
		mAgents[i].Move();
	}
	return allDead;
}

bool Program::AgentReachedTarget()
{
	bool reached = false;
	for (int i = 0; i < 100; i++)
	{
		if (mAgents[i].ReachedTarget())
			reached = true;
	}
	return reached;
}

void Program::CreateNextGen()
{
	Brain nextGenBrain[100];
	nextGenBrain[0] = SelectChampion().CreateCloneBrain();
	float sum = CalculateFitnessSum();
	std::cout << "Gen:\t\t\t" << gen << std::endl;
	std::cout << "Champ fitness:\t\t" << GenChampFit << std::endl;
	std::cout << "Average fitness:\t" << sum / 100 << std::endl;
	std::cout << "--------------------------------" << std::endl;
	for (int i = 1; i < 100; i++)
	{
		nextGenBrain[i] = SelectParent(sum).CreateBabyBrain();
	}

	for (int i = 0; i < 100; i++)
	{
		mAgents[i].SetBrain(nextGenBrain[i]);
	}
	gen++;
}

float Program::CalculateFitnessSum()
{
	float fitnessSum = 0.f;
	for (int i = 0; i < 100; i++)
		fitnessSum += mAgents[i].CalculateFitness();
	return fitnessSum;
}

Agent Program::SelectParent(float sum)
{
	float r = RandomGenerator::GetRandomFloat(0, sum);
	float runningSum = 0;
	for (int j = 0; j < 100; j++)
	{
		runningSum += mAgents[j].CalculateFitness();
		if (runningSum > r)
			return mAgents[j];
	}
}

Agent Program::SelectChampion()
{
	//mAgents[0] will be the champion from the previous generation.
	Agent bestAgent = mAgents[0];
	for (int i = 0; i < 100; i++)
	{
		//If the fitness of the current agent is higher than the champ, it becomes the champ.
		if (bestAgent.CalculateFitness() < mAgents[i].CalculateFitness())
			bestAgent = mAgents[i];
	}
	GenChampFit = bestAgent.CalculateFitness();
	return bestAgent;
}