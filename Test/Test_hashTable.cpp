
/**********************************************************************************//**
	@file           Test_HashTable.cpp
	@brief          �n�b�V���e�[�u���̎����e�X�g���s���܂�
*//***********************************************************************************/

#include "pch.h"
#include"Test_HashTable.h"

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
TEST_F(TestHashTable, BehaviorTestDifferentHashFunc) {

	//�ЂƂڂ̃N���X�̋������m�F
	EXPECT_TRUE(table.Insert(0, 0));
	EXPECT_TRUE(table.Find(0));
	EXPECT_TRUE(table.Erase(0));


	//�Z�o���@�̈قȂ�n�b�V���֐���n�����N���X�̋������m�F
	HashTable<int, int, DifferentHashFunc, BUCKET_SIZE> tableB;
	EXPECT_TRUE(tableB.Insert(0, 0));
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
TEST_F(TestHashTable, GetSizeTestWhenEmpty) {

	EXPECT_EQ(0, table.GetSize());
}

/**********************************************************************************//**
	@brief		�v�f�����}��������̃f�[�^���̎擾�e�X�g
	@details	ID:�n�b�V���e�[�u��-3\n
				�߂�l��1�ł���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestAfterInsertOnce) {
	ASSERT_TRUE(table.Insert(0, 0));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		�v�f��}�����ē����L�[�ō폜������̃f�[�^���̎擾�e�X�g
	@details	ID:�n�b�V���e�[�u��-4\n
				�߂�l��0�ł���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestAfterInsertAndErase) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Erase(0));
	EXPECT_EQ(0, table.GetSize());
}

/**********************************************************************************//**
	@brief		���ɑ��݂���L�[�ŗv�f�̑}���������s������̃f�[�^���̎擾�e�X�g
	@details	ID:�n�b�V���e�[�u��-5\n
				�߂�l��1�ł���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestAfterInsertAlreadyUsedKey) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_FALSE(table.Insert(0, 0));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		�v�f�}�����āA�ʂ̃L�[�ō폜�����s������̃f�[�^���̎擾�e�X�g
	@details	ID:�n�b�V���e�[�u��-6\n
				�߂�l��1�ł���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestAfterEraseFailed) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_FALSE(table.Erase(1));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u������ł���ꍇ�ɁA�폜���s������̃f�[�^���̎擾�e�X�g
	@details	ID:�n�b�V���e�[�u��-7\n
				�߂�l��0�ł���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestAfterEraseWhenEmpty) {
	ASSERT_FALSE(table.Erase(0));
	EXPECT_EQ(0, table.GetSize());
}

/**********************************************************************************//**
	@brief		�v�f�Q�������Ń`�F�C���ɂȂ��Ă��Ȃ��ꍇ�̃f�[�^���̎擾�e�X�g
	@details	ID:�n�b�V���e�[�u��-8\n
				�߂�l��2�ł���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestWhenDataNotChained) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Insert(1, 1));
	EXPECT_EQ(2, table.GetSize());
}

/**********************************************************************************//**
	@brief		�v�f�Q�������Ń`�F�C���ɂȂ��Ă��Ȃ��ꍇ�Ɉ�����폜������̃f�[�^���̎擾�e�X�g
	@details	ID:�n�b�V���e�[�u��-9\n
				�߂�l��1�ł���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestAfterEraseWhenDataNotChained) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Insert(1, 1));
	ASSERT_TRUE(table.Erase(1));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		�v�f�Q�������Ń`�F�C���ɂȂ��Ă���ꍇ�̃f�[�^���̎擾�e�X�g
	@details	ID:�n�b�V���e�[�u��-10\n
				�߂�l��2�ł���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestWhenDataChained) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Insert(BUCKET_SIZE, BUCKET_SIZE));
	EXPECT_EQ(2, table.GetSize());
}

/**********************************************************************************//**
	@brief		�v�f�Q�������Ń`�F�C���ɂȂ��Ă���ꍇ�Ɉ�����폜������̃f�[�^���̎擾�e�X�g
	@details	ID:�n�b�V���e�[�u��-11\n
				�߂�l��1�ł���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestAfterEraseWhenDataChained) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Insert(BUCKET_SIZE, BUCKET_SIZE));
	ASSERT_TRUE(table.Erase(0));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u�����R���X�g�̏ꍇ�̃f�[�^���̎擾�e�X�g
	@details	ID:�n�b�V���e�[�u��-12\n
				�����e�X�g���s���܂���\n
*//***********************************************************************************/

#pragma endregion

#pragma region ================================= �f�[�^�̑}�� =====================================

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u������ł���ꍇ�̑}���e�X�g
	@details	ID:�n�b�V���e�[�u��-13\n
				�v�f���}������Ă���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, InsertWhenEmpty) {
	ASSERT_TRUE(table.Insert(0, 0));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		�����̗v�f���قȂ�L�[�ő}�������ꍇ�̑}���e�X�g
	@details	ID:�n�b�V���e�[�u��-14\n
				�v�f���}������Ă���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, InsertWhenDifferentKey) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Insert(1, 0));
	EXPECT_EQ(2, table.GetSize());
}

/**********************************************************************************//**
	@brief		�g�p�ς݂̃L�[�ő}�������ꍇ�̑}���e�X�g
	@details	ID:�n�b�V���e�[�u��-15\n
				�}���Ɏ��s����Ɛ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, InsertWhenUsedKey) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Insert(1, 0));
	ASSERT_FALSE(table.Insert(1, 0));
	EXPECT_EQ(2, table.GetSize());
}

/**********************************************************************************//**
	@brief		�g�p�ς݂̃L�[�ƃn�b�V���l�������ɂȂ�L�[�ő}�������ꍇ�̑}���e�X�g
	@details	ID:�n�b�V���e�[�u��-16\n
				�v�f���}������Ă���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, InsertWhenSameHash) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Insert(BUCKET_SIZE, BUCKET_SIZE));
	EXPECT_EQ(2, table.GetSize());
}

/**********************************************************************************//**
	@brief		��x�}�����A�폜������ēx�����L�[�ő}�������ꍇ�̑}���e�X�g
	@details	ID:�n�b�V���e�[�u��-17\n
				�v�f���}������Ă���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, InsertWhenErasedKey) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Erase(0));
	ASSERT_TRUE(table.Insert(0, 0));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u�����R���X�g�̏ꍇ�̑}���e�X�g
	@details	ID:�n�b�V���e�[�u��-18\n
				�����e�X�g���s���܂���\n
*//***********************************************************************************/

#pragma endregion

#pragma region ================================= �f�[�^�̍폜 =====================================

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u������ł���ꍇ�̍폜�e�X�g
	@details	ID:�n�b�V���e�[�u��-19\n
				�폜�Ɏ��s����Ɛ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, EraseWhenEmpty) {
	ASSERT_FALSE(table.Erase(0));
	EXPECT_EQ(0, table.GetSize());
}

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u���ɑ��݂���L�[�ō폜�����ꍇ�̍폜�e�X�g
	@details	ID:�n�b�V���e�[�u��-20\n
				�폜����Ă���Ɛ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, EraseWhenExistKey) {
	ASSERT_TRUE(table.Insert(0, 0));
	EXPECT_EQ(1, table.GetSize());
	ASSERT_TRUE(table.Erase(0));
	EXPECT_EQ(0, table.GetSize());
}

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u���ɑ��݂��Ȃ��L�[�ō폜�����ꍇ�̍폜�e�X�g
	@details	ID:�n�b�V���e�[�u��-21\n
				�폜�Ɏ��s����Ɛ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, EraseWhenNotExistKey) {
	ASSERT_TRUE(table.Insert(0, 0));
	EXPECT_EQ(1, table.GetSize());
	ASSERT_FALSE(table.Erase(1));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		�폜�����L�[�ōēx�폜�����ꍇ�̍폜�e�X�g
	@details	ID:�n�b�V���e�[�u��-22\n
				�폜�Ɏ��s����Ɛ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, EraseWhenErasedKey) {
	ASSERT_TRUE(table.Insert(0, 0));
	EXPECT_EQ(1, table.GetSize());
	ASSERT_TRUE(table.Erase(0));
	ASSERT_FALSE(table.Erase(0));
}

/**********************************************************************************//**
	@brief		�`�F�C���ɂȂ��Ă���v�f���폜�����ꍇ�̍폜�e�X�g
	@details	ID:�n�b�V���e�[�u��-23\n
				�w�肵���v�f���폜����Ă���Ɛ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, EraseWhenDataChains) {
	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}

	EXPECT_EQ(3, table.GetSize());

	//�`�F�C���̒������폜
	ASSERT_TRUE(table.Erase(BUCKET_SIZE));

	//�S�Ă��폜���Ďw�肵���v�f�̂ݍ폜����Ă��邱�Ƃ��m�F����
	ASSERT_TRUE(table.Erase(0));
	ASSERT_FALSE(table.Erase(BUCKET_SIZE));
	ASSERT_TRUE(table.Erase(2 * BUCKET_SIZE));
}

/**********************************************************************************//**
	@brief		�`�F�C���ɂȂ��Ă���v�f�ƃn�b�V���l���������݂��Ȃ��L�[���w�肵�č폜�����ꍇ�̍폜�e�X�g
	@details	ID:�n�b�V���e�[�u��-24\n
				�폜�Ɏ��s����Ɛ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, EraseWhenDataChainsUseNotExistKey) {
	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}

	ASSERT_FALSE(table.Erase(5 * BUCKET_SIZE));
}

/**********************************************************************************//**
	@brief		�`�F�C���ɂȂ��Ă���v�f�����ɍ폜�����ꍇ�̍폜�e�X�g
	@details	ID:�n�b�V���e�[�u��-25\n
				�S�č폜�ł���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, EraseAllWhenDataChains) {
	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}

	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Erase(i * BUCKET_SIZE));
	}
}

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u�����R���X�g�̏ꍇ�̍폜�e�X�g
	@details	ID:�n�b�V���e�[�u��-26\n
				�����e�X�g���s���܂���\n
*//***********************************************************************************/

#pragma endregion

#pragma region ================================= �f�[�^�̌��� =====================================

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u������ł���ꍇ�̌����e�X�g
	@details	ID:�n�b�V���e�[�u��-27\n
				�����Ɏ��s����Ɛ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, FindWhenEmpty) {
	int dest;
	ASSERT_FALSE(table.Find(0, dest));
}

/**********************************************************************************//**
	@brief		�����̗v�f������ꍇ�ɁA���݂���L�[�Ō��������ꍇ�̌����e�X�g
	@details	ID:�n�b�V���e�[�u��-28\n
				�w�肵���f�[�^���擾�ł���Ɛ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, FindWhenMultipleData) {

	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}
	int dest;
	ASSERT_TRUE(table.Find(0, dest));
	EXPECT_EQ(0, dest);
}

/**********************************************************************************//**
	@brief		�����̗v�f������ꍇ�ɁA���݂��Ȃ��L�[�Ō��������ꍇ�̌����e�X�g
	@details	ID:�n�b�V���e�[�u��-29\n
				�����Ɏ��s����Ɛ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, FindNotExistKeyWhenMultipleData) {

	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}
	int dest;
	ASSERT_FALSE(table.Find(5 * BUCKET_SIZE, dest));
}

/**********************************************************************************//**
	@brief		�����̗v�f������ꍇ�ɁA�����L�[��2�񌟍������ꍇ�̌����e�X�g
	@details	ID:�n�b�V���e�[�u��-30\n
				2�񓯂��f�[�^���擾�ł���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, FindTwiceSameKeyWhenMultipleData) {

	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}
	int dest;
	ASSERT_TRUE(table.Find(BUCKET_SIZE, dest));
	EXPECT_EQ(1, dest);

	dest = 0;
	ASSERT_TRUE(table.Find(BUCKET_SIZE, dest));
	EXPECT_EQ(1, dest);
}

/**********************************************************************************//**
	@brief		�폜���ꂽ�L�[�Ō��������ꍇ�̌����e�X�g
	@details	ID:�n�b�V���e�[�u��-31\n
				�����Ɏ��s����Ɛ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, FindErasedKey) {

	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Erase(0));

	int dest;
	ASSERT_FALSE(table.Find(0, dest));
}

/**********************************************************************************//**
	@brief		�`�F�C���ɂȂ��Ă���v�f�����������ꍇ�̌����e�X�g
	@details	ID:�n�b�V���e�[�u��-32\n
				�w�肵���f�[�^���擾�ł���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, FindWhenDataChains) {

	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}

	for (int i = 0; i < 3; i++) {
		int dest;
		ASSERT_TRUE(table.Find(i * BUCKET_SIZE, dest));
		EXPECT_EQ(i, dest);
	}
}

/**********************************************************************************//**
	@brief		�`�F�C���ɂȂ��Ă���v�f�̂����A1���폜�����ꍇ�̌����e�X�g
	@details	ID:�n�b�V���e�[�u��-33\n
				�폜�����f�[�^�ȊO�̎w�肵���f�[�^���擾�ł���ΐ����ł�\n
*//***********************************************************************************/
TEST_F(TestHashTable, FindAfterEraseOneOfChainedData) {

	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}

	//�`�F�C���̒������폜
	ASSERT_TRUE(table.Erase(BUCKET_SIZE));

	int dest;
	ASSERT_TRUE(table.Find(0, dest));
	EXPECT_EQ(0, dest);

	ASSERT_FALSE(table.Find(BUCKET_SIZE, dest));

	ASSERT_TRUE(table.Find(2 * BUCKET_SIZE, dest));
	EXPECT_EQ(2, dest);
}

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u�����R���X�g�̏ꍇ�̌����e�X�g
	@details	ID:�n�b�V���e�[�u��-34\n
				�����e�X�g���s���܂���\n
*//***********************************************************************************/

#pragma endregion