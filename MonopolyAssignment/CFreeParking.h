// Alix Sampford G20790929
#pragma once
#include "CSquare.h"
class CFreeParking : public CSquare
{
protected:
	// string name - assinged with the base constructor
	string mNamePart2;

public:

	CFreeParking(istream& file); // Factory will read the in the information from file and place into this object accordingly.

	void OnLanding(shared_ptr<CPlayer> ptrPlayerWhoLanded);

	friend istream& operator >> (istream& inputStream, CFreeParking& freeParking);
	

	void DisplayName();
};

