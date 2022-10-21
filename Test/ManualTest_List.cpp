/**********************************************************************************//**
	@file           ManualTest_List.cpp
	@brief          �蓮�e�X�g
*//***********************************************************************************/


//--------------------------------------------------------------------------------
// �t�@�C���ˑ��֌W
//--------------------------------------------------------------------------------
#include "pch.h"
#include"ManualTest_List.h"

// �e�X�g�Ώۂ̃w�b�_�t�@�C��
#include "../���C���v���W�F�N�g/DoublyLinkedList.h"
#include "../���C���v���W�F�N�g/ResultData.h"

namespace ex01_DataStructure
{
	namespace chapter2
	{
		//--------------------------------------------------------------------------------
		// �R���p�C���֘A�蓮�e�X�g
		//--------------------------------------------------------------------------------
		/**********************************************************************************//**
			@brief		�f�[�^���̎擾�@�\�ɂ��āAconst�̃��\�b�h�ł��邩�̃e�X�g
			@details	ID:���X�g-8(�蓮)\n
						�f�[�^���̎擾�@�\�̃e�X�g�ł��B\n
						const�̃��\�b�h�ł��邩���m�F���Ă��܂��B\n
						�R���p�C�����ʂ�ΐ����ł��B\n
						TT_TEST_GET_DATA_NUM_IS_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
		*//***********************************************************************************/
		TEST(ListManualTest, TestGetDataNumWhenConst)
		{
#if defined TT_TEST_GET_DATA_NUM_WHEN_CONST
			const DoublyLinkedList<ResultData> list;
			EXPECT_EQ(0, list.GetSize());
#endif //TT_TEST_GET_DATA_NUM_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		���X�g�����̃f�[�^�ǉ��ɂ��āA��const���ۏႳ��Ă��邩�̃e�X�g
			@details	ID:���X�g-15(�蓮)\n
						���X�g�����̃f�[�^�ǉ��e�X�g�ł��B\n
						��const���ۏႳ��Ă��邩���m�F���Ă��܂��B\n
						�R���p�C���G���[�ɂȂ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(ListManualTest, TestInsertWhenConst)
		{
#if defined TT_TEST_INSERT_WHEN_CONST
			const DoublyLinkedList<ResultData> list;
			DoublyLinkedList<ResultData>::ConstIterator it = list.GetConstBegin();
			list.Insert(it, ResultData());//�����ŃG���[
#endif //TT_TEST_INSERT_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		�f�[�^�̍폜�@�\�ɂ��Ĕ�const�̃��\�b�h�ł��邩�̃e�X�g
			@details	ID:���X�g-22 (�蓮)\n
						���X�g�̗v�f�폜�e�X�g�ł��B\n
						const�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ邩���m�F���Ă��܂��B\n
						�R���p�C���G���[�ɂȂ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(ListManualTest, TestDeleteWhenConst)
		{
#if defined TT_TEST_DELETE_WHEN_CONST
			const DoublyLinkedList<ResultData> list;
			DoublyLinkedList<ResultData>::ConstIterator it = list.GetConstBegin();
			list.Delete(it);//�����ŃG���[
#endif //TT_TEST_DELETE_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		�擪�C�e���[�^�̎擾�@�\�ɂ��Ĕ�const�̃��\�b�h�ł��邩�̃e�X�g
			@details	ID:���X�g-28 (�蓮)\n
						�擪�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
						const�̃��X�g����Ăяo�����ۂ̋������m�F���Ă��܂��B\n
						�R���p�C���G���[�ɂȂ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(ListManualTest, TestGetBeginWhenConst)
		{
#if defined TT_TEST_GET_BEGIN_WHEN_CONST
			const DoublyLinkedList<ResultData> list;
			list.GetBegin();//�����ŃG���[
#endif //TT_TEST_GET_BEGIN_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		�擪�R���X�g�C�e���[�^�̎擾�@�\�@�\�ɂ���const�̃��\�b�h�ł��邩�̃e�X�g
			@details	ID:���X�g-34 (�蓮)\n
						�擪�R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
						const�̃��X�g����Ăяo�����ۂ̋������m�F���Ă��܂��B\n
						�R���p�C�����ʂ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(ListManualTest, TestGetConstBeginWhenConst)
		{
#if defined TT_TEST_GET_CONST_BEGIN_WHEN_CONST
			const DoublyLinkedList<ResultData> list;
			list.GetConstBegin();
#endif //TT_TEST_GET_CONST_BEGIN_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		�����C�e���[�^�̎擾�@�\�ɂ��Ĕ�const�̃��\�b�h�ł��邩�̃e�X�g
			@details	ID:���X�g-40 (�蓮)\n
						�����C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
						const�̃��X�g����Ăяo�����ۂ̋������m�F���Ă��܂��B\n
						�R���p�C���G���[�ɂȂ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(ListManualTest, TestGetEndWhenConst)
		{
#if defined TT_TEST_GET_END_WHEN_CONST
			const DoublyLinkedList<ResultData> list;
			list.GetEnd();
#endif //TT_TEST_GET_END_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		�����R���X�g�C�e���[�^�̎擾�@�\�ɂ��Ĕ�const�̃��\�b�h�ł��邩�̃e�X�g
			@details	ID:���X�g-46 (�蓮)\n
						�����R���X�g�C�e���[�^�̎擾�@�\�̃e�X�g�ł��B\n
						const�̃��X�g����Ăяo�����ۂ̋������m�F���Ă��܂��B\n
						�R���p�C�����ʂ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(ListManualTest, TestGetConstEndWhenConst)
		{
#if defined TT_TEST_GET_CONST_END_WHEN_CONST
			const DoublyLinkedList<ResultData> list;
			list.GetConstEnd();
#endif //TT_TEST_GET_END_WHEN_CONST
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		�R���X�g�C�e���[�^����擾�����v�f�ɑ΂��āA�l���������ۂ̋����e�X�g
			@details	ID:�C�e���[�^-2 (�蓮)\n
						�R���X�g�C�e���[�^�̗v�f�擾�@�\�̃e�X�g�ł��B\n
						�R���X�g�C�e���[�^����擾�����v�f�ɑ΂��āA�l���������ۂ̋������m�F���Ă��܂��B\n
						�R���p�C���G���[�ɂȂ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(ListManualTest, ConstIteratorGetDataAndAssignment)
		{
#if defined TT_TEST_CONST_ITERATOR_DATA_ASSIGNMENT
			DoublyLinkedList<ResultData> list;
			DoublyLinkedList<ResultData>::ConstIterator cit = list.GetConstBegin();
			list.Insert(cit, ResultData());
			cit->name = "name";
#endif //TT_TEST_CONST_ITERATOR_DATA_ASSIGNMENT
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		ConstIterator<ResultData>����AIterator<ResultData>�փR�s�[���s�����ۂ̋����e�X�g
			@details	ID:�C�e���[�^-17 (�蓮)\n
						�C�e���[�^�̃R�s�[�@�\�̃e�X�g�ł��B\n
						ConstIterator<ResultData>����AIterator<ResultData>�փR�s�[���s�����ۂ̋������m�F���Ă��܂��B\n
						�R���p�C���G���[�ɂȂ�Ɛ����ł��B\n
		*//***********************************************************************************/
		TEST(ListManualTest, CopyConstIteratorToIterator)
		{
#if defined TT_TEST_CONST_ITERATOR_COPY_TO_ITERATOR
			DoublyLinkedList<ResultData>::ConstIterator cit;
			DoublyLinkedList<ResultData>::Iterator it = cit;
#endif //TT_TEST_CONST_ITERATOR_COPY_TO_ITERATOR
			SUCCEED();
		}

		/**********************************************************************************//**
			@brief		Iterator<ResultData>��ConstIterator<ResultData>���������ۂ̋����e�X�g
			@details	ID:�C�e���[�^-19 (�蓮)\n
						�C�e���[�^�̑���̃e�X�g�ł��B\n
						Iterator<ResultData>��ConstIterator<ResultData>���������ۂ̋������m�F���Ă��܂��B\n
						�R���p�C���G���[�ƂȂ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(ListManualTest, AssignmentConstIteratorToIterator)
		{
#if defined TT_TEST_ASSIGNMENT_CONST_ITERATOR_TO_ITERATOR
			DoublyLinkedList<ResultData>::ConstIterator cit;
			DoublyLinkedList<ResultData>::Iterator it;
			it = cit;
#endif //TT_TEST_ASSIGNMENT_CONST_ITERATOR_TO_ITERATOR
			SUCCEED();
		}

	}	// chapter2
}	//	ex01_DataStructure
