#include <iostream>
#include <cstdlib>
#include <conio.h>
using namespace std;

bool game_over = false;

const int Width = 20;
const int Height = 20;
int x, y, fruitx, fruity, score;
int tailx[100], taily[100];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;


void Setup() {

	game_over = false;
	dir = STOP;
	x = Width / 2 - 1;
	y = Height / 2 - 1;
	fruitx = rand() % Width;
	fruity = rand() % Height;
	score = 0;
}

void Draw() {
	system("cls");
	for (int i = 0; i < Width+1; i++) {
		
			cout << "#";
		}
	cout << endl;

	for (int i = 0; i < Height; i++) {
		for (int j = 0; j < Width; j++) {
			if (j == 0 || j == Width - 1) {
				cout << "#";
			}
			if (i == y && j == x) {
				
				cout << "0";
			}
			else if (i == fruity && j == fruitx) {
				cout << "F";
			}
			else {
				bool PrintTail = false;
				for (int k = 0; k < nTail; k++) {
					if (tailx[k] == j && taily[k] == i) {
						PrintTail = true;
						cout << "o";
					}
				}
				if (!PrintTail) {
					cout << " ";
				}
			}
			
		}
		cout << endl;
	}

	for (int i = 0; i < Width+1; i++) {

		cout << "#";
	}
	cout << endl;
	cout << "Score: "<<score<<endl;

}

void Keyboard() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 's':
			dir = DOWN;
			break;
		case'w':
			dir = UP;
			break;
		case 'e':
			game_over == true;
			break;
		}
	}

	
}

void Logic() {
	int prevx = tailx[0];
	int prevy = taily[0];
	int prev2x, prev2y;
	tailx[0] = x;
	taily[0] = y;
	for (int i = 1; i < nTail; i++) {
		prev2x = tailx[i];
		prev2y = taily[i];
		tailx[i] = prevx;
		taily[i] = prevy;
		prevx = prev2x;
		prevy = prev2y;

	}
	switch (dir) {
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
	if (x >= Width || x<=0 || y>=Height || y <= 0) {
		game_over == true;
		cout << "Вы програли :(\n";
		system("pause");
	}
	if (x >= Width) {
		x = 0;
	}
	else if (x < 0) {
		x = Width - 1;
	}
	if (y >= Height) {
		y = 0;
	}
	else if (y < 0) {
		Height - 1;
	}
	
	if (x == fruitx && y == fruity) {
		
		score += 10;
		fruitx = rand()  % Width;
		fruity = rand() % Height;
		nTail++;


	}
	
	
}



int main() {
	
		setlocale(LC_ALL, "rus");

		Setup();

		while (!game_over) {
			Draw();
			Keyboard();
			Logic();

		}

		system("pause");
	
}