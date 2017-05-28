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
	void Race(std::vector<Cockroach>&cockroaches, Stadium stadium);
	void setTime(int time);
	int getTime();
	static Stadium stadium;
private:
	int time;
	
	void printLog(std::vector<Cockroach>&cockroaches, Stadium stadium);
};

