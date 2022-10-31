#ifndef __GAME_H__
#define __GAME__H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

//����
#define row 12
//����
#define col 12
//�������׵�����
#define COUNT 10

//չʾ����
extern char show_mine[row][col];

//��������
extern char real_mine[row][col];

//�˵�����
void menu();
//��ʼ�����麯��
void init_mine();
//���׺���
void set_mine();
//ͳ����Χ�׸����ĺ���
int count_mine();
//��ӡչʾ���̺���
void print_player();
//��ӡ�������̺���
void print_mine();
//ɨ�׺���
int  sweep_mine();
//�����һ�α���ը���ĺ���
void safe_mine();
//չ������
void open_mine(int x, int y);
//�ж��������ʣ���׸����ĺ���
int count_show_mine();

#endif  //__GAME_H__
