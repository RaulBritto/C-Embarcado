#include <string>
#include <iostream>

using namespace std;

#ifndef _CURRENCY_H_
#define _CURRENCY_H_

class Currency
{
private:
	string name;
	float value;

public:
	Currency();
	//Currency(string n, float v);
	~Currency();
	string getName();
	float getValue();
	void setName(string n);
	void setValue(float v);
	int verifyCurrency();
};

#endif