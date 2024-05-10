#include "game.h"

void InitBoard(char board[DIF_ROWS][DIF_COLS], int rows, int cols, char ch)
{
	int i = 0;
	for (i = 0; i < rows; i++)
	{
		int j = 0;
		for (j = 0; j < cols; j++)
		{
			board[i][j] = ch;
		}
	}
}

void DisPlayBoard(char board[DIF_ROWS][DIF_COLS], int row, int col)
{
	int i = 0;
	printf("   ");
	for (i = 1; i <= row; i++)
	{
		printf("%2d ", i);
	}
	printf("\n");
	printf("  |");
	for (i = 1; i <= row; i++)
	{
		printf("---");
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%2d|", i);
		int j = 0;
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char mine[DIF_ROWS][DIF_COLS], int row, int col, int cnt)
{
	while (cnt > 0)
	{
		int x = 0;
		int y = 0;
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			cnt--;
		}
	}
}

int MineCount(char mine[DIF_ROWS][DIF_COLS], int x, int y)
{
	int cnt = mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0';
	return cnt;

}

void Expend(char mine[DIF_ROWS][DIF_COLS], char show[DIF_ROWS][DIF_COLS], int x, int y, int visted[DIF_ROWS][DIF_COLS])
{
	//visted[x][y] == 1;
	int vist[DIF_ROWS][DIF_COLS] = { 0 };
	int cnt = MineCount(mine, x, y);
	if (cnt > 0)
		show[x][y] = cnt + '0';
	else
	{
		show[x][y] = ' ';
		if (visted[x - 1][y - 1] == 0)
		{
			vist[x - 1][y - 1] = 1;
			visted[x - 1][y - 1] = 1;
		}
		if (visted[x - 1][y] == 0)
		{
			vist[x - 1][y] = 1;
			visted[x - 1][y] = 1;
		}
		if (visted[x - 1][y + 1] == 0)
		{
			vist[x - 1][y + 1] = 1;
			visted[x - 1][y + 1] = 1;
		}
		if (visted[x][y - 1] == 0)
		{
			vist[x][y - 1] = 1;
			visted[x][y - 1] = 1;
		}
		if (visted[x][y + 1] == 0)
		{
			vist[x][y + 1] = 1;
			visted[x][y + 1] = 1;
		}
		if (visted[x + 1][y - 1] == 0)
		{
			vist[x + 1][y - 1] = 1;
			visted[x + 1][y - 1] = 1;
		}
		if (visted[x + 1][y] == 0)
		{
			vist[x + 1][y] = 1;
			visted[x + 1][y] = 1;
		}
		if (visted[x + 1][y + 1] == 0)
		{
			vist[x + 1][y + 1] = 1;
			visted[x + 1][y + 1] = 1;
		}


		if (vist[x - 1][y - 1] == 1)
		{
			Expend(mine, show, x - 1, y - 1, visted);
		}
		if (vist[x - 1][y] == 1)
		{
			Expend(mine, show, x - 1, y, visted);
		}
		if (vist[x - 1][y + 1] == 1)
		{
			Expend(mine, show, x - 1, y + 1, visted);
		}
		if (vist[x][y - 1] == 1)
		{
			Expend(mine, show, x, y - 1, visted);
		}
		if (vist[x][y + 1] == 1)
		{
			Expend(mine, show, x, y + 1, visted);
		}
		if (vist[x + 1][y - 1] == 1)
		{
			Expend(mine, show, x + 1, y - 1, visted);
		}
		if (vist[x + 1][y] == 1)
		{
			Expend(mine, show, x + 1, y, visted);
		}
		if (vist[x + 1][y + 1] == 1)
		{
			Expend(mine, show, x + 1, y + 1, visted);
		}
	}
}

void FindMine(char mine[DIF_ROWS][DIF_COLS], char show[DIF_ROWS][DIF_COLS], int row, int col, int cnt, int visted[DIF_ROWS][DIF_COLS])
{
	while (1)
	{
		int x = 0;
		int y = 0;
		printf("请输入:>");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (1 == visted[x][y])
			{
				printf("该位子已被占用\n");
			}
			else if (mine[x][y] == '1')
			{
				show[x][y] = '$';
				DisPlayBoard(show, row, col);
				printf("你踩到雷了\n");
				break;
			}
			else
			{
				visted[x][y] == 1;
				Expend(mine, show, x, y, visted);
				DisPlayBoard(show, row, col);
			}
		}
		else
		{
			printf("超出范围\n");
		}
		int count = 0;
		int i = 0;
		for(i = 1; i <= row; i++)
		{
			int j = 0;
			for (j = 1; j <= col; j++)
			{
				if (show[i][j] == '*')
				{
					count++;
				}
			}
		}
		if (count == cnt)
		{
			printf("恭喜你，你赢了\n");
			break;
		}
	}
} 