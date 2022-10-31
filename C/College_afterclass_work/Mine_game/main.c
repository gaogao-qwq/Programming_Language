#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

double startTime, finishTime;

void game()
{
	srand((unsigned int)time(NULL)); //��ʼ�������������

	init_mine();
	set_mine();
	print_mine();
	printf("\n");
	print_player();
	
	safe_mine();

	startTime = clock(); //��ȡ��Ϸ��ʼʱ��
	bool isExplode = false;
	
	if (count_show_mine() == COUNT) //һ����Ӯ�����
	{
		print_mine();
		printf("���Ӯ��\n\n");
		return;
	}
	print_player(); //��ӡ�������
	
	while (true) //ѭ��ɨ��
	{
		isExplode = sweep_mine(); //ɨ��,�ȵ��׷���true��û�вȵ��׷���false
		if (count_show_mine() == COUNT) //��������̵�'*'����Ϊ����ʱ��ɨ����ɣ���Ϸʤ��
		{
			print_mine(); //��ӡ���������
			printf("���Ӯ��\n\n");
			finishTime = clock(); //��ȡ��Ϸ����ʱ��
			printf("��ʱ%d ��\n", (int)(finishTime - startTime) / CLOCKS_PER_SEC);
			break;
		}
		if (isExplode) //�ж��Ƿ�ȵ���
		{
			printf("����ը��\t");
			finishTime = clock(); //��ȡ��Ϸ����ʱ��
			printf("��ʱ%d ��\n", (int)(finishTime - startTime) / CLOCKS_PER_SEC);
			print_mine(); //��ӡ���������鿴�׵ķֲ�
			break;
		}
		print_player(); //��ӡ�������
	}
}

int main()
{
	int input = 0;

	menu(); //�˵�

	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			exit(true); //�˳���Ϸ
			break;
		default:
			printf("���������������\n");
			break;
		}
		printf("contiue?\n");
		menu();
	} while (true); //ѭ������Ϸ

	system("pause");
	return 0;
}


