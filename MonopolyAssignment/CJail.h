#pragma once
#include "CSquare.h"
class CJail : public CSquare
{
private:

protected:
	// string name - declared within base constructor.

public:

	CJail(istream& file);
	void OnLanding(shared_ptr<CPlayer> playerWhoLanded);

	friend istream& operator >> (istream& inputStream, CJail& go);
};

