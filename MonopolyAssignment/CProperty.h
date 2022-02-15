#pragma once
#include "CSquare.h"
class CProperty : public CSquare
{
protected:
	string namePart2;
	int propertyCost;
	int propertyRent;
	int propertyColour;

public:

	CProperty(istream& file);

	friend istream& operator >> (istream& inputStream, CProperty& property);

	void Display();

	
};

