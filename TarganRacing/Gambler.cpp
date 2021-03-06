#include "Gambler.h"
#include "Random.h"

Gambler::Gambler(std::string name, int id)
{
	(*this).name = name;
	(*this).id = id;
	money = Random::getRandomInteger(1000);
	regularIncome = Random::getRandomInteger(100);
	riskCoef = Random::getRandomInteger(100);
}

Gambler::Gambler(const json& data)
{
	fromJson(data);
}

Gambler::Gambler(std::string name, int id, int money, int regularIncome, int riskCoef):
	name(name),id(id),money(money),regularIncome(regularIncome),riskCoef(riskCoef)
{

}

Gambler::Gambler()
{

}

Gambler::~Gambler()
{
}

void Gambler::fromJson(const json& data)
{
	//name = data["name"]; //problem with assignment
	id = data["id"];
	money = data["money"];
	regularIncome = data["regularIncome"];
	riskCoef = data["riskCoef"];
}

json Gambler::toJson()
{
	json r;
	r["name"] = name;
	r["id"] = id;
	r["money"] = money;
	r["regularIncome"] = regularIncome;
	r["riskCoef"] = riskCoef;
	return r;
}

void Gambler::printInfo()
{
	printf("Gambler ");
	std::cout << name;
	printf(" has %d money.\n",money);
}
int Gambler::chooseCockroach(int cockroachesAmount)
{
	return Random::getRandomInteger(cockroachesAmount-1);
}
int Gambler::chooseHowMuchToBet()
{
	return money*Random::getRandomInteger(65) / 100;
}
int Gambler::chooseBetCompany(int amountOfCompanies)
{
	return Random::getRandomInteger(amountOfCompanies-1);
}

void Gambler::setMoney(int money)
{
	(*this).money = money;
	printInfo();
}

void Gambler::updateMoney(int money)
{
	(*this).money += money;
	printInfo();
	//printf("Gambler "); std::cout << (*this).name; printf(" now has %d money\n", (*this).money);
}