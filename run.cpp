#include <iostream>
#include <string>
#include "Exchange.h"
#include "View.h"

using namespace std;

int main(int argc, char const *argv[])
{

	/*
	*	Função main
	*/
	string inputFile = "data.json";
	View view;
	Exchange year;

	year.Load(inputFile);
	view.showMenu(year);

	return 0;
}