#pragma once
#include <vector>
#include "Cockroach.h"
#include "Gambler.h"
#include "Stadium.h"
#include "BetCompany.h"
class Print
{
public:
	Print();
	~Print();
	void printAllCockroachesInfo(std::vector<Cockroach> &allCockroaches);
	void printSingleCockroachInfo(Cockroach cockroach);
	void printRaceInfo();
	void printAllBetCompaniesInfo(std::vector<BetCompany>&allBetCompanies);
	void printSingleBetCompanyInfo(BetCompany betCompany);
	void printAllGamblersInfo(std::vector<Gambler>&allGamblers);
	void printSingleGamblerInfo(Gambler gambler);
	void printAllStadiumsInfo(std::vector<Stadium> &allStadiums);
	void printSingleStadiumInfo(Stadium stadium);
	void print
};

