#include "Stadium.h"
#include "Racing.h"
#include "BetCompany.h"
#include "Cockroach.h"
#include "TimeTable.h"
#include "Gambler.h"
#include <vector>

std::vector<Cockroach> getCockroaches(int cockroachesAmount)
{
	std::vector<Cockroach>result(cockroachesAmount);
	std::string name="A";
	Cockroach::minExp = (int)1e9;
	Cockroach::maxExp = 0;
	for (int i = 0; i < cockroachesAmount; i++)
	{
		result[i] = Cockroach("Cockroach "+name,i+1,"TeamName"+name);
		Cockroach::minExp = std::min(Cockroach::minExp, result[i].getExperience());
		Cockroach::maxExp = std::max(Cockroach::maxExp, result[i].getExperience());
		result[i].printInfo();
		name[0]++;
	}
	return result;
}

std::vector<Stadium> getStadiums(int stadiumsAmount)
{
	std::vector<Stadium>result(stadiumsAmount);
	std::string name = "A";
	for (int i = 0; i < stadiumsAmount; i++)
	{
		result[i] = Stadium(name + "Stadium", i);
		result[i].printInfo();
		name[0]++;
	}
	return result;

}

std::vector<BetCompany> getBetCompanies(int betCompaniesAmount)
{
	std::vector<BetCompany>result(betCompaniesAmount);
	std::string name = "A";
	for (int i = 0; i < betCompaniesAmount; i++)
	{
		result[i] = BetCompany(i, name + " BetCompany");
		result[i].printInfo();
		name[0]++;
	}
	return result;
}

std::vector<Gambler> getGamblers(int gamblersAmount)
{
	std::vector<Gambler>result(gamblersAmount);
	std::string name = "A";
	for (int i = 0; i < gamblersAmount; i++)
	{
		result[i] = Gambler("Gambler " + name, i);
		result[i].printInfo();
		name[0]++;
	}
	return result;
}
int main()
{
	srand((int)clock());
	const int cockroachesAmount = 9;
	const int stadiumsAmount = 10;
	const int betCompaniesAmount = 10;
	const int gamblersAmount = 15;

	std::vector<Cockroach>cockroaches = getCockroaches(cockroachesAmount); //generate cockroaches
	system("pause");
	std::vector<Stadium>stadiums = getStadiums(stadiumsAmount);//generate stadiums
	system("pause");
	std::vector<BetCompany>betCompanies = getBetCompanies(betCompaniesAmount);//generate betcompanies
	system("pause");
	std::vector<Gambler>gamblers = getGamblers(gamblersAmount);//generate gamblers
	system("pause");
	while (true)
	{
		//todo: add print
		TimeTable timeTable;
		stadiums = timeTable.getTimeTable(stadiums);
		for (int p = 0; p < stadiumsAmount; p++)
		{
			Racing::stadium = stadiums[p];
			for (int i = 0; i < betCompaniesAmount; i++)//assign coefs
			{
				betCompanies[i].assignCoefs(cockroaches, stadiums[p]);
			}
			//add gamblers bet
			Racing racing;
			racing.Race(cockroaches, stadiums[p]);
			//updates, take money
			for (int i = 0; i < cockroachesAmount; i++)//update cockroaches
			{
				cockroaches[i].update(i+1, stadiums[p]);
				//Cockroach::minExp = std::min(Cockroach::minExp, cockroaches[i].getExperience());
				//Cockroach::maxExp = std::max(Cockroach::maxExp, cockroaches[i].getExperience());
			}
			stadiums[p].updateQuality(true);
			system("pause");
		}
		for (int i = 0; i < stadiumsAmount; i++)//update stadiums
		{
			stadiums[i].updateQuality(false);
		}
		system("pause");
	}
}