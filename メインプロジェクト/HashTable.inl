#pragma once
#include "HashTable.h"

template<typename Key, typename Value, uint16_t HashFunc(const Key&), int bucketSize>
HashTable<Key, Value, HashFunc, bucketSize>::HashTable()
	:buckets(),size()
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
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Insert(const Key& key, Value value)
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
inline bool HashTable<Key, Value, HashFunc, bucketSize>::Erase(const Key& key)
{
	//�w�肳�ꂽ�L�[���i�[����Ă��Ȃ���ΏI��
	int dest;
	if (!Find(key, dest)) {
		return false;
	}

	//�w�肳�ꂽ�L�[�̗v�f���폜
	DoublyLinkedList<Pair>& bucket = buckets[GetBucketIndex(key)];
	const int&& BUCKET_SIZE = bucket.GetSize();
	DoublyLinkedList<Pair>::Iterator it = bucket.GetBegin();

	//�����L�[�̗v�f��T��
	for (int i = 0; i < BUCKET_SIZE; i++) {
		if (it->key == key)//�R���X�g���N�^�Ŕ�r���Z�q���L���Ȃ��̂����f
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

	//�����L�[�̗v�f��T��
	for (int i = 0; i < BUCKET_SIZE; i++) {
		if (it->key == key)//�R���X�g���N�^�Ŕ�r���Z�q���L���Ȃ��̂����f
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
	//�����L�[�̗v�f��T��
	for (int i = 0; i < BUCKET_SIZE; i++) {
		if (it->key == key)//�R���X�g���N�^�Ŕ�r���Z�q���L���Ȃ��̂����f
		{
			destination = it->value;
			return true;
		}
		it++;
	}
	return false;
}
