#pragma once
#include"DoublyLinkedList.h"

/**
 * @brief �f�[�^���i�[���A�i�[���ꂽ���Ƀf�[�^�����o���܂�
 * @tparam Type �i�[����f�[�^�̌^
*/
template<typename Type>
class Queue
{
public:
	/** @brief �R���X�g���N�^ */
	Queue();
	/** @brief �f�t�H���g�R�s�[�R���X�g���N�^ */
	Queue(const Queue& obj) = default;
	/** @brief �f�X�g���N�^ */
	virtual ~Queue();

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
	 * @brief �擪�̗v�f�����o���܂�
	 * @param[out] ���o�����v�f�̊i�[��
	 * @return �L���[����̏ꍇ�͉������o���ꂸfalse��߂��܂�
	 */
	bool Pop(Type& destination);

private:
	/** @brief �f�[�^���i�[���郊�X�g */
	DoublyLinkedList<Type> list;
};

#include"Queue.inl"
