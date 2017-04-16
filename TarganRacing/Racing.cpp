#include "Racing.h"



Racing::Racing()
{
}

Racing::Racing(int time)
{
	(*this).time = time;
}

int Racing::getTime()
{
	return (*this).time;
}

void Racing::setTime(int time)
{
	(*this).time = time;
}

std::vector<int> Racing::Race(std::vector<Cockroach>&cockroaches, Stadium stadium)
{
	int size = cockroaches.size();
	std::vector<int>result(size,-1);
	return result;
}

Racing::~Racing()
{
}
