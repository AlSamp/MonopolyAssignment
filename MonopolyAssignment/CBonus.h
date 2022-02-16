#pragma once
#include "CSquare.h"
#include <ctime>
class CBonus : public CSquare
{


protected:
// string name assinged with the base constructor


public:

	CBonus(istream& file);
	int Random();
	void OnLanding(shared_ptr<CPlayer> playerWhoLanded);
	friend istream& operator >> (istream& inputStream, CBonus& go);

public:
};

