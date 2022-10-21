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
 * @tparam bucketSize バケットの数　デフォルトは１６
 */
template<
	typename Key,
	typename Value,
	const int& HashFunc(const Key&),
	int bucketSize = 16
>
class HashTable
{
public:
	/** @brief コンストラクタ */
	HashTable();

	/** @brief デフォルトコピーコンストラクタ */
	HashTable(const HashTable&) = default;

	/** @brief デストラクタ */
	virtual ~HashTable();

	/** 
	 *@brief データ数を取得します
	 *@return データの数
	 */
	int GetSize()const;

	//TODO @returnなどの内容を詳しく書く
	/**
	 * @brief データを挿入します
	 * @param[in] key キー
	 * @param[in] value データ
	 * @return 成否
	 */
	bool Insert(Key key, Value value);

	//TODO @returnなどの内容を詳しく書く
	/**
	 * @brief データを削除します
	 * @param[in] key キー
	 * @return 成否　キーと一致するデータが見つからないと削除に失敗してfalseを返します\n
	 */
	bool Erase(Key key);

	//TODO @returnなどの内容を詳しく書く
	/**
	 * @brief データを検索します
	 * @param[in] key キー
	 * @return 未定
	 */
	bool Find(Key key);

private:

	/** @brief キーと値のペア */
	struct Pair
	{
		Key key;
		Value value;
	};

	/** @brief バケットの配列 */
	std::array<DoublyLinkedList<Pair>, bucketSize> buckets;
};

#include"HashTable.inl"
