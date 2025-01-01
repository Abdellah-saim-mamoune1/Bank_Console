#pragma once
#include<vector>
#include<iomanip>
#include"clsBankUser.h";
#include"clsScreen.h";
#include"clsInputValidate.h";
#include<string>
class clsDeletUserScreen:clsScreen
{
    static void _PrintUserInfo(clsBankUser User) {
        cout << "\nUser Card:";
        cout << "\n___________________________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName;
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.GetPhone();
        cout << "\nAccess      : " << User.Permissions;
        cout << "\n___________________________________\n";
    }


public:
    static void ShowDeleteClientScreen()
    {
        system("cls");
        _DrawScreenHeader("\t\tDelete User Screen");

        string AccountNumber = "";

        cout << "\nPlease Enter Account Code: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankUser::IsUsertExist(AccountNumber))
        {
            cout << "\nAccount Code is not found, choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }

        clsBankUser User1 = clsBankUser::Find(AccountNumber);
        _PrintUserInfo(User1);

        cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {
            if (User1.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUserInfo(User1);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }



};

