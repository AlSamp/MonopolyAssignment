// Alix Sampford G20790929
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
	friend ostream& operator << (ostream& outputStream, const CPlayer& player); // override output operator so that every time this object is called with << it will output its name.

};


