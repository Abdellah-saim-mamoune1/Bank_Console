#pragma once
#include<vector>
#include<iomanip>
#include"clsBankUser.h";
#include"clsScreen.h";

class clsShowUsersInfoScreen:protected clsScreen
{

    static void PrintClientRecordLine(clsBankUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(15) << left << User.code;
        cout << "| " << setw(20) << left << User.FullName;
        cout << "| " << setw(12) << left << User.Phone;
        cout << "| " << setw(20) << left << User.Email;
        cout << "| " << setw(10) << left << User.Permissions;


    }


public:
    static void ShowUsersList()
    {
        system("cls");
        vector <clsBankUser> vUsers = clsBankUser::GetUsersList();
        string Title = "\t\t Users List Screen";
        string SubTitle = "\t\t    (" + to_string(vUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);


        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(15) << "Code";
        cout << "| " << left << setw(20) << "User Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(12) << "Access";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vUsers.size() == 0) {
            cout << "\t\t\t\tNo Users Available In the System!";
        }
        else {

            for (clsBankUser User : vUsers)
            {

                PrintClientRecordLine(User);
                cout << endl;
            }
        }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }

};

