#include <string>
#include <regex>
#include "Currency.h"

using namespace std;

#ifndef _WEEK_H_
#define	_WEEK_H_

class WeekCotation
{
private:
	enum NamesCurrencies {BRL=0, EUR, JPY, CNY};
	string date;
	Currency list[4];

public:
	WeekCotation();
	~WeekCotation();
	void Load(string line);
	void setDate(string date);
	string getDate();
	void addCurrency(Currency c);
	void printWeek();
	float getCurrencyValue(string nameCurrency);
private:
	void regex2Date(smatch sm);
	void regex2Currency(smatch sm);
};

#endif