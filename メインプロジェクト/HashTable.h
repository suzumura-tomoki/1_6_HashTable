#pragma once
#include"DoublyLinkedList.h"

/**
 * @brief �R���e�i�N���X\n
 *		  �i�[�ꏊ���n�b�V���l�ɂ���ĊǗ����܂�\n
 *		  �L�[�ɂ�郉���_���A�N�Z�X���\�ł�\n
 *		  �n�b�V���l���Փ˂���ƃ`�F�C���@��p���Ċi�[���܂�
 * @tparam Key �L�[�̌^
 * @tparam Value �i�[����l�̌^
 * @tparam HashFunc �n�b�V���֐�
 * @tparam bucketSize �o�P�b�g�̐��@�f�t�H���g�͂T
 */
template<
	typename Key,
	typename Value,
	const int& HashFunc(const Key&),
	int bucketSize = 5
>
class HashTable
{
public:
	/** @brief �R���X�g���N�^ */
	HashTable();

	/** @brief �f�t�H���g�R�s�[�R���X�g���N�^ */
	HashTable(const HashTable&) = default;

	/** @brief �f�X�g���N�^ */
	~HashTable();

private:

	/** @brief �L�[�ƒl�̃y�A */
	struct Pair
	{
		Key key;
		Value Data;
	};


	DoublyLinkedList<Pair> bucket[bucketSize];
};

#include"HashTable.inl"
