#include <string>
#include <iostream>
#include <regex>
#include "Week.h"
#include "Currency.h"

using namespace std;

WeekCotation::WeekCotation() {
	date = "";
}

WeekCotation::~WeekCotation(){}

/*
*	Função que recebe uma linha e carrega valores lidos em objeto WeekCotation
*/
void WeekCotation::Load(string line){

	regex date(".*\"date\":\"(\\d+-\\d+-\\d+).*");
	regex regex_real(".*(BRL)\":(\\d+.\\d+).*");
	regex regex_euro(".*(EUR)\":(\\d+.\\d+).*");
	regex regex_jpy(".*(JPY)\":(\\d+.\\d+).*");
	regex regex_cny(".*(CNY)\":(\\d+.\\d+).*");
	smatch sm;

	//Regex date
	regex_match(line,sm,date);
	regex2Date(sm);
	//Regex Real
	regex_match(line,sm,regex_real);
	regex2Currency(sm);
	//Regex Euro
	regex_match(line,sm,regex_euro);
	regex2Currency(sm);
	//Regex Iene
	regex_match(line,sm,regex_jpy);
	regex2Currency(sm);
	//Regex China
	regex_match(line,sm,regex_cny);
	regex2Currency(sm);

	//WeekCotation::printWeek();
}

/*
*	Função que adiciona uma moeda na lista de moedas de um objeto WeekCotation
*/
void WeekCotation::addCurrency(Currency c){

	if 		(c.getName() == "BRL")		list[BRL] = c;
	else if (c.getName() == "EUR")	 	list[EUR] = c;
	else if (c.getName() == "JPY")	 	list[JPY] = c;
	else if (c.getName() == "CNY")	 	list[CNY] = c;
	
}

/*
*	Função que pega o resultado da Regex e guarda no atributo date de um objeto WeekCotation
*/
void WeekCotation::regex2Date(smatch sm){

	if (sm.empty())
	{
		cout << "File with error!" << endl;
		exit(1);
	}else
		WeekCotation::setDate(sm[1].str());
}

/*
*	Função que pega o resultado da Regex e guarda os resultados em um objeto Currency.
*/
void WeekCotation::regex2Currency(smatch sm){

	Currency c;

	if (sm.empty())
	{
		cout << "File with error!" << endl;
		exit(1);
	}else{
		c.setName(sm[1].str());
		c.setValue(stof(sm[2]));
		if(c.verifyCurrency() == -1){
			cout << "Currency " << sm[1].str() << " not avaible." << endl;
			exit(1);
		}
		WeekCotation::addCurrency(c);		
		//cout << "\t" << list[BRL].getName() << " "<< list[BRL].getValue() << endl;
	}	

}
/*
*	Função que retorna o valor númerico de uma moeda presente em algum índice de WeekCotation::list[]
*/
float WeekCotation::getCurrencyValue(string nameCurrency){
	if 		(nameCurrency == "BRL")	return	list[BRL].getValue();
	else if (nameCurrency == "EUR")	return 	list[EUR].getValue();
	else if (nameCurrency == "JPY")	return 	list[JPY].getValue();
	else if (nameCurrency == "CNY")	return 	list[CNY].getValue();
	else	return 0;
}

/*
*	Função que imprime todos os atributos de um objeto WeekCotation
*/
void WeekCotation::printWeek(){
		cout << WeekCotation::getDate() 
		<< "\t" << list[BRL].getName() << " "<< list[BRL].getValue() 
		<< "\t" << list[EUR].getName() << " "<< list[EUR].getValue()
		<< "\t" << list[JPY].getName() << " "<< list[JPY].getValue()
		<< "\t" << list[CNY].getName() << " "<< list[CNY].getValue() << endl;
}

string WeekCotation::getDate(){
	return date;
}
void WeekCotation::setDate(string date){
	this->date = date;
}