#pragma once
#include "CSquare.h"
class CPenalty : public CSquare
{
private:

protected:
	// string name - assigned within base constructor

public:

	CPenalty(istream& file);

	friend istream& operator >> (istream& inputStream, CPenalty& go);
};

