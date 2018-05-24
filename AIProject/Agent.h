#pragma once

#include "Sprite.h"
#include "Brain.h"

class Agent
{
public:
	Agent();
	~Agent();

	//Move the agent to his next position, this updates the sprite.
	void Move();

	//Draws the sprite on the screen.
	void Draw();

	//Update the brain to the next direction. If there are no more directions or it hits a wall or reached the target it dies(stops moving). returns true if it's dead.
	bool Update();

	//Calculates the fitness of the agent.
	float CalculateFitness();

	//Returns true if the target was reached
	bool ReachedTarget();

	//Sets the brain and initializes everything.
	void SetBrain(Brain b);

	//Creates a mutated brain from this agent
	Brain CreateBabyBrain();

	//Creates a cloned brain(so no mutatio) from this agent.
	Brain CreateCloneBrain();

	//Sets the desired target.
	void SetTarget(Position target);

private:
	Position mPosition;
	Position mTarget;
	Brain mBrain;
	bool dead;

	Sprite mSprite;

	//Calculates the distance between the agents position and the target position.
	float CalculateDistance(Position a, Position b);
};