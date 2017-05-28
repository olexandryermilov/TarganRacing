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

bool speedComp(std::pair<Cockroach, Stadium>  l, std::pair<Cockroach, Stadium> r)
{
	Stadium st = l.second;
	return l.first.calculateSpeed(st) > r.first.calculateSpeed(st);
}

void Racing::Race(std::vector<Cockroach>&cockroaches, Stadium stadium)
{
	int size = cockroaches.size();
	std::vector<std::pair<Cockroach, Stadium> >resultOfRace(size);
	for (int i = 0; i < size; i++)
	{
		resultOfRace[i].first = cockroaches[i];
		resultOfRace[i].second = stadium;
	}
	sort(resultOfRace.begin(),resultOfRace.end(), speedComp);
	printLog(cockroaches,stadium);
	/*std::vector<int>result(size,-1);
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
	return result;*/
}

void Racing::printLog(std::vector<Cockroach>&cockroaches, Stadium stadium)
{
	printf("Stadium "); std::cout << stadium.getName()<<":"<<std::endl;
	for (int i = 0; i < cockroaches.size(); i++)
	{
		printf("%d-");
		if (i%10 == 0)printf("st");
		if (i%10 == 1)printf("nd");
		if (i%10 == 2)printf("rd");
		if (i % 10 > 2)printf("th");
		printf(" place - Cockroach ");
		std::cout << cockroaches[i].getName()<<std::endl;
	}
}

Racing::~Racing()
{
}
