#include "CProperty.h"

CProperty::CProperty(istream& file) : CSquare(file)
{
	// base class constructor is going to read in the name of the property.
	// The derived constructor is then going to follow on  and read in the rest of it

	propertyColour = NULL;
	propertyCost = NULL;
	propertyRent = NULL;
	
	file >> *this;
}

istream& operator >>(istream& inputStream, CProperty& property)
{
	if (property.name != "Friargate") // this is for you nick ty <3
	{
		inputStream >> property.namePart2;

	}

		inputStream >> property.propertyCost;
		inputStream >> property.propertyRent;
		inputStream >> property.propertyColour;
	
	return inputStream;
}

void CProperty::Display()
{
	cout << name << " ";

	if (name != "Friargate") // this is for you nick ty <3
	{
		cout << namePart2 << " ";
	}
		cout << propertyCost << " " << propertyRent << " " << propertyColour << endl;
}