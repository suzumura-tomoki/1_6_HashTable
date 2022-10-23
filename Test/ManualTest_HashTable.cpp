/**********************************************************************************//**
	@file           ManualTest_HashTable.cpp
	@brief          �蓮�e�X�g
*//***********************************************************************************/
#include "pch.h"
#include "Test_HashTable.h"
#include "ManualTest_HashTable.h"


/**********************************************************************************//**
	@brief		�s�K�؂ȃn�b�V���֐����e���v���[�g�����œn���ꂽ�ꍇ�̃N���X�̋������m�F���܂�
	@details	ID:�n�b�V���e�[�u��-0\n
				�R���p�C���G���[�ɂȂ�ΐ����ł�
*//***********************************************************************************/
TEST(TestHashTable, IrregularHashFunc) {
#ifdef IRREGULAR_HASH_FUNC
	void IrrgularFunc(const int& key);
	HashTable<int, int, IrrgularFunc, BUCKET_SIZE> table;
#else
	SUCCEED();
#endif
}

/**********************************************************************************//**
	@brief		�e�[�u�����R���X�g�̏ꍇ�̃f�[�^���̎擾�e�X�g
	@details	ID:�n�b�V���e�[�u��-12\n
				�R���p�C�����ʂ�Ɛ����ł�\n
*//***********************************************************************************/
TEST(TestHashTable, GetSizeWhenConst) {
#ifdef GET_SIZE_WHEN_CONST
	const HashTable<int, int, HashFunc, BUCKET_SIZE> table;
	EXPECT_EQ(0, table.GetSize());
#else
	SUCCEED();
#endif
}

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u�����R���X�g�̏ꍇ�̑}���e�X�g
	@details	ID:�n�b�V���e�[�u��-18\n
				�R���p�C���G���[�ɂȂ�ΐ����ł�\n
*//***********************************************************************************/
TEST(TestHashTable, InsertWhenConst) {
#ifdef INSERT_WHEN_CONST
	const HashTable<int, int, HashFunc, BUCKET_SIZE> table;
	table.Insert(0, 0);//�����ŃG���[
#else
	SUCCEED();
#endif
}

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u�����R���X�g�̏ꍇ�̍폜�e�X�g
	@details	ID:�n�b�V���e�[�u��-26\n
				�R���p�C���G���[�ɂȂ�ΐ����ł�\n
*//***********************************************************************************/
TEST(TestHashTable, EraseWhenConst) {
#ifdef ERASE_WHEN_CONST
	const HashTable<int, int, HashFunc, BUCKET_SIZE> table;
	table.Erase(0);//�����ŃG���[
#else
	SUCCEED();
#endif
}

/**********************************************************************************//**
	@brief		�n�b�V���e�[�u�����R���X�g�̏ꍇ�̌����e�X�g
	@details	ID:�n�b�V���e�[�u��-34\n
				�R���p�C�����ʂ�Ɛ����ł�\n
*//***********************************************************************************/
TEST(TestHashTable, FindWhenConst) {
#ifdef FIND_WHEN_CONST
	const HashTable<int, int, HashFunc, BUCKET_SIZE> table;
	int dest;
	table.Find(0, dest);
#else
	SUCCEED();
#endif
}