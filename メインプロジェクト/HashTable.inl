#pragma once
#include "HashTable.h"

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
HashTable<Key, Value, HashFunc, bucketSize>::HashTable()
	:buckets(), size()
{
	//��r���Z�q���L���Ȍ^������
	Key a{};
	//�G���[�ɂȂ�̂œr���o�߂��o���邽�߂ɃR�����g�A�E�g
	//static_assert(a == a, "key has not comparison operator");//�A�T�[�g���������邱�Ƃ͂Ȃ����R���p�C���G���[�ɂȂ�Ȃ����`�F�b�N����
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
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Insert(const Key& KEY, const Value& VALUE)
{
	//�����L�[���i�[����Ă���Ƒ}�����Ȃ�
	int dest;
	if (Find(KEY, dest)) {
		return false;
	}

	//�o�P�b�g�̌��ɑ}��
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

	//�w�肳�ꂽ�L�[�̗v�f������
	DoublyLinkedList<Pair>& bucket = buckets[GetBucketIndex(KEY)];
	DoublyLinkedList<Pair>::ConstIterator cit;

	if (!FindFromBucket(KEY, bucket, cit)) {
		//�w�肳�ꂽ�L�[���i�[����Ă��Ȃ���ΏI��
		return false;
	}

	//�w�肳�ꂽ�L�[�̗v�f���폜
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

	//�o�P�b�g����ł���ΏI��
	if (BUCKET_SIZE == 0) {
		return false;
	}

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
