
/**********************************************************************************//**
	@file           test.cpp
	@brief          キューのテストを行います
*//***********************************************************************************/

#include "pch.h"
#include"..\メインプロジェクト\Queue.h"

#pragma region ================================= 要素数の取得 =====================================

/**********************************************************************************//**
	@brief		キューが空である場合の要素数の取得テスト
	@details	ID:キュー-0\n
				キューが空である場合の戻り値を確認しています。\n
				要素数が0であれば成功です。\n
*//***********************************************************************************/
TEST(TestQueueGetSize, WhenEmpty) {
	Queue<int> queue;
	EXPECT_EQ(0, queue.GetSize());
}

/**********************************************************************************//**
	@brief		要素をプッシュした後の要素数の取得テスト
	@details	ID:キュー-1\n
				空のキューに要素をプッシュした後に要素数の取得を行った場合の戻り値を確認しています。\n
				要素数が1であれば成功です。\n
*//***********************************************************************************/
TEST(TestQueueGetSize, WhenAfterPush) {
	Queue<int> queue;
	queue.Push(0);
	EXPECT_EQ(1, queue.GetSize());
}

/**********************************************************************************//**
	@brief		要素をポップした後の要素数の取得テスト
	@details	ID:キュー-2\n
				キューに要素が1つある場合に、ポップした後に要素数の取得を行った場合の戻り値を確認しています。\n
				要素数が0であれば成功です。\n
*//***********************************************************************************/
TEST(TestQueueGetSize, WhenAfterPop) {
	Queue<int> queue;

	//プッシュ
	queue.Push(0);
	EXPECT_EQ(1, queue.GetSize());

	//ポップ
	int n;
	queue.Pop(n);
	EXPECT_EQ(0, queue.GetSize());
}

/**********************************************************************************//**
	@brief		要素のプッシュに失敗した場合の要素数の取得テスト
	@details	ID:キュー-3\n
				要素のプッシュに失敗するのはメモリの確保に失敗した場合のみなのでテストを行いません
*//***********************************************************************************/
TEST(TestQueueGetSize, WhenAfterPushFailed) {
	//要素のプッシュに失敗するのはメモリの確保に失敗した場合のみなのでテストを行いません
	//Queue<int> queue;
	//queue.Push(0);
	//EXPECT_EQ(0, queue.GetSize());
}

/**********************************************************************************//**
	@brief		プッシュを2回行った場合の要素数の取得テスト
	@details	ID:キュー-4\n
				空のキューでプッシュを2回行った後に要素数の取得を行った場合の戻り値を確認しています。\n
				要素数が2であれば成功です。\n
*//***********************************************************************************/
TEST(TestQueueGetSize, WhenAfterPushTwice) {
	Queue<int> queue;
	queue.Push(0);
	queue.Push(0);
	EXPECT_EQ(2, queue.GetSize());
}

/**********************************************************************************//**
	@brief		プッシュを2回行った後、１回ポップした場合の要素数の取得テスト
	@details	ID:キュー-5\n
				空のキューでプッシュを2回行い、１回ポップした後に要素数の取得を行った場合の戻り値を確認しています。\n
				要素数が1であれば成功です。\n
*//***********************************************************************************/
TEST(TestQueueGetSize, WhenAfterPushTwiceAndPopOnce) {
	Queue<int> queue;

	queue.Push(0);
	queue.Push(0);

	int n;
	queue.Pop(n);

	EXPECT_EQ(1, queue.GetSize());
}

/**********************************************************************************//**
	@brief		空のキューでポップを行った後の要素数の取得テスト
	@details	ID:キュー-6\n
				空のキューでポップを行った後に要素数の取得を行った場合の戻り値を確認しています。\n
				要素数が0であれば成功です。\n
*//***********************************************************************************/
TEST(TestQueueGetSize, WhenEmptyAfterPop) {
	Queue<int> queue;

	int n;

	EXPECT_FALSE(queue.Pop(n));

	EXPECT_EQ(0, queue.GetSize());
}

/**********************************************************************************//**
	@brief		キューがコンテストの場合の要素数の取得テスト
	@details	ID:キュー-7\n
				自動テストを行いません
*//***********************************************************************************/

#pragma endregion ================================= 要素数の取得 =====================================

#pragma region =================================== プッシュ =======================================

/**********************************************************************************//**
	@brief		キューが空である場合のプッシュテスト
	@details	ID:キュー-8\n
				キューが空である場合にプッシュを行った際の挙動を確認しています。\n
				戻り値がtrueであり、要素数が1であれば成功です。\n
*//***********************************************************************************/
TEST(TestQueuePush, WhenEmpty) {
	Queue<int> queue;

	EXPECT_TRUE(queue.Push(0));
	EXPECT_EQ(1, queue.GetSize());
}

/**********************************************************************************//**
	@brief		キューに複数の要素がある場合のプッシュテスト
	@details	ID:キュー-9\n
				キューに複数の要素がある場合にプッシュを行った際の挙動を確認しています。\n
				戻り値がtrueであり、要素数が1増えていると成功です。\n
*//***********************************************************************************/
TEST(TestQueuePush, WhenStackHasMultipleData) {
	Queue<int> queue;

	for (int i = 1; i < 5; i++) {
		EXPECT_TRUE(queue.Push(i));
		EXPECT_EQ(i, queue.GetSize());
	}
}

/**********************************************************************************//**
	@brief		キューがコンテストの場合のプッシュテスト
	@details	ID:キュー-10\n
				自動テストを行いません
*//***********************************************************************************/

#pragma endregion =================================== プッシュ =======================================

#pragma region =================================== ポップ =======================================

/**********************************************************************************//**
	@brief		キューが空である場合のポップテスト
	@details	ID:キュー-11\n
				キューが空である場合にポップを行った際の挙動を確認しています。\n
				戻り値がfalseであり、要素数が0であれば成功です。\n
*//***********************************************************************************/
TEST(TestQueuePop, WhenEmpty) {
	Queue<int> queue;
	int n;
	EXPECT_FALSE(queue.Pop(n));
	EXPECT_EQ(0, queue.GetSize());
}

/**********************************************************************************//**
	@brief		キューに複数の要素がある場合のポップテスト
	@details	ID:キュー-12\n
				キューに複数の要素がある場合にポップを１回行った際の挙動を確認しています。\n
				戻り値がtrueであり、要素数が1減っていると成功です。\n
*//***********************************************************************************/
TEST(TestQueuePop, PopOnceWhenStackHasMultipleData) {
	Queue<int> queue;
	const int dataNum = 4;

	//確認用配列
	int pushNums[dataNum];

	//複数回プッシュ
	for (int i = 0; i < dataNum; i++) {
		queue.Push(i);
		pushNums[i] = i;
	}

	//ポップしてデータを確認
	int popNum;
	EXPECT_TRUE(queue.Pop(popNum));
	EXPECT_EQ(pushNums[0], popNum);
	EXPECT_EQ(dataNum - 1, queue.GetSize());
}

/**********************************************************************************//**
	@brief		キューに複数の要素がある場合のポップテスト
	@details	ID:キュー-13\n
				キューに複数の要素がある場合にポップを複数回行った際の挙動を確認しています。\n
				戻り値がtrueであり、要素数が1減っていると成功です。\n
*//***********************************************************************************/
TEST(TestQueuePop, WhenStackHasMultipleData) {
	Queue<int> queue;
	const int dataNum = 4;

	//確認用配列
	int pushNums[dataNum];
	int popNums[dataNum];

	//複数回プッシュ
	for (int i = 0; i < dataNum; i++) {
		queue.Push(i);
		pushNums[i] = i;
	}

	//ポップしてデータを確認
	for (int i = 0; i < dataNum; i++) {
		EXPECT_TRUE(queue.Pop(popNums[i]));
		EXPECT_EQ(pushNums[i], popNums[i]);
		EXPECT_EQ(dataNum - 1 - i, queue.GetSize());
	}

}

/**********************************************************************************//**
	@brief		キューがコンテストの場合のポップテスト
	@details	ID:キュー-14\n
				自動テストを行いません
*//***********************************************************************************/

#pragma endregion =================================== ポップ =======================================