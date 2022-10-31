#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

char show_mine[row][col] = { 0 };
char real_mine[row][col] = { 0 };

void menu()
{
	printf("*******************************\n");
	printf("*****1.play       0.exit*******\n");
	printf("*******************************\n");
}

void init_mine()
{
	for (int i = 0; i < row; i++) 
	{
		for (int j = 0; j < col; j++)
		{
			show_mine[i][j] = '*';
			real_mine[i][j] = '0';
		}
	}
}

void set_mine()
{
	int count = COUNT; //雷总数

	while (count) //雷布完后跳出循环
	{
		int x = rand() % 10 + 1, y = rand() % 10 + 1; //生成1~10的随机数并分别赋值给x,y

		if (real_mine[x][y] == '0') //找不是雷的地方布雷
		{
			real_mine[x][y] = '1';
			count--;
		}
	}
}

void print_player()
{
	int i = 0;
	int j = 0;
	printf("0  ");
	for (i = 1; i <row-1; i++)
	{
		printf("%d ", i);//打印横标（0--10）
	}
	printf("\n");
	for (i = 1; i < row - 2; i++) //打印竖标（1--10）
	{
		printf("%d  ", i);
		for (j = 1; j < col - 1; j++)
		{
			printf("%c ", show_mine[i][j]);//玩家棋盘数组
		}
		printf("\n");
	}
	printf("10 ");//开始打印最后一行
	for (i = 1; i < row - 1; i++)
	{
		printf("%c ", show_mine[10][i]);
	}
	printf("\n");
}

void print_mine()
{
	int i = 0;
	int j = 0;
	printf("0  ");
	for (i = 1; i < row - 1; i++)
	{
		printf("%d ", i);//打印横标（0--10）
	}
	printf("\n");
	for (i = 1; i < row - 2; i++) //打印竖标（1--10）
	{
		printf("%d  ", i);
		for (j = 1; j < col - 1; j++)
		{
			printf("%c ", real_mine[i][j]);
		}
		printf("\n");
	}
	printf("10 ");//开始打印最后一行
	for (i = 1; i < row - 1; i++)
	{
		printf("%c ", real_mine[10][i]);
	}
	printf("\n");
}

int count_mine(int x, int y)
{
	int count = 0;
	if (real_mine[x - 1][y - 1] == '1')
	{
		count++;
	}
	if (real_mine[x - 1][y] == '1')
	{
		count++;
	}
	if (real_mine[x - 1][y + 1] == '1')
	{
		count++;
	}
	if (real_mine[x][y - 1] == '1')
	{
		count++;
	}	
	if (real_mine[x][y + 1] == '1')
	{
		count++;
	}
	if (real_mine[x + 1][y - 1] == '1')
	{
		count++;
	}	
	if (real_mine[x + 1][y] == '1')
	{
		count++;
	}
	if (real_mine[x + 1][y + 1] == '1')
	{
		count++;
	}
	return count;
}

void safe_mine()
{
	int x = 0;
	int y = 0;
	char ch = 0;
	int count = 0;
	bool isMine = true;

	printf("输入坐标扫雷\n");
	while (true)
	{
		scanf("%d%d", &x, &y);

		if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10)) //判断输入坐标是否有误
		{
			if (real_mine[x][y] == '1') //第一次踩到雷后补救
			{
				real_mine[x][y] = '0';
				char ch = count_mine(x, y);
				show_mine[x][y] = ch + '0'; //数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
				open_mine(x, y);

				while (isMine) //在其余有空的地方设置一个雷
				{
					//生成1~10的随机数并分别赋值给x,y
					int x = rand() % 10 + 1, y = rand() % 10 + 1;

					if (real_mine[x][y] == '0') //如果坐标x,y处无雷，则在此布雷，并跳出此循环
					{
						real_mine[x][y] = '1';
						isMine = false;
						break;
					}
					//否则重新生成随机数
				}
				break;
			}
			if (real_mine[x][y] == '0')
			{
				char ch = count_mine(x, y);
				show_mine[x][y] = ch + '0'; //数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
				open_mine(x, y);
				break;
			}
		}
		else //坐标错误
		{
			printf("输入错误重新输入\n");
		}
	}
}

int sweep_mine()
{
	int x = 0;
	int y = 0;
	int count = 0;

	printf("输入坐标扫雷\n");
	scanf("%d%d", &x, &y); //只能输入1到10

	if ((x >= 1 && x <= 10) && (y >= 1 && y <= 10)) //判断输入坐标是否有误，输入错误重新输入
	{
		if (real_mine[x][y] == '0') //没踩到雷
		{
			char ch = count_mine(x,y);
			show_mine[x][y] = ch + '0'; //数字对应的ASCII值和数字字符对应的ASCII值相差48，即'0'的ASCII值
			open_mine(x, y);

			if (count_show_mine() == COUNT) //判断剩余的个数，个数为雷数时玩家赢
			{
				print_mine();
				printf("玩家赢!\n\n");
				return false;
			}
		}
		else if (real_mine[x][y]=='1') //踩到雷
		{
			return true;
		}
	}
	else
	{
		printf("输入错误重新输入\n");
	}
	return false;//没踩到雷
}

void open_mine(int x, int y)
{
	if (real_mine[x - 1][y - 1] == '0')
	{
		show_mine[x - 1][y - 1] = count_mine(x - 1, y - 1) + '0'; //显示该坐标周围雷数
	}
	if (real_mine[x - 1][y] 	== '0')
	{
		show_mine[x - 1][y] 	= count_mine(x - 1, y) + '0'; //显示该坐标周围雷数
	}
	if (real_mine[x - 1][y + 1] == '0')
	{
		show_mine[x - 1][y + 1] = count_mine(x - 1, y + 1) + '0'; //显示该坐标周围雷数
	}
	if (real_mine[x][y - 1] 	== '0')
	{
		show_mine[x][y - 1] 	= count_mine(x, y - 1) + '0'; //显示该坐标周围雷数
	}
	if (real_mine[x][y + 1] 	== '0')
	{
		show_mine[x][y + 1] 	= count_mine(x, y + 1) + '0'; //显示该坐标周围雷数
	}
	if (real_mine[x + 1][y - 1] == '0')
	{
		show_mine[x + 1][y - 1] = count_mine(x + 1, y - 1) + '0'; //显示该坐标周围雷数
	}
	if (real_mine[x + 1][y] 	== '0')
	{
		show_mine[x + 1][y] 	= count_mine(x + 1, y) + '0'; //显示该坐标周围雷数
	}
	if (real_mine[x + 1][y + 1] == '0')
	{
		show_mine[x + 1][y + 1] = count_mine(x + 1, y + 1) + '0'; //显示该坐标周围雷数
	}
}

int count_show_mine()
{
	int count = 0;
	int i = 0;
	int j = 0;
	for (i = 1; i <= row - 2; i++)
	{
		for (j = 1; j <= col - 2; j++)
		{
			if (show_mine[i][j] == '*')
			{
				count++;
			}
		}

	}
	return count;
}