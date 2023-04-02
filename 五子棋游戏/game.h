#pragma once
#include <stdio.h>
#include <Windows.h>

#define ROW 15
#define COL 15

void InitBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayerMove(char board[ROW][COL], int raw, int col);

void ComputerMove(char board[ROW][COL], int raw, int col);

//void SendBoardData(char board[ROW][COL], int row, int col);
//
//void SendBoardData(char board[ROW][COL], int row, int col);
//
//void SetClipboard(char* buffer);

int WuziqiWin(char ch, char board[ROW][COL], int row, int col);

