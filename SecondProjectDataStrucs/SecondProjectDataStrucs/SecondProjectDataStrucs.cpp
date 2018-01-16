// SecondProjectDataStrucs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<tuple>

using namespace std;

vector<tuple<string,int>> unigram;
vector<tuple<string, int>> bigram;


int main()
{
	string word = "";
	char c;
	string prevWord = "";
	ifstream book("data.txt");
	if (book.is_open())
	{
		c = book.get();
		while (!book.eof())
		{
			word.clear();
			while (((c >= 48) && (c <= 57) || ((c >= 65) && (c <= 90)) || ((c >= 97) && (c <= 122))))
			{
				word += c;
				c = book.get();
			}
			cout << word << endl;
			if (word != "")
			{
				bool isFound = false;
				for (size_t i = 0; i < unigram.size(); i++)
				{
					if (get<0>(unigram[i]) == word)//NEED ACTUAL GET FUNCTION CODE
					{
						isFound = true;
						get<1>(unigram[i]) += 1;
					}
				}
				if (!isFound)
				{
					unigram.push_back(tuple<string, int>(word, 1));
				}
				if (prevWord != "")
				{
					string biWord = prevWord + " " + word;
					isFound = false;
					for (size_t i = 0; i < bigram.size(); i++)
					{
						if (get<0>(bigram[i]) == word)
						{
							isFound = true;
							get<1>(bigram[i]) += 1;
						}
					}
					if (!isFound)
					{
						bigram.push_back(tuple<string, int>(biWord, 1));
					}
				}
				prevWord = word;
			}
			c = book.get();
		}
	}
	cin >> word;
    return 0;
}

