#pragma once
#pragma once
#include <stdio.h>
#include <conio.h>
#include<iostream>
#include<cmath>
#include<math.h>
#include<time.h>
#include <iomanip>
#include<Windows.h>
#include <string>

#define KEY_UP 72 //����������� ������� "�����"
#define KEY_DOWN 80 //����������� ������� "����"
#define KEY_LEFT 75 //����������� ������� "�����"
#define KEY_RIGHT 77 //����������� ������� "������"
#define KEY_SPACE 32 //����������� ������� "������"
#define KEY_ESC 27 //����������� ������� "escape"
#define KEY_ENTER 13 //����������� ������� "enter"

#define size_pole_i 25 //������ ���� i
#define size_pole_j 20 //������ ���� j


#define pole_position_x 5 //�������� ����� x,y  
#define pole_position_y 5 


#define size_blok 4

#define fallen_blok_ACKII 254
#define MENU_ACKII 254
#define GAME_POLE_ACKII 254
#define block_fly 254

using namespace std;


//void* handle = GetStdHandle(STD_OUTPUT_HANDLE);
//CONSOLE_CURSOR_INFO structCursorInfo;
//GetConsoleCursorInfo(handle, &structCursorInfo);
//structCursorInfo.bVisible = FALSE;
//SetConsoleCursorInfo(handle, &structCursorInfo);

void SetColor(int text, int background);
void GotoXY(int X, int Y);
int menu(string menu[], int size, int x, int y);
void tetris();
int ** create_pole();
void rand_blok(int** pole);
void interfaces();
void game();
void help();
void About();