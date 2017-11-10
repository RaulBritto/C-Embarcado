#include <string>
#include <iostream>

using namespace std;

#ifndef _VIEW_H_
#define _VIEW_H_ 


class View
{
public:
	View();
	~View();
	void showMenu(Exchange history);
	string changeCurrency();
};

#endif