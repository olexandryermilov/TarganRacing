#include "Racing.h"
#include <algorithm>

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
	std::vector<std::pair<int,int> >speeds(size);
	for (int i = 0; i < size; i++)
	{
		speeds[i].first = cockroaches[i].calculateSpeed(stadium);
		speeds[i].second = i;
	}
	sort(speeds.begin(), speeds.end());
	for (int i = 0; i < size; i++)
	{
		result[i] = speeds[i].second;
	}
	return result;
}

Racing::~Racing()
{
}
