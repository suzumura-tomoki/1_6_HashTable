#pragma once
#include"Stack.h"

template<typename Type>
Stack<Type>::Stack():list()
{
	//何もしない
}

template<typename Type>
Stack<Type>::~Stack()
{
	//何もしない
}

template<typename Type>
inline uint32_t Stack<Type>::GetSize()const
{
	return list.GetSize();
}

template<typename Type>
inline bool Stack<Type>::Push(const Type& data)
{
	return list.Insert(list.GetEnd(), data);
}

template<typename Type>
inline bool Stack<Type>::Pop(Type& destination)
{
	//要素がなければ終了
	if (GetSize() == static_cast<uint32_t>(0)) {
		return false;
	}

	//末尾ダミーの1つ前のデータを引数に移す
	DoublyLinkedList<Type>::Iterator end = --list.GetEnd();
	destination = std::move(*end);
	//データの移動元の要素を削除する
	return list.Delete(end);
}
