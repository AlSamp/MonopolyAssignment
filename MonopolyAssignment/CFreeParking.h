#pragma once
#include "CSquare.h"
class CFreeParking : public CSquare
{
protected:
	// string name - assinged with the base constructor
	string namePart2;

public:

	CFreeParking(istream& file);

	friend istream& operator >> (istream& inputStream, CFreeParking& freeParking);

	/*void DisplayName();*/
};

