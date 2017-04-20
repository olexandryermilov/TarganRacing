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

int main()
{
	const int cockroachesAmount = 9;
	const int stadiumsAmount = 10;
	const int betCompaniesAmount = 10;
	const int gamblersAmount = 15;
	std::vector<Cockroach>cockroaches = getCockroaches(cockroachesAmount); //generate cockroaches
	//generate stadiums
	//generate betcompanies
	//generate gamblers
	while (true)
	{
		//generate timetables
		//assign coefs
		//race
		//take money
		//update cockroaches
	}
}