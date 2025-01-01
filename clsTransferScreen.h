#pragma once
#include<iostream>
#include"clsBankClient.h";
#include"clsInputValidate.h";
#include"clsScreen.h";
#include"clsString.h";
#include<limits>
using namespace std;
class clsTransferScreen :protected clsScreen
{
private:
	static void _printclientcard(clsBankClient& client) {
		cout << "===============CLIENT CARD================\n\n";
		cout << "Account Number: " << client.AccountNumber() << endl;
		cout << "Full Name: " << client.FullName << endl;
		cout << "Account Balance: " << client.GetAccountBalance() << endl;
		cout << "==========================================\n\n";
	}
	static void _Transfer(clsBankClient& client1, clsBankClient& client2) {
		int price;
		char answer;
		cout << "how much do you want to transfer?: ";
		cin >> price;
		while (cin.fail() || price < 0) {
			cout << "error please enter a valid price\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> price;
		}

		while (!clsInputValidate::IsNumberBetween<short>(price, 0, client1.AccountBalance)) {
			cout << "the price that is not valid please enter a valid price: ";
			cin >> price;
			while (cin.fail() || price < 0) {
				cout << "error please enter a valid price\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> price;
			}
		}
		cout << "do you really want to transfer " << price << "to " << client2.FullName;
		cin >> answer;
		if (clsString::CheckAnswer(toupper(answer))) {
			if (clsBankClient::Transfer(client1, client2, price)) {
				cout << "transfering proccess went successfuly\n";
			}
		}
	}


	
		static void _ask() {
		string code;
		short a = 2;
			cout << "enter the user code that you want to transfer from\n";
			cin >> code;
			while (!clsBankClient::IsClientExist(code)) {
				cout << "error could'nt find user, please enter a valid code\n";
				cin >> code;
			}
			clsBankClient client1 = clsBankClient::Find(code);
			_printclientcard(client1);

			cout << "enter the user code that you want to transfer to\n";
			cin >> code;
			while (!clsBankClient::IsClientExist(code)) {
				cout << "error could'nt find user, please enter a valid code\n";
				cin >> code;
			}
			clsBankClient client2 = clsBankClient::Find(code);
			_printclientcard(client2);
			_Transfer(client1, client2);
	}
public:
	static void TransferingScreen() {
		system("cls");
		clsScreen::_DrawScreenHeader("\t\tTransfering Screen");
		_ask();
	}

};

