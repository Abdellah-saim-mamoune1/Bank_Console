#pragma once
#include<iostream>
#include<vector>
#include"clsCurrency.h";
#include<iomanip>
#include"clsScreen.h";
class clsListCurrencyScreen:protected clsScreen
{

    static void Show(clsCurrency Currency) {
        cout << setw(10) << left << "" << "| " << setw(25) << left << Currency.Country();
        cout << "| " << setw(6) << left << Currency.CurrencyCode();
        cout << "| " << setw(41) << left << Currency.CurrencyName();
        cout << "| " << setw(10) << left << Currency.Rate;
    }

public:
	static void ShowListCurrencyScreen() {
        system("cls");
        vector<clsCurrency>vCurrencyes = clsCurrency::GetAllUSDRates();
		clsScreen::_DrawScreenHeader("\t\tList Currency Screen","\t\t("+to_string(vCurrencyes.size())+")"+"Country(S).");
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        cout << setw(10) << left << "" << "| " << left << setw(25) << "Country";
        cout << "| " << left << setw(6) << "Code";
        cout << "| " << left << setw(41) << "Name";
        cout << "| " << left << setw(10) << "Rate";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrencyes.size() == 0)
            cout << "\t\t\t\tNo Currency Available In the System!";
        else

            for (clsCurrency &Country : vCurrencyes)
            {

               Show(Country);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

	
};

