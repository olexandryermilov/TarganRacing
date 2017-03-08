#pragma once
#include <string>
#include <vector>
#include "Cockroach.h"
#include "json.hpp"

using json = nlohmann::json;

class BetCompany
{
public:
	BetCompany();
	BetCompany(const json& data);
	BetCompany(std::string name, int id, int greedyness, int money);
	json toJson();
	~BetCompany();
	std::vector<double> assignCoefs(std::vector<Cockroach> &allCockroaches);
	//getters start here
	std::string getName() const { return name; }
	int getId() const { return id; }
	int getGreedyness() const { return greedyness; }
	int getMoney() const { return money; }
private:
	std::string name;
	int id;
	int greedyness;//between 0 and 100, generated randomly
	int money;
	void fromJson(const json& data);
};

