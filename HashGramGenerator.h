//author: Matteo Mantese

#ifndef HASHGRAMGENERATOR_H_
#define HASHGRAMGENERATOR_H_

#include "KeyValue.h"
#include "Map_Hash.h"
#include "IGramGenerator.h"
#include <vector>
#include <string>
#include <tuple>
#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;
class HashGramGenerator : public IGramGenerator
{
private:
	Map_Hash<string,int> uniHashMap;
	Map_Hash<string,int> biHashMap;
public:

	HashGramGenerator();
	virtual~HashGramGenerator();
	void addWord(string) override;
	void addTwoWords(string, string) override;
	float computeProbability(string, string) override;
	void printGrams() override;
};
#include "HashGramGenerator.cpp"
#endif