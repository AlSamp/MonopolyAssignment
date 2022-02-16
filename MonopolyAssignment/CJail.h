#pragma once
#include "CSquare.h"
class CJail : public CSquare
{
private:

protected:
	// string name - declared within base constructor.

public:

	CJail(istream& file);
	void OnLanding(CPlayer& player);

	friend istream& operator >> (istream& inputStream, CJail& go);
};

