#pragma once
#include"DoublyLinkedList.h"

/**
 * @brief データを格納し、格納された順にデータを取り出します
 * @tparam Type 格納するデータの型
*/
template<typename Type>
class Queue
{
public:
	/** @brief コンストラクタ */
	Queue();
	/** @brief デフォルトコピーコンストラクタ */
	Queue(const Queue& obj) = default;
	/** @brief デストラクタ */
	virtual ~Queue();

	/**
	 * @brief データの数を取得します
	 * @return データの数
	 */
	uint32_t GetSize()const;

	/**
	 * @brief 末尾に要素を追加します
	 * @param[in] 追加するデータ
	 * @return 追加の成否
	 */
	bool Push(const Type& data);

	/**
	 * @brief 先頭の要素を取り出します
	 * @param[out] 取り出した要素の格納先
	 * @return キューが空の場合は何も取り出されずfalseを戻します
	 */
	bool Pop(Type& destination);

private:
	/** @brief データを格納するリスト */
	DoublyLinkedList<Type> list;
};

#include"Queue.inl"
