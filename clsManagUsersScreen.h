#pragma once
#include<iostream>
#include<iomanip>
using namespace std;
#include"clsBankUser.h";
#include"clsInputValidate.h";
#include"clsScreen.h";
#include"clsShowUsersInfoScreen.h";
#include"clsAddNewUserScreen.h";
#include"clsDeletUserScreen.h";
#include"clsFindUserScreen.h";
#include"clsUpdateUserScreen.h";
class clsManagUsersScreen:protected clsScreen
{
	enum options{usersinfoscreen=1,FindUser=2,addnewuser=3,deletuser=4,updateuserinfo=5,mainscreen=6};
	static short _readmnageusersoption() {
		cout << setw(37) << left << ""<< "chose between [1 to 6]\n";
		short userchoise = clsInputValidate::ReadNumberBetween<short>(1, 6, "please chose between[1 to 6]") ;
		return userchoise;
	}

	static  void _GoBackToManageUsersMenue()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Manage Users Menue...\n";

		system("pause>0");
		ShowManageUsersScreen();
	}

	static void showusersinfoscreen() {
		clsShowUsersInfoScreen::ShowUsersList();
	}

	static void Finduserscreen() {
		clsFindUserScreen::ShowFindUserScreen();

	}

	static void addnewuserscreen() {
		clsAddNewUserScreen::ShowAddNewUserScreen();

	}

	static void deletuserscreen() {
		clsDeletUserScreen::ShowDeleteClientScreen();
	}


	static void Updateuserscreen() {
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}

	static void ProcessTansactionOption(options useroption) {
		switch (useroption) {
		case options::usersinfoscreen:
			showusersinfoscreen();
			_GoBackToManageUsersMenue();
			break;
		case options::FindUser:
			Finduserscreen();
			_GoBackToManageUsersMenue();
			break;
		case options::addnewuser:
			addnewuserscreen();
			_GoBackToManageUsersMenue();
			break;
		case options::deletuser:
			deletuserscreen();
			_GoBackToManageUsersMenue();
			break;
		case options::updateuserinfo:
			Updateuserscreen();
			_GoBackToManageUsersMenue();
			break;
		case options::mainscreen:
			break;
			
		}

	}




public:
	
	static void ShowManageUsersScreen() {
		system("cls");
		_DrawScreenHeader("\t\tManage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tManage Users Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Users Info.\n";
		cout << setw(37) << left << "" << "\t[2] Find User.\n";
		cout << setw(37) << left << "" << "\t[3] Add New User.\n";
		cout << setw(37) << left << "" << "\t[4] Delete User.\n";
		cout << setw(37) << left << "" << "\t[5] Update User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menue Screen.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		ProcessTansactionOption((options)_readmnageusersoption());
	}



};

