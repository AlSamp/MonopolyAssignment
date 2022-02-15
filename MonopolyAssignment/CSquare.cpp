#include "CSquare.h"

CSquare::CSquare(istream& file) // this uses the friend function below to read in
{
	file >> *this; 
}

// no need for friend. or CSquare:: as this function belongs to input stream.
istream& operator >> (istream& inputStream, CSquare& square)
{
	inputStream >> square.name;
	return inputStream;
}

// no need for friend. or CSquare::as this function belongs to output stream.
ostream& operator << (ostream& outputStream, const CSquare& square)
{
	
	outputStream << square.name;
	return outputStream;
}

void CSquare::Display()
{
	cout << name;
}