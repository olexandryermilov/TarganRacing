#include "Racing.h"
#include <algorithm>

Stadium Racing::stadium;
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

bool speedComp(Cockroach &l, Cockroach &r)
{
	Stadium st = Racing::stadium;
	std::cout << l.getId() << ' ' << r.getId() << std::endl;
	return l.calculateSpeed(st) >= r.calculateSpeed(st);
}

void Racing::Race(std::vector<Cockroach>&cockroaches, Stadium stadium)
{
	int size = cockroaches.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 1; j < size; j++)
		{
			if (cockroaches[j].calculateSpeed(Racing::stadium) > cockroaches[j - 1].calculateSpeed(Racing::stadium))
			{
				Cockroach t = cockroaches[j];
				cockroaches[j] = cockroaches[j - 1];
				cockroaches[j - 1] = t;
			}
		}
	}
	printLog(cockroaches,stadium);
}

void Racing::printLog(std::vector<Cockroach>&cockroaches, Stadium stadium)
{
	printf("Stadium "); std::cout << stadium.getName()<<":"<<std::endl;
	for (int i = 0; i < (int)cockroaches.size(); i++)
	{
		printf("%d-",i+1);
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
