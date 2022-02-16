#pragma once
#include <iostream>
#include "CPlayer.h" // dependecy?
using namespace std;
class CSquare
{
protected:
	string name;

public:
	CSquare(istream& file);
	virtual ~CSquare() // neccessary for deletion of derived class objects.
	{
		
	}

	virtual void OnLanding(CPlayer& playerWhoLanded,CPlayer& propertyOwner) // TODO make this pure after wards.
	{
		cout << "ERROR BASE CLASS FUNCTION CALLED" << endl;
	}

	virtual void OnLanding(CPlayer& playerWhoLanded)
	{

	}
	

	friend istream& operator >> (istream& inputStream, CSquare& square);
	
	friend ostream& operator << (ostream& outputStream, const CSquare& square);
	virtual void Display(); // yay polymorphism

	
};

