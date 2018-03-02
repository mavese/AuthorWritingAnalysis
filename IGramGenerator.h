#ifndef IGRAMGENERATOR_H_
#define IGRAMGENERATOR_H_
#include <string>
using namespace std;
class IGramGenerator
{
public:
	virtual void addWord(string) = 0;
	virtual void addTwoWords(string, string) = 0;
	virtual void printGrams() = 0;
	virtual float computeProbability(string, string) = 0;
	
};
#endif