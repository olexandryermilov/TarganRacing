#include "Gambler.h"


Gambler::Gambler()
{}

Gambler::Gambler(const json& data)
{
	fromJson(data);
}

Gambler::Gambler(std::string name, int id, int money, int regularIncome, double riskCoef):
	name(name),id(id),money(money),regularIncome(regularIncome),riskCoef(riskCoef)
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
