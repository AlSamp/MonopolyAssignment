// Alix Sampford G20790929
#include "CJail.h"

CJail::CJail(istream& file) : CSquare(file)
{
	file >> *this;
}



istream& operator>>(istream& inputStream, CJail& jail)
{
	return inputStream;
}

void CJail::OnLanding(shared_ptr<CPlayer>& playerWhoLanded) 
{
	cout << playerWhoLanded->mName << " is just visiting." << endl;
}