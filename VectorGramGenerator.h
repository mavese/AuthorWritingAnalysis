// Author: Matteo Mantese
// Created: January 21, 2018

#ifndef VECTORGRAMGENERATOR_H_
#define VECTORGRAMGENERATOR_H_

#include <vector>
#include <string>
#include <tuple>
#include <iostream>

using namespace std;

class VectorGramGenerator {
private:
	vector<tuple<string, int>> unigram;
	vector<tuple<string, string, int>> bigram;
	void addWord(string);
	void addTwoWords(string, string);
	float computeProbability(string, string);

public:
	// VectorGramGenerator();
	// virtual ~VectorGramGenerator();
	void addUnigram(string);
	void addBigram(string, string);
	void printGrams();
};

#endif /* VECTORGRAMGENERATOR_H_ */