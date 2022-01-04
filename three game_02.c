#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define ROW 3
#define COL 3

void menu()
{
	printf("-------------------------\n");
	printf("---- 0.over  1.play -----\n");
	printf("- player:o computer：+ -\n");
	printf("-------------------------\n\n");
}

void initboard(char board[][COL],int row,int col)
{
	
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++)
			board[i][j] = ' ';
}

void overall(char board[ROW][COL], int row, int col)
{
	int i, j;
	printf("\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j == col - 1)
				printf(" %c \n", board[i][j]);
			else
			    printf(" %c |", board[i][j]);
		}
		if (i < row - 1)
		{
			for (j = 0; j < col - 1; j++)
			{
				printf("---|");
			}
			printf("---\n");
		}
		
	}
	
	printf("\n");
}

void playerMove(char board[][COL], int row, int col,char *p)
{
	int x = 0, y = 0;
	printf("player play chess>>>\nPlease enter the coordinate:  ");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'o';
				*p = board[x - 1][y - 1];
				break;
			}

			else
			{
				printf("There is a coordinates in it,please try again:  ");
			}
		}

		else
		{
			printf("Please enter the correct coordinates:  ");
		}
	}
	
}

void computerMove(char board[][COL], int row, int col, char* p)
{
	int x = 0;
	int y = 0;
	srand(time(0));
	printf("\nThe computer play chess>>>\n\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '+';
			*p = '+';
			break;
		}
	}
}

char whowin(char board[][COL], int row, int col, char* p)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == *p)
			{
				if (j == col - 1)
					return *p;
			}
			else
				break;
		}

		for (j = 0; j < col; j++)
		{
			if (board[j][i] == *p)
			{
			   if (j == row - 1)
				    return *p;
			}
			else
				break;
		}
		
		for (j = 0; j < col; j++)
		{
			if (board[j][col - j - 1] == *p)
			{
			   if (j == col - 1)
				   return *p;
			}
			else
			  break;
		}

		for (j = 0; j < col; j++)
		{
			if (board[j][j] == *p)
			{
				if (j == col - 1)
					return *p;
			}
			else
				break;
		}
	}

	for(i=0;i<row;i++)
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 'c';
		}
	return 'p';
}

//核心代码
void begin(char board[][COL],int row , int col)
{
	char ch = '\0',re='\0', * p;
	p = &ch;
	overall(board, ROW, COL);
	while (1)
	{
		playerMove(board, ROW, COL, p);
		system("cls");
		overall(board, ROW, COL);
		re = whowin(board, ROW, COL, p);
		if (re != 'c')
			break;

		computerMove(board, ROW, COL, p);
		system("cls");
		overall(board, ROW, COL);
		re=whowin(board, ROW, COL, p);
		if (re != 'c')
			break;
	}

	switch (re)
	{
	case 'p':
		Sleep(500);
		printf("\nYou tied with the computer.you are A PIECE OF SHIT !!!\n ");
		break;
	case 'o':
		Sleep(500);
		printf("\nYou victory,But don't prove anything...\n"); 
		break;
	case '+':
		Sleep(500);
		printf("\nYou are A BIG PIECE OF SHIT !!!"); 
		break;
	}
	printf("\n\n");
	system("pause");
	system("cls");
}

void play()
{
	int choose;
	int re=0;
	char board[ROW][COL] = { '0' };
	do
	{
		menu();
		initboard(board, ROW, COL);
		printf("please choose:  ");
		re=scanf("%d", &choose);//这里输入的数据如果是浮点数，字符之类的，就会出现死循环
		if (re != 1)
		{
			printf("\nplease enter it correctly>>>  ");
			re=scanf("%d", &choose);
		}
		switch (choose)
		{
		case 0:break;
		case 1:
			Sleep(100);
			system("cls");
			begin(board,ROW,COL);
			printf("\n\n\nDou you want try again?\n\n");
			break;
		default :
			system("cls");
			printf("\nplease enter it correctly>>>\n\n");
			play();
			break;
		}
	} while (choose);



}

int main()
{
	play();
	return 0;
}