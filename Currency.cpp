#include <string>
#include <iostream>
#include "Currency.h"

Currency::Currency(string n, float v): name(n), value(v) {

	if (value < 0)
	{
		std::cout << "Currency with negative value" << endl;
		return;
	}
	else if (name.size() == 0)
	{
		std::cout << "Currency with empty description" << endl;
		return;	
	}
}


string Currency::getName()
{
	return name;
}

float Currency::getValue()
{
	return value;
}
