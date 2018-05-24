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
	float angleDegrees()
	{
		float angle = (float)(atan(y / x) * (180 / PI));
		if (x < 0 && y < 0)
			angle += 180;
		else if (x < 0)
			angle += 90;
		else if (y < 0)
			angle += 270;
		return angle;
	}
};

class Brain
{
public:
	Brain();
	Brain(Direction directions[100]);
	~Brain();

	Brain Clone();
	void Mutate();

	Direction GetDirection();
	bool NextStep();

	int GetStep();

private:
	Direction mDirections[100];
	int step;
	int counter;
};

