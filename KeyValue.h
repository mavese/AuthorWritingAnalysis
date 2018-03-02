//author: Matteo Mantese

#ifndef KEYVALUE_H_
#define KEYVALUE_H_
#include <iostream>
#include <string>

using namespace std;

template <typename K, typename V>
class KeyValue
{
private:
	K key;
	V value;
public:
	KeyValue(K);
	KeyValue(K, V);
	virtual ~KeyValue();
	bool operator==(KeyValue<K,V>& rhs)const;
	bool operator!=(KeyValue<K,V>& rhs)const;	
	bool operator<(const KeyValue<K,V>& rhs)const;
	bool operator>(const KeyValue<K,V>& rhs)const;
	KeyValue<K,V>& operator++();
	template <typename k, typename v>
	friend ostream& operator<< (ostream& os, const KeyValue<k,v>& kv);
	K& getKey();
	V& getValue();
	
};

#include "KeyValue.cpp"
#endif