#pragma once
#include"DoublyLinkedList.h"

/**
 * @brief コンテナクラス\n
 *		  格納場所をハッシュ値によって管理します\n
 *		  キーによるランダムアクセスが可能です\n
 *		  ハッシュ値が衝突するとチェイン法を用いて格納します
 * @tparam Key キーの型
 * @tparam Value 格納する値の型
 * @tparam HashFunc ハッシュ関数
 * @tparam bucketSize バケットの数　デフォルトは５
 */
template<
	typename Key,
	typename Value,
	const int& HashFunc(const Key&),
	int bucketSize = 5
>
class HashTable
{
public:
	/** @brief コンストラクタ */
	HashTable();

	/** @brief デフォルトコピーコンストラクタ */
	HashTable(const HashTable&) = default;

	/** @brief デストラクタ */
	~HashTable();

private:

	/** @brief キーと値のペア */
	struct Pair
	{
		Key key;
		Value Data;
	};


	DoublyLinkedList<Pair> bucket[bucketSize];
};

#include"HashTable.inl"
