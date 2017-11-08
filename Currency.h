#include <string>
#include <iostream>

using namespace std;

class Currency
{
private:
	string name;
	float value;

public:
	Currency(string n, float v);
	~Currency();
	string getName();
	float getValue();
	
};