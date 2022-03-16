// Alix Sampford G20790929
#include "CSquare.h"

CSquare::CSquare(istream& file) // this uses the friend function below to read in
{
	file >> *this; 
}

// no need for friend. or CSquare:: as this function belongs to input stream.
istream& operator >> (istream& inputStream, CSquare& square)
{
	bool anotherWord = false;
	int nextChar = 0;

	do // check if the word read in is complete. No word read in should have a number in it.
	{
		//input word
		string word;
		inputStream >> word;
		square.mName += word;

		// consume white space
		inputStream >> ws;

		//peek nect char
		nextChar = inputStream.peek();

		// if next char is not a number then that means theres another word.
		anotherWord = !isdigit(nextChar) && nextChar != EOF;

		// add space if there is another word to be added.
		if (anotherWord)
		{
			square.mName += " ";
		}


	} while (anotherWord);


	//inputStream >> square.mName;
	return inputStream;
}

void CSquare::DisplayName() // This is used by go and jail but overriden by all of derived squared objects.
{
	cout << mName;
}