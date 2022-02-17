#pragma once
#include "CSquare.h"
#include <ctime>
class CPenalty : public CSquare
{
private:

protected:
	// string name - assigned within base constructor

public:

	CPenalty(istream& file);
	int Random();
	void OnLanding(shared_ptr<CPlayer> playerWhoLanded);
	friend istream& operator >> (istream& inputStream, CPenalty& go);
};

