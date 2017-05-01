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

void Racing::printLog(std::vector<Cockroach>&cockroaches, Stadium stadium, std::vector<int>&result)
{
	printf("Stadium "); std::cout << stadium.getName()<<std::endl;
	for (int i = 0; i < result.size(); i++)
	{
		printf("%d-");
		if (i%10 == 0)printf("st");
		if (i%10 == 1)printf("nd");
		if (i%10 == 2)printf("rd");
		if (i % 10 > 2)printf("th");
		printf(" place - Cockroach ");
		std::cout << cockroaches[result[i]].getName()<<std::endl;
	}
}

Racing::~Racing()
{
}
