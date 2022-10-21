/**********************************************************************************//**
	@file           Test_Sort.cpp
	@brief          �����e�X�g
*//***********************************************************************************/

//--------------------------------------------------------------------------------
// �t�@�C���ˑ��֌W
//--------------------------------------------------------------------------------
#include "pch.h"
#include "../���C���v���W�F�N�g/DoublyLinkedList.h"
#include "../���C���v���W�F�N�g/ResultData.h"

namespace ex01_DataStructure
{
	namespace chapter2
	{
		//=================================== �O���[�o���ϐ� ===================================

		/**
		 * @brief ���уf�[�^����X�R�A�����o���֐��I�u�W�F�N�g
		 * @param[in] data ���X�g�Ɋi�[���Ă���f�[�^
		 * @return �X�R�A
		 */
		auto fpGetScore = [](const ResultData& data) ->const int&{return data.score;};

		/**
		 * @brief ���уf�[�^���疼�O�����o���֐��I�u�W�F�N�g
		 * @param[in] data ���X�g�Ɋi�[���Ă���f�[�^
		 * @return ���O
		 */
		auto fpGetName = [](const ResultData& data) ->const std::string& {return data.name; };


		//=================================== ���X�g�̃\�[�g ===================================

		/**********************************************************************************//**
			@brief		���X�g����ł���ꍇ�̃\�[�g�@�\�̃e�X�g
			@details	ID:���X�g-�N�C�b�N�\�[�g-0\n
						�����N����Ȃ���ΐ����ł�\n
		*//***********************************************************************************/
		TEST(SortTest, TestWhenEmpty) {
			DoublyLinkedList<ResultData> list;
			
			list.Sort<std::string>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetName);
			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		���X�g�ɗv�f��1����ꍇ�̃\�[�g�@�\�̃e�X�g
			@details	ID:���X�g-�N�C�b�N�\�[�g-1\n
						�����N����Ȃ���ΐ����ł�\n
		*//***********************************************************************************/
		TEST(SortTest, TestWhenOneData) {
			DoublyLinkedList<ResultData> list;

			//�v�f��1�p�ӂ���
			ResultData data;
			data.name = "test";
			list.Insert(list.GetBegin(), data);

			
			list.Sort<std::string>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetName);

			EXPECT_EQ(1, list.GetSize());
			EXPECT_EQ(data.name, list.GetBegin()->name);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɗv�f����������ꍇ�̃\�[�g�@�\�̃e�X�g
			@details	ID:���X�g-�N�C�b�N�\�[�g-2\n
						�w��ʂ�Ƀ\�[�g����Ă���ΐ����ł�\n
		*//***********************************************************************************/
		TEST(SortTest, TestWhenMultipleData) {
			DoublyLinkedList<ResultData> list;

			//�v�f��2�p�ӂ���
			ResultData data1 = { 10, "a" };
			ResultData data2 = { 20, "b" };

			DoublyLinkedList<ResultData>::Iterator it = list.GetBegin();
			list.Insert(it, data1);
			list.Insert(it, data2);

			//�����@�X�R�A
			list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetScore);
			EXPECT_EQ(data1.score, it->score);
			EXPECT_EQ(data2.score, (it+1)->score);

			//�����@���O
			list.Sort<std::string>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetName);
			EXPECT_EQ(data1.name, it->name);
			EXPECT_EQ(data2.name, (it + 1)->name);

			//�~���@�X�R�A
			list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::DESCENDING_ORDER, fpGetScore);
			EXPECT_EQ(data2.score, it->score);
			EXPECT_EQ(data1.score, (it + 1)->score);

			//�~���@���O
			list.Sort<std::string>(DoublyLinkedList<ResultData>::SortOrder::DESCENDING_ORDER, fpGetName);
			EXPECT_EQ(data2.name, it->name);
			EXPECT_EQ(data1.name, (it + 1)->name);
		}

		/**********************************************************************************//**
			@brief		���X�g�ɓ����L�[�����v�f������ꍇ�̃\�[�g�@�\�̃e�X�g
			@details	ID:���X�g-�N�C�b�N�\�[�g-3\n
						�����L�[�����v�f�������Ďw��ʂ�Ƀ\�[�g����Ă���ΐ����ł�\n
		*//***********************************************************************************/
		TEST(SortTest, TestWhenSameData) {
			DoublyLinkedList<ResultData> list;

			//�v�f��3�p�ӂ���
			ResultData data1 = { 10, "a" };
			ResultData data2 = { 20, "b" };

			DoublyLinkedList<ResultData>::Iterator it = list.GetBegin();
			list.Insert(it, data1);//����
			list.Insert(it, data1);//����
			list.Insert(it, data2);

			//��r�p�̔z��
			//�����ɂȂ��Ă���z��
			ResultData asArray[3] = { data1, data1, data2 };
			//�~���ɂȂ��Ă���z��
			ResultData desArray[3] = { data2, data1, data1 };

			//�����@�X�R�A
			list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetScore);

			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(asArray[i].score, it++->score);
			}

			//�����@���O
			list.Sort<std::string>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetName);

			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(asArray[i].score, it++->score);
			}

			//�~���@�X�R�A
			list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::DESCENDING_ORDER, fpGetScore);

			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(desArray[i].score, it++->score);
			}

			//�~���@���O
			list.Sort<std::string>(DoublyLinkedList<ResultData>::SortOrder::DESCENDING_ORDER, fpGetName);

			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(desArray[i].score, it++->score);
			}
		}

		/**********************************************************************************//**
			@brief		���X�g���\�[�g�ς݂̏ꍇ�̃\�[�g�@�\�̃e�X�g
			@details	ID:���X�g-�N�C�b�N�\�[�g-4\n
						�����L�[�����v�f�������āA�ϓ����Ă��Ȃ���ΐ����ł�\n
		*//***********************************************************************************/
		TEST(SortTest, TestWhenSorted) {
			DoublyLinkedList<ResultData> list;
		
			//�v�f��3�p�ӂ���
			ResultData data1 = { 10, "a" };
			ResultData data2 = { 20, "b" };

			DoublyLinkedList<ResultData>::Iterator it = list.GetBegin();
			list.Insert(it, data1);//����
			list.Insert(it, data1);//����
			list.Insert(it, data2);

			//��r�p�̔z��
			//�����ɂȂ��Ă���z��
			ResultData asArray[3] = { data1, data1, data2 };
			//�~���ɂȂ��Ă���z��
			ResultData desArray[3] = { data2, data1, data1 };

			//�����@�X�R�A
			list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetScore);

			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(asArray[i].score, it++->score);
			}

			//�����@�X�R�A�@2���
			list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetScore);

			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(asArray[i].score, it++->score);
			}

			//�����@���O
			list.Sort<std::string>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetName);

			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(asArray[i].score, it++->score);
			}

			//�����@���O�@2���
			list.Sort<std::string>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetName);

			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(asArray[i].score, it++->score);
			}

			//�~���@�X�R�A
			list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::DESCENDING_ORDER, fpGetScore);

			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(desArray[i].score, it++->score);
			}

			//�~���@�X�R�A�@2���
			list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::DESCENDING_ORDER, fpGetScore);

			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(desArray[i].score, it++->score);
			}

			//�~���@���O
			list.Sort<std::string>(DoublyLinkedList<ResultData>::SortOrder::DESCENDING_ORDER, fpGetName);

			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(desArray[i].score, it++->score);
			}

			//�~���@���O�@2���
			list.Sort<std::string>(DoublyLinkedList<ResultData>::SortOrder::DESCENDING_ORDER, fpGetName);

			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(desArray[i].score, it++->score);
			}

		}

		/**********************************************************************************//**
			@brief		���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����ꍇ�̃\�[�g�@�\�̃e�X�g
			@details	ID:���X�g-�N�C�b�N�\�[�g-5\n
						�w��ʂ�Ƀ\�[�g����Ă���ΐ����ł�\n
		*//***********************************************************************************/
		TEST(SortTest, TestWhenAfterSortAndInsert) {
			DoublyLinkedList<ResultData> list;
			
			//�v�f��2�p�ӂ���
			ResultData data10 = { 10, "d" };
			ResultData data20 = { 20, "e" };

			DoublyLinkedList<ResultData>::Iterator it = list.GetBegin();
			list.Insert(it, data10);
			list.Insert(it, data20);

			//�}���p�̗v�f
			ResultData data1 = { 1, "a" };
			ResultData data2 = { 2, "b" };
			ResultData data3 = { 3, "c" };

			//��r�p�̔z��
			//�����ɂȂ��Ă���z��
			ResultData asArray[5] = { data1, data2, data3, data10, data20 };
			//�~���ɂȂ��Ă���z��
			ResultData desArray[5] = { data20, data10, data3, data2, data1 };

			//4�p�^�[��
			//�����@�X�R�A
			list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetScore);

			//�擪�A�����A�����ɑ}��
			list.Insert(it, data1);
			list.Insert(it + 2, data2);
			list.Insert(list.GetEnd(), data3);

			//�����@�X�R�A�@2���
			list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetScore);

			//�f�[�^�̕��я����m�F
			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(asArray[i].score, it++->score);
			}

			//�}�������f�[�^�̍폜
			for (int i = 0; i < 3; i++) {
				list.Delete(list.GetBegin());
			}

			//2/4
			//�����@���O
			list.Sort<std::string>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetName);

			//�擪�A�����A�����ɑ}��
			list.Insert(list.GetBegin(), data1);
			list.Insert(list.GetBegin() + 2, data2);
			list.Insert(list.GetEnd(), data3);

			//�����@���O�@2���
			list.Sort<std::string>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetName);

			//�f�[�^�̕��я����m�F
			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(asArray[i].score, it++->score);
			}

			//�}�������f�[�^�̍폜
			for (int i = 0; i < 3; i++) {
				list.Delete(list.GetBegin());
			}

			//3/4
			//�~���@�X�R�A
			list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::DESCENDING_ORDER, fpGetScore);

			//�擪�A�����A�����ɑ}��
			list.Insert(list.GetBegin(), data1);
			list.Insert(list.GetBegin() + 2, data2);
			list.Insert(list.GetEnd(), data3);

			//�~���@�X�R�A�@2���
			list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::DESCENDING_ORDER, fpGetScore);

			//�f�[�^�̕��я����m�F
			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(desArray[i].score, it++->score);
			}

			//�}�������f�[�^�̍폜
			for (int i = 0; i < 3; i++) {
				list.Delete(list.GetEnd() - 1);
			}

			//4/4
			//�~���@���O
			list.Sort<std::string>(DoublyLinkedList<ResultData>::SortOrder::DESCENDING_ORDER, fpGetName);

			//�擪�A�����A�����ɑ}��
			list.Insert(list.GetBegin(), data1);
			list.Insert(list.GetBegin() + 2, data2);
			list.Insert(list.GetEnd(), data3);

			//�~���@���O�@2���
			list.Sort<std::string>(DoublyLinkedList<ResultData>::SortOrder::DESCENDING_ORDER, fpGetName);

			//�f�[�^�̕��я����m�F
			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(desArray[i].score, it++->score);
			}

		}

		/**********************************************************************************//**
			@brief		�L�[�w������Ȃ�����(nullptr��n����)�ꍇ�̃\�[�g�@�\�̃e�X�g
			@details	ID:���X�g-�N�C�b�N�\�[�g-6\n
						�����N����Ȃ���ΐ����ł�\n
		*//***********************************************************************************/
		TEST(SortTest, TestKeyIsNull) {
			DoublyLinkedList<ResultData> list;

			//�}���p�̃f�[�^
			ResultData data1 = { 1, "a" };
			ResultData data2 = { 2, "b" };
			ResultData data3 = { 3, "c" };

			//��r�p�̔z��
			//������~���ɕ���ł��Ȃ��z��
			const int ARRAY_SIZE = 3;
			ResultData testArray[ARRAY_SIZE] = { data1, data3, data2};

			//�������тɂȂ�悤���X�g�ɑ}��
			DoublyLinkedList<ResultData>::Iterator it = list.GetBegin();
			for (int i = 0; i < ARRAY_SIZE; i++) {
				list.Insert(it, testArray[ARRAY_SIZE-1-i]);
			}

			//��������nullptr��n���ď����Ƀ\�[�g
			list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, nullptr);

			//�f�[�^�̕��я����ς���Ă��Ȃ����Ƃ��m�F
			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(testArray[i].score, it++->score);
			}

			//��������nullptr��n���č~���Ƀ\�[�g
			list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::DESCENDING_ORDER, nullptr);

			//�f�[�^�̕��я����ς���Ă��Ȃ����Ƃ��m�F
			it = list.GetBegin();
			for (int i = 0; i < list.GetSize(); i++) {
				EXPECT_EQ(testArray[i].score, it++->score);
			}
		}

		/**********************************************************************************//**
			@brief		�L�[���s�K�؂ȏꍇ�̃\�[�g�@�\�̃e�X�g
			@details	ID:���X�g-�N�C�b�N�\�[�g-7\n
						�����e�X�g���s���܂���
		*//***********************************************************************************/

		/**********************************************************************************//**
			@brief		���X�g��const�̏ꍇ�̃\�[�g�@�\�̃e�X�g
			@details	ID:���X�g-�N�C�b�N�\�[�g-8\n
						�����e�X�g���s���܂���
		*//***********************************************************************************/
		

	}//namespace chapter2
}//namespace ex01_DataStructure