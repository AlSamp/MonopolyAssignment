// Alix Sampford G20790929
#include "CSquare.h"

CSquare::CSquare(istream& file) // this uses the friend function below to read in
{
	file >> *this; 
}

// no need for friend. or CSquare:: as this function belongs to input stream.
istream& operator >> (istream& inputStream, CSquare& square)
{
	inputStream >> square.mName;
	return inputStream;
}

void CSquare::DisplayName() // This is used by go and jail but overriden by all of derived squared objects.
{
	cout << mName;
}