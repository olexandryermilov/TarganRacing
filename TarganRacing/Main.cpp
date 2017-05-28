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
	for (int i = 0; i < cockroachesAmount; i++)
	{
		result[i] = Cockroach("Name"+(char)(i+'0'),i+1,"TeamName"+(char)(i+'0'));
	}
	return result;
}

std::vector<Stadium> getStadiums(int stadiumsAmount)
{
	std::vector<Stadium>result(stadiumsAmount);
	for (int i = 0; i < stadiumsAmount; i++)
	{
		result[i] = Stadium("", i);
	}
	return result;

}

std::vector<BetCompany> getBetCompanies(int betCompaniesAmount)
{
	std::vector<BetCompany>result(betCompaniesAmount);
	for (int i = 0; i < betCompaniesAmount; i++)
	{
		result[i] = BetCompany(i, "");
	}
	return result;
}

std::vector<Gambler> getGamblers(int gamblersAmount)
{
	std::vector<Gambler>result(gamblersAmount);
	for (int i = 0; i < gamblersAmount; i++)
	{
		result[i] = Gambler("", i);
	}
	return result;
}

int main()
{
	const int cockroachesAmount = 9;
	const int stadiumsAmount = 10;
	const int betCompaniesAmount = 10;
	const int gamblersAmount = 15;
	std::vector<Cockroach>cockroaches = getCockroaches(cockroachesAmount); //generate cockroaches
	std::vector<Stadium>stadiums = getStadiums(stadiumsAmount);//generate stadiums
	std::vector<BetCompany>betCompanies = getBetCompanies(betCompaniesAmount);//generate betcompanies
	std::vector<Gambler>gamblers = getGamblers(gamblersAmount);//generate gamblers
	while (true)
	{
		//todo: add print
		TimeTable timeTable;
		stadiums = timeTable.getTimeTable(stadiums);
		for (int p = 0; p < stadiumsAmount; p++)
		{
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
				cockroaches[i].update(i, stadiums[p]);
			}
			for (int i = 0; i < stadiumsAmount; i++)//update stadiums
			{
				stadiums[i].updateQuality();
			}
			system("pause");
		}
		system("pause");
	}
}