// Alix Sampford G20790929
#pragma once
#include "CSquare.h"
#include "Constants.h"

class CProperty : public CSquare
{
protected:
//private:
	int mPropertyCost;
	int mPropertyRent;
	int mPropertyColour;
	bool mIsOwned;
	shared_ptr<CPlayer> pOwner;

public:

	CProperty(istream& file); // Factory will read the in the information from file and place into this object accordingly.


	void OnLanding(shared_ptr<CPlayer>& ptrPlayerWhoLanded);
	friend istream& operator >> (istream& inputStream, CProperty& property);
};

