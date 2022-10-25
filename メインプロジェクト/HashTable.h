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

	//TODO ディープコピーについて調べる
	/** @brief デフォルトコピーコンストラクタ */
	HashTable(const HashTable&) = delete;//ディープコピーでも良い

	/** @brief デストラクタ */
	virtual ~HashTable();

	/** 
	 *@brief データ数を取得します
	 *@return データの数
	 */
	int GetSize()const;

	/**
	 * @brief 指定したキーの場所にデータを挿入します
	 * @param[in] KEY キー　使用済みのキーだと挿入が行われません
	 * @param[in] value データ
	 * @return 使用済みのキーで挿入すると挿入に失敗してfalseとなります
	 */
	bool Insert(const Key& KEY, const Value& VALUE);

	/**
	 * @brief データを削除します
	 * @param[in] KEY 格納場所を示すキー
	 * @return キーと一致するデータが見つからないと削除に失敗してfalseとなります
	 */
	bool Erase(const Key& KEY);

	/**
	 * @brief データを検索します
	 * @param[in] KEY 格納場所を示すキー
	 * @param[out] destination 検索したデータのコピー先
	 * @return キーと一致するデータが見つからないと検索に失敗してfalseとなります
	 */
	bool Find(const Key& KEY, Value& destination)const;

private:

	/** @brief キーと値のペア */
	struct Pair
	{
		Key key;
		Value value;
	};

	/**
	 * @brief 格納するバケットの番号を取得します
	 * @param[in] KEY 格納場所を示すキー
	 * @return 格納するバケットの番号
	 */
	int GetBucketIndex(const Key& KEY)const;

	/** 
	 * @brief バケットからキーが一致する要素のイテレータを取得します 
	 * @param[in] KEY 格納場所を示すキー
	 * @param[in] BUCKET 探索するバケット
	 * @param[out] destination 検索した要素のイテレータを格納します。検索に失敗するとダミーノードを示します。
	 * @return キーと一致するデータが見つからないと検索に失敗してfalseとなります
	 */
	bool FindFromBucket(const Key& KEY, const DoublyLinkedList<Pair>& BUCKET, typename DoublyLinkedList<Pair>::ConstIterator& destination)const;

	/** @brief バケットの配列 */
	std::array<DoublyLinkedList<Pair>, bucketSize> buckets;

	uint16_t size;
};

#include"HashTable.inl"
