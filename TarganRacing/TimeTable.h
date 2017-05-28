#pragma once
#include "BetCompany.h"
#include "Cockroach.h"
#include "Gambler.h"
#include "Racing.h"
#include "Stadium.h"
#include "Random.h"
#include <vector>
#include <algorithm>
class TimeTable
{
public:
	TimeTable();
	~TimeTable();
	static std::vector <Stadium> getTimeTable(std::vector<Stadium> &stadiums);
};

