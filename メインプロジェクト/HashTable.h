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
 * @tparam bucketSize �o�P�b�g�̐��@�f�t�H���g�͂P�U
 */
template<
	typename Key,
	typename Value,
	const int& HashFunc(const Key&),
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

	//TODO @return�Ȃǂ̓��e���ڂ�������
	/**
	 * @brief �f�[�^��}�����܂�
	 * @param[in] key �L�[
	 * @param[in] value �f�[�^
	 * @return ����
	 */
	bool Insert(Key key, Value value);

	//TODO @return�Ȃǂ̓��e���ڂ�������
	/**
	 * @brief �f�[�^���폜���܂�
	 * @param[in] key �L�[
	 * @return ���ہ@�L�[�ƈ�v����f�[�^��������Ȃ��ƍ폜�Ɏ��s����false��Ԃ��܂�\n
	 */
	bool Erase(Key key);

	//TODO @return�Ȃǂ̓��e���ڂ�������
	/**
	 * @brief �f�[�^���������܂�
	 * @param[in] key �L�[
	 * @return ����
	 */
	bool Find(Key key);

private:

	/** @brief �L�[�ƒl�̃y�A */
	struct Pair
	{
		Key key;
		Value value;
	};

	/** @brief �o�P�b�g�̔z�� */
	std::array<DoublyLinkedList<Pair>, bucketSize> buckets;
};

#include"HashTable.inl"
