#include <string>
#include <iostream>
#include <fstream>
#include "Week.h"
#include "Exchange.h"

using namespace std;
//

Exchange::Exchange(){}

Exchange::~Exchange(){}

/*
*	Função que lê o arquivo de entrada e carrega os dados lidos em um objeto Exchange
*/
void Exchange::Load(string file){

	ifstream file_input;
	string line;
	WeekCotation w;

	file_input.open(file);
	if (file_input.is_open())
	{
		while(getline(file_input,line))	{
			
			w.Load(line);
			exchangeHistory.push_back(w);
			
		}
		file_input.close();
	}else cout << "Open File Error!" << endl;

}

/*
*	Função que calcula o preço do dolar atual e sua tendencia em relação a moeda passada como parametro.
*/
void Exchange::DollarPrice(string nameCurrency){
	
	if (exchangeHistory[1].getCurrencyValue(nameCurrency) > exchangeHistory[2].getCurrencyValue(nameCurrency) > exchangeHistory[3].getCurrencyValue(nameCurrency))
	{
		cout << "\n+$" << exchangeHistory[0].getCurrencyValue(nameCurrency) << endl;
	}else if (exchangeHistory[1].getCurrencyValue(nameCurrency) < exchangeHistory[2].getCurrencyValue(nameCurrency) < exchangeHistory[3].getCurrencyValue(nameCurrency))
		cout << "\n-$" <<  exchangeHistory[0].getCurrencyValue(nameCurrency) << endl;
	else
		cout << "\n=$" <<  exchangeHistory[0].getCurrencyValue(nameCurrency) << endl;
}

/*
*	Função que calcula o preço médio do dolar em relação a moeda passada como parametro.
*/
float Exchange::AveragePrice(string nameCurrency){

	float sum = 0;

	for(unsigned int i=0; i < exchangeHistory.size(); i++)	sum += exchangeHistory[i].getCurrencyValue(nameCurrency);
	return sum/exchangeHistory.size();
}

/*
*	Funçaõ que calcula a taxa de variação do dolar em relação ao valor da moeda passada como parametro no inicio do ano.
*/
float Exchange::ExchangeVariation(string nameCurrency){
	float dc = exchangeHistory.front().getCurrencyValue(nameCurrency);
	float db = exchangeHistory.back().getCurrencyValue(nameCurrency);
	return (dc*100)/db;
}
