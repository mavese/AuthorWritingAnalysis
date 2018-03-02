//author: Matteo Mantese

#ifndef MAP_HASH_H_
#define MAP_HASH_H_

#include <vector>

using namespace std;

template <typename K, typename V>
class Map_Hash
{
private:
	int M;
	int R;
	int spaceUsed;
	KeyValue<K,V> baseElt;
	vector<KeyValue<K,V>> hashTable;
	int getHashVal(KeyValue<K,V>);
	int getDoubleHash(KeyValue<K,V>);
	void rehash();
	bool isCollision(int);
	KeyValue<K,V>& get(K);

public:
	Map_Hash(int, int, K, V);
	virtual ~Map_Hash();
	void add(K);
	vector<KeyValue<K,V>> getContents();
	KeyValue<K,V>& operator[](K);

	
};
#include "Map_Hash.cpp"
#endif