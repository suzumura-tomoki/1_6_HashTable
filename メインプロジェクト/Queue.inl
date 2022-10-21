#pragma once
#include"Queue.h"

template<typename Type>
Queue<Type>::Queue():list()
{
	//何もしない
}

template<typename Type>
Queue<Type>::~Queue()
{
	//何もしない
}

template<typename Type>
inline uint32_t Queue<Type>::GetSize()const
{
	return list.GetSize();
}

template<typename Type>
inline bool Queue<Type>::Push(const Type& data)
{
	return list.Insert(list.GetEnd(), data);
}

template<typename Type>
inline bool Queue<Type>::Pop(Type& destination)
{
	//要素がなければ終了
	if (GetSize() == static_cast<uint32_t>(0)) {
		return false;
	}

	//先頭要素のデータを引数に移す
	DoublyLinkedList<Type>::Iterator begin = list.GetBegin();
	destination = std::move(*begin);
	//データの移動元の要素を削除する
	return list.Delete(begin);
}
