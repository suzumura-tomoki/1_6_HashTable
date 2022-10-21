#pragma once
#include"DoublyLinkedList.h"
#include<assert.h>

template<typename Type>
DoublyLinkedList<Type>::DoublyLinkedList()
	:dummy({ nullptr,nullptr,Type() })
	, pTop(&dummy)
	, size(0)
{
	//�������q���X�g�ŏ�����
}


template<typename Type>
DoublyLinkedList<Type>::~DoublyLinkedList()
{
	DoublyLinkedList<Type>::Iterator it = GetBegin();

	while (size > 0)
	{
		Delete(it);
	}
}


template<typename Type>
unsigned int DoublyLinkedList<Type>::GetSize()const
{
	return size;
}


template<typename Type>
bool DoublyLinkedList<Type>::Insert(ConstIterator& iterator, const Type& data)
{
	if (this != iterator.pList)
	{
		return false;
	}

	if (iterator.pNode == nullptr)
	{
		return false;
	}

	//�V�����v�f�𐶐�
	Node* pNewNode = new Node;
	pNewNode->data = data;
	pNewNode->pNext = iterator.pNode;//�ǉ�����ʒu�ɂ������v�f�����̗v�f�ɂ���
	pNewNode->pPrevious = pNewNode->pNext->pPrevious;//�ǉ��ʒu�̑O�̗v�f��O�̗v�f�ɂ���

	//�O��̗v�f���V�����v�f���Q�Ƃ���悤�ɂ���
	pNewNode->pNext->pPrevious = pNewNode;

	if (pNewNode->pPrevious != nullptr)
	{
		//�O�̗v�f������ꍇ
		pNewNode->pPrevious->pNext = pNewNode;
	}

	//�擪�ɒǉ������ꍇ�ɐ擪�|�C���^���X�V
	if (iterator.pNode == pTop)
	{
		pTop = pNewNode;
	}

	iterator--;//�ǉ������v�f�ֈړ�
	this->size++;

	return true;
}

template<typename Type>
bool DoublyLinkedList<Type>::Delete(ConstIterator& iterator)
{
	// �C�e���[�^�������̃��X�g�̃C�e���[�^�����f����
	if (this != iterator.pList)
	{
		return false;
	}

	//�s���ȃC�e���[�^�����f����
	if (iterator.pNode == nullptr)
	{
		return false;
	}

	//�_�~�[�m�[�h�����f����
	if (iterator.pNode == &iterator.pList->dummy)
	{
		return false;
	}

	//�O�ɗv�f������΍폜�Ώۂ̎��̗v�f���w���悤�ɕύX
	if (iterator.pNode->pPrevious != nullptr)
	{
		iterator.pNode->pPrevious->pNext = iterator.pNode->pNext;
	}

	//���̗v�f���폜�Ώۂ̑O�̗v�f���w���悤�ɕύX
	iterator.pNode->pNext->pPrevious = iterator.pNode->pPrevious;

	Node* pDeleteNode = iterator.pNode;

	iterator++;//���̃m�[�h�ֈړ�

	//�폜�Ώۂ��擪��������擪�|�C���^���X�V
	if (pDeleteNode == pTop)
	{
		pTop = iterator.pNode;
	}

	delete pDeleteNode;

	size--;

	return true;
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::GetBegin()
{
	return Iterator(this, pTop);
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator DoublyLinkedList<Type>::GetConstBegin()const
{
	return ConstIterator(this, pTop);
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::GetEnd()
{
	return Iterator(this, &dummy);
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator DoublyLinkedList<Type>::GetConstEnd()const
{
	//�R���X�g�����o�֐��̒��ł̓����o�ϐ����R���X�g�Ƃ��Ĉ����܂����A�����ɓn���Ȃ����߃R���X�g�������܂�
	return ConstIterator(this, const_cast<Node*>(&dummy));
}

template<typename Type>
template<typename KeyType>
void DoublyLinkedList<Type>::Sort(SortOrder order, FuncGetKey<KeyType> GetKey)
{
	if (size <= 1)
	{
		//�v�f���P�ȉ��̏ꍇ�I��
		return;
	}

	if (GetKey == nullptr)
	{
		//�L�[�̎w�肪�Ȃ��ꍇ�I��
		return;
	}

	QuickSort<KeyType>(order, GetKey, GetBegin(), GetEnd() - 1, size);

}

template<typename Type>
template<typename KeyType>
inline void DoublyLinkedList<Type>::QuickSort(SortOrder order, FuncGetKey<KeyType> GetKey, Iterator head, Iterator tail, uint32_t _size) {

	//�Q�l�ɂ�������
	// �E�B�L�y�f�B�A
	//https://ja.wikipedia.org/wiki/%E3%82%AF%E3%82%A4%E3%83%83%E3%82%AF%E3%82%BD%E3%83%BC%E3%83%88#cite_ref-4
	//�ߋ��̎���̃N�C�b�N�\�[�g

	//�ċA�����Ƃ��ɗv�f��1��������I��
	if (_size <= 1)
		return;

	//��l�����߂�
	// �擪�E�Q�ԖځE�������璆�Ԃ̒l��I�ъ�l�Ƃ���
	const KeyType& keyHead = GetKey(*head);
	const KeyType& keySecond = GetKey(*(head + 1));
	const KeyType& keyTail = GetKey(*tail);

	const KeyType* pPIVOT = GetPivot(keyHead, keySecond, keyTail);

	//����ւ���v�f��T��
	Iterator workHead = head;
	Iterator workTail = tail;
	int cntHeadMoved = 0;
	int cntTailMoved = 0;

	//����������s�{�b�g���܂߂ĒT���@�ȏ�ȉ�(�ȉ��ȏ�)
	//�S�ē����f�[�^�ł��S�ē���ւ��邪����P�[�X���Ȃ�
	while (true) {
		switch (order)
		{
		case SortOrder::ASCENDING_ORDER:
			//�擪���珇�Ɋ�l�ȏ�̒l�����v�f��T��
			//�s�{�b�g���f�[�^���������ԁA�����ɐi��
			while (GetKey(*workHead) < *pPIVOT) {
				workHead++;
				cntHeadMoved++;
			}
			//�������珇�Ɋ�l�ȉ��̒l�����v�f��T��
			//�s�{�b�g���f�[�^���傫���ԁA�擪�ɐi��
			while (GetKey(*workTail) > *pPIVOT) {
				workTail--;
				cntTailMoved++;
			}
			break;
		case SortOrder::DESCENDING_ORDER:
			//�擪���珇�Ɋ�l�ȉ��̒l�����v�f��T��
			//�s�{�b�g���f�[�^���傫���ԁA�����ɐi��
			while (GetKey(*workHead) > *pPIVOT) {
				workHead++;
				cntHeadMoved++;
			}
			//�������珇�Ɋ�l�ȏ�̒l�����v�f��T��
			//�s�{�b�g���f�[�^���������ԁA�擪�ɐi��
			while (GetKey(*workTail) < *pPIVOT) {
				workTail--;
				cntTailMoved++;
			}
			break;
		}

		//�w�b�h�ƃe�[���������ꏊ�܂��͂������Ă���ƒT���I��
		if (cntHeadMoved + cntTailMoved >= _size - 1) {
			break;
		}

		//�T�������v�f�����ւ���
		Swap(workHead, workTail);

		//�s�{�b�g������ւ���ꂽ��A�s�{�b�g�̎Q�Ɛ��ύX����
		if (&GetKey(*workHead) == pPIVOT) {
			pPIVOT = &GetKey(*workTail);
		}
		else if (&GetKey(*workTail) == pPIVOT)
		{
			pPIVOT = &GetKey(*workHead);
		}

		//����ւ����v�f��T������O��
		workHead++;
		cntHeadMoved++;
		workTail--;
		cntTailMoved++;
	}

	//����ւ���v�f���Ȃ��Ȃ�܂ōċA
	//workHead��workTail�͓����ꏊ�ɂ��邩�A�P�������ėׂ荇���Ă���
	//�����ꏊ�ɂ���Ƃ��͂��̏ꏊ���s�{�b�g�ł��肱�̈ʒu���瓮�����K�v���Ȃ��̂�
	//�P���߂�s�{�b�g�������č��E�̏W���ɂ��čċA
	//�������ėׂ荇���Ă���Ȃ�P���߂��č��E�̏W���ɂ��čċA
	QuickSort(order, GetKey, head, --workHead, cntHeadMoved);
	QuickSort(order, GetKey, ++workTail, tail, cntTailMoved);
}

template<typename Type>
template<typename KeyType>
inline const KeyType* DoublyLinkedList<Type>::GetPivot(const KeyType& head, const KeyType& middle, const KeyType& tail)
{
	if (head < middle) {
		if (tail < head) {
			return &head;
		}
		else if (middle < tail) {
			return &middle;
		}
		else {
			return &tail;
		}
	}
	else {
		if (tail > head) {
			return &head;
		}
		else if (middle > tail) {
			return &middle;
		}
		else {
			return &tail;
		}
	}
}

template<typename Type>
inline void DoublyLinkedList<Type>::Swap(Iterator& it1, Iterator& it2)
{
	//���ӁF�l�������������PIVOT�̎Q�Ƃ���f�[�^���ς��

#pragma region //�f�[�^�̃��[�u
	//���[�u������ƃs�{�b�g�̎Q�Ɛ悪�ς��(�Q�Ƃł��|�C���^�ł���������������)�@�������z�u�͕ς��Ȃ��͂��@�|�C���^�̓A�h���X���w�����������Q�ƂƓ�������������͎̂Q�Ƃ̃|�C���^������H
	// �Q�Ɛ�̃L�[���i�[����Ă���\���̂����[�u����ĂȂ��Ȃ遨�@�L�[�̎Q�Ɛ�����������@�Q�Ɛ�̃L�[���i�[����Ă���\���̂ɐV�����������̈悪���[�u����遨�@�L�[�̎Q�Ɛ悪�V�����������̈�ɂȂ�H

	Type work = std::move(*it1);
	*it1 = std::move(*it2);
	*it2 = std::move(work);

#pragma endregion//�f�[�^�̃��[�u

#pragma region //�|�C���^�̌q���ւ�

	//�v�f���ׂ荇���Ă���Ƃ��t���ւ�����肭�����Ȃ��̂ŕ��򂷂�K�v������
	//�R�[�h���璷�ɂȂ�̂Œ��~

	//it1�̑O��̃m�[�h��it2�̃m�[�h�������悤�ɕύX
	//if (nullptr != it1.pNode->pPrevious) {
	//	it1.pNode->pPrevious->pNext = it2.pNode;
	//}
	//if (nullptr != it1.pNode->pNext) {
	//	it1.pNode->pNext->pPrevious = it2.pNode;
	//}

	////it2�̑O��̃m�[�h��it1�̃m�[�h�������悤�ɕύX
	//if (nullptr != it2.pNode->pPrevious) {
	//	it2.pNode->pPrevious->pNext = it1.pNode;
	//}
	//if (nullptr != it2.pNode->pNext) {
	//	it2.pNode->pNext->pPrevious = it1.pNode;
	//}

	////it1��it2�̃m�[�h�̑O��ւ̃|�C���^�����ւ���
	//Node* pWork = it1.pNode->pPrevious;
	//it1.pNode->pPrevious = it2.pNode->pPrevious;
	//it2.pNode->pPrevious = pWork;

	//pWork = it1.pNode->pNext;
	//it1.pNode->pNext = it2.pNode->pNext;
	//it2.pNode->pNext = pWork;

	////�C�e���[�^�̎����m�[�h�����ւ���
	//Iterator work = it1;
	//it1 = it2;
	//it2 = work;
#pragma endregion //�|�C���^�̌q���ւ�

}

template<typename Type>
DoublyLinkedList<Type>::ConstIterator::ConstIterator()
	:pList(nullptr)
	, pNode(nullptr)
{
	//�������q���X�g�ŏ�����
}

template<typename Type>
DoublyLinkedList<Type>::ConstIterator::ConstIterator(const DoublyLinkedList<Type>* _pList, Node* _pNode)
	:pList(_pList)
	, pNode(_pNode)
{
	//�������q���X�g�ŏ�����
}

template<typename Type>
DoublyLinkedList<Type>::ConstIterator::ConstIterator(const ConstIterator& obj)
{
	this->pList = obj.pList;
	this->pNode = obj.pNode;
}

template<typename Type>
DoublyLinkedList<Type>::ConstIterator::~ConstIterator()
{
	//�������Ȃ�
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator& DoublyLinkedList<Type>::ConstIterator::operator++()
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ��ꍇ
	assert(this->pNode != nullptr);//�m�[�h�̎Q�Ƃ��Ȃ��ꍇ
	assert(this->pNode != &this->pList->dummy);//�����m�[�h�ł���ꍇ

	pNode = pNode->pNext;
	return *this;
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator DoublyLinkedList<Type>::ConstIterator::operator++(int)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode != nullptr);//�m�[�h�̎Q�Ƃ��Ȃ��ꍇ
	assert(this->pNode != &this->pList->dummy);//�����m�[�h�ł���

	ConstIterator cit = *this;
	operator++();
	return cit;
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator& DoublyLinkedList<Type>::ConstIterator::operator--()
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode != nullptr);//�m�[�h�̎Q�Ƃ��Ȃ��ꍇ
	assert(this->pNode->pPrevious != nullptr);//�擪�m�[�h�ł���@�܂��̓��X�g����̎��̖����m�[�h
	pNode = pNode->pPrevious;
	return *this;
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator DoublyLinkedList<Type>::ConstIterator::operator--(int)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode != nullptr);//�m�[�h�̎Q�Ƃ��Ȃ��ꍇ
	assert(this->pNode->pPrevious != nullptr);//�擪�m�[�h�ł���@�܂��̓��X�g����̎��̖����m�[�h
	ConstIterator cit = *this;
	operator--();
	return cit;
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator DoublyLinkedList<Type>::ConstIterator::operator+(int n)const
{
	//�G���[�`�F�b�N�@���̍��ڂ�++���Z�q�̌Ăяo�����ɍs����
	//��Ƀm�[�h�ɃA�N�Z�X����̂Ńm�[�h�̎Q�Ƃ̂݃`�F�b�N���Ă���
	assert(this->pNode != nullptr);//�m�[�h�̎Q�Ƃ��Ȃ��ꍇ

	if (n >= 0)
	{//�����ɐi��

		ConstIterator cit = *this;

		for (int i = 0; i < n; i++) {

			//�������z����ƃA�T�[�V�������ł�悤�ύX
			// �Ӑ}���Ȃ������œ����Ă��܂����A�G���[�ɂȂ�ق����ǂ��Ɣ��f
			// �R�[�h�ʂ��኱�y��
			//�������z���Ȃ��悤�ɒ�~����
			//if (cit.pNode->pNext == nullptr)
			//{
			//	return cit;
			//}

			cit++;
		}

		return cit;
	}
	else
	{//�擪�ɐi��

		//��Βl���擾
		n = static_cast<int>(labs(n));

		//�擪�ɐi�߂��C�e���[�^��Ԃ�
		return (*this) - n;
	}
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator DoublyLinkedList<Type>::ConstIterator::operator-(int n)const
{
	//�G���[�`�F�b�N�@���̍��ڂ�++���Z�q�̌Ăяo�����ɍs����
	//��Ƀm�[�h�ɃA�N�Z�X����̂Ńm�[�h�̎Q�Ƃ̂݃`�F�b�N���Ă���
	assert(this->pNode != nullptr);//�m�[�h�̎Q�Ƃ��Ȃ��ꍇ

	if (n >= 0)
	{//�擪�ɐi��

		ConstIterator cit = *this;

		for (int i = 0; i < n; i++) {

			//�擪���z����ƃA�T�[�V�������ł�悤�ύX
			// �Ӑ}���Ȃ������œ����Ă��܂����A�G���[�ɂȂ�ق����ǂ��Ɣ��f
			// �R�[�h�ʂ��኱�y��
			//�擪���z���Ȃ��悤�ɒ�~����
			//if (cit.pNode->pPrevious == nullptr)
			//{
			//	return cit;
			//}

			cit--;
		}

		return cit;
	}
	else
	{//�����ɐi��

		//��Βl���擾
		n = static_cast<int>(labs(n));

		//�����ɐi�߂��C�e���[�^��Ԃ�
		return (*this) + n;
	}
}

template<typename Type>
bool DoublyLinkedList<Type>::ConstIterator::operator==(const ConstIterator& it)const
{
	return this->pNode == it.pNode;
}

template<typename Type>
bool DoublyLinkedList<Type>::ConstIterator::operator!=(const ConstIterator& it)const
{
	return !(*this == it);
}

template<typename Type>
const Type& DoublyLinkedList<Type>::ConstIterator::operator*()const
{
	assert(pList != nullptr);//pList��nullptr�łȂ�����
	assert(pNode != &pList->dummy);//pNode���_�~�[�łȂ�����

	return pNode->data;
}

template<typename Type>

const Type* DoublyLinkedList<Type>::ConstIterator::operator->()const
{
	assert(pList != nullptr);//pList��nullptr�łȂ�����
	assert(pNode != &pList->dummy);//pNode���_�~�[�łȂ�����

	return &pNode->data;
}

template<typename Type>
DoublyLinkedList<Type>::Iterator::Iterator()
{
	//�������Ȃ��@�����o�����Ȃ�
}

template<typename Type>
DoublyLinkedList<Type>::Iterator::Iterator(DoublyLinkedList<Type>* _pList, Node* _pNode) : ConstIterator(_pList, _pNode)
{
	//���N���XConstIterator�̃R���X�g���N�^�Ɉ�����n��
	//�����ł͉������Ȃ�
}

template<typename Type>
DoublyLinkedList<Type>::Iterator::~Iterator()
{
	//�������Ȃ�
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator& DoublyLinkedList<Type>::Iterator::operator++()
{
	ConstIterator::operator++();

	return *this;
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::Iterator::operator++(int)
{
	Iterator it = *this;

	operator++();

	return it;
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator& DoublyLinkedList<Type>::Iterator::operator--()
{
	ConstIterator::operator--();

	return *this;
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::Iterator::operator--(int)
{
	Iterator it = *this;

	operator--();

	return it;
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::Iterator::operator+(int n)const
{
	ConstIterator cit = ConstIterator::operator+(n);

	//�֐���const�̂��߁A�ʂ̃C���X�^���X�̐e�N���X�̃����o��const�Ƃ��Ĉ����Ă��܂��̂ŁA�����Ƃ��ēn�����߂�const���O���܂�
	return Iterator(const_cast<DoublyLinkedList<Type>*>(cit.pList), const_cast<Node*>(cit.pNode));
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::Iterator::operator-(int n)const
{
	ConstIterator cit = ConstIterator::operator-(n);

	//�֐���const�̂��߁A�ʂ̃C���X�^���X�̐e�N���X�̃����o��const�Ƃ��Ĉ����Ă��܂��̂ŁA�����Ƃ��ēn�����߂�const���O���܂�
	return Iterator(const_cast<DoublyLinkedList<Type>*>(cit.pList), const_cast<Node*>(cit.pNode));
}

template<typename Type>
Type& DoublyLinkedList<Type>::Iterator::operator*()
{
	//�R���X�g�C�e���[�^�̋@�\�𗬗p���ăR���X�g������
	return const_cast<Type&>(ConstIterator::operator*());
}

template<typename Type>
Type* DoublyLinkedList<Type>::Iterator::operator->()
{
	//�R���X�g�C�e���[�^�̋@�\�𗬗p���ăR���X�g������
	return const_cast<Type*>(ConstIterator::operator->());//�����ł̓|�C���^��->�͌Ă΂�Ă��Ȃ�
}
