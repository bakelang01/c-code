//��Ź�����Ϸ�Ĵ���

#define _CRT_SECURE_NO_WARNINGS

#define ROW 3
#define ROL 3
#include<stdlib.h>
#include<time.h>
//���̵ĳ�ʼ��
void initBoard(char pb[][ROL], int row, int rol)
{
	int i, j;
	for (i = 0; i < row; i++)
		for (j = 0; j < rol; j++)
			pb[i][j] = ' ';
}

//��ӡ����
void displayboard(char pc[][ROL], int row, int rol)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < rol; j++)
		{
			printf(" %c ", pc[i][j]);
			if (j < rol - 1)
				printf("|");
		}
		printf("\n");
		for (j = 0; j < rol-1; j++)
		{
			printf("---|");
		}
		printf("---\n");
	}
}

//�������
void playerMove(char pd[][ROL], int row,int rol,char *p)
{
	int x = 0, y = 0;
	printf("\n");
	while(1)
	{
		printf("�������\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= rol)
		{
			if (pd[--x][--y] == ' ')
			{
				pd[x][y] = 'o';
				*p = pd[x][y];
				break;
			}
			else
			{
				printf("�������Ѿ������ӣ�����������\n");
			}
			
		}
		else
		{
			printf("�������������\n");
		}
	}
}

//��������
void computerMove(char pe[][ROL], int row, int rol,char *p)
{
	int x = 0, y = 0;
	printf("��������\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % rol;
		if (pe[x][y] == ' ')
		{
			pe[x][y] = '+';
			*p = pe[x][y];
			break;
		}
	}
	

}

//�ж�ʤ��
char isWin(char pf[][ROL],int row,int rol,char* p)
{
	int i=0,j=0;
	for(i=0;i<row;i++)//�ж����Ƿ����
	{
		for (j = 0; j < rol; j++)
		{
			if (pf[i][j] == *p)//�ж������
			{
				if (j == rol - 1)
					return pf[i][j];
			}
			else
				break;
		}
	}

	for (i = 0; i < row; i++)//�ж����Ƿ����
	{
		for (j = 0; j < rol; j++)
		{
			if (pf[j][i] == *p)
			{
				if (j == rol - 1)
					return pf[j][i];
			}
			else
				break;
		}
	
	}
	i = 0;
	while (1)
	{
		if (pf[i][i++] == *p)
		{
			if (i == row)
				return *p;
			else
				continue;
		}
		else
			break;
	}
	j = 0;
	while (1)
	{
		if (pf[j][rol - 1 - j] == *p)
		{
			if (rol - 1 == j)
				return *p;
			else
			{
				j++;
				continue;
			}
			
		}
		else
			break;
	}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < rol; j++)
		{
			if (pf[i][j] == ' ')
				return 'c';//����
			
		}
	}
		
	return 'p';

}