/**********************************************************************************//**
	@file           ManualTest_Sort.cpp
	@brief          手動テスト
*//***********************************************************************************/
#include"ManualTest_Sort.h"
#include "pch.h"
#include "../メインプロジェクト/DoublyLinkedList.h"
#include "../メインプロジェクト/ResultData.h"

/**********************************************************************************//**
			@brief		キーが不適切な場合のソート機能のテスト
			@details	ID:リスト-クイックソート-7\n
						キーの型がテンプレート引数と引数で異なる場合のテスト
						コンパイルエラーとなれば成功です\n
*//***********************************************************************************/
TEST(SortTest, TestKeyIsIrregular) {
	//#define SORT_TEST_KEY_IS_IRREGULAR
#ifdef SORT_TEST_KEY_IS_IRREGULAR
	DoublyLinkedList<ResultData> list;

	//キーの型がテンプレート引数と引数で異なる
	list.Sort<int>(DoublyLinkedList<ResultData>::SortOrder::ASCENDING_ORDER, fpGetName);
#else
	SUCCEED();
#endif
}

/**********************************************************************************//**
			@brief		リストがconstの場合のソート機能のテスト
			@details	ID:リスト-クイックソート-8\n
						コンパイルエラーとなれば成功です\n
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