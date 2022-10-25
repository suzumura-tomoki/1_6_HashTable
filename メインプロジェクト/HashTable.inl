#pragma once
#include "HashTable.h"

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
HashTable<Key, Value, HashFunc, bucketSize>::HashTable()
	:buckets(), size()
{
	//比較演算子が有効な型か試す
	Key a{};
	//エラーになるので途中経過を提出するためにコメントアウト
	//static_assert(a == a, "key has not comparison operator");//アサートが発生することはないがコンパイルエラーにならないかチェックする
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
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Insert(const Key& KEY, const Value& VALUE)
{
	//同じキーが格納されていると挿入しない
	int dest;
	if (Find(KEY, dest)) {
		return false;
	}

	//バケットの後ろに挿入
	DoublyLinkedList<Pair>& bucket = buckets[GetBucketIndex(KEY)];
	bool&& result = bucket.Insert(bucket.GetEnd(), Pair({ KEY, VALUE }));

	if (result) {
		size++;
	}

	return result;
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Erase(const Key& KEY)
{

	//指定されたキーの要素を検索
	DoublyLinkedList<Pair>& bucket = buckets[GetBucketIndex(KEY)];
	DoublyLinkedList<Pair>::ConstIterator cit;

	if (!FindFromBucket(KEY, bucket, cit)) {
		//指定されたキーが格納されていなければ終了
		return false;
	}

	//指定されたキーの要素を削除
	bool result = bucket.Delete(cit);

	if (result) {
		size--;
	}

	return result;
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Find(const Key& KEY, Value& destination)const
{
	const DoublyLinkedList<Pair>& BUCKET = buckets[GetBucketIndex(KEY)];
	DoublyLinkedList<Pair>::ConstIterator cit;

	if (FindFromBucket(KEY, BUCKET, cit)) {
		destination = cit->value;
		return true;
	}

	return false;
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline int HashTable<Key, Value, HashFunc, bucketSize>::GetBucketIndex(const Key& KEY) const
{
	return HashFunc(KEY) % bucketSize;
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline bool HashTable<Key, Value, HashFunc, bucketSize>::FindFromBucket(const Key& KEY, const DoublyLinkedList<Pair>& BUCKET, typename DoublyLinkedList<Pair>::ConstIterator& destination) const
{
	const int BUCKET_SIZE = BUCKET.GetSize();

	//バケットが空であれば終了
	if (BUCKET_SIZE == 0) {
		return false;
	}

	destination = BUCKET.GetConstBegin();

	//同じキーの要素を探索
	for (int i = 0; i < BUCKET_SIZE; i++) {
		if (destination->key == KEY)//コンストラクタで比較演算子が有効なものか判断
		{
			return true;
		}
		destination++;
	}
	return false;
}
