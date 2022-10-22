#pragma once
#include "HashTable.h"

template<typename Key, typename Value, int& HashFunc(Key&), int bucketSize>
HashTable<Key, Value, HashFunc, bucketSize>::HashTable()
	:buckets()
{
	//‰½‚à‚µ‚È‚¢
}

template<typename Key, typename Value, int& HashFunc(Key&), int bucketSize>
HashTable<Key, Value, HashFunc, bucketSize>::~HashTable()
{
	//‰½‚à‚µ‚È‚¢
}

template<typename Key, typename Value, int& HashFunc(Key&), int bucketSize>
inline int HashTable<Key, Value, HashFunc, bucketSize>::GetSize() const
{
	return 0;
}

template<typename Key, typename Value, int& HashFunc(Key&), int bucketSize>
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Insert(Key key, Value value)
{
	return false;
}

template<typename Key, typename Value, int& HashFunc(Key&), int bucketSize>
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Erase(Key key)
{
	return false;
}

template<typename Key, typename Value, int& HashFunc(Key&), int bucketSize>
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Find(Key key)
{
	return false;
}
