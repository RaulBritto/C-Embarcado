#include <string>
#include <iostream>
#include <vector>
#include "Week.h"

using namespace std;

#ifndef _EXCHANGE_H_
#define _EXCHANGE_H_ 


class Exchange
{
private:
	vector<WeekCotation> exchangeHistory;
public:
	Exchange();
	~Exchange();
	void Load(string file);
	void DollarPrice(string nameCurrency);
	float AveragePrice(string nameCurrency);
	float ExchangeVariation(string nameCurrency);

};

#endif