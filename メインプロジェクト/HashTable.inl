#pragma once
#include "HashTable.h"

template<typename Key, typename Value, const int& HashFunc(const Key&), int bucketSize>
HashTable<Key,Value,HashFunc,bucketSize>::HashTable()
{
	//TODO �n�b�V���֐����������@���l����
}

template<typename Key, typename Value, const int& HashFunc(const Key&), int bucketSize>
HashTable<Key, Value, HashFunc, bucketSize>::~HashTable()
{
}