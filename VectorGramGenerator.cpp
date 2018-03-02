// Author: Matteo Mantese
// Created: January 21, 2018


#include "VectorGramGenerator.h"

using namespace std;

VectorGramGenerator::VectorGramGenerator()
{
}

VectorGramGenerator::~VectorGramGenerator()
{
	// unigram.clear();
	// vector<tuple<string, int>>().swap(unigram);
	// bigram.clear();
	// vector<tuple<string, int>>().swap(bigram);
}
void VectorGramGenerator::addWord(string word)
{
	bool isFound = false;
	for (size_t i = 0; i < unigram.size(); i++)
	{
		if (get<0>(unigram[i]) == word)
		{
			isFound = true;
			get<1>(unigram[i]) += 1;
		}
	}
	if (!isFound)
	{
		unigram.push_back(tuple<string, int>(word, 1));
	}
}

void VectorGramGenerator::addTwoWords(string biWord1, string biWord2)
{
	bool isFound = false;
	for (size_t i = 0; i < bigram.size(); i++)
	{
		if (get<0>(bigram[i]) == biWord1 && get<1>(bigram[i]) == biWord2)
		{
			isFound = true;
			get<2>(bigram[i]) += 1;
		}
	}
	if (!isFound)
	{
		bigram.push_back(tuple<string, string, int>(biWord1, biWord2, 1));
	}
}

float VectorGramGenerator::computeProbability(string biWord1, string biWord2)
{
	float nTimesBi = 0;
	float nTimesUn = 0;
	for (int i = 0; i < bigram.size(); i++)
	{
		if (get<0>(bigram[i]) == biWord1 && get<1>(bigram[i]) == biWord2)
		{
			nTimesBi = get<2>(bigram[i]);
			break;
		}
	}
	for (int i = 0; i < unigram.size(); i++)
	{
		if (get<0>(unigram[i]) == biWord1)
		{
			nTimesUn = get<1>(unigram[i]);
			break;
		}
	}
	if (nTimesUn != 0)
	{
		return nTimesBi / nTimesUn;
	}
	return 0;
}

void VectorGramGenerator::printGrams()
{
	cout << "Unigrams:\n";
	for (int i = 0; i < unigram.size(); i++)
	{
		cout << get<0>(unigram[i]) << " " << get<1>(unigram[i]) << endl;
	}

	cout << "\nBigrams:\n";
	for (int i = 0; i < bigram.size(); i++)
	{
		float prob = computeProbability(get<0>(bigram[i]), get<1>(bigram[i]));
		cout << get<0>(bigram[i]) << " " << get<1>(bigram[i]) << " " << get<2>(bigram[i]) << " " << prob << endl;
	}
}