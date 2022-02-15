#include "CStation.h"

CStation::CStation(istream& file) : CSquare(file)
{
	file >> *this;
}

void CStation::Display()
{
	cout << name << " " << namePart2 << endl;
}

istream& operator>>(istream& inputStream, CStation& station)
{
	inputStream >> station.namePart2;

	return inputStream;
}
