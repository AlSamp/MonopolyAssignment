#pragma once
#include "CSquare.h"
#include "Constants.h"

class CProperty : public CSquare
{
protected:
	string namePart2;
	int propertyCost;
	int propertyRent;
	int propertyColour;
	bool isOwned;

	shared_ptr<CPlayer> owner;

public:

	CProperty(istream& file);

	void Display();
	int getRent();
	int getCost();
	int getColour();
	void setIsOwned(bool newStatus);
	bool getIsOwned();
	string getOwner();
	void setOwner(shared_ptr<CPlayer>& newOwner);
	void OnLanding(shared_ptr<CPlayer> playerWhoLanded);


	
	friend istream& operator >> (istream& inputStream, CProperty& property);
};

