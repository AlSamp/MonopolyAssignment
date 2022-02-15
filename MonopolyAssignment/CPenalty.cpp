#include "CPenalty.h"

CPenalty::CPenalty(istream& file) : CSquare(file)
{
	file >> *this;
}

istream& operator>>(istream& inputStream, CPenalty& penalty)
{
	return inputStream;
}

