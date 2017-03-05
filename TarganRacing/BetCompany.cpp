#include "BetCompany.h"



BetCompany::BetCompany()
{
}

BetCompany::BetCompany(const json& data)
{
	*this = fromJson(data);
}

BetCompany::BetCompany(std::string name, int id, int greedyness, int money):
	name(name), id(id), greedyness(greedyness), money(money)
{
}


BetCompany::~BetCompany()
{
}

BetCompany BetCompany::fromJson(const json& data)
{
	BetCompany bc;
	//bc.name = data["name"];
	bc.id = data["id"];
	bc.greedyness = data["greedyness"];
	bc.money = data["money"];
	return bc;
}

json BetCompany::toJson()
{
	json r;
	r["name"] = name;
	r["id"] = id;
	r["greedyness"] = greedyness;
	r["money"] = money;
	return r;
}
