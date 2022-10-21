#pragma once
#include"Queue.h"

template<typename Type>
Queue<Type>::Queue():list()
{
	//�������Ȃ�
}

template<typename Type>
Queue<Type>::~Queue()
{
	//�������Ȃ�
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
	//�v�f���Ȃ���ΏI��
	if (GetSize() == static_cast<uint32_t>(0)) {
		return false;
	}

	//�擪�v�f�̃f�[�^�������Ɉڂ�
	DoublyLinkedList<Type>::Iterator begin = list.GetBegin();
	destination = std::move(*begin);
	//�f�[�^�̈ړ����̗v�f���폜����
	return list.Delete(begin);
}
