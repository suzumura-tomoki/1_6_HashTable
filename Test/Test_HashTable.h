#pragma once
#include"..\���C���v���W�F�N�g\HashTable.h"

//=======================================
// �錾�E��`
//=======================================

/** @brief �o�P�b�g�̐�*/
#define BUCKET_SIZE 16

/**
 * @brief �n�b�V���֐�
 * @param[in] key �L�[
 * @return �n�b�V���l
 */
inline uint16_t HashFunc(const int& key) {
	return key % BUCKET_SIZE;
}

/**
 * @brief �e�X�g�P�[�XTestHashTableBehavior-DifferentHashFunc�p�̃n�b�V���֐�
 * @param[in] key �L�[
 * @return �n�b�V���l
 */
inline uint16_t DifferentHashFunc(const int& key) {
	return (key * key) % BUCKET_SIZE;
};

/**
 * @brief �e�X�g�t�B�N�X�`��\n
 *		  �e�e�X�g�ɋ��ʂ����ݒ���`���܂�
 */
class TestHashTable :public ::testing::Test
{
protected:
	/** @brief �J�n����*/
	virtual void SetUp() {/*�������Ȃ�*/ }

	/** @brief �I������*/
	virtual void TearDown() {/*�������Ȃ�*/ }

	HashTable<int, int, HashFunc, BUCKET_SIZE> table;
};