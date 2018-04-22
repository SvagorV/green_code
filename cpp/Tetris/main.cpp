#include "game.h"


void main() {

	game();


}
void game() {
	
	string menu_[5]{ "Start","Option","About","Author","Exit", };
	int x = pole_position_x + 49; //отступ берем из интерфейса  
	int y = pole_position_y ;
	interfaces();
	switch (menu(menu_, 5, x, y))
	{
	case 0: {

		int** polr_arr = create_pole();
		rand_blok(polr_arr);
	}break;
	case 2:
	{

		system("cls");

		About();

		_getch();
		system("cls");
		game();
	}break;

	case 3: {

		system("cls");

		tetris();

		_getch();
		system("cls");
		game();
	}break;
	case 4: {

		exit(0);

	}break;
	default:
		break;
	}
}