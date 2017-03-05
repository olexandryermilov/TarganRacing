#pragma once
#include <string>
#include "json.hpp"

using json = nlohmann::json;

class Gambler
{
public:
	Gambler();
	Gambler(std::string name, int id, int money, int regularIncome, double riskCoef);
	Gambler(const json& data);
	~Gambler();
	json toJson();
	//getters start here
	std::string getName() const { return name; }
	int getId() const { return id; }
	int getMoney() const { return money; }
	int getRegularIncome() const { return regularIncome; }
	double getRiskCoef() const { return riskCoef; }
	//int chooseCockroach();
	//favorite betcompany?
private:
	std::string name;
	int id;
	int money;
	int regularIncome;
	double riskCoef;
	Gambler fromJson(const json& data);
};

