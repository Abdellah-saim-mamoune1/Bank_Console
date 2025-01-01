#pragma once
#include<vector>
#include"clsCurrency.h";
#include<iomanip>
#include"clsScreen.h";
class clsFindCurrency:protected clsScreen
{

	static void Currency_Card(clsCurrency &c) {
		cout << "\nCurrency Card:";
		cout << "\n_________________________________________________________";
		cout << "\nCountry Name   : " << c.Country();
		cout << "\nCode    : " << c.CurrencyCode();
		cout << "\nCurrency Name  : " << c.CurrencyName();
		cout << "\nRate      : " << c.Rate;
		cout << "\n_________________________________________________________";
	}

	static short ask() {
		short option;
		cout << "\nFind by [1] Code, [2] Country ? ";
		cin >> option;
		while (cin.fail() || option > 2 || option < 1) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error please choise Find by [1] Code, [2] Country ? ";
			cin >> option;
		}
		return option;
		
	}
	static void setout() {
		short option = ask();
		string currency;
		if (option == 1) {
			cout << "enter the Currency code ";
			cin >> currency;
			while (!clsCurrency::Is_Country_ExistBy_C(currency)) {
				cout << "Currency was not found please enter another code: ";
				cin >> currency;
			}
			cout << "\nCurrency was found :)\n\n";
			clsCurrency Currency = clsCurrency::FindByCode(currency);
			Currency_Card(Currency);

		}
		else {
			cout << "enter the Country Name: ";
			cin >> currency;
			while (!clsCurrency::Is_Country_ExistBy_N(currency)) {
				cout << "country was not found please enter another Country Name: ";
				cin >> currency;
			}
			cout << "\nCurrency was found :)\n\n";
			clsCurrency Currency = clsCurrency::FindByName(currency);
			Currency_Card(Currency);

		}
	}
public:
	static void ShoeFindCurrencyScreen() {
		system("cls");
		clsScreen::_DrawScreenHeader("\t\tFind Currency Screen");
		setout();
	}

};

