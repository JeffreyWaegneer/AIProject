#include "Brain.h"
#include <ctime>
#include <iostream>

Brain::Brain()
{
	step = 0;
	counter = 0;
	for (int i = 0; i < 100; i++)
	{
		mDirections[i].x = RandomGenerator::GetRandomFloat(-1, 1);
		mDirections[i].y = RandomGenerator::GetRandomFloat(-1, 1);
		mDirections[i].magnitude = RandomGenerator::GetRandomInt(0, 10);
	}
}

Brain::Brain(Direction directions[100])
{
	step = 0;
	counter = 0;
	for (int i = 0; i < 100; i++)
	{
		mDirections[i] = directions[i];
	}
}


Brain::~Brain()
{
}

Brain Brain::Clone()
{
	Brain clone = Brain(mDirections);
	return clone;
}

void Brain::Mutate()
{
	float mutationRate = 0.01;
	for (int i = 0; i < 100; i++)
	{
		float random = RandomGenerator::GetRandomFloat(0, 1);
		if (random <= mutationRate)
		{
			mDirections[i].x = RandomGenerator::GetRandomFloat(-1, 1);
			mDirections[i].y = RandomGenerator::GetRandomFloat(-1, 1);
			mDirections[i].magnitude = RandomGenerator::GetRandomInt(0, 10);
		}
	}
}

Direction Brain::GetDirection()
{
	return mDirections[step];
}

bool Brain::NextStep()
{
	if (mDirections[step].magnitude < counter++)
	{
		counter = 0;
		step++;
		if (step >= 100)
			return false;
	}
	return true;
}

int Brain::GetStep()
{
	return step;
}