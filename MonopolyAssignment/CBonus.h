// Alix Sampford G20790929
#pragma once
#include "CSquare.h"
#include <ctime>
class CBonus : public CSquare
{


protected:
// string name assinged with the base constructor


public:

	CBonus(istream& file); // Factory will read the in the information from file and place into this object accordingly.
	int Random();
	void OnLanding(shared_ptr<CPlayer>& ptrPlayerWhoLanded);
	friend istream& operator >> (istream& inputStream, CBonus& go);
};

