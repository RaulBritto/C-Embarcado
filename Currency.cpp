#include <string>
#include <iostream>
#include "Currency.h"

/*
*	Construtor padrao
*/
Currency::Currency(){
	name = "";
	value = 0;
}

Currency::~Currency(){

}

/*
*	Função que verifica se uma moeda é valida
*/
int Currency::verifyCurrency(){

	if (value < 0)
	{
		std::cout << "Currency with negative value" << endl;
		return -1;
	}
	else if (name.size() == 0)
	{
		std::cout << "Currency with empty description" << endl;
		return -1;	
	}
	return 0;
}

string Currency::getName()
{
	return name;
}

float Currency::getValue()
{
	return value;
}

void Currency::setName(string n)
{
	this->name = n;
}

void Currency::setValue(float v){
	this->value = v;
}
