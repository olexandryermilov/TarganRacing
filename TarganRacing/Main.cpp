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
	const int stadiumsAmount = 8;
	const int betCompaniesAmount = 5;
	const int gamblersAmount = 5;

	std::vector<Cockroach>cockroaches = getCockroaches(cockroachesAmount); //generate cockroaches
	system("pause");
	std::vector<Stadium>stadiums = getStadiums(stadiumsAmount);//generate stadiums
	system("pause");
	std::vector<BetCompany>betCompanies = getBetCompanies(betCompaniesAmount);//generate betcompanies
	for (int i = 0; i < betCompaniesAmount; i++)
	{
		betCompanies[i].coefs.resize(cockroachesAmount);
	}
	system("pause");
	std::vector<Gambler>gamblers = getGamblers(gamblersAmount);//generate gamblers
	system("pause");
	while (true)
	{
		//todo: add print
		printf("Timetable:\n");
		stadiums = TimeTable::getTimeTable(stadiums);
		//system("pause");
		for (int p = 0; p < stadiumsAmount; p++)
		{
			Racing::stadium = stadiums[p];
			for (int i = 0; i < betCompaniesAmount; i++)//assign coefs
			{
				betCompanies[i].coefs=betCompanies[i].assignCoefs(cockroaches, stadiums[p]);
			}
			//add gamblers bet
			std::vector<int>cockroachesChosenId(gamblersAmount);
			std::vector<int> betCompaniesChosenNumber(gamblersAmount);	
			std::vector<int>moneyToWin(gamblersAmount);
			for (int i = 0; i < gamblersAmount; i++)
			{
				betCompaniesChosenNumber[i] = gamblers[i].chooseBetCompany(betCompaniesAmount);
				int moneyToBet = gamblers[i].chooseHowMuchToBet();
				int cockroachNum = gamblers[i].chooseCockroach(cockroachesAmount);
				cockroachesChosenId[i] = cockroaches[cockroachNum].getId();
				gamblers[i].setMoney(gamblers[i].getMoney() - moneyToBet);
				betCompanies[betCompaniesChosenNumber[i]].setMoney(betCompanies[betCompaniesChosenNumber[i]].getMoney()+moneyToBet);
				moneyToWin[i] = moneyToBet*betCompanies[betCompaniesChosenNumber[i]].coefs[cockroachNum];
				printf("Gambler "); std::cout << gamblers[i].getName(); printf(" bet %d money on cockroach ", moneyToBet); std::cout << cockroaches[cockroachNum].getName();
				printf(". He will win %d money if his bet is right\n", moneyToWin[i]);
			}
			//system("pause");
			Racing racing;
			racing.Race(cockroaches, stadiums[p]);
			//updates, take money
			for (int i = 0; i < cockroachesAmount; i++)//update cockroaches
			{
				cockroaches[i].update(i+1, stadiums[p]);
				Cockroach::minExp = std::min(Cockroach::minExp, cockroaches[i].getExperience());
				Cockroach::maxExp = std::max(Cockroach::maxExp, cockroaches[i].getExperience());
			}
			system("pause");
			for (int i = 0; i < gamblersAmount; i++)
			{
				bool hasWon = cockroachesChosenId[i] == cockroaches[0].getId();
				if(hasWon)
				{
					printf("Gambler "); std::cout << gamblers[i].getName(); printf(" won\n");
					gamblers[i].updateMoney(moneyToWin[i]);
					betCompanies[betCompaniesChosenNumber[i]].updateMoney(moneyToWin[i]);
				}
				else
				{
					printf("Gambler "); std::cout << gamblers[i].getName(); printf(" lost\n");
				}
			}
			//system("pause");
			stadiums[p].updateQuality(true);
			//system("pause");
		}
		for (int i = 0; i < stadiumsAmount; i++)//update stadiums
		{
			stadiums[i].updateQuality(false);
		}
		for (int i = 0; i < cockroachesAmount; i++)
		{
			cockroaches[i].printInfo();
		}
		system("pause");
	}
}