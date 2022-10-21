#pragma once
#include "HashTable.h"

template<typename Key, typename Value, const int& HashFunc(const Key&), int bucketSize>
HashTable<Key,Value,HashFunc,bucketSize>::HashTable()
{
	//TODO ハッシュ関数を試す方法を考える
}

template<typename Key, typename Value, const int& HashFunc(const Key&), int bucketSize>
HashTable<Key, Value, HashFunc, bucketSize>::~HashTable()
{
}