#pragma once

/**
 * @brief �o�������X�g�̃N���X\n
 *		  �ʖ�bi-directional list
 * @tparam Type ���X�g�Ɋi�[����f�[�^�̌^
 */
template<typename Type>
class DoublyLinkedList
{
private:

	/** @brief �o�������X�g�̃m�[�h */
	struct Node {
		DoublyLinkedList<Type>::Node* pPrevious = nullptr;
		DoublyLinkedList<Type>::Node* pNext = nullptr;
		Type data;
	};

public:

	/**
	 * @brief �o�������X�g�̃R���X�g�C�e���[�^\n
	 *		  �����Z�q�܂���->���Z�q�Ńf�[�^�ɃA�N�Z�X�ł��܂�
	 */
	class ConstIterator {

		friend DoublyLinkedList<Type>;
		
	public:
		/** @brief �R���X�g���N�^*/
		ConstIterator();
		/**
		 * @brief �R���X�g���N�^
		 * @param[in] _pList �Q�Ƃ��郊�X�g�ւ̃|�C���^\n
		 *					 nullptr�̏ꍇ�A�}����폜�Ɏ��s���A�C�e���[�^���ړ�����ۂɃG���[�ɂȂ�܂�\n
		 *					 _pList��_pNode�Ɋ֘A�������ꍇ�A�Q�Ƃ��郊�X�g�ɃC�e���[�^��n�����Ƃő}����폜���s���܂����A���ۂɂ̓m�[�h�̏������郊�X�g���X�V����܂�
		 * @param[in] _pNode �R���X�g�C�e���[�^�������m�[�h�ւ̃|�C���^\n
		 *					 nullptr�̏ꍇ�͑}����폜���s��ꂸ�A�C�e���[�^���ړ�����ۂɃG���[�ɂȂ�܂��B
		 */
		ConstIterator(const DoublyLinkedList<Type>* _pList, Node* _pNode);

		/**
		 * @brief �R�s�[�R���X�g���N�^
		 * @param[in] obj �R�s�[���̃I�u�W�F�N�g
		 */
		ConstIterator(const ConstIterator& obj);

		/** @brief �f�X�g���N�^ */
		virtual ~ConstIterator();

		/**
		 * @brief ���̗v�f�Ɉړ����܂�
		 * @return �ړ������R���X�g�C�e���[�^
		 */
		ConstIterator& operator++();
		/**
		 * @brief ���̗v�f�Ɉړ����܂�
		 * @return �ړ����Ă��Ȃ��R���X�g�C�e���[�^
		 */
		ConstIterator operator++(int);
		/**
		 * @brief �O�̗v�f�Ɉړ����܂�
		 * @return �ړ������R���X�g�C�e���[�^
		 */
		ConstIterator& operator--();
		/**
		 * @brief �O�̗v�f�Ɉړ����܂�
		 * @return �ړ����Ă��Ȃ��R���X�g�C�e���[�^
		 */
		ConstIterator operator--(int);

		/**
		 * @brief ���������Ɏw�肵���������ړ������R���X�g�C�e���[�^��Ԃ��܂�
		 * @param[in] n �ړ���\n
		 *				���X�g�͈̔͂��z���Ďw�肵���ꍇ�A�擪�܂��͖����̃R���X�g�C�e���[�^��Ԃ��܂�
		 * @return �ړ������R���X�g�C�e���[�^
		 */
		ConstIterator operator+(int n)const;
		/**
		 * @brief �擪�����Ɏw�肵���������ړ������R���X�g�C�e���[�^��Ԃ��܂�
		 * @param[in] n �ړ���\n
		 *				���X�g�͈̔͂��z���Ďw�肵���ꍇ�A�擪�܂��͖����̃R���X�g�C�e���[�^��Ԃ��܂�
		 * @return �ړ������R���X�g�C�e���[�^
		 */
		ConstIterator operator-(int n)const;

		/**
		 * @brief �C�e���[�^�̎����m�[�h���������̂���r���܂�
		 * @param[in] it ��r�Ώ�
		 * @return true:�����m�[�h���w���Ă���\n
		 *		   false:�قȂ�m�[�h���w���Ă���
		 */
		bool operator==(const ConstIterator& it)const;
		/**
		 * @brief �C�e���[�^�̎����m�[�h���قȂ���̂���r���܂�
		 * @param[in] it ��r�Ώ�
		 * @return true:�قȂ�m�[�h���w���Ă���\n
		 *		   false:�����m�[�h���w���Ă���
		 */
		bool operator!=(const ConstIterator& it)const;

		/**
		 * @brief �R���X�g�C�e���[�^�������v�f�̃R���X�g�Q�Ƃ��擾���܂�
		 * @return �C�e���[�^�������v�f�̃R���X�g�Q��
		 */
		const Type& operator*()const;
		/**
		 * @brief �R���X�g�C�e���[�^�������R���X�g�v�f���擾���܂�\n
		 *		  �ÖٓI�ɖ߂�l�̎���->���Ă΂�܂�
		 * @return �R���X�g�C�e���[�^�������R���X�g�v�f�ւ̃|�C���^
		 */
		const Type* operator->()const;

	protected:
		/** @brief ���̃C�e���[�^�������m�[�h�ւ̃|�C���^ */
		Node* pNode = nullptr;
		/** @brief ���̃C�e���[�^���Q�Ƃ��Ă��郊�X�g�ւ̃|�C���^ */
		const DoublyLinkedList<Type>* pList = nullptr;
	private:

	};

	/**
	 * @brief �o�������X�g�̃C�e���[�^\n
	 *		 �p���F�R���X�g�C�e���[�^\n
	 *		 �����Z�q�܂���->���Z�q�Ńf�[�^�ɃA�N�Z�X�ł��܂�
	 */
	class Iterator :public ConstIterator {
	public:
		/** @brief �R���X�g���N�^ */
		Iterator();
		/**
		 * @brief �R���X�g���N�^
		 * @param[in] _pList �Q�Ƃ��郊�X�g�ւ̃|�C���^\n
		 *					 nullptr�̏ꍇ�A�}����폜�Ɏ��s���A�C�e���[�^���ړ�����ۂɃG���[�ɂȂ�܂�\n
		 *					 _pList��_pNode�Ɋ֘A�������ꍇ�A�Q�Ƃ��郊�X�g�ɃC�e���[�^��n�����Ƃő}����폜���s���܂����A���ۂɂ̓m�[�h�̏������郊�X�g���X�V����܂�
		 * @param[in] _pNode �C�e���[�^�������m�[�h�ւ̃|�C���^\n
		 *					 nullptr�̏ꍇ�͑}����폜���s��ꂸ�A�C�e���[�^���ړ�����ۂɃG���[�ɂȂ�܂��B
		 */
		Iterator(DoublyLinkedList<Type>* _pList, Node* _pNode);

		/**
		 * @brief �f�t�H���g�R�s�[�R���X�g���N�^
		 * @param[in] obj �R�s�[���̃I�u�W�F�N�g
		 */
		Iterator(const Iterator& obj) = default;

		/** @brief �f�X�g���N�^ */
		virtual ~Iterator();

		/**
		 * @brief ���̗v�f�Ɉړ����܂�
		 * @return �ړ������C�e���[�^
		 */
		Iterator& operator++();
		/**
		 * @brief ���̗v�f�Ɉړ����܂�
		 * @return �ړ����Ă��Ȃ��C�e���[�^
		 */
		Iterator operator++(int);
		/**
		 * @brief �O�̗v�f�Ɉړ����܂�
		 * @return �ړ������C�e���[�^
		 */
		Iterator& operator--();
		/**
		 * @brief �O�̗v�f�Ɉړ����܂�
		 * @return �ړ����Ă��Ȃ��C�e���[�^
		 */
		Iterator operator--(int);

		/**
		 * @brief ���������Ɏw�肵���������ړ������C�e���[�^��Ԃ��܂�
		 * @param[in] n �ړ���\n
		 *				���X�g�͈̔͂��z���Ďw�肵���ꍇ�A�擪�܂��͖����̃C�e���[�^��Ԃ��܂�
		 * @return �ړ������C�e���[�^
		 */
		Iterator operator+(int n)const;
		/**
		 * @brief �擪�����Ɏw�肵���������ړ������C�e���[�^��Ԃ��܂�
		 * @param[in] n �ړ���\n
		 *				���X�g�͈̔͂��z���Ďw�肵���ꍇ�A�擪�܂��͖����̃C�e���[�^��Ԃ��܂�
		 * @return �ړ������C�e���[�^
		 */
		Iterator operator-(int n)const;

		/**
		 * @brief �C�e���[�^�������v�f�̎Q�Ƃ��擾���܂�
		 * @return �C�e���[�^�������v�f�̎Q��
		 */
		Type& operator*();
		/**
		 * @brief �C�e���[�^�������v�f���擾���܂�\n
		 *		  �ÖٓI�ɖ߂�l�̎���->���Ă΂�܂�
		 * @return �C�e���[�^�������v�f�ւ̃|�C���^
		 */
		Type* operator->();

	private:

	};

	/** @brief �R���X�g���N�^ */
	DoublyLinkedList();

	/** @brief �f�t�H���g�R�s�[�R���X�g���N�^ */
	DoublyLinkedList(const DoublyLinkedList<Type>& obj) = default;

	/**
	 * @brief �f�X�g���N�^\n
	 * �m�ۂ����m�[�h��S�ĉ������
	 */
	virtual ~DoublyLinkedList();

	/**
	 * @brief �v�f�����擾���܂�
	 * @return �v�f��
	 */
	unsigned int GetSize()const;

	/**
	 * @brief �C�e���[�^�������v�f�̑O�ɗv�f��}�����܂�\n
	 *		  �ǉ������v�f�ɃC�e���[�^���ړ������܂�
	 * @param[in,out] iterator �}���ʒu�̃C�e���[�^�A�}�������v�f�Ɉړ����܂�
	 * @param[in]	  data     �i�[����f�[�^
	 * @return true:�}���ɐ���\n
	 *		   false:�}���Ɏ��s\n
	 * �ʂ̃��X�g�̃C�e���[�^��n�����ꍇ��A���X�g��m�[�h�ւ̎Q�Ƃ��Ȃ��C�e���[�^��n�����ꍇ�ɑ}���Ɏ��s���܂�
	 */
	bool Insert(ConstIterator& iterator, const Type& data);

	/**
	 * @brief �C�e���[�^�������v�f���폜���܂�\n
	 *		  �폜�����v�f�̎��̗v�f�ɃC�e���[�^���ړ������܂�
	 * @param[in,out] iterator �폜����v�f�̃C�e���[�^
	 * @return true:�폜�ɐ���\n
	 *		   false:�폜�Ɏ��s\n
	 * �ʂ̃��X�g�̃C�e���[�^��n�����ꍇ��A���X�g��m�[�h�ւ̎Q�Ƃ��Ȃ��C�e���[�^��n�����ꍇ�ɍ폜�Ɏ��s���܂�\n
	 * �����̃C�e���[�^��n�����ꍇ�����s���܂�
	 */
	bool Delete(ConstIterator& iterator);

	/**
	 * @brief �擪�̃C�e���[�^���擾
	 * @return �擪�̃C�e���[�^
	 */
	Iterator GetBegin();

	/**
	 * @brief �擪�̃R���X�g�C�e���[�^���擾
	 * @return �擪�̃R���X�g�C�e���[�^
	 */
	ConstIterator GetConstBegin()const;

	/**
	 * @brief �����̃C�e���[�^���擾
	 * @return �����̃C�e���[�^
	 */
	Iterator GetEnd();

	/**
	 * @brief �����̃R���X�g�C�e���[�^���擾
	 * @return �����̃R���X�g�C�e���[�^
	 */
	ConstIterator GetConstEnd()const;

private:

	/** @brief �����������_�~�[�v�f�@�f�[�^�͊i�[����Ȃ� */
	Node dummy;
	/** @brief �擪�v�f�ւ̃|�C���^ */
	Node* pTop;
	/** @brief �v�f�̐� */
	unsigned int size;
};

#include"DoublyLinkedList.inl"