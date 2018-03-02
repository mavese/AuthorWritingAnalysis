#include "VectorGramGenerator.h"
#include "HashGramGenerator.h"
#include "AVLGramGenerator.h"
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <cctype>


using namespace std;


int main(int argc, char** argv)
{
	string word = "";
	char c;
	locale loc;
	string file = argv[1];
	string prevWord = "";
	ifstream book(file.c_str());
	// Instantiating generator class
	// VectorGramGenerator generator;
	HashGramGenerator generator;
	// AVLGramGenerator generator;
	// Scanning through document one character at a time
	if (book.is_open())
	{
		c = book.get();
		while (!book.eof())
		{
			word.clear();
			// Checking the character is a letter to know when the end of the word is and to cut out puntiation
			while ((((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))))
			{
				word += c;
				c = book.get();
			}
			if (word != "")
			{
				string tempWord = word;
				int i = 0;
				word = "";
				while(tempWord[i])
				{
					word += tolower(tempWord[i]);
					i += 1;
				}
				generator.addWord(word);
				if (prevWord != "")
				{
					generator.addTwoWords(prevWord, word);
				}
				prevWord = word;
			}
			c = book.get();
		}
	}
	generator.printGrams();
	// delete generator;
    return 0;
}

