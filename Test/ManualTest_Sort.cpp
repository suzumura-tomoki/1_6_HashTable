/**********************************************************************************//**
	@file           ManualTest_Sort.cpp
	@brief          �蓮�e�X�g
*//***********************************************************************************/
#include"ManualTest_Sort.h"
#include "pch.h"
#include "../���C���v���W�F�N�g/DoublyLinkedList.h"
#include "../���C���v���W�F�N�g/ResultData.h"

/**********************************************************************************//**
			@brief		�L�[���s�K�؂ȏꍇ�̃\�[�g�@�\�̃e�X�g
			@details	ID:���X�g-�N�C�b�N�\�[�g-7\n
						�L�[�̌^���e���v���[�g�����ƈ����ňقȂ�ꍇ�̃e�X�g
						�R���p�C���G���[�ƂȂ�ΐ����ł�\n
*//***********************************************************************************/
TEST(SortTest, TestKeyIsIrregular) {
	//#define SORT_TEST_KEY_IS_IRREGULAR
#ifdef SORT_TEST_KEY_IS_IRREGULAR
	DoublyLinkedList<ResultData> list;

	//�L�[�̌^���e���v���[�g�����ƈ����ňقȂ�
	list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetName);
#else
	SUCCEED();
#endif
}

/**********************************************************************************//**
			@brief		���X�g��const�̏ꍇ�̃\�[�g�@�\�̃e�X�g
			@details	ID:���X�g-�N�C�b�N�\�[�g-8\n
						�R���p�C���G���[�ƂȂ�ΐ����ł�\n
*//***********************************************************************************/
TEST(SortTest, TestWhenConstList) {
	//#define SORT_CONST_LIST
#ifdef SORT_CONST_LIST
	const DoublyLinkedList<ResultData> list;

	list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetScore);
#else
	SUCCEED();
#endif
}