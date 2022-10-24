#pragma once
#include"DoublyLinkedList.h"
#include<array>

/**
 * @brief コンテナクラス\n
 *		  格納場所をハッシュ値によって管理します\n
 *		  キーによるランダムアクセスが可能です\n
 *		  ハッシュ値が衝突するとチェイン法を用いて格納します
 * @tparam Key キーの型 比較演算子が有効なもの
 * @tparam Value 格納する値の型
 * @tparam HashFunc ハッシュ関数
 * @tparam bucketSize バケットの数　デフォルトは１６
 */
template<
	typename Key,
	typename Value,
	uint16_t HashFunc(const Key&),
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

	/**
	 * @brief 指定したキーの場所にデータを挿入します
	 * @param[in] key キー　使用済みのキーだと挿入が行われません
	 * @param[in] value データ
	 * @return 使用済みのキーで挿入すると挿入に失敗してfalseとなります
	 */
	bool Insert(Key key, Value value);

	//TODO @returnなどの内容を詳しく書く
	/**
	 * @brief データを削除します
	 * @param[in] key 格納場所を示すキー
	 * @return キーと一致するデータが見つからないと削除に失敗してfalseとなります
	 */
	bool Erase(Key key);

	//TODO @returnなどの内容を詳しく書く
	/**
	 * @brief データを検索します
	 * @param[in] key 格納場所を示すキー
	 * @param[out] destination 検索したデータのコピー先
	 * @return キーと一致するデータが見つからないと検索に失敗してfalseとなります
	 */
	bool Find(Key key, Value& destination)const;

private:

	/** @brief キーと値のペア */
	struct Pair
	{
		Key key;
		Value value;
	};

	/** @brief 格納するバケットの添え字を取得します */
	const int& GetBucketIndex(Key& key)const;

	/** @brief バケットの配列 */
	std::array<DoublyLinkedList<Pair>, bucketSize> buckets;

	uint16_t size;
};

#include"HashTable.inl"
