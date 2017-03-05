#include "Gambler.h"


Gambler::Gambler()
{}

Gambler::Gambler(const json& data)
{
	*this=fromJson(data);
}

Gambler::Gambler(std::string name, int id, int money, int regularIncome, double riskCoef):
	name(name),id(id),money(money),regularIncome(regularIncome),riskCoef(riskCoef)
{

}


Gambler::~Gambler()
{
}

Gambler Gambler::fromJson(const json& data)
{
	Gambler g;
	//g.name = data["name"]; //problem with assignment
	g.id = data["id"];
	g.money = data["money"];
	g.regularIncome = data["regularIncome"];
	g.riskCoef = data["riskCoef"];
	return g;
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
