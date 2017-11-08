#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

struct Cotation
{
	string date;
	float euro;
	float real;
	float iene;
	float yuan;
};

float getCoinValue(string s, string demiliter)
{

	int index = s.find(demiliter)+ demiliter.size();
	
	string value = s.substr(index, 6);
	if (value[5] == ',')
	{
		value[5] = 0;
	}
			
	return stof(value);
}

string getDate(string s, int size)
{

	int index = s.find("date\":")+7;
	return s.substr(index,size);

}

void readValuesFile(string file, Cotation c[], int size)
{

	ifstream file_input;
	int i = 0;
	string line;
	string demiliter[4] = {"\"BRL\":","\"EUR\":","\"JPY\":","\"CNY\":"};

	file_input.open(file);
	if (file_input.is_open())
	{
		while(getline(file_input,line))	{

			c[i].date = getDate(line,10);
			c[i].real = getCoinValue(line,demiliter[0]);
			c[i].euro = getCoinValue(line,demiliter[1]);
			c[i].iene = getCoinValue(line,demiliter[2]);
			c[i].yuan = getCoinValue(line,demiliter[3]);
		
			//cout << c[i].date <<"\tReal: " << c[i].real << "\tEuro: " << c[i].euro << "\tIene: " << c[i].iene << "\tYuan: "<< c[i].yuan << endl;	
			i++;
		}
		file_input.close();
	}
}

void dollarPrice(Cotation c[], int size,int coin)
{
	switch(coin){
		case 1:

			if (c[1].real > c[2].real > c[3].real)
				cout << "\nReal: +$" << c[0].real << endl;
			else if (c[1].real < c[2].real < c[3].real)
				cout << "\nReal: -$" << c[0].real << endl;
			else
				cout << "\nReal: =$" << c[0].real << endl;
			break;

		case 2:

			if (c[1].euro > c[2].euro > c[3].euro)
				cout << "\nEuro: +$" << c[0].euro << endl;
			else if (c[1].euro < c[2].euro < c[3].euro)
				cout << "\nEuro: -$" << c[0].euro << endl;
			else
				cout << "\nEuro: =$" << c[0].euro << endl;
			break;

		case 3:

			if (c[1].iene > c[2].iene > c[3].iene)
				cout << "\nIene: +$" << c[0].iene << endl;
			else if (c[1].iene < c[2].iene < c[3].iene)
				cout << "\nIene: -$" << c[0].iene << endl;
			else
				cout << "\nIene: =$" << c[0].iene << endl;
			break;

		case 4:

			if (c[1].yuan > c[2].yuan > c[3].yuan)
				cout << "\nYuan: +$" << c[0].yuan << endl;
			else if (c[1].yuan < c[2].yuan < c[3].yuan)
				cout << "\nYuan: -$" << c[0].yuan << endl;
			else
				cout << "\nYuan: =$" << c[0].yuan << endl;
			break;

	}

}

void averageValue(Cotation c[], int size,int coin){

	float averageValue = 0;

	switch (coin)
	{
		case 1:
			for (int i = 0; i < 44; ++i)
				averageValue += c[i].real;
			averageValue = averageValue/44;
			break;
		case 2:
			for (int i = 0; i < 44; ++i)
				averageValue += c[i].euro;
			averageValue = averageValue/44;
			break;
		case 3:
			for (int i = 0; i < 44; ++i)
				averageValue += c[i].iene;
			averageValue = averageValue/44;
			break;
		case 4:
			for (int i = 0; i < 44; ++i)
				averageValue += c[i].yuan;
			averageValue = averageValue/44;
			break;
	}

	cout << "\nValor medio: $" << averageValue << endl;
}

void exchangeVariation(Cotation c[], int size, int coin)
{
	
	float varation = 0;

	switch (coin)
	{
		case 1:
			varation = (c[0].real-c[43].real)/c[43].real * 100;
			break;
		case 2:
			varation = (c[0].euro-c[43].euro)/c[43].euro * 100;;
			break;
		case 3:
			varation = (c[0].iene-c[43].iene)/c[43].iene * 100;
			break;
		case 4:
			varation = (c[0].yuan-c[43].yuan)/c[43].yuan * 100;
			break;
	}

	cout << "\nVariacao: " << varation << "%"<< endl;	
}


int main(int argc, char const *argv[])
{
	
	Cotation weeksCotation[44];
	int option = 0;
	int current_coin = 1;
	
	readValuesFile("data.json",weeksCotation,44);

	while(true){

		cout << "\nDigite a opção desejada:\n 1-Preço do Dolár \n 2-Media Anual \n 3-Variacao Cambial \n 4-Mudar moeda\n" << endl;
		cin >> option;
		
		switch(option){
			case 1:
					dollarPrice(weeksCotation,44,current_coin);
					break;
			case 2:
					averageValue(weeksCotation,44,current_coin);
					break;
			case 3:
					exchangeVariation(weeksCotation,44,current_coin);
					break;
			case 4:
					cout << "Digite a moeda :\n 1-Real \n 2-Euro \n 3-Iene \n 4-Yuan\n" << endl;
					cin >> current_coin;
					break;
			case 0:
					return 0;
			default:
					cout << "Opcao invalida!\n";
		}
	}
}