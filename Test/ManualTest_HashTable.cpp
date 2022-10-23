/**********************************************************************************//**
	@file           ManualTest_HashTable.cpp
	@brief          手動テスト
*//***********************************************************************************/
#include "pch.h"
#include "Test_HashTable.h"
#include "ManualTest_HashTable.h"


/**********************************************************************************//**
	@brief		不適切なハッシュ関数がテンプレート引数で渡された場合のクラスの挙動を確認します
	@details	ID:ハッシュテーブル-0\n
				コンパイルエラーになれば成功です
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
	@brief		テーブルがコンストの場合のデータ数の取得テスト
	@details	ID:ハッシュテーブル-12\n
				コンパイルが通ると成功です\n
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
	@brief		ハッシュテーブルがコンストの場合の挿入テスト
	@details	ID:ハッシュテーブル-18\n
				コンパイルエラーになれば成功です\n
*//***********************************************************************************/
TEST(TestHashTable, InsertWhenConst) {
#ifdef INSERT_WHEN_CONST
	const HashTable<int, int, HashFunc, BUCKET_SIZE> table;
	table.Insert(0, 0);//ここでエラー
#else
	SUCCEED();
#endif
}

/**********************************************************************************//**
	@brief		ハッシュテーブルがコンストの場合の削除テスト
	@details	ID:ハッシュテーブル-26\n
				コンパイルエラーになれば成功です\n
*//***********************************************************************************/
TEST(TestHashTable, EraseWhenConst) {
#ifdef ERASE_WHEN_CONST
	const HashTable<int, int, HashFunc, BUCKET_SIZE> table;
	table.Erase(0);//ここでエラー
#else
	SUCCEED();
#endif
}

/**********************************************************************************//**
	@brief		ハッシュテーブルがコンストの場合の検索テスト
	@details	ID:ハッシュテーブル-34\n
				コンパイルが通ると成功です\n
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