#pragma once
#include "CSquare.h"
class CGo : public CSquare
{

protected:
// string name assinged with the base constructor


public:

	CGo(istream& file);
	
	friend istream& operator >> (istream& inputStream, CGo& go);

	void OnLanding(shared_ptr<CPlayer> playerWhoLanded)
	{
		// Do nothing for now
	}


	

};

