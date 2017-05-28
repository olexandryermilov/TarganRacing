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
	return stadiums;
}

