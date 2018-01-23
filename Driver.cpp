#include <iostream>
#include <fstream>
#include <string>
#include "VectorGramGenerator.h"

using namespace std;


int main(int argc, char** argv)
{
	string word = "";
	char c;
	string file = argv[1];
	string prevWord = "";
	ifstream book(file.c_str());
	// Instantiating generator class
	VectorGramGenerator* generator = new VectorGramGenerator();
	// Scanning through document one character at a time
	if (book.is_open())
	{
		c = book.get();
		while (!book.eof())
		{
			word.clear();
			// Checking the character is a letter to know when the end of the word is and to cut out puntiation
			while (((c >= 48) && (c <= 57) || ((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))))
			{
				word += c;
				c = book.get();
			}
			if (word != "")
			{
				generator->addUnigram(word);
				if (prevWord != "")
				{
					generator->addBigram(prevWord, word);
				}
				prevWord = word;
			}
			c = book.get();
		}
	}
	generator->printGrams();
    return 0;
}

