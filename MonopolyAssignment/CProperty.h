#pragma once
#include "CSquare.h"

class CProperty : public CSquare
{
protected:
	string namePart2;
	int propertyCost;
	int propertyRent;
	int propertyColour;
	bool isOwned;
	string owner;

public:

	CProperty(istream& file);

	void Display();
	int getRent();
	int getCost();
	int getColour();
	void setIsOwned(bool newStatus);
	bool getIsOwned();
	string getOwner();
	void setOwner(string newOwner);
	void OnLanding(CPlayer& playerWhoLanded, CPlayer& propertyOwner);


	
	friend istream& operator >> (istream& inputStream, CProperty& property);
};

