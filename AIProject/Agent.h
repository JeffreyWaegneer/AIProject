#pragma once

#include "Sprite.h"
#include "Brain.h"

class Agent
{
public:
	Agent();
	~Agent();

	void Move();
	void Draw();
	bool Update();
	float CalculateFitness();
	bool ReachedTarget();
	void SetBrain(Brain b);
	Brain CreateBabyBrain();
	Brain CreateCloneBrain();

	void SetTarget(Position target);

private:
	Position mPosition;
	Position mTarget;
	Brain mBrain;
	int counter;
	bool dead;

	Sprite mSprite;

	float CalculateDistance(Position a, Position b);
};