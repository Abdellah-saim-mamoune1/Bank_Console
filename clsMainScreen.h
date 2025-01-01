#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include"clsTransactionScreen.h";
#include"clsLogOutScreen.h";
#include"clsManagUsersScreen.h";
#include"clsLoginRegister.h";
#include"clsCurrencyExchange.h";
#include"clsCurrency.h";
#include<vector>

using namespace std;

class clsMainScreen :protected clsScreen
{

     
private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, enLogOut = 8, LoginRegister=9, CurrencyExchange=10, eExit = 11
    };


    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

    static short _ReadMainMenueOption()
    {
        short Choice;
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 11]? ";
        cin >> Choice;
        while (cin.fail() ||
            !clsInputValidate::IsNumberBetween<short>(Choice,1, 11)) {
           printf("Error Please Enter a Number between [1 to 11]? ");
           cin >> Choice;
        }
        return Choice;
    }
    static void declainedmessage() {
        cout << "________________________________________________________\n\n";
        cout << "you don't have access to this screen, talk to your admin\n";
        cout << "________________________________________________________\n\n";
    }
    

    static void _ShowAllClientsScreen()
    {
        //  cout << "\nClient List Screen Will be here...\n";
        if (!checkpermission1(clsBankUser::enPermissions::enshowclientlist)) {
            declainedmessage();
            return;
        }
        else {
            clsClientListScreen::ShowClientsList();
        }

    }

    static void _ShowAddNewClientsScreen()
    {
        // cout << "\nAdd New Client Screen Will be here...\n";
        if (!checkpermission1(clsBankUser::enPermissions::enAddnewclient)) {
            declainedmessage();
            return;
        }
        else { clsAddNewClientScreen::ShowAddNewClientScreen();}

    }

    static void _ShowDeleteClientScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
        if (!checkpermission1(clsBankUser::enPermissions::enDeleteClient)) {
            declainedmessage();
            return;
        }
        else { clsDeleteClientScreen::ShowDeleteClientScreen(); }

    }

    static void _ShowUpdateClientScreen()
    {
        //cout << "\nUpdate Client Screen Will be here...\n";
        if (!checkpermission1(clsBankUser::enPermissions::enUpdateClient)) {
            declainedmessage();
            return;
        }
        else { clsUpdateClientScreen::ShowUpdateClientScreen(); }


    }

    static void _ShowFindClientScreen()
    {
        // cout << "\nFind Client Screen Will be here...\n";
        if (!checkpermission1(clsBankUser::enPermissions::enFindClient)) {
            declainedmessage();
            return;
        }

        else { clsFindClientScreen::ShowFindClientScreen(); }


    }

    static void _ShowTransactionsMenue()
    {
        if (!checkpermission1(clsBankUser::enPermissions::enTransactions)) {
            declainedmessage();
            return;
        }
        else { clsTransactionScreen::ShowTransactionMenue();}

    }

    static void _ShowManageUsersMenue()
    {
        if (!checkpermission1(clsBankUser::enPermissions::enManageUsers)) {
            declainedmessage();
            return;
        }
        else { clsManagUsersScreen::ShowManageUsersScreen(); }
    }

    static void _ShowLoginRegisterScreen() {
        if (!checkpermission1(clsBankUser::enPermissions::enLoninRegister)) {
            declainedmessage();
            return;
        }
        else {
            clsLoginRegister::showloginregisterscreen();
        }
    }
    static void _ShowCurrencyExchangeScreen() {
        if (!checkpermission1(clsBankUser::enPermissions::enCurrencyExchange)) {
            declainedmessage();
            return;
        }
        else {
            clsCurrencyExchange::ShowCurrencyExchangeScreen();
        }
    }

    static void _ShowLogOutScreen()
    {
        Start();
       

    }


    static void Message() {
        cout << "\nyou don't have access to Show Clients Screen\n";
        system("pause");
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        
       
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eDeleteClient:
            system("cls");
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eUpdateClient:
            system("cls");
            _ShowUpdateClientScreen() ;
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eFindClient:
            system("cls");
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
           _ShowTransactionsMenue() ;
           _GoBackToMainMenue();//to avoid press any key to continue
            break;

        case enMainMenueOptions::eManageUsers:
            system("cls");
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;

        case enMainMenueOptions::enLogOut:
            system("cls");
            _ShowLogOutScreen();
            break;
        case enMainMenueOptions::LoginRegister:
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::CurrencyExchange:
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eExit:
           system("cls"); 
           system("exit");
            break;
        }
    }

public:

    static void Start() {
        if (clsLogOutScreen::ManageUsersScreen()) {
            ShowMainMenue();
        }
    }
    static void ShowMainMenue()
    {
        system("cls");
      
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Logout.\n";
        cout << setw(37) << left << "" << "\t[9] Login Register.\n";
        cout << setw(37) << left << "" << "\t[10] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[11] Exit.\n";
        cout << setw(37) << left << "" << "===========================================\n";
       
        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption());
    }
  
};



    


