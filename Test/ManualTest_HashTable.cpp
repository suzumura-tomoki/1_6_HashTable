/**********************************************************************************//**
	@file           ManualTest_HashTable.cpp
	@brief          手動テスト
*//***********************************************************************************/
#include "pch.h"
#include "ManualTest_HashTable.h"
#include "../メインプロジェクト/HashTable.h"

//=======================================
// 宣言・定義
//=======================================
const int BUCKET_SIZE = 16;

const int& HashFunc(const int& key) {
	return key % BUCKET_SIZE;
}

HashTable<int, int, HashFunc, BUCKET_SIZE> table;

/**********************************************************************************//**
	@brief		不適切なハッシュ関数がテンプレート引数で渡された場合のクラスの挙動を確認します
	@details	ID:ハッシュテーブル-0\n
				コンパイルエラーになれば成功です
*//***********************************************************************************/
TEST(TestHashTableBehavior, IrregularHashFunc) {
#ifdef IRREGULAR_HASH_FUNC
	void IrrgularFunc(const int& key);
	HashTable<int, int, IrrgularFunc, BUCKET_SIZE> table;
#else
	SUCCEED();
#endif
}