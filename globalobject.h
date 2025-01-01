#pragma once
#include<iostream>
#include"clsBankUser.h";
using namespace std;
clsBankUser User;
bool checkpermission1(short num) {
	return (User.Permissions & num) == num;
}