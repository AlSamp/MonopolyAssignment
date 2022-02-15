#include "CJail.h"

CJail::CJail(istream& file) : CSquare(file)
{
	file >> *this;
}

istream& operator>>(istream& inputStream, CJail& jail)
{
	return inputStream;
}
