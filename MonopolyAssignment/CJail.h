// Alix Sampford G20790929
#pragma once
#include "CSquare.h"
class CJail : public CSquare
{
private:

protected:
	// string name - declared within base constructor.

public:

	CJail(istream& file); // Factory will read the in the information from file and place into this object accordingly.
	void OnLanding(shared_ptr<CPlayer>& ptrPlayerWhoLanded);

	friend istream& operator >> (istream& inputStream, CJail& go);
};

