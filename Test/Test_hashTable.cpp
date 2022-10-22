
/**********************************************************************************//**
	@file           Test_HashTable.cpp
	@brief          ハッシュテーブルの自動テストを行います
*//***********************************************************************************/

#include "pch.h"
#include"..\メインプロジェクト\HashTable.h"

//=======================================
// 宣言・定義
//=======================================

/** @brief バケットの数*/
const int BUCKET_SIZE = 16;

/**
 * @brief ハッシュ関数
 * @param[in]	  各テストに共通した設定を定義します
 */
int& HashFunc(int& key) {
	return key % BUCKET_SIZE;
}

/** @brief ID:ハッシュテーブル-1 用のハッシュ関数*/
int& DifferentHashFunc(int& key) { 
	return (key * key)% BUCKET_SIZE;
};



/**
 * @brief テストフィクスチャ\n
 *		  各テストに共通した設定を定義します
 */
class TestHashTable:public ::testing::Test
{
protected:
	void SetUp() {

	}
	HashTable<int, int, HashFunc, BUCKET_SIZE> table;
};

TestHashTable:public ::testing::Test::TestHashTable:public ::testing::Test()
{
}

TestHashTable:public ::testing::Test::~TestHashTable:public ::testing::Test()
{
}

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
	@brief		ハッシュテーブルが空である場合のデータ数の取得テスト
	@details	ID:ハッシュテーブル-2\n
				戻り値が0であれば成功です\n
*//***********************************************************************************/
TEST(TestHashTableGetSize, WhenEmpty) {



	//ひとつ目のクラスの挙動を確認
	EXPECT_TRUE(table.Insert(0, 0));
	EXPECT_TRUE(table.Find(0));
	EXPECT_TRUE(table.Erase(0));


}

#pragma endregion