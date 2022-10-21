#pragma once
#include"DoublyLinkedList.h"

/**
 * @brief �f�[�^���i�[���A��Ɋi�[���ꂽ�f�[�^���珇�Ɏ��o���܂�
 * @tparam Type �i�[����f�[�^�̌^
 */
template<typename Type>
class Stack
{
public:
	/** @brief �R���X�g���N�^ */
	Stack();
	/** @brief �f�t�H���g�R�s�[�R���X�g���N�^ */
	Stack(const Stack& obj) = default;
	/** @brief �f�X�g���N�^ */
	virtual ~Stack();

	/**
	 * @brief �f�[�^�̐����擾���܂�
	 * @return �f�[�^�̐�
	 */
	uint32_t GetSize()const;

	/**
	 * @brief �����ɗv�f��ǉ����܂�
	 * @param[in] �ǉ�����f�[�^
	 * @return �ǉ��̐���
	 */
	bool Push(const Type& data);

	/**
	 * @brief �����̗v�f�����o���܂�
	 * @param[out] ���o�����v�f�̊i�[��
	 * @return �X�^�b�N����̏ꍇ�͉������o���ꂸfalse��߂��܂�
	 */
	bool Pop(Type& destination);

private:
	/** @brief �f�[�^���i�[���郊�X�g */
	DoublyLinkedList<Type> list;
};

#include"Stack.inl"
