#pragma once
#include"Stack.h"

template<typename Type>
Stack<Type>::Stack():list()
{
	//�������Ȃ�
}

template<typename Type>
Stack<Type>::~Stack()
{
	//�������Ȃ�
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
	//�v�f���Ȃ���ΏI��
	if (GetSize() == static_cast<uint32_t>(0)) {
		return false;
	}

	//�����_�~�[��1�O�̃f�[�^�������Ɉڂ�
	DoublyLinkedList<Type>::Iterator end = --list.GetEnd();
	destination = std::move(*end);
	//�f�[�^�̈ړ����̗v�f���폜����
	return list.Delete(end);
}
