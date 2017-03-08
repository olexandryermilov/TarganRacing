#include "Cockroach.h"
#include "json.hpp"




Cockroach::Cockroach(std::string name, int id, std::string teamName, int amountOfLegs, int experience, int glory):
	name(name),id(id),teamName(teamName),amountOfLegs(amountOfLegs),experience(experience),glory(glory)
{
}

Cockroach::Cockroach(const json& data)
{
	fromJson(data);
}

Cockroach::Cockroach()
{

}

Cockroach::~Cockroach()
{
}

json Cockroach::toJson()
{
	json r;
	r["name"] = name;
	r["id"] = id;
	r["teamName"] = teamName;
	r["amontOfLegs"] = amountOfLegs;
	r["experience"] = experience;
	r["glory"] = glory;
	return r;
}

int Cockroach::calculateSpeed()
{
	const int legsInfluence = 65;
	const int experienceInfluence=35;

	return amountOfLegs*legsInfluence + experience*experienceInfluence;
}

void Cockroach::fromJson(const json& data)
{
	//name = data["name"];
	id = data["id"];
	//teamName = data["teamName"];
	amountOfLegs = data["amountOfLegs"];
	experience = data["experience"];
	glory = data["glory"];
}

void Cockroach::updateExperience(const int place, const int length, const int quality)
{
	const int maximumPlace = 15;
	const int maxQuality = 100;
	const int maxLength = 5000;
	const int minimumDelta = 5;
	const int firstPlacePrize = 10;
	int delta = (int)((maximumPlace - place)*(length/maxLength)*(maxQuality - quality))
		              +minimumDelta+firstPlacePrize*(place==1);
	experience += delta;
	return;
}

void Cockroach::updateLegs(const int quality, const int length)
{
	int influenceCoef = (105 - quality) * length;
	if (influenceCoef >= 10000)
	{
		if (amountOfLegs > 4)
		{
			amountOfLegs -= 2;
		}
		else
		{
			if (amountOfLegs > 2)
			{
				amountOfLegs--;
			}
			else
			{
				//do smth
			}
		}
	}
	else
	{
		if (influenceCoef >= 5000)
		{
			if (amountOfLegs > 4)
			{
				amountOfLegs--
			}
			else
			{
				//do smth
			}
		}
	}
	return;
}
