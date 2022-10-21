
/**********************************************************************************//**
	@file           ManualTest_Stack.cpp
	@brief          �X�^�b�N�̎蓮�e�X�g���s���܂�
*//***********************************************************************************/

#include "pch.h"
#include"ManualTest_Stack.h"
#include"..\���C���v���W�F�N�g\Stack.h"

/**********************************************************************************//**
	@brief		�X�^�b�N���R���e�X�g�̏ꍇ�̗v�f���̎擾�e�X�g
	@details	ID:�X�^�b�N-7\n
				�R���e�X�g�̃X�^�b�N�ŗv�f���̎擾���s�����ꍇ�̖߂�l���m�F���Ă��܂��B\n
				�R���p�C���G���[�ƂȂ�Ȃ���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestStackGetSize, WhenConst) {
#ifdef STACK_GET_SIZE_WHEN_CONST
	const Stack<int> stack;

	EXPECT_EQ(0, stack.GetSize());
#else
	SUCCEED();
#endif
}

/**********************************************************************************//**
	@brief		�X�^�b�N���R���e�X�g�̏ꍇ�̃v�b�V���e�X�g
	@details	ID:�X�^�b�N-10\n
				�X�^�b�N���R���e�X�g�ł���ꍇ�Ƀv�b�V�����s�����ۂ̋������m�F���Ă��܂��B\n
				�R���p�C���G���[�ɂȂ�ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestStackPush, WhenConst) {

	//#define PUSH_WHEN_CONST

#ifdef PUSH_WHEN_CONST

	const Stack<int> stack;
	stack.Push(0);//�����ŃG���[

#else
	SUCCEED();
#endif 
}

/**********************************************************************************//**
	@brief		�X�^�b�N���R���e�X�g�̏ꍇ�̃|�b�v�e�X�g
	@details	ID:�X�^�b�N-14\n
				�X�^�b�N���R���e�X�g�ł���ꍇ�Ƀ|�b�v���s�����ۂ̋������m�F���Ă��܂��B\n
				�R���p�C���G���[�ɂȂ�ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestStackPop, WhenConst) {

	//#define POP_WHEN_CONST

#ifdef POP_WHEN_CONST

	const Stack<int> stack;
	int n;

	stack.Pop(n);//�����ŃG���[

#else
	SUCCEED();
#endif 
}