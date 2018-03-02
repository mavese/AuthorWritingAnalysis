//author: Matteo Mantese

#ifndef AVLGRAMGENERATOR_H_
#define AVLGRAMGENERATOR_H_

#include "IGramGenerator.h"
#include "AVLTree.h"
#include "KeyValue.h"
#include <string>

using namespace std;

using namespace std;
class AVLGramGenerator : public IGramGenerator
{
private:
	AVLtree<KeyValue<string, int>> uniAVL;
	AVLtree<KeyValue<string, int>> biAVL;
public:
	AVLGramGenerator();
	~AVLGramGenerator();
	void addWord(string) override;
	void addTwoWords(string, string) override;
	float computeProbability(string, string) override;	
	void printGrams() override;
};
#include "AVLGramGenerator.cpp"
#endif