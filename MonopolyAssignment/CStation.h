#pragma once
#include "CSquare.h"
class CStation : public CSquare
{
private:

protected:
	string namePart2;


public:

	CStation(istream& file);

	friend istream& operator >> (istream& inputStream, CStation& station);

	void Display();
};

