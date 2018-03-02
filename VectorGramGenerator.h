// Author: Matteo Mantese
// Created: January 21, 2018

#ifndef VECTORGRAMGENERATOR_H_
#define VECTORGRAMGENERATOR_H_

#include "IGramGenerator.h"
#include <vector>
#include <string>
#include <tuple>
#include <iostream>

using namespace std;

class VectorGramGenerator : public IGramGenerator
{
private:
	vector<tuple<string, int>> unigram;
	vector<tuple<string, string, int>> bigram;
public:
	VectorGramGenerator();
	virtual ~VectorGramGenerator();
	void addWord(string) override;
	void addTwoWords(string, string) override;
	float computeProbability(string, string) override;
	void printGrams() override;
};

#include "VectorGramGenerator.cpp"
#endif /* VECTORGRAMGENERATOR_H_ */