#pragma once
#include "HashTable.h"

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
HashTable<Key, Value, HashFunc, bucketSize>::HashTable()
	:buckets(),size()
{
	//比較演算子が有効な型か試す
	Key a{};
	static_assert(a == a, "key has not comparison operator");//アサートが発生することはないがコンパイルエラーにならないかチェックする
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
HashTable<Key, Value, HashFunc, bucketSize>::~HashTable()
{
	//何もしない
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline int HashTable<Key, Value, HashFunc, bucketSize>::GetSize() const
{
	return size;
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Insert(const Key& key, Value value)
{
	//同じキーが格納されていると挿入しない
	int dest;
	if (Find(key, dest)) {
		return false;
	}

	//バケットの後ろに挿入
	DoublyLinkedList<Pair>& bucket = buckets[GetBucketIndex(key)];
	bool&& result = bucket.Insert(bucket.GetEnd(), Pair({ key, value }));

	if (result) {
		size++;
	}

	return result;
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Erase(const Key& key)
{
	//指定されたキーが格納されていなければ終了
	int dest;
	if (!Find(key, dest)) {
		return false;
	}

	//指定されたキーの要素を削除
	DoublyLinkedList<Pair>& bucket = buckets[GetBucketIndex(key)];
	const int&& BUCKET_SIZE = bucket.GetSize();
	DoublyLinkedList<Pair>::Iterator it = bucket.GetBegin();

	//同じキーの要素を探索
	for (int i = 0; i < BUCKET_SIZE; i++) {
		if (it->key == key)//コンストラクタで比較演算子が有効なものか判断
		{
			break;
		}
		it++;
	}
	bool&& result = bucket.Delete(it);

	if (result) {
		size--;
	}

	return result;
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Find(const Key& key, Value& destination)const
{
	const DoublyLinkedList<Pair>& bucket = buckets[GetBucketIndex(key)];
	const int&& BUCKET_SIZE = bucket.GetSize();
	DoublyLinkedList<Pair>::ConstIterator it = bucket.GetConstBegin();

	//同じキーの要素を探索
	for (int i = 0; i < BUCKET_SIZE; i++) {
		if (it->key == key)//コンストラクタで比較演算子が有効なものか判断
		{
			destination = it->value;
			return true;
		}
		it++;
	}

	return false;
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline const int& HashTable<Key, Value, HashFunc, bucketSize>::GetBucketIndex(const Key& key) const
{
	return HashFunc(key) % bucketSize;
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Find(const Key& KEY, typename DoublyLinkedList<Pair>::ConstIterator& destination) const
{
	//TODO Find(const Key& KEY, typename DoublyLinkedList<Pair>::ConstIterator& destination)
	//同じキーの要素を探索
	for (int i = 0; i < BUCKET_SIZE; i++) {
		if (it->key == key)//コンストラクタで比較演算子が有効なものか判断
		{
			destination = it->value;
			return true;
		}
		it++;
	}
	return false;
}
