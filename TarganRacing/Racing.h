#pragma once
#include "json.hpp"
#include <vector>
#include <string>
#include "Stadium.h"
#include "Cockroach.h"
using nlohmann::json;
class Racing
{
public:
	Racing();
	~Racing();
	Racing(int time);
	//Stadium stadium;
	//std::vector<Cockroach>cockroaches;
	std::vector<int> Race(std::vector<Cockroach>&cockroaches, Stadium stadium);
	void setTime(int time);
	int getTime();
private:
	int time;
};

