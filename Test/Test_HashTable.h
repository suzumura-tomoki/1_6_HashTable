#pragma once
#include"..\メインプロジェクト\HashTable.h"

//=======================================
// 宣言・定義
//=======================================

/** @brief バケットの数*/
#define BUCKET_SIZE 16

/**
 * @brief ハッシュ関数
 * @param[in] key キー
 * @return ハッシュ値
 */
inline uint16_t HashFunc(const int& key) {
	return key % BUCKET_SIZE;
}

/**
 * @brief テストケースTestHashTableBehavior-DifferentHashFunc用のハッシュ関数
 * @param[in] key キー
 * @return ハッシュ値
 */
inline uint16_t DifferentHashFunc(const int& key) {
	return (key * key) % BUCKET_SIZE;
};

/**
 * @brief テストフィクスチャ\n
 *		  各テストに共通した設定を定義します
 */
class TestHashTable :public ::testing::Test
{
protected:
	/** @brief 開始処理*/
	virtual void SetUp() {/*何もしない*/ }

	/** @brief 終了処理*/
	virtual void TearDown() {/*何もしない*/ }

	HashTable<int, int, HashFunc, BUCKET_SIZE> table;
};