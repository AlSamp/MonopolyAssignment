#include "CFreeParking.h"

CFreeParking::CFreeParking(istream& file) : CSquare(file)
{
	file >> *this;
}

istream& operator>>(istream& inputStream, CFreeParking& freeParking)
{
	inputStream >> freeParking.namePart2;

	return inputStream;
}

//void CFreeParking::DisplayName()
//{
//	cout << name << " " << namePart2 << endl;
//}