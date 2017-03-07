#pragma once
#include <string>
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
	//getters start here
	std::string getName() const { return name; }
	int getId() const { return id; }
	int getGreedyness() const { return greedyness; }
	int getMoney() const { return money; }
private:
	std::string name;
	int id;
	int greedyness;
	int money;
	void fromJson(const json& data);
};

