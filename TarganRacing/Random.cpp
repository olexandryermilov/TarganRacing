#include "Random.h"
#include <cstdlib>
#include <ctime>


Random::Random()
{
}


int Random::getRandomInteger(int bound)
{
	srand((int)clock());
	int result = rand()*rand();
	return result%(bound+1);
}

Random::~Random()
{
}
