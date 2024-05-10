#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//��
#define EASY_ROW 9
#define EASY_COL 9
#define EASY_COUNT 15

//�м�
#define MID_ROW 15
#define MID_COL 15
#define MID_COUNT 30

//����
#define DIF_ROW 21
#define DIF_COL 21
#define DIF_COUNT 40

//��
#define EASY_ROWS EASY_ROW+2
#define EASY_COLS EASY_COL+2
//�м�
#define MID_ROWS MID_ROW+2
#define MID_COLS MID_COL+2
//����
#define DIF_ROWS DIF_ROW+2
#define DIF_COLS DIF_COL+2

//��ʼ������
extern void InitBoard(char board[DIF_ROWS][DIF_COLS], int rows, int cols, char ch);
//��ӡ����
extern void DisPlayBoard(char board[DIF_ROWS][DIF_COLS], int row, int col);
//�����
extern void SetMine(char mine[DIF_ROWS][DIF_COLS], int row, int col, int cnt);
//�Ų���
extern void FindMine(char mine[DIF_ROWS][DIF_COLS], char show[DIF_ROWS][DIF_COLS], int row, int col, int cnt, int visted[DIF_ROWS][DIF_COLS]);
extern int MineCount(char mine[DIF_ROWS][DIF_COLS], int x, int y);
extern void Expend(char mine[DIF_ROWS][DIF_COLS], char show[DIF_ROWS][DIF_COLS], int x, int y, int visted[DIF_ROWS][DIF_COLS]);#pragma once
