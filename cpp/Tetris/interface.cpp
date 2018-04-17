#pragma once
#include "game.h"

void interfaces() {

	for (int i = 0, pos_x = pole_position_x - 1, pos_y = pole_position_y - 1; i < size_pole_i + 2; i++) {
		for (int j = 0; j < size_pole_j + 2; j++) {
			GotoXY(pos_x, pos_y++);

			if (i == 0 || j == 0 || size_pole_i + 1 == i || size_pole_j + 1 == j) {
				SetColor(3, 0);
				cout << char(GAME_POLE_ACKII);
			}
			else {
				cout << " ";
			}
		}
		GotoXY(pos_x++, pos_y);
		pos_y = pole_position_y - 1;
		cout << endl;
	}

	for (int i = 0, cord_Y = pole_position_y - 1, cord_X = 40 + pole_position_x; i < 25; i++) {
		for (int j = 0; j < size_pole_j; j++) {
			GotoXY(cord_X, cord_Y++);
			SetColor(3, 0);
			if (i == 0 || j == 0 || 24 == i || size_pole_j - 1 == j || j == 8 || j == 11) {
				cout << char(MENU_ACKII);
			}
			else {
				cout << " ";
			}

		}
		GotoXY(cord_X++, cord_Y);
		cord_Y = pole_position_y - 1;
	}

}

int menu(string menu[],int size,int x1,int y1 ) {
	help();
	
	int  flag = 0; //отступ берем из интерфейса  
	int x = x1, y = y1;
	for (int i = 0; i < size; i++) {
		GotoXY(x, y);
		SetColor(15, 0);
		cout << menu[i] << endl;
		y++;
	}
	 x = x1, y = y1;
//	x = pole_position_x + 49, y = pole_position_y + 1; //отступ берем из интерфейса 
	GotoXY(x, y);
	SetColor(11, 0);
	cout << menu[0];
	while (true) {
		switch (_getch()) {
		case KEY_UP: {
			GotoXY(x, y);
			SetColor(15, 0);
			cout << menu[flag];

			flag--;

			if (flag == -1) {
				flag = size-1;
				y += size;
			}
			y--;

			GotoXY(x, y);
			SetColor(11, 0);
			cout << menu[flag];
			break;
		}

		case KEY_DOWN: {
			GotoXY(x, y);
			SetColor(15, 0);
			cout << menu[flag];

			flag++;
			if (flag == size) {
				flag = 0;
				y -= size;
			}
			y++;

			GotoXY(x, y);
			SetColor(11, 0);
			cout << menu[flag];
			break;
		}
		case KEY_ENTER: {
			return flag;

		}

		}
	}
}
void tetris() {
	int mas[22][47]{
		{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,3 },
		{ 3,0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,1,1,1,1,0,0,1,1,1,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,3 },
		{ 3,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,1,1,0,0,0,1,0,0,3 },
		{ 3,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,1,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,3 },
		{ 3,0,0,0,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,3 },
		{ 3,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,1,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0,3 },
		{ 3,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,0,0,1,1,0,0,1,0,0,0,1,1,0,0,3 },
		{ 3,0,0,0,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,1,0,1,1,0,0,1,1,1,1,1,1,0,0,3 },
		{ 3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3 },
		{ 3,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,3 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0 },
		{ 0,0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,3,3,2,2,2,2,2,2,2,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0 },
	};
	int y = 5, x = 15;
	for (int i = 0; i < 22; i++) {
		for (int j = 0; j < 47; j++) {


			GotoXY(x++, y);
			if (mas[i][j] == 1) {
				cout << char(254);
			}
			else if (mas[i][j] == 2) {
				cout << char(254);
			}
			else if (mas[i][j] == 3) {
				cout << char(254);
			}
			else if (mas[i][j] == 0) {
				cout << " ";
			}
		}
		y++; x = 15;
		cout << endl;
	}
	GotoXY(29, 19);
	cout << " Student: Andrey";
	GotoXY(29, 20);
	cout << " Palamarchyk";
	GotoXY(29, 24);
	cout << " Date:29:03:2018" << endl;

	GotoXY(27, 30);
	cout << "email: Svagor1995@gmail.com" << endl;
}

void help() {
	SetColor(7, 0);
	GotoXY(47, 17);
	cout << "Left-key:block left ";
	GotoXY(47, 18);
	cout << "Right-key:block right ";
	GotoXY(47, 19);
	cout << "Up-key:block rotation";
	GotoXY(47, 20);
	cout << "Down-key:block down";
	GotoXY(47, 21);
	cout << "Space-key: pause";
	GotoXY(47, 21);
	cout << "Esc-key: exit menu";

}
void About() {

	cout << "\t\t\t\Gameplay" << endl
		<< "Tetriminos are game pieces shaped like tetrominoes, geometric shapes composed of four square " << endl
		<< "blocks each. A random sequence of Tetriminos fall down the playing field (a rectangular vertical " << endl
		<< "shaft, called the 'well' or 'matrix'). The objective of the game is to manipulate these Tetriminos, by " << endl
		<< "moving each one sideways (if the player feels the need) and rotating it by 90 degree units, with the " << endl
		<< "aim of creating a horizontal line of  without gaps. When such a line is created, it gets destroyed, and " << endl
		<< "any block above the deleted line will fall. When a certain number of lines are cleared, the game " << endl
		<< "enters a new level. As the game progresses, each level causes the Tetriminos to fall faster, and the " << endl
		<< "game ends when the stack of Tetriminos reaches the top of the playing field and no new Tetriminos " << endl
		<< "are able to enter.";

}