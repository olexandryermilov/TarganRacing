#include "BetCompany.h"



BetCompany::BetCompany()
{
}

BetCompany::BetCompany(const json& data)
{
	fromJson(data);
}

BetCompany::BetCompany(std::string name, int id, int greedyness, int money):
	name(name), id(id), greedyness(greedyness), money(money)
{
}


BetCompany::~BetCompany()
{
}

void BetCompany::fromJson(const json& data)
{
	//name = data["name"];
	id = data["id"];
	greedyness = data["greedyness"];
	money = data["money"];
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
