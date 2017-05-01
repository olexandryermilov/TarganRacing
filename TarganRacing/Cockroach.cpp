#include "Cockroach.h"
#include "json.hpp"
#include "Random.h"


Cockroach::Cockroach(std::string name, int id, std::string teamName)
{
	(*this).name = name;
	(*this).id = id;
	(*this).teamName = teamName;
	amountOfLegs = 10;
	experience = 0;
	glory = 0;
}

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
	r["amountOfLegs"] = amountOfLegs;
	r["experience"] = experience;
	r["glory"] = glory;
	return r;
}

int Cockroach::calculateSpeed(Stadium stadium)//returns value between 0 and 200
{
	Random random;
	const int legsInfluence = 65;
	const int experienceInfluence=35;
	const int luckCoef =random.getRandomInteger(7);
	const int qualityInfluence = 15;
	const int lengthInfluence =10 ;
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

void Cockroach::updateExperience(const int place, Stadium stadium)
{
	const int maximumPlace = 15;
	const int maxQuality = 100;
	const int maxLength = 5000;
	const int minimumDelta = 5;
	const int firstPlacePrize = 10;
	int length = stadium.getLength();
	int quality = stadium.getQuality();
	int delta = (int)((maximumPlace - place)*(length/maxLength)*(maxQuality - quality))
		              +minimumDelta+firstPlacePrize*(place==1);
	printf("Cockroach ");
	std::cout << name;
	printf(": experience changed from %d to %d", experience, experience + delta);
	experience += delta;
	return;
}

void Cockroach::updateLegs(Stadium stadium)
{
	int length = stadium.getLength();
	int quality = stadium.getQuality();
	const int influenceCoef = (105 - quality) * length;//value between 5*100==500 and 105*5000==525000
	int delta = 0;
	if (influenceCoef >= 100000)
	{
		if (amountOfLegs > 6)
		{
			delta= 3;
		}
	}
	if (influenceCoef >= 10000)
	{
		if (amountOfLegs > 4)
		{
			delta= 2;
		}
		else
		{
			if (amountOfLegs > 2)
			{
				delta = 1;
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
				delta = 1;
			}
			else
			{
				//do smth
			}
		}
	}
	printf(", lost %d leg(s)\n", delta);
	amountOfLegs -= delta;
	return;
}

void Cockroach::update(const int place, Stadium stadium)
{
	updateExperience(place, stadium);
	updateLegs(stadium);
}

void Cockroach::printInfo()
{
	printf("Cockroach ");
	std::cout << name;
	printf(" has %d legs, %d experience and %d glory\n", amountOfLegs, experience, glory);
}
