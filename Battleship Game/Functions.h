#pragma once


void progressbar() {
	FILE* s;
	SetConsoleTextAttribute(console, 8);
	fopen_s(&s, "loading menu logo.txt", "r");
	char symbol = getc(s);
	while (symbol != EOF)
	{
		cout << symbol;
		symbol = getc(s);
	}
	fclose(s);
	for (size_t i = 0; i < 10; i++)
	{
		int eded = rand() % 10;
	}
	SetConsoleTextAttribute(console, 7);
	cout << endl;
	cout << endl;
	cout << endl;
	srand(time(NULL));
	for (int progress = 0; progress != 100; progress += rand() % 20) {
		if (progress > 100) progress = 100;
		cout << "[";
		for (int i = 0; i < 100; i++)
			if (i < progress)
				cout << '=';
			else if (i == progress)
				std::cout << '>';
			else
				cout << ' ';
		cout << "] " << progress << " %" << '\r';
		cout.flush();
		this_thread::sleep_for(chrono::milliseconds(500));

		if (progress == 100) break;
	}
	cout << endl;
}

void menu_print(char** arr, int a, int size)
{
	system("color 5");
	for (size_t i = 0; i < size; i++)
	{
		if (i == a)
			SetConsoleTextAttribute(console, 80);
		else
			SetConsoleTextAttribute(console, 7);
		cout << "\t\t\t\t\t";
		cout << arr[i] << " ";
		SetConsoleTextAttribute(console, 7);
		cout << endl;
	}
}

void check_rotate(int input)
{
	if (input == 224)
	{
		input = _getch();
		//Up
		if (int(input) == 72)
		{
			if (a == 0)
			{
				mymenu[a][b] = ' ';
				a = 4;
			}
			else
			{
				a--;
				mymenu[a + 1][b] = ' ';
			}

		}
		//down
		else if (int(input) == 80)
		{

			if (a == 4)
			{
				mymenu[a][b] = ' ';
				a = 0;
			}
			else
			{
				a++;
				mymenu[a - 1][b] = ' ';
			}
		}
		if (a == -1 && int(input) == 72)
		{
			a = 0;
			mymenu[a][b] = ' ';
			a = 4;
		}
		if (a == 5 && int(input) == 80)
		{
			a = 4;
			mymenu[a][b] = ' ';
			a = 0;
		}
	}
	else if (input == 87)
	{
		if (a == 0)
		{
			mymenu[a][b] = ' ';
			a = 4;
		}
		else
		{
			a--;
			mymenu[a + 1][b] = ' ';
		}
	}
	else if (input == 83)
	{
		if (a == 4)
		{
			mymenu[a][b] = ' ';
			a = 0;
		}
		else
		{
			a++;
			mymenu[a - 1][b] = ' ';
		}
	}
}

void space() {

	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			cout << " ";
		}
		cout << endl;
	}
}

void printBoard()
{
	cout << "\tPlayer\t\t\t\tBot" << endl;
	for (int i = 0; i < 14; ++i)
	{
		for (int j = 0; j < 14; ++j) {
			if ((i == 0 || i == 13) && j != 13) {
				cout << player_arr[i][j] << char(205);
			}
			else
			{
				if (player_arr[i][j] == 'H')
				{
					HANDLE  console = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(console, 10);
					cout << player_arr[i][j] << " ";
				}
				else if (player_arr[i][j] == 'M')
				{
					HANDLE  console = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(console, 12);
					cout << player_arr[i][j] << " ";
				}

				else {
					HANDLE  console = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(console, 7);
					cout << player_arr[i][j] << " ";
				}
			}
		}
		cout << "  ";
		for (int j = 0; j < 14; ++j) {
			if ((i == 0 || i == 13) && j != 13) {
				cout << arr3[i][j] << char(205);
			}
			else
			{
				if (arr3[i][j] == 'H')
				{
					HANDLE  console = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(console, 10);
					cout << arr3[i][j] << " ";
				}
				else if (arr3[i][j] == 'M')
				{
					HANDLE  console = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(console, 12);
					cout << arr3[i][j] << " ";
				}

				else {
					HANDLE  console = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(console, 7);
					cout << arr3[i][j] << " ";
				}
			}
		}
		cout << endl;
	}
	cout << "Player Remaninning Ships: " << player_remainning << endl;

	cout << "Bot Remaninning Ships: " << bot_remainning << endl;
}


bool isValidLocation(char** board, int row, int col, int size, bool horizontal) {
	if (horizontal) {
		if (col + size > BOARD_SIZE) {
			return false;
		}
		for (int j = col; j < col + size; ++j) {
			if (board[row][j] != ' ') {
				return false;
			}
		}
	}
	else {
		if (row + size > BOARD_SIZE) {
			return false;
		}
		for (int i = row; i < row + size; ++i) {
			if (board[i][col] != ' ') {
				return false;
			}
		}
	}
	return true;
}

void placeShip(char** board, int row, int col, int size, bool horizontal) {
	if (horizontal) {
		for (int j = col; j < col + size; ++j) {
			board[row][j] = 'S';
		}
	}
	else {
		for (int i = row; i < row + size; ++i) {
			board[i][col] = 'S';
		}
	}
}
void placeShips() {
	srand(time(nullptr));
	for (int i = 0; i < NUM_SHIPS; ++i) {
		int row, col;
		bool horizontal;
		do {
			row = std::rand() % BOARD_SIZE;
			col = std::rand() % BOARD_SIZE;
			horizontal = std::rand() % 2 == 0;
		} while (!isValidLocation(player_arr, row, col, SHIP_SIZES[i], horizontal));
		placeShip(player_arr, row, col, SHIP_SIZES[i], horizontal);
	}

}
void place_bots_ships()
{
	for (int i = 0; i < NUM_SHIPS; ++i) {
		int row, col;
		bool horizontal;
		do {
			row = std::rand() % BOARD_SIZE;
			col = std::rand() % BOARD_SIZE;
			horizontal = std::rand() % 2 == 0;
		} while (!isValidLocation(bots_background_arr, row, col, SHIP_SIZES[i], horizontal));
		placeShip(bots_background_arr, row, col, SHIP_SIZES[i], horizontal);
	}
}