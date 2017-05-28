#include "TimeTable.h"



TimeTable::TimeTable()
{
}


TimeTable::~TimeTable()
{
}

std::vector<Stadium> TimeTable::getTimeTable(std::vector<Stadium> &stadiums) {
	//int stadiumsAmount = stadiums.size();
	std::random_shuffle(stadiums.begin(), stadiums.end());
	TimeTable::printInfo(stadiums);
	return stadiums;
}

void TimeTable::printInfo(std::vector<Stadium> &stadiums)
{
	for (int i = 0; i < stadiums.size(); i++)
	{
		std::cout << stadiums[i].getName() << std::endl;
	}
	std::cout << std::endl;
}

