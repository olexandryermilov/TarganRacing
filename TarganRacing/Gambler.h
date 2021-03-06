#pragma once
#include <string>
#include "json.hpp"

using json = nlohmann::json;

class Gambler
{
public:
	Gambler(std::string name, int id);
	Gambler(std::string name, int id, int money, int regularIncome, int riskCoef);
	Gambler(const json& data);
	Gambler();
	~Gambler();
	json toJson();
	void printInfo();
	int chooseCockroach(int cockroachesAmount);
	int chooseHowMuchToBet();
	int chooseBetCompany(int amountOfCompanies);
	void updateMoney(int money);
	void setMoney(int money);
	//getters start here
	std::string getName() const { return name; }
	int getId() const { return id; }
	int getMoney() const { return money; }
	int getRegularIncome() const { return regularIncome; }
	int getRiskCoef() const { return riskCoef; }
	//favorite betcompany?
private:
	std::string name;
	int id;
	int money;
	int regularIncome;//between 0 and 100
	int riskCoef;//between 0 and 100
	void fromJson(const json& data);
};

