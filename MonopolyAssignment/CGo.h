// Alix Sampford G20790929
#pragma once
#include "CSquare.h"
class CGo : public CSquare
{

protected:
// string name assinged with the base constructor


public:

	CGo(istream& file); // Factory will read the in the information from file and place into this object accordingly.
	void OnLanding(shared_ptr<CPlayer>& ptrPlayerWhoLanded)
	{
		// Do nothing for now
	}

	friend istream& operator >> (istream& inputStream, CGo& go);
};

