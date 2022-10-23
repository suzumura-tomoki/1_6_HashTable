
/**********************************************************************************//**
	@file           Test_HashTable.cpp
	@brief          ハッシュテーブルの自動テストを行います
*//***********************************************************************************/

#include "pch.h"
#include"Test_HashTable.h"

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
TEST_F(TestHashTable, BehaviorTestDifferentHashFunc) {

	//ひとつ目のクラスの挙動を確認
	EXPECT_TRUE(table.Insert(0, 0));
	EXPECT_TRUE(table.Find(0));
	EXPECT_TRUE(table.Erase(0));


	//算出方法の異なるハッシュ関数を渡したクラスの挙動を確認
	HashTable<int, int, DifferentHashFunc, BUCKET_SIZE> tableB;
	EXPECT_TRUE(tableB.Insert(0, 0));
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
TEST_F(TestHashTable, GetSizeTestWhenEmpty) {

	EXPECT_EQ(0, table.GetSize());
}

/**********************************************************************************//**
	@brief		要素を一回挿入した後のデータ数の取得テスト
	@details	ID:ハッシュテーブル-3\n
				戻り値が1であれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestAfterInsertOnce) {
	ASSERT_TRUE(table.Insert(0, 0));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		要素を挿入して同じキーで削除した後のデータ数の取得テスト
	@details	ID:ハッシュテーブル-4\n
				戻り値が0であれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestAfterInsertAndErase) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Erase(0));
	EXPECT_EQ(0, table.GetSize());
}

/**********************************************************************************//**
	@brief		既に存在するキーで要素の挿入をし失敗した後のデータ数の取得テスト
	@details	ID:ハッシュテーブル-5\n
				戻り値が1であれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestAfterInsertAlreadyUsedKey) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_FALSE(table.Insert(0, 0));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		要素挿入して、別のキーで削除し失敗した後のデータ数の取得テスト
	@details	ID:ハッシュテーブル-6\n
				戻り値が1であれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestAfterEraseFailed) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_FALSE(table.Erase(1));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		ハッシュテーブルが空である場合に、削除を行った後のデータ数の取得テスト
	@details	ID:ハッシュテーブル-7\n
				戻り値が0であれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestAfterEraseWhenEmpty) {
	ASSERT_FALSE(table.Erase(0));
	EXPECT_EQ(0, table.GetSize());
}

/**********************************************************************************//**
	@brief		要素２つが内部でチェインになっていない場合のデータ数の取得テスト
	@details	ID:ハッシュテーブル-8\n
				戻り値が2であれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestWhenDataNotChained) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Insert(1, 1));
	EXPECT_EQ(2, table.GetSize());
}

/**********************************************************************************//**
	@brief		要素２つが内部でチェインになっていない場合に一方を削除した後のデータ数の取得テスト
	@details	ID:ハッシュテーブル-9\n
				戻り値が1であれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestAfterEraseWhenDataNotChained) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Insert(1, 1));
	ASSERT_TRUE(table.Erase(1));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		要素２つが内部でチェインになっている場合のデータ数の取得テスト
	@details	ID:ハッシュテーブル-10\n
				戻り値が2であれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestWhenDataChained) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Insert(BUCKET_SIZE, BUCKET_SIZE));
	EXPECT_EQ(2, table.GetSize());
}

/**********************************************************************************//**
	@brief		要素２つが内部でチェインになっている場合に一方を削除した後のデータ数の取得テスト
	@details	ID:ハッシュテーブル-11\n
				戻り値が1であれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, GetSizeTestAfterEraseWhenDataChained) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Insert(BUCKET_SIZE, BUCKET_SIZE));
	ASSERT_TRUE(table.Erase(0));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		ハッシュテーブルがコンストの場合のデータ数の取得テスト
	@details	ID:ハッシュテーブル-12\n
				自動テストを行いません\n
*//***********************************************************************************/

#pragma endregion

#pragma region ================================= データの挿入 =====================================

/**********************************************************************************//**
	@brief		ハッシュテーブルが空である場合の挿入テスト
	@details	ID:ハッシュテーブル-13\n
				要素が挿入されていれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, InsertWhenEmpty) {
	ASSERT_TRUE(table.Insert(0, 0));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		複数の要素を異なるキーで挿入した場合の挿入テスト
	@details	ID:ハッシュテーブル-14\n
				要素が挿入されていれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, InsertWhenDifferentKey) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Insert(1, 0));
	EXPECT_EQ(2, table.GetSize());
}

/**********************************************************************************//**
	@brief		使用済みのキーで挿入した場合の挿入テスト
	@details	ID:ハッシュテーブル-15\n
				挿入に失敗すると成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, InsertWhenUsedKey) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Insert(1, 0));
	ASSERT_FALSE(table.Insert(1, 0));
	EXPECT_EQ(2, table.GetSize());
}

/**********************************************************************************//**
	@brief		使用済みのキーとハッシュ値が同じになるキーで挿入した場合の挿入テスト
	@details	ID:ハッシュテーブル-16\n
				要素が挿入されていれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, InsertWhenSameHash) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Insert(BUCKET_SIZE, BUCKET_SIZE));
	EXPECT_EQ(2, table.GetSize());
}

/**********************************************************************************//**
	@brief		一度挿入し、削除した後再度同じキーで挿入した場合の挿入テスト
	@details	ID:ハッシュテーブル-17\n
				要素が挿入されていれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, InsertWhenErasedKey) {
	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Erase(0));
	ASSERT_TRUE(table.Insert(0, 0));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		ハッシュテーブルがコンストの場合の挿入テスト
	@details	ID:ハッシュテーブル-18\n
				自動テストを行いません\n
*//***********************************************************************************/

#pragma endregion

#pragma region ================================= データの削除 =====================================

/**********************************************************************************//**
	@brief		ハッシュテーブルが空である場合の削除テスト
	@details	ID:ハッシュテーブル-19\n
				削除に失敗すると成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, EraseWhenEmpty) {
	ASSERT_FALSE(table.Erase(0));
	EXPECT_EQ(0, table.GetSize());
}

/**********************************************************************************//**
	@brief		ハッシュテーブルに存在するキーで削除した場合の削除テスト
	@details	ID:ハッシュテーブル-20\n
				削除されていると成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, EraseWhenExistKey) {
	ASSERT_TRUE(table.Insert(0, 0));
	EXPECT_EQ(1, table.GetSize());
	ASSERT_TRUE(table.Erase(0));
	EXPECT_EQ(0, table.GetSize());
}

/**********************************************************************************//**
	@brief		ハッシュテーブルに存在しないキーで削除した場合の削除テスト
	@details	ID:ハッシュテーブル-21\n
				削除に失敗すると成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, EraseWhenNotExistKey) {
	ASSERT_TRUE(table.Insert(0, 0));
	EXPECT_EQ(1, table.GetSize());
	ASSERT_FALSE(table.Erase(1));
	EXPECT_EQ(1, table.GetSize());
}

/**********************************************************************************//**
	@brief		削除したキーで再度削除した場合の削除テスト
	@details	ID:ハッシュテーブル-22\n
				削除に失敗すると成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, EraseWhenErasedKey) {
	ASSERT_TRUE(table.Insert(0, 0));
	EXPECT_EQ(1, table.GetSize());
	ASSERT_TRUE(table.Erase(0));
	ASSERT_FALSE(table.Erase(0));
}

/**********************************************************************************//**
	@brief		チェインになっている要素を削除した場合の削除テスト
	@details	ID:ハッシュテーブル-23\n
				指定した要素が削除されていると成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, EraseWhenDataChains) {
	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}

	EXPECT_EQ(3, table.GetSize());

	//チェインの中央を削除
	ASSERT_TRUE(table.Erase(BUCKET_SIZE));

	//全てを削除して指定した要素のみ削除されていることを確認する
	ASSERT_TRUE(table.Erase(0));
	ASSERT_FALSE(table.Erase(BUCKET_SIZE));
	ASSERT_TRUE(table.Erase(2 * BUCKET_SIZE));
}

/**********************************************************************************//**
	@brief		チェインになっている要素とハッシュ値が同じ存在しないキーを指定して削除した場合の削除テスト
	@details	ID:ハッシュテーブル-24\n
				削除に失敗すると成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, EraseWhenDataChainsUseNotExistKey) {
	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}

	ASSERT_FALSE(table.Erase(5 * BUCKET_SIZE));
}

/**********************************************************************************//**
	@brief		チェインになっている要素を順に削除した場合の削除テスト
	@details	ID:ハッシュテーブル-25\n
				全て削除できれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, EraseAllWhenDataChains) {
	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}

	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Erase(i * BUCKET_SIZE));
	}
}

/**********************************************************************************//**
	@brief		ハッシュテーブルがコンストの場合の削除テスト
	@details	ID:ハッシュテーブル-26\n
				自動テストを行いません\n
*//***********************************************************************************/

#pragma endregion

#pragma region ================================= データの検索 =====================================

/**********************************************************************************//**
	@brief		ハッシュテーブルが空である場合の検索テスト
	@details	ID:ハッシュテーブル-27\n
				検索に失敗すると成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, FindWhenEmpty) {
	int dest;
	ASSERT_FALSE(table.Find(0, dest));
}

/**********************************************************************************//**
	@brief		複数の要素がある場合に、存在するキーで検索した場合の検索テスト
	@details	ID:ハッシュテーブル-28\n
				指定したデータを取得できると成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, FindWhenMultipleData) {

	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}
	int dest;
	ASSERT_TRUE(table.Find(0, dest));
	EXPECT_EQ(0, dest);
}

/**********************************************************************************//**
	@brief		複数の要素がある場合に、存在しないキーで検索した場合の検索テスト
	@details	ID:ハッシュテーブル-29\n
				検索に失敗すると成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, FindNotExistKeyWhenMultipleData) {

	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}
	int dest;
	ASSERT_FALSE(table.Find(5 * BUCKET_SIZE, dest));
}

/**********************************************************************************//**
	@brief		複数の要素がある場合に、同じキーで2回検索した場合の検索テスト
	@details	ID:ハッシュテーブル-30\n
				2回同じデータを取得できれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, FindTwiceSameKeyWhenMultipleData) {

	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}
	int dest;
	ASSERT_TRUE(table.Find(BUCKET_SIZE, dest));
	EXPECT_EQ(1, dest);

	dest = 0;
	ASSERT_TRUE(table.Find(BUCKET_SIZE, dest));
	EXPECT_EQ(1, dest);
}

/**********************************************************************************//**
	@brief		削除されたキーで検索した場合の検索テスト
	@details	ID:ハッシュテーブル-31\n
				検索に失敗すると成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, FindErasedKey) {

	ASSERT_TRUE(table.Insert(0, 0));
	ASSERT_TRUE(table.Erase(0));

	int dest;
	ASSERT_FALSE(table.Find(0, dest));
}

/**********************************************************************************//**
	@brief		チェインになっている要素を検索した場合の検索テスト
	@details	ID:ハッシュテーブル-32\n
				指定したデータを取得できれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, FindWhenDataChains) {

	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}

	for (int i = 0; i < 3; i++) {
		int dest;
		ASSERT_TRUE(table.Find(i * BUCKET_SIZE, dest));
		EXPECT_EQ(i, dest);
	}
}

/**********************************************************************************//**
	@brief		チェインになっている要素のうち、1つを削除した場合の検索テスト
	@details	ID:ハッシュテーブル-33\n
				削除したデータ以外の指定したデータを取得できれば成功です\n
*//***********************************************************************************/
TEST_F(TestHashTable, FindAfterEraseOneOfChainedData) {

	for (int i = 0; i < 3; i++) {
		ASSERT_TRUE(table.Insert(i * BUCKET_SIZE, i));
	}

	//チェインの中央を削除
	ASSERT_TRUE(table.Erase(BUCKET_SIZE));

	int dest;
	ASSERT_TRUE(table.Find(0, dest));
	EXPECT_EQ(0, dest);

	ASSERT_FALSE(table.Find(BUCKET_SIZE, dest));

	ASSERT_TRUE(table.Find(2 * BUCKET_SIZE, dest));
	EXPECT_EQ(2, dest);
}

/**********************************************************************************//**
	@brief		ハッシュテーブルがコンストの場合の検索テスト
	@details	ID:ハッシュテーブル-34\n
				自動テストを行いません\n
*//***********************************************************************************/

#pragma endregion