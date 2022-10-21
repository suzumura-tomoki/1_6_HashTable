/**********************************************************************************//**
	@file           ManualTest_HashTable.cpp
	@brief          �蓮�e�X�g
*//***********************************************************************************/
#include "pch.h"
#include "ManualTest_HashTable.h"
#include "../���C���v���W�F�N�g/HashTable.h"

//=======================================
// �錾�E��`
//=======================================
const int BUCKET_SIZE = 16;

const int& HashFunc(const int& key) {
	return key % BUCKET_SIZE;
}

HashTable<int, int, HashFunc, BUCKET_SIZE> table;

/**********************************************************************************//**
	@brief		�s�K�؂ȃn�b�V���֐����e���v���[�g�����œn���ꂽ�ꍇ�̃N���X�̋������m�F���܂�
	@details	ID:�n�b�V���e�[�u��-0\n
				�R���p�C���G���[�ɂȂ�ΐ����ł�
*//***********************************************************************************/
TEST(TestHashTableBehavior, IrregularHashFunc) {
#ifdef IRREGULAR_HASH_FUNC
	void IrrgularFunc(const int& key);
	HashTable<int, int, IrrgularFunc, BUCKET_SIZE> table;
#else
	SUCCEED();
#endif
}