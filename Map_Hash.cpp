//author: Matteo Mantese

#include "Map_Hash.h"
#include <functional>

template <typename K, typename V>
Map_Hash<K,V>::Map_Hash(int M, int R, K baseKey, V baseValue)
	:M(M), R(R), spaceUsed(0), baseElt(baseKey, baseValue), hashTable(M, baseElt)
{}

template <typename K, typename V>
Map_Hash<K,V>::~Map_Hash()
{}

template <typename K, typename V>
void Map_Hash<K,V>::add(K key)
{
	KeyValue<K,V> elt(key);
	if (spaceUsed > M/2)
	{
		rehash();
	}
	bool isFound = false;
	int origHashVal = getHashVal(elt);
	int hashVal = origHashVal;
	int i = 1;
	while (isCollision(hashVal))
	{
		if (hashTable[hashVal] == elt)
		{
			++hashTable[hashVal];
			isFound = true;
			break;
		}
		hashVal = (origHashVal + i*getDoubleHash(elt))%M;
		++i;
	}
	if (!isFound)
	{
		hashTable[hashVal] = elt;
	}
	++spaceUsed;
}

template <typename K, typename V>
KeyValue<K,V>& Map_Hash<K,V>::get(K key)
{
	KeyValue<K,V> elt(key);
	bool isFound = false;
	int origHashVal = getHashVal(elt);
	int hashVal = origHashVal;
	int i = 1;
	while (isCollision(hashVal))
	{
		if (hashTable[hashVal] == elt)
		{
			isFound = true;
			break;
		}
		hashVal = (origHashVal + i*getDoubleHash(elt))%M;
		i ++;
	}
	if (isFound)
	{
		return hashTable[hashVal];
	}
	return baseElt;
}

template <typename K, typename V>
vector<KeyValue<K,V>> Map_Hash<K,V>::getContents()
{
	vector<KeyValue<K,V>> v;
	for (int i = 0; i < M; i++)
	{
		if (isCollision(i))
		{
			v.push_back(hashTable[i]);
		}
	}
	return v;
}

template <typename K, typename V>
int Map_Hash<K,V>::getHashVal(KeyValue<K,V> elt)
{
	return hash<K>{}(elt.getKey()) % M;
}

template <typename K, typename V>
int Map_Hash<K,V>::getDoubleHash(KeyValue<K,V> elt)
{
	return R - (hash<K>{}(elt.getKey()) % R);
}

template <typename K, typename V>
void Map_Hash<K,V>::rehash()
{
	M *= 2+1;
	bool isPrime = false;
	bool isFound = false;
	while(!isPrime)
	{
		isFound = false;
	  	for(int i = 2; i <= M / 2; i++)
	  	{
	      if(M % i == 0)
	      {
	          isPrime = false;
	          isFound = true;
	          break;
	      }
	  	}
	  	if (!isFound)
	  	{
	  		isPrime = true;
	  	}
	  	else
	  	{
	  		M += 1;
	  	}
  	}
	vector<KeyValue<K,V>> temp(M,baseElt);
	for (int i = 0; i < hashTable.size(); i++)
	{
		if (isCollision(i))
		{
			int j = 1;
			int origHashVal = getHashVal(hashTable[i]);
			int hashVal = origHashVal;
			while (temp[hashVal] != baseElt)
			{
				hashVal = (origHashVal + j*getDoubleHash(hashTable[i]))%M;
				j += 1;
			}
			temp[hashVal] = hashTable[i];
		}
	}
	hashTable.swap(temp);
}

template <typename K, typename V>
bool Map_Hash<K,V>::isCollision(int idx)
{
	return hashTable[idx] != baseElt;
}

template <typename K, typename V>
KeyValue<K,V>& Map_Hash<K,V>::operator[](K key)
{
	return get(key);
}