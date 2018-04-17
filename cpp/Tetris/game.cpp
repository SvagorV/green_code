
#include"game.h"
struct position_blok {
	int x;
	int y;
};

int points = 0;
int block_1[size_blok][size_blok] =
{
	{ 0,0,0,0 },
	{ 1,0,0,0 },
	{ 1,1,1,0 },
	{ 0,0,0,0 }
};
int block_2[size_blok][size_blok] =
{
	{ 0,0,0,0 },
	{ 1,1,1,0 },
	{ 1,0,0,0 },
	{ 0,0,0,0 }
};

int block_3[size_blok][size_blok] =
{
	{ 0,1,0,0 },
	{ 0,1,0,0 },
	{ 0,1,0,0 },
	{ 0,1,0,0 }
};
int block_4[size_blok][size_blok] =
{
	{ 0,0,0,0 },
	{ 0,1,1,0 },
	{ 0,1,1,0 },
	{ 0,0,0,0 }
};
int block_5[size_blok][size_blok] =
{
	{ 0,0,0,0 },
	{ 0,1,1,0 },
	{ 1,1,0,0 },
	{ 0,0,0,0 }
};

int block_6[size_blok][size_blok] =
{
	{ 0,0,0,0 },
	{ 0,1,0,0 },
	{ 1,1,1,0 },
	{ 0,0,0,0 }
};
int block_7[size_blok][size_blok] =
{
	{ 0,0,0,0 },
	{ 0,1,1,0 },
	{ 0,0,1,1 },
	{ 0,0,0,0 }
};


HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

void SetColor(int text, int background) {
	SetConsoleTextAttribute(hStdOut, background * 16 + text);
}
void GotoXY(int X, int Y) {
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}


void end(int**pole, bool flag = false) {
	if (flag) {
		int  pos_x = pole_position_x, pos_y = pole_position_y;
		for (int i = 0; i < size_pole_i; i++) {
			for (int j = 0; j < size_pole_j; j++) {
				GotoXY(pos_x, pos_y++);  //+добавиь изменения цвета 
				pole[i][j] = 0;
				cout << " ";
			}
			GotoXY(pos_x++, pos_y);
			pos_y = pole_position_y;
			cout << endl;

		}
		pos_x = pole_position_x, pos_y = pole_position_y;
		SetColor(15, 0);
		GotoXY(10, 8);
		cout << "Game over ";
		GotoXY(10, 9);
		cout << "You points:" << points;

		_getch();
		points = 0;
		for (int count = 0; count< size_pole_i; count++) {
			delete[]pole[count];
		}
		delete[]pole;
		game();
	}
	else {
		GotoXY(52, 14);
		cout << "points: " << points;
	}

}
//удаление блока при передвежении 
void delete_blok(int blok[size_blok][size_blok], position_blok position) {

	int pos_y2 = position.y;
	for (int i = 0; i < size_blok; i++) {
		for (int j = 0; j < size_blok; j++) {
			GotoXY(position.x, position.y++);
			if (blok[i][j] == 1) {
				SetColor(8, 0);
				cout << ".";
			}
		}
		GotoXY(position.x++, position.y);
		position.y = pos_y2;
		cout << endl;
	}
}
// печать блока
void print_blok(int blok[size_blok][size_blok], position_blok position) {
	int pos_y2 = position.y;
	for (int i = 0; i < size_blok; i++) {
		for (int j = 0; j < size_blok; j++) {
			SetColor(11, 0);
			GotoXY(position.x, position.y++);
			if (blok[i][j] == 1) {

				cout << char(block_fly);
			}

		}
		GotoXY(position.x++, position.y);
		position.y = pos_y2;
		cout << endl;
	}
}
//печать поля
void print_pole(int** pole) {
	for (int i = 0, pos_x = pole_position_x, pos_y = pole_position_y; i < size_pole_i; i++) {
		for (int j = 0; j < size_pole_j; j++) {
			GotoXY(pos_x, pos_y++);

			if (pole[i][j] == 0) {
				SetColor(8, 0);
				cout << ".";
			}
			else if (pole[i][j] == 1) {
				SetColor(11, 0);
				cout << char(fallen_blok_ACKII);
			}
			else {
				cout << "2";
			}
		}
		GotoXY(pos_x++, pos_y);
		pos_y = pole_position_y;
		cout << endl;
	}
}






int valnewpos(int **pole, int blok[size_blok][size_blok], int X, int Y) //необходимость движения фигуры 
{
	int x = X - pole_position_x;
	int y = Y - pole_position_y;

	for (int i = 0; i < size_blok; i++) {
		for (int j = 0; j < size_blok; j++) {
			if (blok[j][i]) {
				if (x < 0) {
					return FALSE;
				}
				if ((j + x >= size_pole_i) || (i + y >= size_pole_j)) {
					return FALSE;
				}
				if (pole[j + x][i + y]) {
					return FALSE;
				}
			}
		}
	}
	return TRUE;
}

int  delete_full_row(int** pole) { // удаленее рядка 
	int ball = 0;
	int flag = 0;
	for (int i = size_pole_j - 1; i >= 0; i--) {
		for (int j = 0; j < size_pole_i; j++) {

			flag += pole[j][i];
		}
		if (flag == size_pole_i) {
			ball += 10;

			for (int k = i; k > 0; k--) {
				for (int j = 0; j < size_pole_j; j++) {
					pole[j][k] = pole[j][k - 1];
				}
				end(pole);
			}
		}

		flag = 0;


	}
	return ball;
}


void rotation(int** pole, int blok[size_blok][size_blok], position_blok position) {
	int arr[4] = { 3,2,1,0 };
	int map[4][4];
	int  sx = 4, sy = 4;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			map[j][i] = blok[j][i];
			if (blok[j][i])
			{
				if (i < sx) sx = i;
				if (arr[j] < sy) sy = arr[j];
			}
			blok[j][i] = 0;
		}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (map[arr[i]][j]) blok[j - sx][i - sy] = 1;

	if (!valnewpos(pole, blok, position.x, position.y)) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) { blok[j][i] = map[j][i]; }
		}
	}

}
void DOWN(int** pole, int blok[size_blok][size_blok], position_blok *position) {

	delete_blok(blok, *position);
	if (!(valnewpos(pole, blok, position->x, ++position->y))) {
		for (int i = 0; i < size_blok; i++) {
			for (int j = 0; j < size_blok; j++) {
				if (blok[j][i]) {
					pole[position->x + j - pole_position_x][position->y + i - pole_position_y - 1] = 1;
					for (int j = 0; j < size_pole_j; j++) {
						if (pole[j][1] == 1) {
							end(pole, true);
						}
					}
				}
			}
		}

		points += delete_full_row(pole);
		print_pole(pole);
		rand_blok(pole);
	}
}


// управление блоками 
void control_blok(int** pole, int blok[size_blok][size_blok], position_blok *position) {

	end(pole);
	if (_kbhit()) {
		switch (_getch()) {
		case KEY_UP: {
			delete_blok(blok, *position);
			rotation(pole, blok, *position);
		}break;
		case KEY_DOWN: {
			DOWN(pole, blok, position);


		}break;
		case KEY_LEFT: {
			if (valnewpos(pole, blok, position->x - 1, position->y)) {
				delete_blok(blok, *position);
				position->x--;
			}

		}break;
		case KEY_RIGHT: {
			if (valnewpos(pole, blok, position->x + 1, position->y)) {
				delete_blok(blok, *position);
				position->x++;
			}

		}break;
		case KEY_SPACE: {

			while (1) {
				GotoXY(52, 13);
				SetColor(4, 15);
				cout << "pause!!!";
				Sleep(60);
				GotoXY(52, 13);
				SetColor(15, 4);
				cout << "pause!!!";
				Sleep(60);
				if (_kbhit()) {
					if (_getch() == KEY_SPACE) { break; }
				}
			}
			GotoXY(52, 13);
			SetColor(4, 0);
			cout << "        ";
		}break;
		case 27: {
			for (int i = 0; i < size_pole_i; i++) {
				for (int j = 0; j < size_pole_j; j++) {
					pole[i][j] = 0;
				}
			}
			print_pole(pole);
			points = 0;
			game();
		}

		default:
			break;
		}
	}

	else {
		Sleep(620 - (points / 2));
		DOWN(pole, blok, position);
	}

}


void game(int **pole, int blok[4][4], position_blok position) {
	while (true)
	{
		print_blok(blok, position);
		control_blok(pole, blok, &position);


	}
}

// выбор рандомного блока и вся игра 
void rand_blok(int** pole) {
	srand((int)time(NULL));
	position_blok position;
	position.x = pole_position_x + (size_pole_i / 2); //стартовая позиция блока 
	position.y = pole_position_y;
	switch (rand() % 7) {
	case 0: {game(pole, block_1, position); }break;
	case 1: {game(pole, block_2, position); }break;
	case 2: {game(pole, block_3, position); }break;
	case 3: {game(pole, block_4, position); }break;
	case 4: {game(pole, block_5, position); }break;
	case 5: {game(pole, block_6, position); }break;
	case 6: {game(pole, block_7, position); }break;
	default:
		break;
	}
}

// создание поля 
int ** create_pole() {

	int** pole = new int*[size_pole_i];
	for (int i = 0; i < size_pole_i; i++) {
		pole[i] = new int[size_pole_j] {0};
	}
	for (int i = 0; i < size_pole_i; i++) {
		for (int j = 0; j < size_pole_j; j++) {
			pole[i][j] = 0;
		}
	}
	print_pole(pole);
	return pole;
}
