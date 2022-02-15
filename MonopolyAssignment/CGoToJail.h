#pragma once
#include "CSquare.h"
class CGoToJail : public CSquare
{

protected:
	// string name assinged with the base constructor
	string namePart2;
	string namePart3;

public:

	CGoToJail(istream& file);

	friend istream& operator >> (istream& inputStream, CGoToJail& goToJail);
};

