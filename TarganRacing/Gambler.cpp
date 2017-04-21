#include "Gambler.h"
#include "Random.h"

Gambler::Gambler(std::string name, int id)
{
	Random random;
	(*this).name = name;
	(*this).id = id;
	money = random.getRandomInteger(1000);
	regularIncome = random.getRandomInteger(100);
	riskCoef = random.getRandomInteger(100);
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
/*int Gambler::chooseCockroach()
{

}*/
