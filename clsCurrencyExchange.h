#pragma once
#include<iostream>
#include<iomanip>
#include"clsListCurrencyScreen.h";
#include"clsInputValidate.h";
#include<limits>
#include"clsScreen.h";
#include"clsFindCurrency.h";
#include"clsUpdateCurrency.h";
#include"clsCurrencyCalculator.h";
using namespace std;
class clsCurrencyExchange:protected clsScreen
{
	enum options{ ListCurrencies =1, FindCurrency=2, UpdateRate=3, CurrencyCalculator=4, MainMenue=5};
	static short _ask() {
		short choise;
		printf("please chose between [1 to 5] ?: ");
		cin >> choise;
		while (cin.fail() || (!clsInputValidate::IsNumberBetween<short>(choise, 1, 5))) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			printf("not a valid choise please chose between [1 to 5]?: ");
			cin >> choise;
		}
		return choise;
	}

	static  void _GoBackToCurrencyMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Currency Exchange Menue...\n";
		system("pause>0");
		ShowCurrencyExchangeScreen();
		
	}

	static void _showListCurrenciesScreen() {
		clsListCurrencyScreen::ShowListCurrencyScreen();
		
	}

	static void _FindCurrencyscreen() {
		clsFindCurrency::ShoeFindCurrencyScreen();

	}

	static void _CurrencyCalculatorscreen() {
		clsCurrencyCalculator::ShowCalculatorCurrency();
	}


	static void _UpdateRatescreen() {
		clsUpdateCurrency::ShowUpdateCurrencyScreen();
	}

	static void ProcessCurrenciesOption(options useroption) {
		switch (useroption) {
		case options::ListCurrencies:
			_showListCurrenciesScreen();
			_GoBackToCurrencyMenue();
			break;
		case options::FindCurrency:
			_FindCurrencyscreen();
			_GoBackToCurrencyMenue();
			break;
		case options::UpdateRate:
			_UpdateRatescreen();
			_GoBackToCurrencyMenue();
			break;
		case options::CurrencyCalculator:
			_CurrencyCalculatorscreen();
			_GoBackToCurrencyMenue();
			break;
		case options::MainMenue:
		
			break;
	
		}

	}

public:
	static void ShowCurrencyExchangeScreen() {
		system("cls");
		_DrawScreenHeader("\t\tCurrency Exchange Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		ProcessCurrenciesOption((options)_ask());
	}


};

