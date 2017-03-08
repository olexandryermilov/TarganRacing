#include "BetCompany.h"
#include <algorithm>



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

std::vector <double> BetCompany::assignCoefs(std::vector<Cockroach> &allCockroaches)
{
	const double beginningCoef = 1.25;
	int amountOfCockroaches = allCockroaches.size();
	std::vector< std::pair<int,int>  >speeds(amountOfCockroaches);
	for (int i = 0; i < amountOfCockroaches; ++i)
	{
		speeds[i].first = allCockroaches[i].calculateSpeed();
		speeds[i].second = i;
	}
	sort(speeds.begin(), speeds.end(), [](std::pair<int, int >l, std::pair<int,int>r)
	{
		return l.first > r.first;
	}
	);
	double tempCoef = beginningCoef - greedyness/400;//between 1.0 and 1.25
	std::vector<double>coefs(amountOfCockroaches);
	for (int i = 0; i < amountOfCockroaches; ++i)
	{
		coefs[speeds[i].second] = tempCoef;
		if (i < amountOfCockroaches - 1)tempCoef += 4 * (speeds[i + 1].first - speeds[i].first);
	}
	return coefs;
	
}
