#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include"game.h"

//提供选择
void menu()
{
	printf("-----------------------------------\n");
	printf("--------->0.over   1.paly----------\n");
	printf("-----------------------------------\n");
	printf("--------落子坐标的格式：a b ---------\n");
	printf("----- 玩家棋子：o  电脑棋子：+ -------\n");
}

//核心算法
void game()
{
	//定义棋盘
	char board[ROW][ROL];
	char *p,re,k=0;
	p = &k;
	//棋盘的初始化
	initBoard(board, ROW, ROL);
	//打印棋盘
	displayboard(board, ROW, ROL);
	//下棋
	while (1)
	{
		//玩家落子
		playerMove(board, ROW, ROL,p);
		displayboard(board, ROW, ROL);
		//判断是否胜利
		re=isWin(board,ROW,ROL,p);
		if (re != 'c')
			break;
		//电脑落子
		printf("\n");
		computerMove(board, ROW, ROL,p);
		displayboard(board, ROW, ROL);
		//判断是否胜利
		re = isWin(board, ROW, ROL, p);
		if (re != 'c')
			break;
	}
	switch (re)
	{
	case 'o':printf("玩家胜利！\n"); break;
	case '+':printf("电脑胜利！\n"); break;
	case 'p':printf("这一局是平局\n"); break;
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
		printf("--请选择：");
		t=scanf("%d", &input);
		if (t==0)
			play();
		switch (input) {
		  case 1:
			  printf("游戏开始：\n");
			  game();
			  printf("\n\n\n-----------再来一局吗？------------\n");
			  play();
			break;
		  case 0:
			  printf("\n游戏结束！\n");
			break;
		  default:
			  printf("请认真选择！！！\n");
			break;
		}
	} while (input);
}

int main()
 {
	play();
	return 0;
}
