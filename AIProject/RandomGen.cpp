#include <random>
#include <ctime>
#include "RandomGen.h"

namespace RandomGenerator
{
	static std::mt19937_64 rng = std::mt19937_64(time(0));
	static std::uniform_real_distribution<float> unifFloat;
	static std::uniform_int_distribution<int> unifInt;

	int GetRandomInt(int min, int max)
	{
		unifInt = std::uniform_int_distribution<int>(min, max);
		return unifInt(rng);
	}
	float GetRandomFloat(float min, float max)
	{
		unifFloat = std::uniform_real_distribution<float>(min, max);
		return unifFloat(rng);
	}
}