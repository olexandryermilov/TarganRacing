#include "Random.h"
#include <cstdlib>
#include <ctime>


Random::Random()
{
}

double Random::getRandomDouble()
{
	srand((int)clock());
	return ;
}

int Random::getRandomInteger(int bound)
{
	int result = rand()*rand();
	return result%(bound+1);
}

Random::~Random()
{
}
