
/**********************************************************************************//**
	@file           Test_HashTable.cpp
	@brief          �n�b�V���e�[�u���̎����e�X�g���s���܂�
*//***********************************************************************************/

#include "pch.h"
#include"..\���C���v���W�F�N�g\HashTable.h"

//=======================================
// �錾�E��`
//=======================================

/** @brief �o�P�b�g�̐�*/
const int BUCKET_SIZE = 16;

/**
 * @brief �n�b�V���֐�
 * @param[in]	  �e�e�X�g�ɋ��ʂ����ݒ���`���܂�
 */
int& HashFunc(int& key) {
	return key % BUCKET_SIZE;
}

/** @brief ID:�n�b�V���e�[�u��-1 �p�̃n�b�V���֐�*/
int& DifferentHashFunc(int& key) { 
	return (key * key)% BUCKET_SIZE;
};



/**
 * @brief �e�X�g�t�B�N�X�`��\n
 *		  �e�e�X�g�ɋ��ʂ����ݒ���`���܂�
 */
class TestHashTable:public ::testing::Test
{
protected:
	void SetUp() {

	}
	HashTable<int, int, HashFunc, BUCKET_SIZE> table;
};

TestHashTable:public ::testing::Test::TestHashTable:public ::testing::Test()
{
}

TestHashTable:public ::testing::Test::~TestHashTable:public ::testing::Test()
{
}

#pragma region ================================= �N���X�̋��� =====================================

/**********************************************************************************//**
	@brief		�s�K�؂ȃn�b�V���֐����e���v���[�g�����œn���ꂽ�ꍇ�̃N���X�̋������m�F���܂�
	@details	ID:�n�b�V���e�[�u��-0\n
				�����e�X�g���s���܂���
*//***********************************************************************************/


/**********************************************************************************//**
	@brief		�Z�o���@�̈قȂ�K�؂ȃn�b�V���֐���n�����Ƃ��̂��ꂼ��̃N���X�̋������m�F���܂�
	@details	ID:�n�b�V���e�[�u��-1\n
				�}���A�����A�폜���s���A�S�Ă̖߂�l��TRUE�ɂł���ΐ����ł�\n
*//***********************************************************************************/
TEST(TestHashTableBehavior, DifferentHashFunc) {

	//�ЂƂڂ̃N���X�̋������m�F
	EXPECT_TRUE(table.Insert(0, 0));
	EXPECT_TRUE(table.Find(0));
	EXPECT_TRUE(table.Erase(0));
	

	//�Z�o���@�̈قȂ�n�b�V���֐���n�����N���X�̋������m�F

	

	HashTable<int, int, DifferentHashFunc, BUCKET_SIZE> tableB;
	EXPECT_TRUE(tableB.Insert(0,0));
	EXPECT_TRUE(tableB.Find(0));
	EXPECT_TRUE(tableB.Erase(0));
	
}

#pragma endregion

#pragma region ================================= �f�[�^���̎擾 =====================================

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u������ł���ꍇ�̃f�[�^���̎擾�e�X�g
	@details	ID:�n�b�V���e�[�u��-2\n
				�߂�l��0�ł���ΐ����ł�\n
*//***********************************************************************************/
TEST(TestHashTableGetSize, WhenEmpty) {



	//�ЂƂڂ̃N���X�̋������m�F
	EXPECT_TRUE(table.Insert(0, 0));
	EXPECT_TRUE(table.Find(0));
	EXPECT_TRUE(table.Erase(0));


}

#pragma endregion