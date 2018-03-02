//author: Matteo Mantese

#include "HashGramGenerator.h"

HashGramGenerator::HashGramGenerator()
	: uniHashMap(199, 89, "", 0), biHashMap(199, 89, "", 0)
{}
HashGramGenerator::~HashGramGenerator()
{}

void HashGramGenerator::addWord(string word)
{
	uniHashMap.add(word);
}

void HashGramGenerator::addTwoWords(string biWord1, string biWord2)
{
	biHashMap.add(biWord1+" "+biWord2);
}

float HashGramGenerator::computeProbability(string biWord1, string biWord2)
{
	float nTimesBi = biHashMap[biWord1+" "+biWord2].getValue();
	float nTimesUn = uniHashMap[biWord1].getValue();
	if (nTimesUn != 0)
	{
		return nTimesBi / nTimesUn;
	}
	return 0;
}

void HashGramGenerator::printGrams()
{
	cout << "Unigrams:\n";
	vector<KeyValue<string, int>> uniHashT = uniHashMap.getContents(); 
	for (int i = 0; i < uniHashT.size(); i++)
	{
		cout << uniHashT[i] << endl;
	}
	cout << "\nBigrams:\n";
	vector<KeyValue<string, int>> biHashT = biHashMap.getContents(); 
	for (int i = 0; i < biHashT.size(); i++)	
	{
		istringstream iss(biHashT[i].getKey());
		vector<string> tokens{istream_iterator<string>{iss},
   		istream_iterator<string>{}};
		float prob = computeProbability(tokens[0], tokens[1]);
		cout << biHashT[i] << " " << prob << endl;

	}
}
