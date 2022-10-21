
/**********************************************************************************//**
	@file           ManualTest_Queue.cpp
	@brief          キューの手動テストを行います
*//***********************************************************************************/

#include "pch.h"
#include"ManualTest_Queue.h"
#include"..\メインプロジェクト\Queue.h"

/**********************************************************************************//**
	@brief		キューがコンテストの場合の要素数の取得テスト
	@details	ID:キュー-7\n
				コンテストのキューで要素数の取得を行った場合の戻り値を確認しています。\n
				コンパイルエラーとならなければ成功です。\n
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
	@brief		キューがコンテストの場合のプッシュテスト
	@details	ID:キュー-10\n
				キューがコンテストである場合にプッシュを行った際の挙動を確認しています。\n
				コンパイルエラーになれば成功です。\n
*//***********************************************************************************/
TEST(TestQueuePush, WhenConst) {

	//#define PUSH_WHEN_CONST

#ifdef PUSH_WHEN_CONST

	const Queue<int> queue;
	queue.Push(0);//ここでエラー

#else
	SUCCEED();
#endif // PUSH_WHEN_CONST
}

/**********************************************************************************//**
	@brief		キューがコンテストの場合のポップテスト
	@details	ID:キュー-14\n
				キューがコンテストである場合にポップを行った際の挙動を確認しています。\n
				コンパイルエラーになれば成功です。\n
*//***********************************************************************************/
TEST(TestQueuePop, WhenConst) {

	//#define POP_WHEN_CONST

#ifdef POP_WHEN_CONST

	const Queue<int> queue;
	int n;

	queue.Pop(n);//ここでエラー

#else
	SUCCEED();
#endif // POP_WHEN_CONST
}