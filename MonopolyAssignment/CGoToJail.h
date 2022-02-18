// Alix Sampford G20790929
#pragma once
#include "CSquare.h"
class CGoToJail : public CSquare
{

protected:
	// string name assinged with the base constructor
	string mNamePart2;
	string mNamePart3;

public:

	CGoToJail(istream& file); // Factory will read the in the information from file and place into this object accordingly.
	void OnLanding(shared_ptr<CPlayer> ptrPlayerWhoLanded);
	void DisplayName();

	friend istream& operator >> (istream& inputStream, CGoToJail& goToJail);
};

