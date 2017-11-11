#include <string>
#include <iostream>
#include "Exchange.h"
#include "View.h"

using namespace std;


View::View(){}
View::~View(){}

/*
*	Função que exibe o menu inicial da aplicação. É definido como moeda padrão o Real.
*/
void View::showMenu(Exchange history){

	int option = 0;
	string current_coin = "BRL";

		while(true){

			cout << "\nDigite a opção desejada:\n 1-Preço do Dolár \n 2-Media Anual \n 3-Variacao Cambial \n 4-Mudar moeda\n" << endl;
			cin >> option;

			try{
				switch(option)
				{
					case 1:
							system("clear");
							history.DollarPrice(current_coin);
							break;
					case 2:
							system("clear");
							cout << "\nPreco medio: $" << history.AveragePrice(current_coin) << endl;
							break;
					case 3:
							system("clear");
							cout << "\nVariacao: " << history.ExchangeVariation(current_coin) << "%"<< endl;
							break;
					case 4:
							current_coin = changeCurrency();
							break;
	 
					default:
							throw(exception());
				}
			}catch(exception e){
				system("clear");
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout << "Unavailable Option!\n";
			}
			
		}
}

/*
*	Função que realiza a seleção de moedas pelo usuario.
*/
string View::changeCurrency(){

	int option = 0;

	while(true){

		cout << "\nDigite a moeda :\n 1-Real \n 2-Euro \n 3-Iene \n 4-Yuan\n" << endl;
		cin >> option;
		try{

			system("clear");
			switch(option){
				case 1:	return "BRL";
				case 2:	return "EUR";
				case 3:	return "JPY";
				case 4:	return "CNY";
				default:
						throw(exception());
			}
		}catch(exception e){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				cout << "Unavailable Currency!\n";
		}
	}
}