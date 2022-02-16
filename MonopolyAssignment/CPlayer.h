#pragma once
#include <iostream>

using namespace std;

class CPlayer
{
public:
	string mName;
	int mMoney;
	int mPlayerPosition;


	CPlayer(string name, int startingMoney);
	void buyProperty();
	void payRent();

	friend ostream& operator << (ostream& outputStream, const CPlayer& player);

};


