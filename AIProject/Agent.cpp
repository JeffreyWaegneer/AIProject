#include "Agent.h"
#include <cstdlib>
#include <iostream>
#include <math.h>


Agent::Agent()
{
	mPosition.x = 0.f;
	mPosition.y = -.99f;
	mBrain = Brain();
	mSprite.Init(mPosition.x, mPosition.y, 0.02f, 0.04f, mBrain.GetDirection().angleRadian());
	dead = false;
}


Agent::~Agent()
{
}

void Agent::Move()
{
	if (dead)
		return;

	mPosition.x += float(mBrain.GetDirection().x)/100;
	mPosition.y += float(mBrain.GetDirection().y)/100;

	mSprite.Update(mPosition.x, mPosition.y, mBrain.GetDirection().angleRadian());
}

void Agent::Draw()
{
	mSprite.Draw();
}

bool Agent::Update()
{
	bool next = true;
	next = mBrain.NextStep();

	if (mPosition.x >= 0.99 || mPosition.x <= -0.99 || mPosition.y >= 0.99 || mPosition.y <= -1 || ReachedTarget() || !next)
	{
		dead = true;
	}
	return dead;
}

float Agent::CalculateFitness()
{
	float fitness;
	float distance = CalculateDistance(mTarget, mPosition);

	if (ReachedTarget())
		//If you get really close to the target it's possible to score up to 2500 without touching the target.
		fitness = 2500 + 2500.0f / (float)((powf((float)mBrain.GetStep(), 2)));
	else
		fitness = 100 / powf(distance, 2);
	return fitness;
}

Brain Agent::CreateBabyBrain()
{
	Brain b = mBrain.Clone();
	b.Mutate();
	return b;
}

Brain Agent::CreateCloneBrain()
{
	Brain b = mBrain.Clone();
	return b;
}

void Agent::SetTarget(Position target)
{
	mTarget = target;
}

float Agent::CalculateDistance(Position a, Position b)
{
	return sqrt(powf((a.x - b.x), 2) + powf((a.y - b.y), 2));
}

bool Agent::ReachedTarget()
{
	if (CalculateDistance(mTarget, mPosition) < .02f)
		return true;
	else
		return false;
}

void Agent::SetBrain(Brain b)
{
	dead = false;
	mPosition.x = 0.f;
	mPosition.y = -.99f;
	mBrain = b;
	mSprite.Init(mPosition.x, mPosition.y, 0.02, 0.04, mBrain.GetDirection().angleRadian());
}
