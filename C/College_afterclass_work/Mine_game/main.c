#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

double startTime, finishTime;

void game()
{
	srand((unsigned int)time(NULL)); //初始化随机数生成器

	init_mine();
	set_mine();
	print_mine();
	printf("\n");
	print_player();
	
	safe_mine();

	startTime = clock(); //获取游戏开始时间
	bool isExplode = false;
	
	if (count_show_mine() == COUNT) //一步就赢的情况
	{
		print_mine();
		printf("玩家赢！\n\n");
		return;
	}
	print_player(); //打印玩家棋盘
	
	while (true) //循环扫雷
	{
		isExplode = sweep_mine(); //扫雷,踩到雷返回true，没有踩到雷返回false
		if (count_show_mine() == COUNT) //若玩家棋盘的'*'个数为雷数时，扫雷完成，游戏胜利
		{
			print_mine(); //打印设计者棋盘
			printf("玩家赢！\n\n");
			finishTime = clock(); //获取游戏结束时间
			printf("用时%d 秒\n", (int)(finishTime - startTime) / CLOCKS_PER_SEC);
			break;
		}
		if (isExplode) //判断是否踩到雷
		{
			printf("被雷炸死\t");
			finishTime = clock(); //获取游戏结束时间
			printf("用时%d 秒\n", (int)(finishTime - startTime) / CLOCKS_PER_SEC);
			print_mine(); //打印设计者雷阵查看雷的分布
			break;
		}
		print_player(); //打印玩家棋盘
	}
}

int main()
{
	int input = 0;

	menu(); //菜单

	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			exit(true); //退出游戏
			break;
		default:
			printf("输入错误，重新输入\n");
			break;
		}
		printf("contiue?\n");
		menu();
	} while (true); //循环玩游戏

	system("pause");
	return 0;
}


