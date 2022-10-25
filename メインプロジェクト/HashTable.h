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

	//TODO �f�B�[�v�R�s�[�ɂ��Ē��ׂ�
	/** @brief �f�t�H���g�R�s�[�R���X�g���N�^ */
	HashTable(const HashTable&) = delete;//�f�B�[�v�R�s�[�ł��ǂ�

	/** @brief �f�X�g���N�^ */
	virtual ~HashTable();

	/** 
	 *@brief �f�[�^�����擾���܂�
	 *@return �f�[�^�̐�
	 */
	int GetSize()const;

	/**
	 * @brief �w�肵���L�[�̏ꏊ�Ƀf�[�^��}�����܂�
	 * @param[in] KEY �L�[�@�g�p�ς݂̃L�[���Ƒ}�����s���܂���
	 * @param[in] value �f�[�^
	 * @return �g�p�ς݂̃L�[�ő}������Ƒ}���Ɏ��s����false�ƂȂ�܂�
	 */
	bool Insert(const Key& KEY, const Value& VALUE);

	/**
	 * @brief �f�[�^���폜���܂�
	 * @param[in] KEY �i�[�ꏊ�������L�[
	 * @return �L�[�ƈ�v����f�[�^��������Ȃ��ƍ폜�Ɏ��s����false�ƂȂ�܂�
	 */
	bool Erase(const Key& KEY);

	/**
	 * @brief �f�[�^���������܂�
	 * @param[in] KEY �i�[�ꏊ�������L�[
	 * @param[out] destination ���������f�[�^�̃R�s�[��
	 * @return �L�[�ƈ�v����f�[�^��������Ȃ��ƌ����Ɏ��s����false�ƂȂ�܂�
	 */
	bool Find(const Key& KEY, Value& destination)const;

private:

	/** @brief �L�[�ƒl�̃y�A */
	struct Pair
	{
		Key key;
		Value value;
	};

	/**
	 * @brief �i�[����o�P�b�g�̔ԍ����擾���܂�
	 * @param[in] KEY �i�[�ꏊ�������L�[
	 * @return �i�[����o�P�b�g�̔ԍ�
	 */
	int GetBucketIndex(const Key& KEY)const;

	/** 
	 * @brief �o�P�b�g����L�[����v����v�f�̃C�e���[�^���擾���܂� 
	 * @param[in] KEY �i�[�ꏊ�������L�[
	 * @param[in] BUCKET �T������o�P�b�g
	 * @param[out] destination ���������v�f�̃C�e���[�^���i�[���܂��B�����Ɏ��s����ƃ_�~�[�m�[�h�������܂��B
	 * @return �L�[�ƈ�v����f�[�^��������Ȃ��ƌ����Ɏ��s����false�ƂȂ�܂�
	 */
	bool FindFromBucket(const Key& KEY, const DoublyLinkedList<Pair>& BUCKET, typename DoublyLinkedList<Pair>::ConstIterator& destination)const;

	/** @brief �o�P�b�g�̔z�� */
	std::array<DoublyLinkedList<Pair>, bucketSize> buckets;

	uint16_t size;
};

#include"HashTable.inl"
