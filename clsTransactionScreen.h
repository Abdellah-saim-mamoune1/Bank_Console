#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
#include"clsBankClient.h";
#include"clsInputValidate.h";
#include"clsScreen.h";
#include"clsTotalBalanceScreen.h";
#include"clsDepositScreen.h";
#include"clsWithDrawScreen.h";
#include"clsTransferScreen.h";

class clsTransactionScreen:protected clsScreen
{
	enum TransactionOptions { totalbalancescreen = 1, deposit = 2, withdraw = 3,transfer=4 , mainmenuescreen = 5 };
	static short _ReadTransactionMenueOption() {
		cout << setw(37) << left<<"" << "chose between [1 to 5] ";
		short _userchoise = clsInputValidate::ReadNumberBetween<short>(1, 5,"enter a number within [1 to 5]?\n");
		return _userchoise;
	}
	static  void _GoBackToTransactionMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Transaction Menue...\n";

		system("pause>0");
		ShowTransactionMenue();
	}

	static void ShowTotalBalanceScreen() {
		clsTotalBalanceScreen::totalbalancescreen();
		
	}

	static void ShowDepositScreen() {
		clsDepositScreen::depositing();
	}
	static void ShowWithdrawScreen() {
		clsWithDrawScreen::withdrawingscreen();
	}
	static void ShowTransferScreen() {
		clsTransferScreen::TransferingScreen();
	}
	static void ShowMainMenueScreen() {

	}

	static void ProcessTansactionOption(TransactionOptions Option) {
		switch (Option) {
		case TransactionOptions::totalbalancescreen:
			ShowTotalBalanceScreen();
			_GoBackToTransactionMenue();
			break;
		case TransactionOptions::deposit:
			ShowDepositScreen();
			_GoBackToTransactionMenue();
			break;
		case TransactionOptions::withdraw:
			ShowWithdrawScreen();
			_GoBackToTransactionMenue();
			break;
		case TransactionOptions::transfer:
			ShowTransferScreen();
			_GoBackToTransactionMenue();
			break;
		case TransactionOptions::mainmenuescreen:
			break;

		}
	}
		
public:
	static void ShowTransactionMenue() {
		system("cls");
		_DrawScreenHeader("\t\tTransaction Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tTransaction Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] TotalBalance.\n";
		cout << setw(37) << left << "" << "\t[2] Deposit.\n";
		cout << setw(37) << left << "" << "\t[3] WithDraw.\n";
		cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue Screen.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		ProcessTansactionOption((TransactionOptions)_ReadTransactionMenueOption());

	}

};

