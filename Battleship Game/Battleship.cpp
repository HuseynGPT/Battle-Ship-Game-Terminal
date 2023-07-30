#include<iostream> 
#include<chrono>
#include<thread> 
#include<cstdlib>
#include<ctime>
#include <conio.h>
#include <Windows.h>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
char** player_arr = new char* [14] {
	new char[14] { char(201), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(187) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(200), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(188) }};

char** bots_background_arr = new char* [14] {
	new char[14] { char(201), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(187) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(200), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(188) }};

char** arr3 = new char* [14] {
	new char[14] { char(201), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(187) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(186), ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', char(186) },
		new char[14] { char(200), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(205), char(188) }};

const int ROWS = 14;
const int COLS = 14;
const int BOARD_SIZE = 14;
const int NUM_SHIPS = 5;
const int SHIP_SIZES[NUM_SHIPS] = { 5, 4, 3, 3, 2 };
int a = 0, b = 0;
int exit_menu_row = 0, exit_menu_col = 0;
int settings_menu_row = 0, settings_menu_col = 0;
char** mymenu = new char* [5]
{
	new char[] {"  [1].New Game"},
		new char[] {"  [2].Help"},
		new char[] {"  [3].Settings"},
		new char[] {"  [4].Register"},
		new char[] {"  [5].Exit "},
};
int player_remainning = 17;
int bot_remainning = 17;

int row = 1, column = 1;
int ship_sizes[] = { 0,1,2,3,3,4,5 };
int ships[] = { 0,1,2,3,4,5,6 };


char** exit_menu = new char* [2]
{
	new char[] {" Yes"},
		new char[] {" No"},
};
char** settings_menu = new char* [2]
{
	new char[] {" Change Ship Symbol"},
		new char[] {" Change Menu logo"},
};
#include "Functions.h"
int main()
{
	srand(time(0));
	system("color 5");
	int saved_change_logo = 1;
	int saved_symbol = char(254);
	int count_shipss_bot = 0;
	int count_shipss_player = 0;
	int bot_or_player_round = 1;
	const int RED = 12;
	const int BLUE = 9;
	const int GREEN = 10;
	int input;
	while (true)
	{

	menu:
		system("cls");
		//Print main menu logo
		if (saved_change_logo == 1)
		{
			FILE* logo;
			fopen_s(&logo, "battleship main menu logo.txt", "r");
			char symbol = getc(logo);
			while (symbol != EOF)
			{
				cout << symbol;
				symbol = getc(logo);
			}
			fclose(logo);
		}
		else if (saved_change_logo == 2)
		{
			FILE* logo;
			fopen_s(&logo, "battleship main menu logo 2.txt", "r");
			char symbol = getc(logo);
			while (symbol != EOF)
			{
				cout << symbol;
				symbol = getc(logo);
			}
			fclose(logo);
		}

		mymenu[a][b] = '>';
		space();
		menu_print(mymenu, a, 5);
		input = _getch();
		check_rotate(input);
		//New Game
		if (a == 0 && input == 13)
		{
		game:
			char move;
			system("cls");
			//progressbar();
			placeShips();
			place_bots_ships();
			while (1)
			{
				int bot_row = 1 + rand() % (12);
				int bot_column = 1 + rand() % (12);
				bot_or_player_round = bot_or_player_round % 2 ? 1 : 2;
				system("cls");
				printBoard();


				if (bot_or_player_round == 1)
				{
					move = _getch();
					//down arrow
					if (int(move) == 80)
					{
						if (arr3[row + 1][column] == char(205))
							cout << '\a' << flush;
						else
						{
							row++;
							if (row > 0 && arr3[row - 1][column] != 'M' && arr3[row - 1][column] != 'H')
								arr3[row - 1][column] = ' ';

							if (arr3[row][column] != 'H' && arr3[row][column] != 'M')
								arr3[row][column] = saved_symbol;
						}

					}
					//up arrow
					else if (int(move) == 72)
					{
						if (arr3[row - 1][column] == char(205))
							cout << '\a' << flush;
						else
						{
							row--;
							if (row > 0 && arr3[row + 1][column] != 'H' && arr3[row + 1][column] != 'M')//
								arr3[row + 1][column] = ' ';

							if (arr3[row][column] != 'H' && arr3[row][column] != 'M')
								arr3[row][column] = saved_symbol;

						}

					}
					//right arrow
					else if (int(move) == 77)
					{
						if (arr3[row][column + 1] == char(186))
							cout << '\a' << flush;
						else
						{
							column++;
							if (column > 0 && arr3[row][column - 1] != 'M' && arr3[row][column - 1] != 'H')//
								arr3[row][column - 1] = ' ';

							if (arr3[row][column] != 'H' && arr3[row][column] != 'M')
								arr3[row][column] = saved_symbol;
						}

					}
					//left arrow
					else if (int(move) == 75)
					{

						if (arr3[row][column - 1] == char(186))
							cout << '\a' << flush;
						else
						{
							column--;
							if (column > 0 && arr3[row][column + 1] != 'M' && arr3[row][column + 1] != 'H')//
								arr3[row][column + 1] = ' ';

							if (arr3[row][column] != 'H' && arr3[row][column] != 'M')
								arr3[row][column] = saved_symbol;
						}
					}
					if (move == 27) {
						system("cls");
						int keyy;

						while (1)
						{
							system("cls");
							cout << "\t\t\t\tAre u sure for exit?" << endl;
							exit_menu[exit_menu_row][exit_menu_col] = '>';
							menu_print(exit_menu, exit_menu_row, 2);
							keyy = _getch();
							if (int(keyy) == 72)
							{
								if (exit_menu_row == 0)
								{
									exit_menu[exit_menu_row][b] = ' ';
									exit_menu_row = 1;
								}
								else
								{
									exit_menu_row--;
									exit_menu[exit_menu_row + 1][b] = ' ';
								}

							}
							//down
							else if (int(keyy) == 80)
							{

								if (exit_menu_row == 1)
								{
									exit_menu[exit_menu_row][b] = ' ';
									exit_menu_row = 0;
								}
								else
								{
									exit_menu_row++;
									exit_menu[exit_menu_row - 1][b] = ' ';
								}
							}
							if (exit_menu_row == -1 && int(keyy) == 72)
							{
								exit_menu_row = 0;
								exit_menu[exit_menu_row][b] = ' ';
								exit_menu_row = 4;
							}
							if (exit_menu_row == 2 && int(keyy) == 80)
							{
								exit_menu_row = 1;
								exit_menu[exit_menu_row][b] = ' ';
								exit_menu_row = 0;
							}
							if (int(keyy) == 13 && exit_menu_row == 0)
							{
								for (size_t i = 0; i < 14; i++)
								{
									for (size_t j = 0; j < 14; j++)
									{
										if (i != 0 && j != 0 && i != 13 && j != 13)
											arr3[i][j] = ' ';
									}
								}
								for (size_t i = 0; i < 14; i++)
								{
									for (size_t j = 0; j < 14; j++)
									{
										if (i != 0 && j != 0 && i != 13 && j != 13)
											player_arr[i][j] = ' ';
									}
								}
								player_remainning = 17;
								bot_remainning = 17;
								goto menu;
							}
							if (int(keyy) == 13 && exit_menu_row == 1)
							{
								goto game;
							}
						}

					}


				}

				if (int(move) == 13 && bots_background_arr[row][column] == 'S')
				{

					arr3[row][column] = 'H';
					count_shipss_player++;
					bot_or_player_round++;
					bot_remainning--;

				}
				else if (int(move) == 13 && bots_background_arr[row][column] == ' ')
				{
					arr3[row][column] = 'M';
					bot_or_player_round++;
				}

				if (count_shipss_player == 17)
				{

					cout << "YOU WON" << endl;
					cout << "Press any key to go back..." << endl;
					for (size_t i = 0; i < 14; i++)
					{
						for (size_t j = 0; j < 14; j++)
						{
							if (i != 0 && j != 0 && i != 13 && j != 13)
								arr3[i][j] = ' ';
						}
					}
					for (size_t i = 0; i < 14; i++)
					{
						for (size_t j = 0; j < 14; j++)
						{
							if (i != 0 && j != 0 && i != 13 && j != 13)
								player_arr[i][j] = ' ';
						}
					}
					player_remainning = 17;
					bot_remainning = 17;
					while (true) {
						if (_kbhit()) {
							Sleep(100);
							goto menu;
						}
					}
				}
				else if (bot_or_player_round == 2)
				{
					if (player_arr[bot_row][bot_column] == 'M')
					{

					}
					else
					{
						if (player_arr[bot_row][bot_column] == 'S')
						{
							player_arr[bot_row][bot_column] = 'H';
							count_shipss_bot++;
							bot_or_player_round++;
							player_remainning--;

						}
						else
						{
							player_arr[bot_row][bot_column] = 'M';
							bot_or_player_round++;
						}
					}
					
					
					if (count_shipss_bot == 17)
					{
						cout << "BOT WON" << endl;
						for (size_t i = 0; i < 14; i++)
						{
							for (size_t j = 0; j < 14; j++)
							{
								if (i != 0 && j != 0 && i != 13 && j != 13)
									arr3[i][j] = ' ';
							}
						}
						for (size_t i = 0; i < 14; i++)
						{
							for (size_t j = 0; j < 14; j++)
							{
								if (i != 0 && j != 0 && i != 13 && j != 13)
									player_arr[i][j] = ' ';
							}
						}
						player_remainning = 17;
						bot_remainning = 17;
						cout << "Press any key to go back...." << endl;
						while (true) {
							if (_kbhit()) {
								Sleep(100);
								goto menu;
							}
						}
					}
				}
			}
		}
		//About Game
		if (a == 1 && input == 13)
		{
			system("cls");
			FILE* about_game;
			fopen_s(&about_game, "about game.txt", "r");
			if (about_game != 0)
			{
				char symbol = fgetc(about_game);
				while (symbol != EOF) {
					cout << symbol;
					Sleep(10);

					if (symbol == '\n') {
						if (cin.get() == 13)
							continue;
					}
					symbol = fgetc(about_game);
				}cout << endl;
				cout << "Program running. Press ESC to exit." << endl;
				while (true) {
					if (_kbhit()) {
						char ch = _getch();
						if (ch == 27) {
							cout << "Exiting the program..." << endl;
							Sleep(100);
							goto menu;
						}
					}
				}
				fclose(about_game);
			}
		}
		if (a == 2 && input == 13)
		{
			system("cls");

			int keyy;
		ayarlar:
			while (1)
			{
				system("cls");
				cout << "\t\t\t\t\t\tSettings" << endl;
				settings_menu[settings_menu_row][settings_menu_col] = '>';
				menu_print(settings_menu, settings_menu_row, 2);
				keyy = _getch();
				if (int(keyy) == 72)
				{
					if (settings_menu_row == 0)
					{
						settings_menu[settings_menu_row][b] = ' ';
						settings_menu_row = 1;
					}
					else
					{
						settings_menu_row--;
						settings_menu[settings_menu_row + 1][b] = ' ';
					}

				}
				//down
				else if (int(keyy) == 80)
				{

					if (settings_menu_row == 1)
					{
						settings_menu[settings_menu_row][b] = ' ';
						settings_menu_row = 0;
					}
					else
					{
						settings_menu_row++;
						settings_menu[settings_menu_row - 1][b] = ' ';
					}
				}
				if (settings_menu_row == -1 && int(keyy) == 72)
				{
					settings_menu_row = 0;
					settings_menu[settings_menu_row][b] = ' ';
					settings_menu_row = 1;
				}
				if (settings_menu_row == 2 && int(keyy) == 80)
				{
					settings_menu_row = 1;
					settings_menu[settings_menu_row][b] = ' ';
					settings_menu_row = 0;
				}
				if (keyy == 27)
				{
					goto menu;
				}
				if (int(keyy) == 13 && settings_menu_row == 0)
				{
					char** symbol_choice = new char* [3]
					{
						new char[] {" ®"},
							new char[] {" #"},
							new char[] {" *"},
					};
					int rowww = 0, coll = 0;
					int inpt;

					while (1)
					{

						system("cls");
						symbol_choice[rowww][coll] = '>';
						menu_print(symbol_choice, rowww, 3);
						inpt = _getch();
						if (int(inpt) == 72)
						{
							if (rowww == 0)
							{
								symbol_choice[rowww][b] = ' ';
								rowww = 2;
							}
							else
							{
								rowww--;
								symbol_choice[rowww + 1][b] = ' ';
							}

						}
						//down
						else if (int(inpt) == 80)
						{

							if (rowww == 2)
							{
								symbol_choice[rowww][b] = ' ';
								rowww = 0;
							}
							else
							{
								rowww++;
								symbol_choice[rowww - 1][b] = ' ';
							}
						}
						if (rowww == -1 && int(inpt) == 72)
						{
							rowww = 0;
							symbol_choice[rowww][b] = ' ';
							rowww = 1;
						}
						if (rowww == 3 && int(inpt) == 80)
						{
							rowww = 1;
							symbol_choice[rowww][b] = ' ';
							rowww = 0;
						}
						if (int(inpt) == 13 && rowww == 0)
						{
							saved_symbol = '®';
							goto ayarlar;

						}
						if (int(inpt) == 13 && rowww == 1)
						{
							saved_symbol = '#';
							goto ayarlar;

						}
						if (int(inpt) == 13 && rowww == 2)
						{
							saved_symbol = '*';
							goto ayarlar;

						}

					}

				}
				if (int(keyy) == 13 && settings_menu_row == 1)
				{

					char** logo_choice = new char* [2]
					{
						new char[] {" 1"},
							new char[] {" 2"},
					};
					int rowww = 0, coll = 0;
					int inpt;

					while (1)
					{

						system("cls");
						logo_choice[rowww][coll] = '>';
						menu_print(logo_choice, rowww, 2);
						inpt = _getch();
						if (int(inpt) == 72)
						{
							if (rowww == 0)
							{
								logo_choice[rowww][b] = ' ';
								rowww = 1;
							}
							else
							{
								rowww--;
								logo_choice[rowww + 1][b] = ' ';
							}

						}
						//down
						else if (int(inpt) == 80)
						{

							if (rowww == 1)
							{
								logo_choice[rowww][b] = ' ';
								rowww = 0;
							}
							else
							{
								rowww++;
								logo_choice[rowww - 1][b] = ' ';
							}
						}
						if (rowww == -1 && int(inpt) == 72)
						{
							rowww = 0;
							logo_choice[rowww][b] = ' ';
							rowww = 1;
						}
						if (rowww == 2 && int(inpt) == 80)
						{
							rowww = 1;
							logo_choice[rowww][b] = ' ';
							rowww = 0;
						}
						if (int(inpt) == 13 && rowww == 0)
						{
							saved_change_logo = 1;
							goto ayarlar;

						}
						if (int(inpt) == 13 && rowww == 1)
						{
							saved_change_logo = 2;
							goto ayarlar;

						}

					}
				}
			}
		}
		//Register
		if (a == 3 && input == 13)
		{
			system("cls");
			char* arr = new char[] {"Coming soon..."};
			for (size_t i = 0; i < strlen(arr); i++)
			{
				cout << arr[i];
				Sleep(100);
			}
			Sleep(1000);
		}
		if (a == 4 && input == 13)
		{
			system("cls");
			int keyy;
			while (1)
			{
				system("cls");
				cout << "\t\t\t\tAre u sure for exit?" << endl;
				exit_menu[exit_menu_row][exit_menu_col] = '>';
				menu_print(exit_menu, exit_menu_row, 2);
				keyy = _getch();
				if (int(keyy) == 72)
				{
					if (exit_menu_row == 0)
					{
						exit_menu[exit_menu_row][b] = ' ';
						exit_menu_row = 1;
					}
					else
					{
						exit_menu_row--;
						exit_menu[exit_menu_row + 1][b] = ' ';
					}

				}
				//down
				else if (int(keyy) == 80)
				{

					if (exit_menu_row == 1)
					{
						exit_menu[exit_menu_row][b] = ' ';
						exit_menu_row = 0;
					}
					else
					{
						exit_menu_row++;
						exit_menu[exit_menu_row - 1][b] = ' ';
					}
				}
				if (exit_menu_row == -1 && int(keyy) == 72)
				{
					exit_menu_row = 0;
					exit_menu[exit_menu_row][b] = ' ';
					exit_menu_row = 1;
				}
				if (exit_menu_row == 2 && int(keyy) == 80)
				{
					exit_menu_row = 1;
					exit_menu[exit_menu_row][b] = ' ';
					exit_menu_row = 0;
				}
				if (int(keyy) == 13 && exit_menu_row == 0)
				{
					system("cls");
					goto exitt;
				}
				if (int(keyy) == 13 && exit_menu_row == 1)
				{
					goto menu;
				}
			}

		}
	exitt:
		if (a == 4 && input == 13)
		{
			break;
		}
	}
}