#include<fstream>
#include"DoublyLinkedList.h"
#include"ResultData.h"

int main() {

	std::ifstream ifsScoreFile;
	ifsScoreFile.open("Scores.txt");

	if (!ifsScoreFile) {
		printf("�t�@�C�����J���܂���ł���");
		getchar();
		return 1;
	}

	DoublyLinkedList<ResultData> list;
	DoublyLinkedList<ResultData>::Iterator it;

	while (ifsScoreFile.eof() == false)
	{
		//�t�@�C���̓ǂݎ��

		ResultData data{};
		std::string readString{};

		//�X�R�A�̓ǂݍ���
		std::getline(ifsScoreFile, readString, '\t');

		//�t�@�C���I�[�̉��s�𖳎�
		if (ifsScoreFile.eof())
		{
			break;
		}

		//�����̕�����𐮐��l�ɕϊ�
		data.score = std::stoi(readString);


		//���O�̓ǂݍ���
		//ResultData�ɒ��ړǂݍ���
		std::getline(ifsScoreFile, data.name, '\n');

		//�t�@�C���I�[�̉��s�𖳎�
		if (ifsScoreFile.eof())
		{
			break;
		}

		//�ǂݎ�����f�[�^�̑}��
		it = list.GetEnd();
		list.Insert(it, data);
	}

	ifsScoreFile.close();

	//�ǂݍ��񂾒l���o��
	const DoublyLinkedList<ResultData>::Iterator end = list.GetEnd();
	for (it = list.GetBegin(); it != end; it++) {
		printf(std::to_string(it->score).c_str());
		printf("\t");
		printf(it->name.c_str());
		printf("\n");
	}

	printf("\nENTER�L�[�������ƏI�����܂�");
	getchar();
	return 0;
}