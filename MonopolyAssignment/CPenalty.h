// Alix Sampford G20790929
#pragma once
#include "CSquare.h"
#include <ctime>
class CPenalty : public CSquare
{
private:

protected:
	// string name - assigned within base constructor

public:

	CPenalty(istream& file); // Factory will read the in the information from file and place into this object accordingly.
	int Random();
	void OnLanding(shared_ptr<CPlayer> playerWhoLanded);
	friend istream& operator >> (istream& inputStream, CPenalty& penalty);
};

