#pragma once
#include <iostream>
#include "CPlayer.h" // dependecy?
#include"Constants.h"
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

	virtual void OnLanding(shared_ptr<CPlayer> playerWhoLanded) = 0;
	//{
	//	cout << "ERROR BASE CLASS FUNCTION CALLED" << endl;
	//}

	virtual void DisplayName()
	{
		cout << name;
	}

	friend istream& operator >> (istream& inputStream, CSquare& square);
	
	friend ostream& operator << (ostream& outputStream, const CSquare& square);
	virtual void Display(); // yay polymorphism

	
};

