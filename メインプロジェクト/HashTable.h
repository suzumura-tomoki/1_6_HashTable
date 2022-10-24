#pragma once
#include"DoublyLinkedList.h"
#include<array>

/**
 * @brief �R���e�i�N���X\n
 *		  �i�[�ꏊ���n�b�V���l�ɂ���ĊǗ����܂�\n
 *		  �L�[�ɂ�郉���_���A�N�Z�X���\�ł�\n
 *		  �n�b�V���l���Փ˂���ƃ`�F�C���@��p���Ċi�[���܂�
 * @tparam Key �L�[�̌^ ��r���Z�q���L���Ȃ���
 * @tparam Value �i�[����l�̌^
 * @tparam HashFunc �n�b�V���֐�
 * @tparam bucketSize �o�P�b�g�̐��@�f�t�H���g�͂P�U
 */
template<
	typename Key,
	typename Value,
	uint16_t HashFunc(const Key&),
	int bucketSize = 16
>
class HashTable
{
public:
	/** @brief �R���X�g���N�^ */
	HashTable();

	/** @brief �f�t�H���g�R�s�[�R���X�g���N�^ */
	HashTable(const HashTable&) = default;

	/** @brief �f�X�g���N�^ */
	virtual ~HashTable();

	/** 
	 *@brief �f�[�^�����擾���܂�
	 *@return �f�[�^�̐�
	 */
	int GetSize()const;

	/**
	 * @brief �w�肵���L�[�̏ꏊ�Ƀf�[�^��}�����܂�
	 * @param[in] key �L�[�@�g�p�ς݂̃L�[���Ƒ}�����s���܂���
	 * @param[in] value �f�[�^
	 * @return �g�p�ς݂̃L�[�ő}������Ƒ}���Ɏ��s����false�ƂȂ�܂�
	 */
	bool Insert(Key key, Value value);

	/**
	 * @brief �f�[�^���폜���܂�
	 * @param[in] key �i�[�ꏊ�������L�[
	 * @return �L�[�ƈ�v����f�[�^��������Ȃ��ƍ폜�Ɏ��s����false�ƂȂ�܂�
	 */
	bool Erase(Key key);

	/**
	 * @brief �f�[�^���������܂�
	 * @param[in] key �i�[�ꏊ�������L�[
	 * @param[out] destination ���������f�[�^�̃R�s�[��
	 * @return �L�[�ƈ�v����f�[�^��������Ȃ��ƌ����Ɏ��s����false�ƂȂ�܂�
	 */
	bool Find(Key key, Value& destination)const;

private:

	/** @brief �L�[�ƒl�̃y�A */
	struct Pair
	{
		Key key;
		Value value;
	};

	/** @brief �i�[����o�P�b�g�̓Y�������擾���܂� */
	const int& GetBucketIndex(Key& key)const;

	/** @brief �o�P�b�g�̔z�� */
	std::array<DoublyLinkedList<Pair>, bucketSize> buckets;

	uint16_t size;
};

#include"HashTable.inl"
