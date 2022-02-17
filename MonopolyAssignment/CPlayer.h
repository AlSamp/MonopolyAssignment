#pragma once
#include <iostream>

using namespace std;

class CPlayer
{
public:
	string mName; //TODO makes this private and make/use the appropriate getters and setters
	int mMoney;
	int mPlayerPosition;
	const int NUM_COLOUR_GROUPS = 8;
	//int propertyColours = make_unique<int[]>(8);

	CPlayer(string name, int startingMoney);
	void buyProperty();
	void payRent();

	friend ostream& operator << (ostream& outputStream, const CPlayer& player);

};


