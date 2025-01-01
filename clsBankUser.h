#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h";
#include "String.h";
#include <vector>
#include <fstream>
#include"clsString.h";
using namespace std;
class clsBankUser :public clsPerson
{
    protected:
    enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DeleteMode = 3 };
   
    enMode _Mode;

    string _code;
    bool _MarkedForDelete = false;
    short _Permissions=0;
   

    static clsBankUser _ConvertLinetoUserObject(string Line, string Seperator = "/#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsBankUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], stod(vUserData[5]));
    }
    static clsBankUser _ConvertLinetoUserObject2(string Line, string Seperator = "/#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsBankUser(vUserData[0], vUserData[1], stod(vUserData[2])
        );
    }

    static  vector <clsBankUser> _LoadUsersDataFromFile()
    {

        vector <clsBankUser> vUsers;

        fstream MyFile;
        MyFile.open("Users1.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsBankUser Client = _ConvertLinetoUserObject(Line);

                vUsers.push_back(Client);
            }

            MyFile.close();

        }

        return vUsers;

    }

    string login_register() {
        return _code + "/#" + FullName + "/#" + to_string(Permissions);
    }
    static clsBankUser _GetEmptyUserObject()
    {
        return clsBankUser(enMode::EmptyMode, "", "", "", "", "", 0);
    }


    static string _ConvertUserObjectToLine(clsBankUser Users, string Seperator = "/#")
    {

        string stUsertRecord = "";
        stUsertRecord += Users._code + Seperator;
        stUsertRecord += Users.FirstName + Seperator;
        stUsertRecord += Users.LastName + Seperator;
        stUsertRecord += Users.Email + Seperator;
        stUsertRecord += Users.Phone + Seperator;
        stUsertRecord += to_string(Users.Permissions) + Seperator;
       
        return stUsertRecord;

    }

    static void _SaveUsersDataToFile(vector <clsBankUser> vClients)
    {

        fstream MyFile;
        MyFile.open("Users1.txt", ios::out);//overwrite

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsBankUser& C : vClients)
            {
                if (C.MarkedForDeleted() == false)
                {
                    //we only write records that are not marked for delete.  
                    DataLine = _ConvertUserObjectToLine(C);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users1.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    void _Update()
    {
        vector <clsBankUser> _vClients;
        _vClients = _LoadUsersDataFromFile();

        for (clsBankUser& C : _vClients)
        {
            if (C._code == code)
            {
                C = *this;
                break;
            }
        }

        _SaveUsersDataToFile(_vClients);

    }


    void _AddNew()
    {

        _AddDataLineToFile(_ConvertUserObjectToLine(*this));
    }

public:
    bool Delete()
    {
        vector <clsBankUser> _vClients;
        _vClients = _LoadUsersDataFromFile();

        for (clsBankUser& C : _vClients)
        {
            if (C.code == _code)
            {
                C._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vClients);

        *this = _GetEmptyUserObject();

        return true;

    }

    void save_login() {
        string info = login_register();
        fstream MYFILE;
        MYFILE.open("login register.txt", ios::out|ios::app);
            if (MYFILE.is_open()) {
                MYFILE << info<<endl;
            }
            MYFILE.close();
    }

   

   static vector<clsBankUser>load_login_register() {
        fstream MYFILE;
        vector<clsBankUser>vusers;
        string line;
        MYFILE.open("login register.txt", ios::in);
        if (MYFILE.is_open()) {
            while (getline(MYFILE, line)) {
                clsBankUser user = _ConvertLinetoUserObject2(line);
                vusers.push_back(user);
            }
        }
        MYFILE.close();
        return vusers;
    }
   

    void SetPermissions(short Permissions) {
        _Permissions = Permissions;
    }
    short GetPermissions() {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) short Permissions;

    


    string GetCode() {
        return _code;
    }

    void SetCode(string code) {
        _code = code;
    }
    __declspec(property(get = GetCode, put = SetCode)) string code;
    clsBankUser(){
       
    }

    clsBankUser(enMode UpdateMode,string code, string firstn, string lastn,
        string email, string number,short access) :clsPerson(firstn, lastn, email, number) {
        _Mode = UpdateMode;
        _code = code;
        _Permissions = access;
        
    }
    clsBankUser(string code, string fullname, short permission) {
        _code = code;
        FullName = fullname;
        Permissions = permission;
    }

   
    static vector <clsBankUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }


    static clsBankUser Find(string code)
    {


        fstream MyFile;
        MyFile.open("Users1.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankUser User = _ConvertLinetoUserObject(Line);
                if (User._code == code)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }


    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    static bool IsUsertExist(string AccountNumber)
    {

        clsBankUser User1 = clsBankUser::Find(AccountNumber);
        return (!User1.IsEmpty());
    }


    static clsBankUser GetAddNewClientObject(string Code)
    {
        return clsBankUser(enMode::AddNewMode,Code, "", "", "", "",0);
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };
    enum enPermissions {
        enAll = -1, enshowclientlist = 1, enAddnewclient = 2, enDeleteClient = 4,
        enFindClient = 8, enUpdateClient = 16, enTransactions = 32, enManageUsers = 64,
        enLoninRegister = 128,enCurrencyExchange=256
    };


    enSaveResults Save()
    {

        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            if (IsEmpty())
            {

                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::UpdateMode:
        {
            _Update();

            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsBankUser::IsUsertExist(_code))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
       
        }
    }

   


    bool MarkedForDeleted()
    {
        return _MarkedForDelete;
    }
   


};
