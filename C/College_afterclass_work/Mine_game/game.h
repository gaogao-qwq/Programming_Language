#ifndef __GAME_H__
#define __GAME__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

//行数
#define row 12
//列数
#define col 12
//棋盘中雷的总数
#define COUNT 10

//展示数组
extern char show_mine[row][col];

//布雷数组
extern char real_mine[row][col];

//菜单函数
void menu();
//初始化数组函数
void init_mine();
//布雷函数
void set_mine();
//统计周围雷个数的函数
int count_mine();
//打印展示棋盘函数
void print_player();
//打印布雷棋盘函数
void print_mine();
//扫雷函数
int  sweep_mine();
//避免第一次被雷炸死的函数
void safe_mine();
//展开函数
void open_mine(int x, int y);
//判断玩家棋盘剩余雷个数的函数
int count_show_mine();

#endif  //__GAME_H__
