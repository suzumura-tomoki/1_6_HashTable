#pragma once
#include "HashTable.h"

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
HashTable<Key, Value, HashFunc, bucketSize>::HashTable()
	:buckets(), size()
{
	//��r���Z�q���L���Ȍ^������
	Key a{};
	static_assert(a == a, "key has not comparison operator");//�A�T�[�g���������邱�Ƃ͂Ȃ����R���p�C���G���[�ɂȂ�Ȃ����`�F�b�N����
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
HashTable<Key, Value, HashFunc, bucketSize>::~HashTable()
{
	//�������Ȃ�
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline int HashTable<Key, Value, HashFunc, bucketSize>::GetSize() const
{
	return size;
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Insert(const Key& KEY, Value value)
{
	//�����L�[���i�[����Ă���Ƒ}�����Ȃ�
	int dest;
	if (Find(key, dest)) {
		return false;
	}

	//�o�P�b�g�̌��ɑ}��
	DoublyLinkedList<Pair>& bucket = buckets[GetBucketIndex(key)];
	bool&& result = bucket.Insert(bucket.GetEnd(), Pair({ key, value }));

	if (result) {
		size++;
	}

	return result;
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Erase(const Key& KEY)
{

	//�w�肳�ꂽ�L�[�̗v�f������
	DoublyLinkedList<Pair>& bucket = buckets[GetBucketIndex(key)];
	DoublyLinkedList<Pair>::Iterator it;

	if (!Find(KEY, bucket, it)) {
		//�w�肳�ꂽ�L�[���i�[����Ă��Ȃ���ΏI��
		return false;
	}

	//�w�肳�ꂽ�L�[�̗v�f���폜
	bool result = bucket.Delete(it);

	if (result) {
		size--;
	}

	return result;
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Find(const Key& KEY, Value& destination)const
{
	const DoublyLinkedList<Pair>& BUCKET = buckets[GetBucketIndex(key)];
	DoublyLinkedList<Pair>::ConstIterator constIt;

	if (Find(KEY, BUCKET, constIt)) {
		destination = constIt->value;
		return true;
	}

	return false;
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline int HashTable<Key, Value, HashFunc, bucketSize>::GetBucketIndex(const Key& KEY) const
{
	return HashFunc(key) % bucketSize;
}

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Find(const Key& KEY, const DoublyLinkedList<Pair> BUCKET, typename DoublyLinkedList<Pair>::ConstIterator& destination) const
{
	const int BUCKET_SIZE = BUCKET.GetSize();
	destination = BUCKET.GetConstBegin();

	//�����L�[�̗v�f��T��
	for (int i = 0; i < BUCKET_SIZE; i++) {
		if (destination->key == KEY)//�R���X�g���N�^�Ŕ�r���Z�q���L���Ȃ��̂����f
		{
			return true;
		}
		destination++;
	}
	return false;
}
