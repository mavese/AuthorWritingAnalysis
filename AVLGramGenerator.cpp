#include "AVLGramGenerator.h"

AVLGramGenerator::AVLGramGenerator(){}

AVLGramGenerator::~AVLGramGenerator(){}

void AVLGramGenerator::addWord(string word)
{
	KeyValue<string, int> kv(word, 1);
	KeyValue<string, int>* rtn = uniAVL[kv];
	if (rtn == nullptr)
	{
		uniAVL.insert(kv);
	}
	else
	{
		++(*rtn);
	}
}

void AVLGramGenerator::addTwoWords(string biWord1, string biWord2)
{
	KeyValue<string, int> kv(biWord1+ " " + biWord2, 1);
	KeyValue<string, int>* rtn = biAVL[kv];
	if (rtn == nullptr)
	{
		biAVL.insert(kv);
	}
	else
	{
		++(*rtn);
	}
}

float AVLGramGenerator::computeProbability(string biWord1, string biWord2)
{
	KeyValue<string, int>* base = new KeyValue<string, int>("",0);
	float nTimesBi = biAVL.find(KeyValue<string, int>((biWord1+" "+biWord2),0), base).getValue();
	float nTimesUn = uniAVL.find(KeyValue<string,int>(biWord1, 0), base).getValue();
	delete base;
	if (nTimesUn != 0)
	{
		return nTimesBi / nTimesUn;
	}
	return 0;
}

void AVLGramGenerator::printGrams()
{
	cout << "Unigrams:\n";
	uniAVL.print();
	cout << "Bigrams:\n";
	biAVL.print();
}