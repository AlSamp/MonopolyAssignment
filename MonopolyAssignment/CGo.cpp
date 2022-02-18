// Alix Sampford G20790929
#include "CGo.h"

CGo::CGo(istream& file) : CSquare(file)
{
	file >> *this;
}  

istream& operator>>(istream& inputStream, CGo& go)
{
	return inputStream; // nothing else to assign.
}
