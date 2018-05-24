#pragma once
#include "RandomGen.h"
#include <cmath>

const long double PI = 3.141592653589793238L;


struct Position
{
	float x;
	float y;
};

struct Direction
{
	float x;
	float y;
	int magnitude;
	float angleRadian()
	{
		float angle = atan(y / x);
		if (x < 0)
			angle += (float)PI;
		return angle - (float)PI / 2;
	}
};

class Brain
{
public:
	Brain();
	Brain(Direction directions[100]);
	~Brain();

	//Creates a new brain with same directions.
	Brain Clone();

	//Mutates the brain, small chance a direction gets randomized.
	void Mutate();

	//Returns the direction it's heading in.
	Direction GetDirection();

	//Returns true if not dead. 
	bool NextStep();

	//Returns the number of steps taken.
	int GetStep();

private:
	Direction mDirections[100];

	//This is for the direction it's heading in.
	int step;

	//This is for the magnitude of the direction (eg. if it's 5 it should keep going in that direction for five turns)
	int counter;
};

