#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include"game.h"

//�ṩѡ��
void menu()
{
	printf("-----------------------------------\n");
	printf("--------->0.over   1.paly----------\n");
	printf("-----------------------------------\n");
	printf("--------��������ĸ�ʽ��a b ---------\n");
	printf("----- ������ӣ�o  �������ӣ�+ -------\n");
}

//�����㷨
void game()
{
	//��������
	char board[ROW][ROL];
	char *p,re,k=0;
	p = &k;
	//���̵ĳ�ʼ��
	initBoard(board, ROW, ROL);
	//��ӡ����
	displayboard(board, ROW, ROL);
	//����
	while (1)
	{
		//�������
		playerMove(board, ROW, ROL,p);
		displayboard(board, ROW, ROL);
		//�ж��Ƿ�ʤ��
		re=isWin(board,ROW,ROL,p);
		if (re != 'c')
			break;
		//��������
		printf("\n");
		computerMove(board, ROW, ROL,p);
		displayboard(board, ROW, ROL);
		//�ж��Ƿ�ʤ��
		re = isWin(board, ROW, ROL, p);
		if (re != 'c')
			break;
	}
	switch (re)
	{
	case 'o':printf("���ʤ����\n"); break;
	case '+':printf("����ʤ����\n"); break;
	case 'p':printf("��һ����ƽ��\n"); break;
	default:break;
	}

}

void play()
{
	int t = 0;
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("--��ѡ��");
		t=scanf("%d", &input);
		if (t==0)
			play();
		switch (input) {
		  case 1:
			  printf("��Ϸ��ʼ��\n");
			  game();
			  printf("\n\n\n-----------����һ����------------\n");
			  play();
			break;
		  case 0:
			  printf("\n��Ϸ������\n");
			break;
		  default:
			  printf("������ѡ�񣡣���\n");
			break;
		}
	} while (input);
}

int main()
 {
	play();
	return 0;
}