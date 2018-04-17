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

#define KEY_UP 72 //определение клавиши "вверх"
#define KEY_DOWN 80 //определение клавиши "вниз"
#define KEY_LEFT 75 //определение клавиши "влево"
#define KEY_RIGHT 77 //определение клавиши "вправо"
#define KEY_SPACE 32 //определение клавиши "пробел"
#define KEY_ESC 27 //определение клавиши "escape"
#define KEY_ENTER 13 //определение клавиши "enter"

#define size_pole_i 25 //размер поля i
#define size_pole_j 20 //размер поля j


#define pole_position_x 5 //позициии полей x,y  
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