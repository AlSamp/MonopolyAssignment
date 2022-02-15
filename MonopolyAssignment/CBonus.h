#pragma once
#include "CSquare.h"
class CBonus : public CSquare
{


protected:
// string name assinged with the base constructor


public:

	CBonus(istream& file);

	friend istream& operator >> (istream& inputStream, CBonus& go);

public:
};

