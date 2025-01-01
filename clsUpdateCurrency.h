#pragma once
#include<vector>
#include"clsCurrency.h";
#include<iomanip>
#include"clsScreen.h";
class clsUpdateCurrency :clsScreen
{

	static void Currency_Card(clsCurrency& c) {
		cout << "\nCurrency Card:";
		cout << "\n_________________________________________________________";
		cout << "\nCountry Name   : " << c.Country();
		cout << "\nCode    : " << c.CurrencyCode();
		cout << "\nCurrency Name  : " << c.CurrencyName();
		cout << "\nRate      : " << c.Rate;
		cout << "\n_________________________________________________________";
	}

	static void setout() {
		string currency;
		char option;
		float rate;
		cout << "enter the Currency code ";
		cin >> currency;
		while (!clsCurrency::Is_Country_ExistBy_C(currency)) {
			cout << "Currency was not found please enter another code: ";
			cin >> currency;
		}
		cout << "\nCurrency was found :)\n\n";
		clsCurrency Currency = clsCurrency::FindByCode(currency);
		Currency_Card(Currency);
		cout << "\n\ndo you really want to Update this Currency Rate?: ";
		cin >> option;
		if (toupper(option) == 'Y') {
			cout << "Enter The New Rate: ";
			cin >> rate;
			while (rate <= 0) {
				cout << "Error please Enter A Valid Rate: ";
				cin >> rate;
			}
			Currency.Rate = rate;
			Currency._Update();
			cout << "Rate was updated Successfuly :)\n";
			Currency_Card(Currency);
		}
	}

		

public:
	static void ShowUpdateCurrencyScreen() {
		system("cls");
		clsScreen::_DrawScreenHeader("\t\tUpdate Currency Screen");
		setout();
	}
};
