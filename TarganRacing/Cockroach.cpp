#include "Cockroach.h"
#include "json.hpp"
#include "Random.h"

int Cockroach::maxExp;
int Cockroach::minExp;

Cockroach::Cockroach(std::string name, int id, std::string teamName)
{
	(*this).name = name;
	(*this).id = id;
	(*this).teamName = teamName;
	amountOfLegs = 10+(1-Random::getRandomInteger(2))*Random::getRandomInteger(4);
	experience = Random::getRandomInteger(15);
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
	const int legsInfluence = 80;
	const int experienceInfluence=50;
	const int luckCoef =Random::getRandomInteger(5);
	const int qualityInfluence = 40;
	const int lengthInfluence =30;
	int mxE = Cockroach::maxExp;
	int mnE = Cockroach::minExp;

	int speedResult = (amountOfLegs*legsInfluence / Cockroach::maxLegs)+ qualityInfluence*stadium.getQuality()/Stadium::maxQuality + lengthInfluence*(6-stadium.lengthType)/6+
		(experience*experienceInfluence)/(std::abs(Cockroach::maxExp - Cockroach::minExp)+1);
	return speedResult-speedResult*luckCoef/10;
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
	const int maximumPlace = 9;
	const int maxQuality = 100;
	const int maxLength = 5000;
	const int minimumDelta = Random::getRandomInteger(6)+1;
	const int firstPlacePrize = 10;
	int length = stadium.getLength();
	int quality = stadium.getQuality();
	//printf("%d %.4f %d",maximumPlace-place,length*5.0/maxLength,maxQuality-quality);
	int delta = (int)((maximumPlace - place)*(1.0*length/maxLength)*(maxQuality - quality))
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
			delta = Random::getRandomInteger(1);
			if (delta == 1)delta = 3; else delta = 2;
		}
	}
	if (influenceCoef >= 10000)
	{
		if (amountOfLegs > 4)
		{
			//delta= 2;
			delta = Random::getRandomInteger(1);
			if (delta == 1)delta = 2; else delta = 1;
		}
		else
		{
			if (amountOfLegs > 2)
			{
				delta = Random::getRandomInteger(1);
				if (delta == 1)delta = 1; else delta = 0;
			}
			else
			{
				delta = Random::getRandomInteger(3);
				if (delta == 3&&amountOfLegs>1)delta = 1; else delta = 0;
			}
		}
	}
	else
	{
		if (influenceCoef >= 5000)
		{
			if (amountOfLegs > 4)
			{
				delta = Random::getRandomInteger(1);
				if (delta == 1)delta = 1; else delta = 0;
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
	lastThreePlaces[2] = lastThreePlaces[1];
	lastThreePlaces[1] = lastThreePlaces[0];
	lastThreePlaces[0] = place;
	updateExperience(place, stadium);
	updateLegs(stadium);
	updateGlory();
}

void Cockroach::updateGlory()
{
	glory = 0;
	glory += 100.0*(9 - lastThreePlaces[0]) / 8.0;
	glory += 50.0 * (9 - lastThreePlaces[1]) / 8.0;
	glory += 25.0 * (9 - lastThreePlaces[0]) / 8.0;
}


void Cockroach::printInfo()
{
	printf("Cockroach ");
	std::cout << name;
	printf(" has %d legs, %d experience and %d glory\n", amountOfLegs, experience, glory);
}
