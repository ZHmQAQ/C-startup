#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 14
#define COL 14
#define DENSITY 0.15

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>


void deleteLine(int n);

void PrintWelcome();
void InitMineField(int minefield[ROW][COL], int row,int col);
void PrintMineField(char minefield_show[ROW][COL],int row,int col);
int IndexNotOut(int x, int y);
void InitMineField_Show(char minefield_show[ROW][COL], int row, int col);
int ChangeMineField_Show(int minefield[ROW][COL], char minefield_show[ROW][COL], int row, int col);
void RevealMineField_Show(int minefield[ROW][COL], char minefield_show[ROW][COL], int x, int y);
void AutoShow(int minefield[ROW][COL], char minefield_show[ROW][COL], int x, int y);
int JudgeWin(int minefield[ROW][COL], char minefield_show[ROW][COL], int row, int col);


