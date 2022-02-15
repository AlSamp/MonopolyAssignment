#include "CGoToJail.h"

CGoToJail::CGoToJail(istream& file) :CSquare(file)
{
	file >> *this;
}

istream& operator>>(istream& inputStream, CGoToJail& goToJail)
{
	inputStream >> goToJail.namePart2;
	inputStream >> goToJail.namePart3;
	return inputStream;
}
