#include "BetCompany.h"
#include <algorithm>
#include "Random.h"

BetCompany::BetCompany(int id, std::string name)
{
	(*this).id = id;
	(*this).name = name;
	greedyness = Random::getRandomInteger(100);
	money = Random::getRandomInteger(1000);
}

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

void BetCompany::printInfo()
{
	printf("BetCompany "); std::cout << name;
	printf(" has %d money\n", money);
}

void BetCompany::updateMoney(int money)
{
	(*this).money -= money;
	if ((*this).money < 0)(*this).money = 0;
	printInfo();
	//printf("BetCompany "); std::cout << (*this).name; printf(" now has %d money\n", (*this).money);
}

void BetCompany::setMoney(int money)
{
	(*this).money = money;
	printInfo();
}

std::vector <double> BetCompany::assignCoefs(std::vector<Cockroach> &allCockroaches, Stadium stadium)
{
	const double beginningCoef = 1.25;
	const int maxGlory = 175;
	int amountOfCockroaches = allCockroaches.size();
	std::vector< std::pair<int,int>  >speeds(amountOfCockroaches);
	for (int i = 0; i < amountOfCockroaches; ++i)
	{
		speeds[i].first = allCockroaches[i].calculateSpeed(stadium);
		speeds[i].second = i;
	}
	sort(speeds.begin(), speeds.end(), [](std::pair<int, int >l, std::pair<int,int>r)
	{
		return l.first < r.first;
	}
	);
	double tempCoef = beginningCoef - greedyness/400.0;//between 1.0 and 1.25
	std::vector<double>coefs(amountOfCockroaches);
	for (int i = 0; i < amountOfCockroaches; ++i)
	{
		coefs[speeds[i].second] = tempCoef;
		const int glory = allCockroaches[speeds[i].second].getGlory();
		const double greedyInfluence = greedyness / 200.0;// value between 0.0 and 0.5
		if (coefs[speeds[i].second] > 5.0)
		{
			if (glory > 100)
			{
				coefs[speeds[i].second] -= 2.0-greedyInfluence;
			}
			if (glory > 50)
			{
				coefs[speeds[i].second] -= 1.0 - greedyInfluence;
			}
			if (glory < 25)
			{
				coefs[speeds[i].second] += 0.5 - greedyInfluence;
			}
		}
		else
		{
			if (coefs[speeds[i].second] > 3.0)
			{
				if (glory > 100)
				{
					coefs[speeds[i].second] -= 1.5 - 0.5*greedyInfluence;
				}
				if (glory > 50)
				{
					coefs[speeds[i].second] -= 0.6 - 0.5*greedyInfluence;
				}
				if (glory < 25)
				{
					coefs[speeds[i].second] += 0.3 - 0.5*greedyInfluence;
				}
			}
			else
			{
				if (coefs[speeds[i].second] > 2.0)
				{
					if (glory > 100)
					{
						coefs[speeds[i].second] -= 0.5 - 0.25*greedyInfluence;
					}
					if (glory > 50)
					{
						coefs[speeds[i].second] -= 0.25 - 0.25*greedyInfluence;
					}
					if (glory < 25)
					{
						coefs[speeds[i].second] += 0.25 - 0.25*greedyInfluence;
					}
				}
				else
				{
					//do smth?
				}
			}
		}
		if (i < amountOfCockroaches - 1)
			tempCoef += 4.0 * (speeds[i + 1].first - speeds[i].first)/100-0.3*greedyInfluence;
		if (tempCoef < 0)throw 1;
	}
	std::cout << "BetCompany " << name << " gave those coefficients\n";
	for (int i = 0; i < amountOfCockroaches; i++)
	{
		std::cout << "Cockroach " << allCockroaches[i].getName()<< " - "<<coefs[i]<<std::endl;
	}
	return coefs;
	
}
