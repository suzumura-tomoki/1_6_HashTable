
/**********************************************************************************//**
	@file           ManualTest_Queue.cpp
	@brief          �L���[�̎蓮�e�X�g���s���܂�
*//***********************************************************************************/

#include "pch.h"
#include"ManualTest_Queue.h"
#include"..\���C���v���W�F�N�g\Queue.h"

/**********************************************************************************//**
	@brief		�L���[���R���e�X�g�̏ꍇ�̗v�f���̎擾�e�X�g
	@details	ID:�L���[-7\n
				�R���e�X�g�̃L���[�ŗv�f���̎擾���s�����ꍇ�̖߂�l���m�F���Ă��܂��B\n
				�R���p�C���G���[�ƂȂ�Ȃ���ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestQueueGetSize, WhenConst) {
#ifdef TEST_QUEUE_GET_SIZE_WHEN_CONST
	const Queue<int> queue;
	EXPECT_EQ(0, queue.GetSize());
#else
	SUCCEED();
#endif 
}

/**********************************************************************************//**
	@brief		�L���[���R���e�X�g�̏ꍇ�̃v�b�V���e�X�g
	@details	ID:�L���[-10\n
				�L���[���R���e�X�g�ł���ꍇ�Ƀv�b�V�����s�����ۂ̋������m�F���Ă��܂��B\n
				�R���p�C���G���[�ɂȂ�ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestQueuePush, WhenConst) {

	//#define PUSH_WHEN_CONST

#ifdef PUSH_WHEN_CONST

	const Queue<int> queue;
	queue.Push(0);//�����ŃG���[

#else
	SUCCEED();
#endif // PUSH_WHEN_CONST
}

/**********************************************************************************//**
	@brief		�L���[���R���e�X�g�̏ꍇ�̃|�b�v�e�X�g
	@details	ID:�L���[-14\n
				�L���[���R���e�X�g�ł���ꍇ�Ƀ|�b�v���s�����ۂ̋������m�F���Ă��܂��B\n
				�R���p�C���G���[�ɂȂ�ΐ����ł��B\n
*//***********************************************************************************/
TEST(TestQueuePop, WhenConst) {

	//#define POP_WHEN_CONST

#ifdef POP_WHEN_CONST

	const Queue<int> queue;
	int n;

	queue.Pop(n);//�����ŃG���[

#else
	SUCCEED();
#endif // POP_WHEN_CONST
}