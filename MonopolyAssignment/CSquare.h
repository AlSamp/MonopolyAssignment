// Alix Sampford G20790929
#pragma once
#include <iostream>
#include "CPlayer.h" // dependecy?
#include"Constants.h"
using namespace std;
class CSquare
{
protected:
	string mName;

public:
	CSquare(istream& file); // Factory will read the in the information from file and place into this object accordingly.

	virtual ~CSquare() {}// neccessary for deletion of derived class objects.
	virtual void OnLanding(shared_ptr<CPlayer> playerWhoLanded) = 0; // All derived objects must specify what they do OnLanding even if its nothing.
	virtual void DisplayName(); // This is used by go and jail but overriden by all of derived squared objects.
	friend istream& operator >> (istream& inputStream, CSquare& square); // override input operator.	
};

