
/**********************************************************************************//**
	@file           Test_HashTable.cpp
	@brief          ハッシュテーブルの自動テストを行います
*//***********************************************************************************/

#include "pch.h"
#include"..\メインプロジェクト\HashTable.h"

//=======================================
// 宣言・定義
//=======================================
const int BUCKET_SIZE = 16;

const int& HashFunc(const int& key) {
	return key % BUCKET_SIZE;
}

const int& DifferentHashFunc(const int& key) { 
	return (key * key)% BUCKET_SIZE;
};

HashTable<int, int, HashFunc, BUCKET_SIZE> table;

#pragma region ================================= クラスの挙動 =====================================

/**********************************************************************************//**
	@brief		不適切なハッシュ関数がテンプレート引数で渡された場合のクラスの挙動を確認します
	@details	ID:ハッシュテーブル-0\n
				自動テストを行いません
*//***********************************************************************************/


/**********************************************************************************//**
	@brief		算出方法の異なる適切なハッシュ関数を渡したときのそれぞれのクラスの挙動を確認します
	@details	ID:ハッシュテーブル-1\n
				挿入、検索、削除を行い、全ての戻り値がTRUEにであれば成功です\n
*//***********************************************************************************/
TEST(TestHashTableBehavior, DifferentHashFunc) {

	//ひとつ目のクラスの挙動を確認
	EXPECT_TRUE(table.Insert(0, 0));
	EXPECT_TRUE(table.Find(0));
	EXPECT_TRUE(table.Erase(0));
	

	//算出方法の異なるハッシュ関数を渡したクラスの挙動を確認

	

	HashTable<int, int, DifferentHashFunc, BUCKET_SIZE> tableB;
	EXPECT_TRUE(tableB.Insert(0,0));
	EXPECT_TRUE(tableB.Find(0));
	EXPECT_TRUE(tableB.Erase(0));
	
}

#pragma endregion

#pragma region ================================= データ数の取得 =====================================

/**********************************************************************************//**
	@brief		リストが空である場合のデータ数の取得テスト
	@details	ID:ハッシュテーブル-2\n
				挿入、検索、削除を行い、全ての戻り値がTRUEにであれば成功です\n
*//***********************************************************************************/
TEST(TestHashTableBehavior, DifferentHashFunc) {

	//ひとつ目のクラスの挙動を確認
	EXPECT_TRUE(table.Insert(0, 0));
	EXPECT_TRUE(table.Find(0));
	EXPECT_TRUE(table.Erase(0));


	//算出方法の異なるハッシュ関数を渡したクラスの挙動を確認

	constexpr auto DifferentFunc = [](const int& key)->const int& {return key * 11 % BUCKET_SIZE; };

	HashTable<int, int, DifferentFunc, BUCKET_SIZE> tableB;
	EXPECT_TRUE(tableB.Insert(0, 0));
	EXPECT_TRUE(tableB.Find(0));
	EXPECT_TRUE(tableB.Erase(0));

}

#pragma endregion