#pragma once
#include<vector>
#include"clsCurrency.h";
#include<iomanip>
#include"clsScreen.h";
class clsCurrencyCalculator:protected clsScreen
{
	static void Currency_Card(clsCurrency& c,string title) {
		cout << title;
		cout << "\n_________________________________________________________";
		cout << "\nCountry Name : " << c.Country();
		cout << "\nCode         : " << c.CurrencyCode();
		cout << "\nCurrency Name: " << c.CurrencyName();
		cout << "\nRate         : " << c.Rate<<"$";
		cout << "\n_________________________________________________________\n";
	}


	static void ask() {
		string Code1, Code2;
		float Amount;
		cout << "Enter Currency1 Code: ";
		cin >> Code1;
		while (!clsCurrency::Is_Country_ExistBy_C(Code1)) {
			cout << "Currency was not found please enter another code: ";
			cin >> Code1;
		}
		clsCurrency Currency1 = clsCurrency::FindByCode(Code1);

		cout << "\nEnter Currency2 Code: ";
		cin >> Code2;
		while (!clsCurrency::Is_Country_ExistBy_C(Code2)) {
			cout << "Currency was not found please enter another code: ";
			cin >> Code2;
		}
		while (clsString::UpperAllString(Code1) == clsString::UpperAllString(Code2)) {
			cout << "Code2 Matches Code1 Please Enter Another Code: ";
			cin >> Code2;
		}
		clsCurrency Currency2 = clsCurrency::FindByCode(Code2);
		cout << "Enter Amount To Exchange: ";
		cin >> Amount;
		while (cin.fail() || Amount <= 0) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error please Enter A Valid Amount ? ";
			cin >> Amount;
		}
		Currency_Card(Currency1,"\nConvert From");
		Perform(Currency1, Currency2, Amount);
	}
	


	static void Perform(clsCurrency& C1, clsCurrency& C2,float Amount) {
		float Trans;
		if (C1.CurrencyCode() == "USD") {
			Trans = C2.CurrencyCalculator_FromUSDto(Amount);
			cout <<endl<< Amount<<" USD Is " << Trans<<" "<<C2.CurrencyCode();
			return;
		}
		else if (C2.CurrencyCode() == "USD") {
			Trans = C1.CurrencyCalculator_ToUSD(Amount);
			cout << endl<<Amount <<" "<< C1.CurrencyCode() << " Is " << Trans << " USD";
			return;
		}
		else {
			Trans = C1.CurrencyCalculator_ToUSD(Amount);
			cout << endl<<Amount <<" "<< C1.CurrencyCode() << " Is " << Trans << " USD\n";
			Currency_Card(C2, "\nConvert To");
			Trans = C2.CurrencyCalculator_FromUSDto(Trans);
			cout << endl<<Amount <<" "<< C1.CurrencyCode() << " Is " << Trans <<" " << C2.CurrencyCode();
		}
	}

public:
	static void ShowCalculatorCurrency() {
		char Answer;
		do {
			system("cls");
			_DrawScreenHeader("\t\tCurrency Calculator Screen");
			ask();
			cout << "\nDo you want To Calculate Again Y/N ?";
			cin >> Answer;
		} while (toupper(Answer) == 'Y');
	}


};

