// Alix Sampford G20790929
#pragma once
#include "CSquare.h"
class CStation : public CSquare
{
private:

protected:
	bool isOwned;
	shared_ptr<CPlayer> pOwner;

public:

	CStation(istream& file);

	void OnLanding(shared_ptr<CPlayer>& ptrPlayerWhoLanded);

	friend istream& operator >> (istream& inputStream, CStation& station);


};

