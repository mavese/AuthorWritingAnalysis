//author: Matteo Mantese

#include "KeyValue.h"

template <typename K, typename V>
KeyValue<K,V>::KeyValue(K key)
{
	this->key = key;
	this->value = 1;
}

template <typename K, typename V>
KeyValue<K,V>::KeyValue(K key, V value)
{
	this->key = key;
	this->value = value;
}
template <typename K, typename V>
KeyValue<K,V>::~KeyValue()
{}

template <typename K, typename V>
bool KeyValue<K,V>::operator==(KeyValue<K,V>& rhs)const
{

	if (key == rhs.key)
	{
		return true;
	}
	return false;
}

template <typename K, typename V>
bool KeyValue<K,V>::operator!=(KeyValue<K,V>& rhs)const
{
	if (key != rhs.key)
	{
		return true;
	}
	return false;
}

template <typename K, typename V>
bool KeyValue<K,V>::operator<(const KeyValue<K,V>& rhs)const
{
	if (key < rhs.key)
	{
		return true;
	}
	return false;
}

template <typename K, typename V>
bool KeyValue<K,V>::operator>(const KeyValue<K,V>& rhs)const
{

	if (key > rhs.key)
	{
		return true;
	}
	return false;	
}

template <typename k, typename v>
ostream& operator<<(ostream& os, const KeyValue<k,v>& kv)
{
	os << kv.key << " " << kv.value;
	return os;
}

template <typename K, typename V>
KeyValue<K,V>& KeyValue<K,V>::operator++()
{
	++value;
	return *this;
}

template <typename K, typename V>
K& KeyValue<K,V>::getKey()
{
	return key;
}

template <typename K, typename V>
V& KeyValue<K,V>::getValue()
{
	return value;
}