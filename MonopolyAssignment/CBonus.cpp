#include "CBonus.h"

CBonus::CBonus(istream& file) : CSquare(file)
{
    file >> *this;
}

istream& operator>>(istream& inputStream, CBonus& bonus)
{
    return inputStream;
}
