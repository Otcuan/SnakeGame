#pragma once
#include "mylib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <string>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <string>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <conio.h>
#include <random>
using namespace std;

#define MAX 100	//snake	size

//Kích thước khung, menu
#define WIDTH 119
#define HEIGHT 29

//Snake control size
#define MAX_WIDTH 120
#define MAX_LENGTH 30

struct point {
	int x;
	int y;

	//Toan tu so sanh
	bool operator==(const point& other) const {
		return x == other.x && y == other.y;
	}
};
typedef struct {
	string name;
	int level;
	int score;
	int foodEaten;
	int length;
	int speed;
	point coord;
} savedData;
string userName;
struct highScore {
	string name;
	int score;
	int length;
};
struct highScoreNormal {
	string name;
	int score;
	int level;
	int length;
};
point* toaDoSnake = NULL;
static string str[MAX];
static int index = 4;
static const string sequence = "23127529231275092312738023127264";
//point Food = { 0, 0 };
point* Gate = NULL;

//Mot so bien su dung trong chuong trinh
int x = 1, y = 13;
int score = 0;
int speed = 1;
int foodEaten = 0;
int level = 1;
int length = 4;
int sl = 4;
point Food{ 0,0 };
int countAdd = 0;
int rancolor = 1;
int bomau = 1;
int idLoad = 1;

mutex mtx;
condition_variable cv;
bool shouldContinue = true;
bool needChange = true;
bool abutton = false;
int mauchumenu = 0, mauchucredit = 1;
int mute = 0;

point obs{ 44,14 };
vector <point> obstacles_1;
vector <point> obstacles_2;
vector <point> obstacles_3;
bool isPlayingMusic = 0;
int snakeColor=1;
//Function Prototype 
void loadGame();
void highScoress();
void AnimationButton();
void ChangeColorMenu();
void ChangeColor();

void SetConsoleFormat();
void ve_tuong_tren();
void ve_tuong_duoi();
void ve_tuong_trai();
void ve_tuong_phai();
void ve_tuong_phai_ngoai_cung();
void ve_tuong1();
void ve_tuong2();
void veNgang(int x, int y, int len, int maunen, int mauchu);
void veDoc(int x, int y, int len, int maunen, int mauchu);
void veCheoXuong(int x, int y, int len, int maunen, int mauchu);
void veCheoLen(int x, int y, int len, int maunen, int mauchu);
void veCheoXuongPhaiQuaTrai(int x, int y, int len, int maunen, int mauchu);
void veCheoLenPhaiQuaTrai(int x, int y, int len, int maunen, int mauchu);
void snakeInit(point*& toaDoSnake);
void xoaRanDiChuyen(point *&toaDoSnake);
void xuLyDiChuyen();
void xuLyDiChuyen2();	//For infinity mode
void drawSnake(point *&toaDoSnake, point Food);
void drawSnake2(point *&toaDoSnake, point Food);
void xuLyRan(point *&toaDoSnake, int x, int y, point& Food);
void xuLyRan2(point *&toaDoSnake, int x, int y, point& Food);
void add(point*& toaDoSnake, int& x, int& y);
void del1(point*& toaDoSnake, int vt);
bool snakeEatItself(point *&toaDoSnake);
void makeFood(point& Food, point *&toaDoSnake);
bool snakePassFood(point Food, point *&toaDoSnake);
bool snakeEatFood(point Food, point head);
void InfinityMode();
void NormalMode();
bool GameOver(point*& toaDoSnake);
bool GameOver2();	//For infinity mode
void drawGameOver(int x, int y, int maunen, int mauchu);
void chuG(int x, int y, int maunen, int mauchu);
void chuA(int x, int y, int maunen, int mauchu);
void chuM(int x, int y, int maunen, int mauchu);
void chuE(int x, int y, int maunen, int mauchu);
void chuO(int x, int y, int maunen, int mauchu);
void chuV(int x, int y, int maunen, int mauchu);
void chuR(int x, int y, int maunen, int mauchu);
void chuN(int x, int y, int maunen, int mauchu);
void chuF(int x, int y, int maunen, int mauchu);
void nut(int x, int y, int maunen, int mauchu);
void hoatHoa(int sonut, int maunen, int mauchu);
void del(int choice);
int lapLanh();
bool checkGate();
void drawGate();
bool ranChuiVaoCong(point *&toaDoSnake);
void xuLyQuaCong(point *&toaDoSnake);
void ResetGameData();
//void pauseGame(point*&toaDoSnake);
void loadGameInit(point*& toaDoSnake, int gameIndex);
void drawMenu();
void chuMenuHunting(int a, int b);
void chuMenuCredit(int a, int b);
void ranMenu(int num);
void Start(int mode);
void modeSauStart();
void ranSauStart(int choice, int maunen, int mauchu);
void credit();

void ChangeColorMenu();
void ChangeColor();
void map(int level);
void vetuongformat();
void pause(point*& toaDoSnake);
void demGiay();
void nuttutorial(int x, int y, int maunen);
void setting();
void tutorial();
void huongMuiTen(int num, int maunen);

void printSavedGame();
bool compareHighScore(const highScore& a, const highScore& b);
void saveHighScore(int diem, const string& name, int length);
vector<highScore> readHighScoresFromFile();
vector<savedData> readSavedData();
void writeDataToFile();

void saveNormalHighScore(int diem, const string& name, int level, int length);
vector <highScoreNormal> readNormalHighScoresFromFile();

string userNameInput();
string getLimitedInput(int limit);
point generateRandomPointExcept(const vector<point>& except, int range, int xmin, int xmax, int ymin, int ymax);
void PlayBackgroundMusic(const string& fileName);
void CloseBackgroundMusic();
void SetLeftVolume(DWORD volume);
void SetRightVolume(DWORD volume);

void Congratulation(int x, int y, int maunen, int mauchu);
void chuanCongra();
void chuC(int x, int y, int maunen, int mauchu);
void chuT(int x, int y, int maunen, int mauchu);
void chuU(int x, int y, int maunen, int mauchu);
void chuL(int x, int y, int maunen, int mauchu);
void chuI(int x, int y, int maunen, int mauchu);
void setting();
void tutorial();
void SetConsoleFormat()
{
	FixConsoleWindow();
	ShowCur(0);
	DisableSelection();
	SetWindowSize(120, 30);
	SetScreenBufferSize(120, 30);
	DisableCtrButton(0, 1, 1);
	ShowScrollbar(0);
	SetConsoleBackgroundColor(14);
}
void credit() {
	system("cls");
	char kitu = '1';
	int choice = 1;
	veNgang(40, 5, 40, 4, 0);
	veDoc(40, 5, 20, 4, 0);
	veDoc(80, 5, 20, 4, 0);
	veNgang(40, 25, 41, 4, 0);
	gotoXY(45, 6);
	SetColor1(0, 6);
	cout << "VNUHCM - University of Science";
	gotoXY(43, 7);
	cout << "Faculty of Information Technology";
	gotoXY(53, 8);
	cout << "Class: 23CLC01";
	gotoXY(44, 9);
	cout << "Subject: Programming Techniques";
	gotoXY(49, 10);
	cout << "Project: Hunting Snake";
	gotoXY(45, 11);
	cout << "Mentor: Dr.Truong Toan Thinh";
	gotoXY(55, 12);
	cout << "Group 10";
	gotoXY(52, 13);
	cout << "Leader: Tran Tho";
	gotoXY(55, 14);
	cout << "Member:";
	gotoXY(52, 15);
	cout << "Phan Trung Hieu";
	gotoXY(53, 16);
	cout << "Le Cong Tuan";
	gotoXY(53, 17);
	cout << "Tran Van Huy";
	gotoXY(52, 27);
	cout << "Press Esc to exit";
	do {
		if (choice == 1) {
			gotoXY(52, 12);
			SetColor1(7, 4);
			cout << ">> Group 10 <<";
		}
		else {
			gotoXY(52, 12);
			SetColor1(0, 6);
			cout << "    Group 10   ";
		}
		if (choice == 2) {
			gotoXY(52, 13);
			SetColor1(7, 4);
			cout << ">> Leader: 23127264 <<";
		}
		else {

			gotoXY(52, 13);
			SetColor1(0, 6);
			cout << "Leader: Tran Tho         ";
		}
		if (choice == 3) {
			gotoXY(52, 15);
			SetColor1(7, 4);
			cout << ">>  23127529 <<";
		}
		else {
			gotoXY(52, 15);
			SetColor1(0, 6);
			cout << "Phan Trung Hieu   ";
		}
		if (choice == 4) {
			gotoXY(53, 16);
			SetColor1(7, 4);
			cout << ">> 23127509 <<";
		}
		else {
			gotoXY(53, 16);
			SetColor1(0, 6);
			cout << "Le Cong Tuan   ";
		}
		if (choice == 5) {
			gotoXY(53, 17);
			SetColor1(7, 4);
			cout << ">> 23127380 <<";
		}
		else {
			gotoXY(53, 17);
			SetColor1(0, 6);
			cout << "Tran Van Huy   ";
		}
		if (_kbhit()) {
			kitu = _getch();

			if ((kitu == 's' || kitu == 'S') && choice == 1) {
				choice = 2;
				continue;
			}
			else if ((kitu == 'w' || kitu == 'W') && choice == 2) {
				choice = 1;
				continue;
			}
			else if ((kitu == 'w' || kitu == 'W') && choice == 3) {
				choice = 2;
				continue;
			}
			else if ((kitu == 'w' || kitu == 'W') && choice == 4) {
				choice = 3;
				continue;
			}
			else if ((kitu == 'w' || kitu == 'W') && choice == 5) {
				choice = 4;
				continue;
			}
			else if ((kitu == 's' || kitu == 'S') && choice == 2) {
				choice = 3;
				continue;
			}
			else if ((kitu == 's' || kitu == 'S') && choice == 3) {
				choice = 4;
				continue;
			}
			else if ((kitu == 's' || kitu == 'S') && choice == 4) {
				choice = 5;
				continue;
			}
			else if ((kitu == 's' || kitu == 'S') && choice == 5) {
				choice = 4;
				continue;
			}
			else if (kitu == 27) {
				
				break;
			}
		}
	} while (kitu != 27);
	system("cls");

	for (int i = 0; i < HEIGHT + 1; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			SetColor1(8, 0);
			cout << " ";
		}
		cout << "\n";
	}
	chuMenuHunting(1, 1);
	chuMenuCredit(1, 1);
	ranMenu(2);
	return;
}
void snakeInit(point*& toaDoSnake)
{
	toaDoSnake = new point[MAX];
	int x = 1, y = 13;
	for (int i = 0; i < sl; i++)
	{
		toaDoSnake[i].x = x;
		toaDoSnake[i].y = y;
		x--;
	}
}
void drawSnake(point *&toaDoSnake, point Food)
{
	if (snakeEatFood(Food, toaDoSnake[0]) == true)
	{
		index++;
	}
	for (int i = 0; i < MAX; i++)
	{
		str[i] = sequence[i % 32];
	}
	for (int i = 0; i < sl; i++) {
		gotoXY(toaDoSnake[i].x, toaDoSnake[i].y);
		if (i == 0) {
			SetColor(4);
			cout << str[0];
		}
		else {
			SetColor(snakeColor);
			cout << str[i];
		}
	}
}
void drawSnake2(point *&toaDoSnake, point Food)
{
	for (int i = 0; i < MAX; i++)
	{
		str[i] = str[i + 1];
	}
	for (int i = 0; i < sl; i++) {
		gotoXY(toaDoSnake[i].x, toaDoSnake[i].y);
		if (i == 0) {
			SetColor(4);
			cout << str[0];
		}
		else {
			SetColor(snakeColor);
			cout << str[i];
		}
	}
}
void xoaRanDiChuyen(point *&toaDoSnake)
{
	for (int i = 0; i < sl; i++)
	{
		gotoXY(toaDoSnake[i].x, toaDoSnake[i].y);
		cout << " ";
	}
}
void xuLyRan(point *&toaDoSnake, int x, int y, point& Food)
{
	if (!ranChuiVaoCong(toaDoSnake)) {
		add(toaDoSnake, x, y);
		countAdd++;
		if (snakeEatFood(Food, toaDoSnake[0]) == false)
		{
			//Khi ran di chuyen thi xoa toa do o cuoi mang
			del1(toaDoSnake, sl - 1);
		}
		if (snakeEatFood(Food, toaDoSnake[0]) == true)
		{
			PlaySound("EATING_SOUND.wav", NULL, SND_ASYNC);
			score += 10;
			foodEaten++;
			length++;
			gotoXY(95, 24);
			SetColor(4);
			cout << "Level: " << level << "/3";
			gotoXY(95, 25);
			cout << "Food: " << foodEaten << "/4";
			gotoXY(95, 26);
			cout << "Score: " << score;
			gotoXY(95, 27);
			cout << "Length: " << length;
			if (checkGate() == false)
				makeFood(Food, toaDoSnake);
			else {
				drawGate();
			}
		}
		drawSnake(toaDoSnake, Food);
		if (countAdd == sl) {
			ve_tuong_trai();
			SetColor1(7, 0);
		}
	}
	else {
		PlaySound("LEVEL_UP", NULL, SND_ASYNC);
		xuLyQuaCong(toaDoSnake);
		drawSnake2(toaDoSnake, Food);
	}
	//Ve ran
}
void xuLyRan2(point *&toaDoSnake, int x, int y, point& Food)
{
	//Khi ran di chuyen thi them vao toa do o dau mang
	add(toaDoSnake, x, y);
	countAdd++;
	if (snakeEatFood(Food, toaDoSnake[0]) == false)
	{
		//Khi ran di chuyen thi xoa toa do o cuoi mang
		del1(toaDoSnake, sl - 1);
	}
	if (snakeEatFood(Food, toaDoSnake[0]) == true)
	{
		PlaySound("EATING_SOUND.wav", NULL, SND_ASYNC);
		score += 10;
		foodEaten++;
		length++;
		score += 10;
		if (speed < 13)
			speed++;
		gotoXY(95, 24);
		SetColor(4);
		cout << "Score: " << score;
		gotoXY(95, 25);
		cout << "Food: " << foodEaten << "/oo";
		gotoXY(95, 26);
		cout << "Length: " << length;
		makeFood(Food, toaDoSnake);
		//Ran ma an food thi tao food moi
	}
	//Ve ran
	drawSnake(toaDoSnake, Food);
	if (countAdd == sl) {
		ve_tuong_trai();
		SetColor1(7, 0);
	}
}
void add(point*& toaDoSnake, int& x, int& y)
{
	for (int i = sl; i > 0; i--)
	{
		toaDoSnake[i].x = toaDoSnake[i - 1].x;
		toaDoSnake[i].y = toaDoSnake[i - 1].y;
	}
	toaDoSnake[0].x = x;
	toaDoSnake[0].y = y;
	sl++;
}
void del1(point*& toaDoSnake, int vt)
{
	for (int i = vt; i < sl; i++)
	{
		toaDoSnake[i].x = toaDoSnake[i + 1].x;
		toaDoSnake[i].y = toaDoSnake[i + 1].y;
	}
	sl--;
}
bool snakeEatItself(point *&toaDoSnake)
{
	for (int i = 1; i < sl; i++)
	{
		if ((toaDoSnake[0].x == toaDoSnake[i].x) && (toaDoSnake[0].y == toaDoSnake[i].y))
		{
			return true; //Gameover
		}
	}
	return false;
}
// Hàm phát sinh số nguyên dương ngẫu nhiên từ 1 đến 88, trừ một số nhất định
point generateRandomPointExcept(const vector<point>& except, int range, int xmin, int xmax, int ymin , int ymax) {
	// Tạo một bộ phát sinh số ngẫu nhiên
	random_device rd;
	mt19937 gen(rd());

	// Tạo một phân phối đều từ 1 đến 88
	uniform_int_distribution<> dis(1, range);

	// Tạo một vector chứa các số từ 1 đến 88
	vector<point> numbers;
	for (int i = xmin; i <= xmax; ++i) {
		if (ymax == 0) {
			numbers.push_back({ i,0 });
		}
		else
			for (int j = ymin; j <= ymax; j++)
			{
				numbers.push_back({ i,j });
			}
	}
	// Loại bỏ các số bạn không muốn
	for (point num : except) {
		auto it = find(numbers.begin(), numbers.end(), num);
		if (it != numbers.end()) {
			numbers.erase(it);
		}
	}
	// Phát sinh số ngẫu nhiên từ danh sách đã xử lý
	int index = dis(gen) % numbers.size();
	return numbers[index];
}
void makeFood(point& Food, point *&toaDoSnake)
{
	SetColor1(7, 0);
	int i;	//Biến màu
	switch (level) {
	case 1:
		do
		{
			//1 <= Food.x <= 89
			Food.x = rand() % 88 + 1;
			//1 <= Food.y <= 29
			Food.y = rand() % 28 + 1;
		} while (snakePassFood(Food, toaDoSnake) == true);
		break;
	case 2:
		do
		{
			Food = generateRandomPointExcept(obstacles_2, 88, 1, 88, 1, 28);
		} while (snakePassFood(Food, toaDoSnake) == true);
		break;
	case 3:
		do
		{
			Food = generateRandomPointExcept(obstacles_3, 88, 1, 88, 2, 28);
		} while (snakePassFood(Food, toaDoSnake) == true);
		break;
	}
	i = rand() % 6 + 1;
	SetColor(i);
	gotoXY(Food.x, Food.y);
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"\u25CF";
	_setmode(_fileno(stdout), _O_TEXT);
	SetColor(7);//mau trang
}
bool snakePassFood(point Food, point *&toaDoSnake)
{
	for (int i = 0; i < sl; i++)
	{
		if ((Food.x == toaDoSnake[i].x) && (Food.y == toaDoSnake[i].y))
		{
			return true;//Ran di qua food
		}
	}
	return false;
}
bool snakeEatFood(point Food, point head)
{
	if ((head.x == Food.x) && (head.y == Food.y))
	{
		return true;//Ran an food
	}
	return false;
}
void xuLyDiChuyen()
{
	int huongDiChuyen = 2;
	while (true)
	{
		xoaRanDiChuyen(toaDoSnake);
		//0: di xuong
		//1: di len
		//2: qua phai
		//3: trai
		//Dieu khien ran, neu co phim nhap vao
		if (_kbhit())
		{
			//Nhan vao ki tu cua ban phim
			char kitu = _getch();
			if ((kitu == 'w' || kitu == 'W') && huongDiChuyen != 0)//Di len
			{
				huongDiChuyen = 1;
			}
			else if ((kitu == 's' || kitu == 'S') && huongDiChuyen != 1)//Di xuong
			{
				huongDiChuyen = 0;
			}
			else if ((kitu == 'd' || kitu == 'D') && huongDiChuyen != 3)//Di qua phai
			{
				huongDiChuyen = 2;
			}
			else if ((kitu == 'a' || kitu == 'A') && huongDiChuyen != 2)//Di trai
			{
				huongDiChuyen = 3;
			}
			else if ((kitu == 'p' || kitu == 'P'))
				//pauseGame(toaDoSnake);
				pause(toaDoSnake);
			if (kitu == -32)
			{
				kitu = _getch();
				if (kitu == 72 && huongDiChuyen != 0)
					huongDiChuyen = 1;
				else if (kitu == 80 && huongDiChuyen != 1)
					huongDiChuyen = 0;
				else if (kitu == 77 && huongDiChuyen != 3)
					huongDiChuyen = 2;
				else if (kitu == 75 && huongDiChuyen != 2)
					huongDiChuyen = 3;
			}
		}
		//Di chuyen theo huong di chuyen
		if (!ranChuiVaoCong(toaDoSnake)) {
			if (huongDiChuyen == 0)
			{
				y++;
			}
			else if (huongDiChuyen == 1)
			{
				y--;
			}
			else if (huongDiChuyen == 2)
			{
				x++;
			}
			else if (huongDiChuyen == 3)
			{
				x--;
			}
		}
		else {
			if (huongDiChuyen == 0)
			{
				y++;
			}
			else if (huongDiChuyen == 1)
			{
				y++;
			}
			else if (huongDiChuyen == 2)
			{
				x++;
			}
			else if (huongDiChuyen == 3)
			{
				x--;
			}
		}
		xuLyRan(toaDoSnake, x, y, Food);
		//Game over
		Sleep(150 - speed * 20);
		if (GameOver(toaDoSnake))
		{
			CloseBackgroundMusic();
			PlaySound("GAME_OVER.wav", NULL, SND_ASYNC);
			countAdd = 0;
			x = 1, y = 13;
			saveNormalHighScore(score, userName, level, length);
			drawGameOver(25, 10, 4, 0);
			break;
		}
	}
	char x333 = '8'; int choice333 = 1;
	SetColor1(8, 14);
	gotoXY(55, 18);
	cout << ">> Replay <<";
	gotoXY(52, 20);
	cout << "Back to Menu";
	gotoXY(56, 22);
	cout << "Exit";
	do {
		if (choice333 == 1) {
			gotoXY(55, 18);
			SetColor1(15, 4);
			cout << ">> Replay <<";
		}
		else {
			gotoXY(55, 18);
			SetColor1(8, 14);
			cout << "   Replay   ";
		}
		if (choice333 == 2) {
			gotoXY(52, 20);
			SetColor1(15, 4);
			cout << ">> Back to Menu <<";
		}
		else {
			gotoXY(52, 20);
			SetColor1(8, 14);
			cout << "   Back to Menu   ";
		}
		if (choice333 == 3) {
			gotoXY(56, 22);
			SetColor1(15, 4);
			cout << ">> Exit <<";
		}
		else {
			gotoXY(56, 22);
			SetColor1(8, 14);
			cout << "   Exit   ";
		}
		if (_kbhit()) {
			x333 = _getch();
			if (x333 == 27)break;
			else if ((x333 == 's' || x333 == 'S') && choice333 == 1) {
				choice333 = 2;
				continue;
			}
			else if ((x333 == 'w' || x333 == 'W') && choice333 == 1) {
				choice333 = 3;
				continue;
			}
			if ((x333 == 's' || x333 == 'S') && choice333 == 2) {
				choice333 = 3;
				continue;
			}
			else if ((x333 == 'w' || x333 == 'W') && choice333 == 2) {
				choice333 = 1;
				continue;
			}
			if ((x333 == 's' || x333 == 'S') && choice333 == 3) {
				choice333 = 1;
				continue;
			}
			else if ((x333 == 'w' || x333 == 'W') && choice333 == 3) {
				choice333 = 2;
				continue;
			}
			else if (x333 == '\r' && choice333 == 1) {//Chơi lại từ đầu (Replay)
				system("cls");
				ResetGameData();
				SetColor1(7, 0);
				Start(1);
				break;
			}
			else if (x333 == '\r' && choice333 == 2) {//Trở về Menu (Back to Menu)
				ResetGameData();
				SetColor1(7, 0);
				CloseBackgroundMusic();
				drawMenu();
				break;
			}
			else if (x333 == '\r' && choice333 == 3) {//Thoát game (Exit)
				system("cls");
				SetColor1(7, 0);
				exit(0);
			}
		}
	} while (x333 != 27);

	
}
void xuLyDiChuyen2()	//For infinity mode
{
	int huongDiChuyen = 2;
	while (true)
	{
		xoaRanDiChuyen(toaDoSnake);
		//0: di xuong
		//1: di len
		//2: qua phai
		//3: trai
		//Dieu khien ran, neu co phim nhap vao
		if (_kbhit())
		{
			//Nhan vao ki tu cua ban phim
			char kitu = _getch();
			if ((kitu == 'w' || kitu == 'W') && huongDiChuyen != 0)//Di len
			{
				huongDiChuyen = 1;
			}
			else if ((kitu == 's' || kitu == 'S') && huongDiChuyen != 1)//Di xuong
			{
				huongDiChuyen = 0;
			}
			else if ((kitu == 'd' || kitu == 'D') && huongDiChuyen != 3)//Di qua phai
			{
				huongDiChuyen = 2;
			}
			else if ((kitu == 'a' || kitu == 'A') && huongDiChuyen != 2)//Di trai
			{
				huongDiChuyen = 3;
			}
			else if ((kitu == 'p' || kitu == 'P'))
				pause(toaDoSnake);
			if (kitu == -32)
			{
				kitu = _getch();
				if (kitu == 72 && huongDiChuyen != 0)
					huongDiChuyen = 1;
				else if (kitu == 80 && huongDiChuyen != 1)
					huongDiChuyen = 0;
				else if (kitu == 77 && huongDiChuyen != 3)
					huongDiChuyen = 2;
				else if (kitu == 75 && huongDiChuyen != 2)
					huongDiChuyen = 3;
			}
		}
		//Di chuyen theo huong di chuyen
		if (huongDiChuyen == 0)
		{
			y++;
		}
		else if (huongDiChuyen == 1)
		{
			y--;
		}
		else if (huongDiChuyen == 2)
		{
			x++;
		}
		else if (huongDiChuyen == 3)
		{
			x--;
		}
		if (y == 0)
			y = MAX_LENGTH - 2;
		else if (y == MAX_LENGTH - 1)
			y = 0 + 1;
		else if (x == 0)
			x = 90 - 2;
		else if (x == 89)
			x = 0 + 1;
		xuLyRan2(toaDoSnake, x, y, Food);
		//Game over
		if (GameOver2())
		{
			CloseBackgroundMusic();
			PlaySound("GAME_OVER.wav", NULL, SND_ASYNC);
			countAdd = 0;
			x = 1, y = 13;
			saveHighScore(score, userName, length);
			drawGameOver(25, 10, 4, 0);
			break;
		}
		Sleep(150 - speed * 10);
	}
	
	char x333 = '8'; int choice333 = 1;
	SetColor1(8, 14);
	gotoXY(55, 18);
	cout << ">> Replay <<";
	gotoXY(52, 20);
	cout << "Back to Menu";
	gotoXY(56, 22);
	cout << "Exit";
	do {
		if (choice333 == 1) {
			gotoXY(55, 18);
			SetColor1(15, 4);
			cout << ">> Replay <<";
		}
		else {
			gotoXY(55, 18);
			SetColor1(8, 14);
			cout << "   Replay   ";
		}
		if (choice333 == 2) {
			gotoXY(52, 20);
			SetColor1(15, 4);
			cout << ">> Back to Menu <<";
		}
		else {
			gotoXY(52, 20);
			SetColor1(8, 14);
			cout << "   Back to Menu   ";
		}
		if (choice333 == 3) {
			gotoXY(56, 22);
			SetColor1(15, 4);
			cout << ">> Exit <<";
		}
		else {
			gotoXY(56, 22);
			SetColor1(8, 14);
			cout << "   Exit   ";
		}
		if (_kbhit()) {
			x333 = _getch();
			if (x333 == 27)break;
			else if ((x333 == 's' || x333 == 'S') && choice333 == 1) {
				choice333 = 2;
				continue;
			}
			else if ((x333 == 'w' || x333 == 'W') && choice333 == 1) {
				choice333 = 3;
				continue;
			}
			if ((x333 == 's' || x333 == 'S') && choice333 == 2) {
				choice333 = 3;
				continue;
			}
			else if ((x333 == 'w' || x333 == 'W') && choice333 == 2) {
				choice333 = 1;
				continue;
			}
			if ((x333 == 's' || x333 == 'S') && choice333 == 3) {
				choice333 = 1;
				continue;
			}
			else if ((x333 == 'w' || x333 == 'W') && choice333 == 3) {
				choice333 = 2;
				continue;
			}
			else if (x333 == '\r' && choice333 == 1) {//Chơi lại từ đầu (Replay)
				system("cls");
				ResetGameData();
				SetColor1(7, 0);
				Start(1);
				break;
			}
			else if (x333 == '\r' && choice333 == 2) {//Trở về Menu (Back to Menu)
				ResetGameData();
				SetColor1(7, 0);
				CloseBackgroundMusic();
				drawMenu();
				break;
			}
			else if (x333 == '\r' && choice333 == 3) {//Thoát game (Exit)
				system("cls");
				SetColor1(7, 0);
				exit(0);
			}
		}
	} while (x333 != 27);
}
//Game mode
void InfinityMode()
{
	snakeInit(toaDoSnake);
	ve_tuong2();
	drawSnake(toaDoSnake, Food);
	srand(time(NULL));
	makeFood(Food, toaDoSnake);
	xuLyDiChuyen2();
}
void NormalMode()
{
	snakeInit(toaDoSnake);
	//loadGameInit(toaDoSnake, 3);
	//ve_tuong1();
	switch (level) {
	case 1:
		map(1);
		break;
	case 2:
		map(2);
		break;
	case 3:
		map(3);
		break;
	}
	drawSnake(toaDoSnake, Food);
	srand(time(NULL));
	makeFood(Food, toaDoSnake);
	xuLyDiChuyen();
}
bool GameOver(point *&toaDoSnake)
{
	//Chua co cong
	if (toaDoSnake == NULL)
		return false;
	if (Gate == NULL) {
		if (y == 29 || y == 0 || x == 0 || x == 89)
		{
			delete[] toaDoSnake;
			return true;
		}
		else if (snakeEatItself(toaDoSnake) == true)
		{
			delete[] toaDoSnake;
			return true;
		}
	}
	//co cong
	else
	{
		if (x == Gate->x && y == Gate->y)
			return false;
		else if ((y == 29 || y == 0 || x == 0 || x == 89) || (y == Gate->y + 1 && x == Gate->x - 1) || (y == Gate->y + 1 && x == Gate->x + 1) || (x == Gate->x - 1 && y == Gate->y - 1) || (x == Gate->x + 1 && y == Gate->y + 1) && (y != Gate->y && x != Gate->x)) {
			delete[] toaDoSnake;
			return true;
		}
		else if (snakeEatItself(toaDoSnake) == true)
		{
			delete[] toaDoSnake;
			return true;
		}
	}
	int countObstacles;
	switch (level) {
	case 2:
		countObstacles = obstacles_2.size();
		for (int i = 0; i < countObstacles; i++)
		{
			if (x == obstacles_2[i].x && y == obstacles_2[i].y) {
				delete[] toaDoSnake;
				return true;
			}
		}
		break;
	case 3:
		countObstacles = obstacles_3.size();
		for (int i = 0; i < countObstacles; i++)
		{
			if (x == obstacles_3[i].x && y == obstacles_3[i].y) {
				delete[] toaDoSnake;
				return true;
			}
		}
		break;
	}
	return false;
}
bool GameOver2()	//For infinity mode
{
	if (snakeEatItself(toaDoSnake) == true)
		return true;
}
void ve_tuong1()
{
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			SetColor1(7, 0);
			cout << " ";
		}
		cout << "\n";
	}
	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_trai();
	ve_tuong_phai();
	ve_tuong_phai_ngoai_cung();
	veNgang(90, 22, 29, 10, 0);
	//Chu L

	veDoc(92, 1, 4, 12, 0);
	veNgang(92, 5, 4, 12, 0);
	//Chu E
	veDoc(92, 7, 5, 12, 0);
	veNgang(92, 7, 4, 12, 0);
	veNgang(92, 9, 4, 12, 0);
	veNgang(92, 11, 4, 12, 0);
	//Chu V
	veCheoXuong(91, 13, 2, 12, 0);
	veCheoLen(93, 15, 2, 12, 0);
	//Chu E
	veDoc(92, 17, 5, 12, 0);
	veNgang(92, 17, 4, 12, 0);
	veNgang(92, 19, 4, 12, 0);
	veNgang(92, 21, 4, 12, 0);
	//Chu L
	veDoc(98, 17, 4, 12, 0);
	veNgang(98, 21, 4, 12, 0);
	//1
	veCheoLen(105, 9, 2, 12, 0);
	veDoc(108, 6, 6, 12, 0);
	veNgang(105, 11, 7, 12, 0);
	//Khung
	veDoc(103, 5, 9, 9, 0);
	veNgang(103, 5, 10, 9, 0);
	veDoc(113, 5, 9, 9, 0);
	veNgang(103, 13, 10, 9, 0);

	//ran nho
	//veCheoLen(105, 17, 2, 0, 0);
	//veNgang(107, 15, 3, 0, 0);
	//veCheoXuong(110, 15, 2, 0, 0);
	//veDoc(107, 18, 2, 0, 0);
	//veNgang(106, 18, 1, 0, 0);
	//veDoc(110, 18, 2, 0, 0);
	//veNgang(111, 18, 1, 0, 0);

	gotoXY(108, 14);
	SetColor1(7, 2);
	cout << "_";
	cout << "_";
	gotoXY(107, 15);
	cout << "{00}";
	gotoXY(107, 16);
	cout << "\\__/";
	gotoXY(107, 17);
	cout << "/^/";
	gotoXY(106, 18);
	cout << "( (";
	gotoXY(106, 19);
	cout << "\\_\\____";
	gotoXY(106, 20);
	cout << "(______)";
	gotoXY(105, 21);
	cout << "(_______()0o";

	//Ghi chữ
	gotoXY(95, 24);
	SetColor(4);
	cout << "Level: " << level << "/3";
	gotoXY(95, 25);
	cout << "Food: " << foodEaten << "/4";
	gotoXY(95, 26);
	cout << "Score: " << score;
	gotoXY(95, 27);
	cout << "Length: " << length;
	gotoXY(91, 23);
	for (int i = 0; i < 28; i++) {
		cout << "=";
	}
	gotoXY(91, 28);
	for (int i = 0; i < 28; i++) {
		cout << "=";
	}
}
void ve_tuong2()
{
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			SetColor1(7, 0);
			cout << " ";
		}
		cout << "\n";
	}
	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_trai();
	ve_tuong_phai();
	ve_tuong_phai_ngoai_cung();
	veNgang(90, 22, 29, 10, 0);
	//Chu L

	veDoc(92, 1, 4, 12, 0);
	veNgang(92, 5, 4, 12, 0);
	//Chu E
	veDoc(92, 7, 5, 12, 0);
	veNgang(92, 7, 4, 12, 0);
	veNgang(92, 9, 4, 12, 0);
	veNgang(92, 11, 4, 12, 0);
	//Chu V
	veCheoXuong(91, 13, 2, 12, 0);
	veCheoLen(93, 15, 2, 12, 0);
	//Chu E
	veDoc(92, 17, 5, 12, 0);
	veNgang(92, 17, 4, 12, 0);
	veNgang(92, 19, 4, 12, 0);
	veNgang(92, 21, 4, 12, 0);
	//Chu L
	veDoc(98, 17, 4, 12, 0);
	veNgang(98, 21, 4, 12, 0);
	//1
	veCheoLen(105, 9, 2, 12, 0);
	veDoc(108, 6, 6, 12, 0);
	veNgang(105, 11, 7, 12, 0);
	//Khung
	veDoc(103, 5, 9, 9, 0);
	veNgang(103, 5, 10, 9, 0);
	veDoc(113, 5, 9, 9, 0);
	veNgang(103, 13, 10, 9, 0);

	//ran nho
	//veCheoLen(105, 17, 2, 0, 0);
	//veNgang(107, 15, 3, 0, 0);
	//veCheoXuong(110, 15, 2, 0, 0);
	//veDoc(107, 18, 2, 0, 0);
	//veNgang(106, 18, 1, 0, 0);
	//veDoc(110, 18, 2, 0, 0);
	//veNgang(111, 18, 1, 0, 0);

	gotoXY(108, 14);
	SetColor1(7, 2);
	cout << "_";
	cout << "_";
	gotoXY(107, 15);
	cout << "{00}";
	gotoXY(107, 16);
	cout << "\\__/";
	gotoXY(107, 17);
	cout << "/^/";
	gotoXY(106, 18);
	cout << "( (";
	gotoXY(106, 19);
	cout << "\\_\\____";
	gotoXY(106, 20);
	cout << "(______)";
	gotoXY(105, 21);
	cout << "(_______()0o";

	//Ghi chữ
	gotoXY(95, 24);
	SetColor(4);
	cout << "Score: " << score;
	gotoXY(95, 25);
	cout << "Food: " << foodEaten << "/oo";
	gotoXY(95, 26);
	cout << "Length: " << length;
	gotoXY(91, 23);
	for (int i = 0; i < 28; i++) {
		cout << "=";
	}
	gotoXY(91, 28);
	for (int i = 0; i < 28; i++) {
		cout << "=";
	}
}
void ve_tuong_tren()
{
	int x = 0, y = 0;
	while (x < MAX_WIDTH - 1)
	{
		gotoXY(x, y);
		SetColor1(10, 0);
		cout << " ";
		x++;
	}
}
void ve_tuong_duoi()
{
	int x = 0, y = MAX_LENGTH - 1;;
	while (x < MAX_WIDTH - 1)
	{
		gotoXY(x, y);
		SetColor1(10, 0);
		cout << " ";
		x++;
	}
}
void ve_tuong_trai()
{
	int x = 0, y = 0;
	while (y < MAX_LENGTH - 1)
	{
		gotoXY(x, y);
		SetColor1(10, 0);
		cout << " ";
		y++;
	}
}
void ve_tuong_phai()
{
	int x = 89, y = 0;
	while (y < MAX_LENGTH - 1)
	{
		gotoXY(x, y);
		SetColor1(10, 0);
		cout << " ";
		y++;
	}
}
void ve_tuong_phai_ngoai_cung()
{
	int x = 119, y = 0;
	while (y < MAX_LENGTH)
	{
		gotoXY(x, y);
		SetColor1(10, 0);
		cout << " ";
		y++;
	}
}
void veNgang(int x, int y, int len, int maunen, int mauchu) { //Ham ve ngang chen tu vi tri nao do
	gotoXY(x, y);
	SetColor1(maunen, mauchu);
	for (int i = 1; i <= len; i++) {
		cout << " ";
	}
}
void veDoc(int x, int y, int len, int maunen, int mauchu) { //Ham ve doc chen tu vi tri nao do
	gotoXY(x, y);
	SetColor1(maunen, mauchu);
	for (int i = 1; i <= len; i++) {
		cout << " ";
		y++;
		gotoXY(x, y);
	}
}
void veCheoXuong(int x, int y, int len, int maunen, int mauchu) {
	gotoXY(x, y);
	SetColor1(maunen, mauchu);
	for (int i = 0; i <= len; i++) {
		gotoXY(x, y);
		cout << " ";
		x += 1;
		y += 1;
	}
}
void veCheoLen(int x, int y, int len, int maunen, int mauchu) {
	gotoXY(x, y);
	SetColor1(maunen, mauchu);
	for (int i = 0; i <= len; i++) {
		gotoXY(x, y);
		cout << " ";
		x += 1;
		y -= 1;
	}
}
void veCheoXuongPhaiQuaTrai(int x, int y, int len, int maunen, int mauchu) {
	gotoXY(x, y);
	SetColor1(maunen, mauchu);
	for (int i = 0; i <= len; i++) {
		gotoXY(x, y);
		cout << " ";
		x -= 1;
		y += 1;
	}
}
void veCheoLenPhaiQuaTrai(int x, int y, int len, int maunen, int mauchu) {
	gotoXY(x, y);
	SaveConsoleAttributes();
	SetColor1(maunen, mauchu);
	for (int i = 0; i <= len; i++) {
		gotoXY(x, y);
		cout << " ";
		x -= 1;
		y -= 1;
	}
	RestoreConsoleAttributes();
}
void drawMenu() {
	PlayBackgroundMusic("BACKGROUND.wav");
	int loops = 0;
	system("cls");
	for (int i = 0; i < HEIGHT + 1; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			SetColor1(8, 0);
			cout << " ";
		}
		cout << "\n";
	}
	int choice = 1;
	int m1 = 0;
	int m2 = 14;
	int mauchumenu = 0, mauchucredit = 1;
	shouldContinue = true;

	//Nhan vao ki tu cua ban phim
	char kitu = '7';
	int mau = 13;

	//Nut 1

	nut(1, 1, 3, 0);
	hoatHoa(1, m1, m2);

	//Nut 2

	nut(22, 1, 3, 0);

	//Nut 3

	nut(1, 10, 3, 0);

	//Nut 4

	nut(22, 10, 3, 0);

	//Nut 5

	nut(1, 19, 3, 0);

	//Nut 6

	nut(22, 19, 3, 0);
	gotoXY(2, 27);
	SetColor1(8, 15);
	cout << "Press Enter to choose!";
	gotoXY(2, 28);
	SetColor1(8, 15);
	cout << "Press X to Exit!";

	thread m(ChangeColorMenu);

	std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
	ranMenu(1);
	cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
	lock.unlock(); // Mở khóa mutex

	while(true){
		//Hoạt họa nút 1
		if (choice == 1) {
			//Nut 1

			std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
			nut(1, 1, mau, 0);
			hoatHoa(1, m1, m2);
			//Viet chu cho nut 1
			gotoXY(8, 4); // giá trị 84
			cout << "START";
			cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
			lock.unlock(); // Mở khóa mutex

		}
		else {

			std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
			nut(1, 1, 3, 0);
			gotoXY(8, 4); // giá trị 84
			cout << "START";
			cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
			lock.unlock(); // Mở khóa mutex
		}


		//Hoạt họa nút 2
		if (choice == 2) {

			std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
			nut(22, 1, mau, 0);
			hoatHoa(2, m1, m2);
			gotoXY(29, 4);  //giá trị 294
			cout << "LOAD";
			cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
			lock.unlock(); // Mở khóa mutex
		}
		else {
			//Nut 2

			std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
			nut(22, 1, 3, 0);
			gotoXY(29, 4);  //giá trị 294
			cout << "LOAD";
			cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
			lock.unlock(); // Mở khóa mutex
		}
		//Viet chu cho nut 2



		//Hoạt họa nút 3
		if (choice == 3) {

			std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
			nut(1, 10, mau, 0);
			hoatHoa(3, m1, m2);
			//Viet chu cho nut 3
			gotoXY(5, 13); //giá trị 813
			cout << "HIGH SCORE";
			cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
			lock.unlock(); // Mở khóa mutex
		}
		else {
			//Nut 3
			std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
			nut(1, 10, 3, 0);
			//Viet chu cho nut 3
			gotoXY(5, 13); //giá trị 813
			cout << "HIGH SCORE";
			cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
			lock.unlock(); // Mở khóa mutex
		}


		//Hoạt họa nút 4
		if (choice == 4) {
			//Nut 4
			std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
			nut(22, 10, mau, 0);
			hoatHoa(4, m1, m2);
			//Viet chu cho nut 4
			gotoXY(28, 13);
			cout << "TUTORIAL";
			cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
			lock.unlock(); // Mở khóa mutex
		}
		else {
			//Nut 4

			std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
			nut(22, 10, 3, 0);
			//Viet chu cho nut 4
			gotoXY(28, 13);
			cout << "TUTORIAL";
			cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
			lock.unlock(); // Mở khóa mutex
		}


		//Hoạt họa nút 5
		if (choice == 5) {
			//Nut 5

			std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
			nut(1, 19, mau, 0);
			hoatHoa(5, m1, m2);
			gotoXY(7, 22);
			cout << "SETTING";
			cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
			lock.unlock(); // Mở khóa mutex
		}
		else {
			//Nut 5

			std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
			nut(1, 19, 3, 0);
			gotoXY(7, 22);
			cout << "SETTING";
			cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
			lock.unlock(); // Mở khóa mutex
		}
		//Hoạt họa nút 6
		if (choice == 6) {
			//Nut 6

			std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
			nut(22, 19, mau, 0);
			hoatHoa(6, m1, m2);
			gotoXY(28, 22);
			cout << "CREDITS";
			cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
			lock.unlock(); // Mở khóa mutex
		}
		else {
			//Nut 6

			std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
			nut(22, 19, 3, 0);
			gotoXY(28, 22);
			cout << "CREDITS";
			cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
			lock.unlock(); // Mở khóa mutex
		}
		if (_kbhit())
		{
			//Nhan vao ki tu cua ban phim
			// 72 up 80 down 75 left 77 right
			kitu = _getch();
			if ((kitu == 's' || kitu == 'S' || kitu == 50) && choice == 1)
			{
				choice = 3;
				std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
				del(1);
				ranMenu(2);
				cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
				lock.unlock(); // Mở khóa mutex
				continue;
			}
			else if ((kitu == 'd' || kitu == 'D' || kitu == 77) && choice == 1)
			{
				choice = 2;
				std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
				del(1);
				ranMenu(1);
				cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
				lock.unlock(); // Mở khóa mutex
				continue;
			}
			else if ((kitu == 'a' || kitu == 'A' || kitu == 75) && choice == 2)
			{
				choice = 1;
				std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
				del(2);
				ranMenu(1);
				cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
				lock.unlock(); // Mở khóa mutex
				continue;
			}
			else if ((kitu == 's' || kitu == 'S' || kitu == 80) && choice == 2)
			{
				choice = 4;
				std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
				del(2);
				ranMenu(2);
				cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
				lock.unlock(); // Mở khóa mutex
				continue;
			}
			else if ((kitu == 's' || kitu == 'S' || kitu == 80) && choice == 3)
			{
				choice = 5;
				std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
				del(3);
				ranMenu(3);
				cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
				lock.unlock(); // Mở khóa mutex
				continue;
			}
			else if ((kitu == 'w' || kitu == 'W' || kitu == 72) && choice == 3)
			{
				choice = 1;
				std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
				del(3);
				ranMenu(1);
				cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
				lock.unlock(); // Mở khóa mutex
				continue;
			}
			else if ((kitu == 'd' || kitu == 'D' || kitu == 77) && choice == 3)
			{
				choice = 4;
				std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
				del(3);
				ranMenu(2);
				cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
				lock.unlock(); // Mở khóa mutex
				continue;
			}
			else if ((kitu == 'w' || kitu == 'W' || kitu == 72) && choice == 4)
			{
				choice = 2;
				std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
				del(4);
				ranMenu(1);
				cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
				lock.unlock(); // Mở khóa mutex
				continue;
			}
			else if ((kitu == 'a' || kitu == 'A' || kitu == 75) && choice == 4)
			{
				choice = 3;
				std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
				del(4);
				ranMenu(2);
				cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
				lock.unlock(); // Mở khóa mutex
				continue;
			}
			else if ((kitu == 's' || kitu == 'S' || kitu == 80) && choice == 4)
			{
				choice = 6;
				std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
				del(4);
				ranMenu(3);
				cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
				lock.unlock(); // Mở khóa mutex
				continue;
			}
			else if ((kitu == 'w' || kitu == 'W' || kitu == 72) && choice == 5)
			{
				choice = 3;
				std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
				del(5);
				ranMenu(2);
				cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
				lock.unlock(); // Mở khóa mutex
				continue;
			}
			else if ((kitu == 'd' || kitu == 'D' || kitu == 77) && choice == 5)
			{
				choice = 6;
				std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
				del(5);
				ranMenu(3);
				cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
				lock.unlock(); // Mở khóa mutex
				continue;
			}
			else if ((kitu == 'w' || kitu == 'W' || kitu == 72) && choice == 6)
			{
				choice = 4;
				std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
				del(6);
				ranMenu(2);
				cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
				lock.unlock(); // Mở khóa mutex
				continue;
			}
			else if ((kitu == 'a' || kitu == 'A' || kitu == 75) && choice == 6)
			{
				choice = 5;
				std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
				del(6);
				ranMenu(3);
				cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
				lock.unlock(); // Mở khóa mutex
				continue;
			}
			else if ((kitu == '\r') && choice == 5)
			{

				setting();
			}
			else if ((kitu == '\r') && choice == 4)
			{
				needChange = false;
				cv.notify_one();
				tutorial();
			}
			else if ((kitu == '\r') && choice == 1)
			{
				modeSauStart();
				break;
			}
			else if ((kitu == '\r') && choice == 2)
			{
				loadGame();
			}
			else if (kitu == '\r' && choice == 6) {
				credit();
			}
			else if (kitu == '\r' && choice == 3) {
				highScoress();
			}
			else if (kitu == 'x' || kitu == 'X') {
				system("cls");
				exit(0);
			}
		}
	}
}
void chuMenuCredit(int a, int b) {
	//credit
	//by N10
	//b
	veDoc(81, 23, 5, a, b);
	veNgang(81, 25, 3, a, b);
	veDoc(84, 25, 3, a, b);
	veNgang(81, 27, 4, a, b);

	//Y
	veCheoXuong(86, 23, 2, a, b);
	veCheoLen(88, 25, 2, a, b);
	veDoc(88, 25, 3, a, b);

	//N
	veDoc(95, 23, 5, a, b);
	veCheoXuong(96, 24, 3, a, b);
	veDoc(99, 23, 5, a, b);
	//1
	veCheoLen(101, 24, 1, a, b);
	veDoc(103, 23, 5, a, b);
	//0
	veDoc(105, 23, 5, a, b);
	veNgang(105, 23, 4, a, b);
	veNgang(105, 27, 4, a, b);
	veDoc(109, 23, 5, a, b);
}
void chuMenuHunting(int a, int b) {
	//Ve chu:
		//Chu H:
	veDoc(55, 1, 5, a, b);
	veNgang(55, 3, 5, a, b);
	veDoc(59, 1, 5, a, b);
	//Chu U:
	veDoc(61, 1, 4, a, b);
	veDoc(65, 1, 4, a, b);
	veNgang(61, 5, 5, a, b);
	//Chu N:
	veDoc(67, 1, 5, a, b);
	veCheoXuong(68, 2, 3, a, b);
	veDoc(71, 1, 5, a, b);
	//chu T
	veNgang(73, 1, 5, a, b);
	veDoc(75, 1, 5, a, b);
	//Chu I
	veDoc(79, 1, 5, a, b);
	//Chu N
	veDoc(81, 1, 5, a, b);
	veCheoXuong(82, 2, 3, a, b);
	veDoc(85, 1, 5, a, b);
	//Chu G
	veDoc(87, 1, 5, a, b);
	veNgang(87, 1, 5, a, b);
	veNgang(87, 5, 5, a, b);
	veDoc(91, 3, 3, a, b);
	veNgang(89, 3, 2, a, b);
	//Chu S
	if (a + 5 == 2) a = -2;
	if (a + 5 == 8) a = 4;
	if (a + 5 == 10) a = 6;
	veNgang(75, 7, 4, a + 5, b);
	veDoc(74, 8, 2, a + 5, b);
	veNgang(75, 10, 4, a + 5, b);
	veDoc(79, 11, 2, a + 5, b);
	veNgang(75, 13, 4, a + 5, b);
	//Chu N
	if (a + 1 == 2) a = 2;
	if (a + 1 == 8) a = 8;
	if (a + 1 == 10) a = 10;
	veDoc(81, 9, 5, a + 1, b);
	veCheoXuong(82, 10, 3, a + 1, b);
	veDoc(85, 9, 5, a + 1, b);
	//Chu A
	if (a + 2 == 2) a = 1;
	if (a + 2 == 8) a = 7;
	if (a + 2 == 10) a = 9;
	veCheoLen(87, 13, 4, a + 2, b);
	veCheoXuong(91, 9, 4, a + 2, b);
	veNgang(90, 11, 3, a + 2, b);
	//Chu K
	if (a + 3 == 2) a = 0;
	if (a + 3 == 8) a = 6;
	if (a + 3 == 10) a = 8;
	veDoc(97, 9, 5, a + 3, b);
	veCheoLen(98, 11, 2, a + 3, b);
	veCheoXuong(98, 11, 2, a + 3, b);
	//Chu E
	if (a + 4 == 2) a = -1;
	if (a + 4 == 8) a = 5;
	if (a + 4 == 10) a = 7;
	veDoc(102, 9, 5, a + 4, b);
	veNgang(102, 9, 4, a + 4, b);
	veNgang(102, 11, 4, a + 4, b);
	veNgang(102, 13, 4, a + 4, b);
}
void ranMenu(int num) {
	int c = 0;
	int d = 10;
	if (num == 0) {
		c = 8;
		d = 8;
	}

	if (rancolor == 1 && num != 0) {
		d = 10;
	}
	else if (rancolor == 2 && num != 0) {
		d = 11;
	}
	else if (rancolor == 3 && num != 0) {
		d = 12;
	}


	//con rắn
	veNgang(57, 8, 7, c, 4);
	veCheoLen(53, 12, 4, c, 4);
	veCheoXuong(64, 8, 2, c, 4);
	veDoc(66, 10, 2, c, 4);
	veCheoXuong(66, 11, 1, c, 4);
	veCheoXuong(53, 12, 2, c, 4);
	veNgang(55, 14, 12, c, 4);
	veCheoLen(66, 14, 1, c, 4);
	//Mau da
	veNgang(57, 9, 8, d, 0);
	veNgang(56, 10, 10, d, 0);
	veNgang(55, 11, 11, d, 0);
	veNgang(54, 12, 13, d, 0);
	veNgang(55, 13, 12, d, 0);
	//Ve mat
	if (num == 2) {
		veNgang(58, 10, 2, 0, 0);
		veNgang(58, 11, 1, 15, 0); //lòng mắt nhìn giữa
		veNgang(59, 11, 1, 0, 0);
		veNgang(58, 12, 2, 0, 0);
	}
	else if (num == 1) {
		veNgang(58, 11, 2, 0, 0);
		veNgang(58, 10, 1, 15, 0); //lòng mắt nhìn lên trên
		veNgang(59, 10, 1, 0, 0);
		veNgang(58, 12, 2, 0, 0);
	}
	else if (num == 3) {
		veNgang(58, 10, 2, 0, 0);
		veNgang(58, 12, 1, 15, 0); //lòng mắt nhìn dưới
		veNgang(59, 12, 1, 0, 0);
		veNgang(58, 11, 2, 0, 0);
	}

	if (num != 0) {
		//Da luoi
		veCheoLen(52, 15, 1, 12, 0);
		veNgang(51, 15, 2, 12, 0);
		veCheoXuong(48, 13, 2, 12, 0);
		//veCheoXuong(47, 12, 1, 12, 0);
		veCheoLen(48, 13, 1, 12, 0);
		veNgang(47, 13, 1, 12, 0);
		veNgang(46, 12, 1, 12, 0);
		//Than
		veCheoXuongPhaiQuaTrai(58, 14, 5, 0, 0);
		veCheoXuong(55, 25, 2, 0, 0);
		veDoc(53, 20, 4, 0, 0);
		veNgang(54, 24, 1, 0, 0);

		veCheoXuongPhaiQuaTrai(66, 14, 5, 0, 0);
		veDoc(61, 20, 3, 0, 0);
		veNgang(62, 23, 7, 0, 0);

		veCheoLen(69, 23, 7, 0, 0);

		veNgang(57, 27, 18, 0, 0);
		veCheoLen(75, 27, 6, 0, 0);

		veNgang(76, 16, 30, 0, 0);
		veCheoLen(106, 16, 7, 0, 0);

		veNgang(82, 21, 28, 0, 0);
		veCheoLen(110, 21, 3, 0, 0);
		veDoc(113, 10, 9, 0, 0);

		//To than
		int xt = 58, yt = 15;
		for (int i = 0; i < 5; i++) {
			veNgang(xt, yt, 7, d, 0);
			--xt; ++yt;
		}
		xt++;
		for (int i = 0; i < 4; i++) {
			veNgang(xt, yt, 7, d, 0);
			++yt;
			if (i == 3) {
				veNgang(xt, yt - 1, 8, d, 0);
			}
		}
		int  xt1 = xt, yt1 = yt;
		xt1 += 15;
		xt++;
		int len = 23;
		for (int j = 0; j < 3; j++) {
			veNgang(xt, yt, len, d, 0);
			++xt; ++yt; len -= 2;
		}
		for (int i = 0; i < 4; i++) {
			veNgang(xt1, yt1, 9, d, 0);
			xt1++;
			yt1--;
		}
		int len1 = 38;
		for (int i = 0; i < 4; i++) {
			if (i == 3) {
				len1--;
				veNgang(xt1, yt1, len1, d, 0);
			}
			else {
				veNgang(xt1, yt1, len1, d, 0);
				xt1++; yt1--;
			}
		}
		len1 -= 31;
		yt1--;
		xt1 += 31;
		for (int k = 0; k < 7; k++) {
			veNgang(xt1, yt1, len1, d, 0);
			xt1++;
			yt1--;
			--len1;
		}
	}
	else {
		//Da luoi
		veCheoLen(52, 15, 1, d, 0);
		veNgang(51, 15, 2, d, 0);
		veCheoXuong(48, 13, 2, d, 0);
		//veCheoXuong(47, 12, 1, 12, 0);
		veCheoLen(48, 13, 1, d, 0);
		veNgang(47, 13, 1, d, 0);
		veNgang(46, 12, 1, d, 0);
		//Than
		veCheoXuongPhaiQuaTrai(58, 14, 5, d, 0);
		veCheoXuong(55, 25, 2, d, 0);
		veDoc(53, 20, 4, d, 0);
		veNgang(54, 24, 1, d, 0);

		veCheoXuongPhaiQuaTrai(66, 14, 5, d, 0);
		veDoc(61, 20, 3, d, 0);
		veNgang(62, 23, 7, d, 0);

		veCheoLen(69, 23, 7, d, 0);

		veNgang(57, 27, 18, d, 0);
		veCheoLen(75, 27, 6, d, 0);

		veNgang(76, 16, 30, d, 0);
		veCheoLen(106, 16, 7, d, 0);

		veNgang(82, 21, 28, d, 0);
		veCheoLen(110, 21, 3, d, 0);
		veDoc(113, 10, 9, d, 0);
		//To than
		int xt = 58, yt = 15;
		for (int i = 0; i < 5; i++) {
			veNgang(xt, yt, 7, d, 0);
			--xt; ++yt;
		}
		xt++;
		for (int i = 0; i < 4; i++) {
			veNgang(xt, yt, 7, d, 0);
			++yt;
			if (i == 3) {
				veNgang(xt, yt - 1, 8, d, 0);
			}
		}
		int  xt1 = xt, yt1 = yt;
		xt1 += 15;
		xt++;
		int len = 23;
		for (int j = 0; j < 3; j++) {
			veNgang(xt, yt, len, d, 0);
			++xt; ++yt; len -= 2;
		}
		for (int i = 0; i < 4; i++) {
			veNgang(xt1, yt1, 9, d, 0);
			xt1++;
			yt1--;
		}
		int len1 = 38;
		for (int i = 0; i < 4; i++) {
			if (i == 3) {
				len1--;
				veNgang(xt1, yt1, len1, d, 0);
			}
			else {
				veNgang(xt1, yt1, len1, d, 0);
				xt1++; yt1--;
			}
		}
		len1 -= 31;
		yt1--;
		xt1 += 31;
		for (int k = 0; k < 7; k++) {
			veNgang(xt1, yt1, len1, d, 0);
			xt1++;
			yt1--;
			--len1;
		}
	}
}
void drawGameOver(int x, int y, int maunen, int mauchu) {//25 10 4 0 chữ game over sẽ nằm giữa với nền đen chữ đỏ
	system("cls");
	int len = 4;
	int a = maunen, b = mauchu;
	//x=25
	chuG(x, y, a, b);
	chuA(x + 10, y, a, b);
	chuM(x + 20, y, a, b);
	chuE(x + 31, y, a, b);
	chuO(x + 39, y, a, b);
	chuV(x + 45, y, a, b);
	chuE(x + 55, y, a, b);
	chuR(x + 60, y, a, b);
	
	return;

}
void chuG(int x, int y, int maunen, int mauchu) {
	int len = 4;
	int a = maunen, b = mauchu;
	veNgang(x, y, len + 1, a, b);
	veDoc(x, y, len, a, b);
	veNgang(x, y + len, len + 1, a, b);
	veDoc(x + len, y + len - 2, len - 2, a, b);
	veNgang(x + 2, y + len - 2, len - 2, a, b);
}
void chuA(int x, int y, int maunen, int mauchu) {
	const int len = 4;
	int a = maunen, b = mauchu;
	veCheoXuongPhaiQuaTrai(x, y, len, a, b);
	veCheoXuong(x, y, len, a, b);
	veNgang(x - 2, y + 3, len + 1, a, b);

}
void chuM(int x, int y, int maunen, int mauchu) {
	const int len = 4;
	int a = maunen, b = mauchu;
	veCheoXuongPhaiQuaTrai(x, y, len, a, b);
	veCheoXuong(x, y, len - 1, a, b);
	veCheoXuongPhaiQuaTrai(x + 5, y, len - 1, a, b);
	veCheoXuong(x + 5, y, len, a, b);

}
void chuE(int x, int y, int maunen, int mauchu) {
	const int len = 4;
	int a = maunen, b = mauchu;
	veDoc(x, y, len + 1, a, b);
	veNgang(x, y, len, a, b);
	veNgang(x, y + 2, len, a, b);
	veNgang(x, y + 4, len, a, b);

}
void chuO(int x, int y, int maunen, int mauchu) {
	const int len = 4;
	int a = maunen, b = mauchu;
	veNgang(x, y, len, a, b);
	veNgang(x, y + 4, len, a, b);
	veDoc(x, y, len, a, b);
	veDoc(x + len, y, len + 1, a, b);

}
void chuV(int x, int y, int maunen, int mauchu) {
	const int len = 4;
	int a = maunen, b = mauchu;
	veCheoXuong(x, y, len, a, b);
	veCheoLen(x + 4, y + 4, len, a, b);

}
void chuR(int x, int y, int maunen, int mauchu) {
	const int len = 4;
	int a = maunen, b = mauchu;
	veDoc(x, y, len + 1, a, b);
	veNgang(x, y, len - 1, a, b);
	veDoc(x + 3, y, len - 1, a, b);
	veNgang(x, y + 2, len - 1, a, b);
	veCheoXuong(x + 1, y + 2, len - 2, a, b);

}
void chuN(int x, int y, int maunen, int mauchu) {
	const int len = 4;
	int a = maunen, b = mauchu;
	veDoc(x, y, len + 1, a, b);
	veDoc(x + len, y, len + 1, a, b);
	veCheoXuong(x, y, len, a, b);
}
void chuF(int x, int y, int maunen, int mauchu) {
	const int len = 4;
	int a = maunen, b = mauchu;
	veNgang(x, y, len, a, b);
	veNgang(x, y + 2, len, a, b);
	veDoc(x, y, len + 1, a, b);
}
//1 1 cho nút 1  22 1 cho nút 2 1 10 nút 3 22 10 nút 4 1 19 nút 5 22 19 nút 6
void nut(int x, int y, int maunen, int mauchu) {
	int len = 18;
	int a = maunen, b = mauchu;

	veNgang(x, y, len, a, b);
	veDoc(x, y, len - 12, a, b);
	veDoc(x + len, y, len - 12, a, b);
	veNgang(x, y + 6, len + 1, a, b);
	SetColor1(8, 15);
}
void hoatHoa(int sonut, int maunen, int mauchu) {
	SetColor1(maunen, mauchu);
	switch (sonut) {
	case 1:

		gotoXY(2, 2);
		printf("%c", 188);
		gotoXY(2, 6);
		printf("%c", 187);
		gotoXY(18, 2);
		printf("%c", 200);
		gotoXY(18, 6);
		printf("%c", 201);
		gotoXY(6, 4); //>>
		printf("%c", 175);
		gotoXY(14, 4);//<<
		printf("%c", 174);
		break;
	case 2:

		gotoXY(23, 2);
		printf("%c", 188);
		gotoXY(23, 6);
		printf("%c", 187);
		gotoXY(39, 2);
		printf("%c", 200);
		gotoXY(39, 6);
		printf("%c", 201);
		gotoXY(27, 4); //>>
		printf("%c", 175);
		gotoXY(34, 4);//<<
		printf("%c", 174);
		break;
	case 3:

		gotoXY(2, 11);
		printf("%c", 188);
		gotoXY(2, 15);
		printf("%c", 187);
		gotoXY(18, 11);
		printf("%c", 200);
		gotoXY(18, 15);
		printf("%c", 201);
		gotoXY(6, 13); //>>
		printf("%c", 175);
		gotoXY(13, 13);//<<
		printf("%c", 174);
		break;
	case 4:

		gotoXY(23, 11);
		printf("%c", 188);
		gotoXY(23, 15);
		printf("%c", 187);
		gotoXY(39, 11);
		printf("%c", 200);
		gotoXY(39, 15);
		printf("%c", 201);
		gotoXY(26, 13); //>>
		printf("%c", 175);
		gotoXY(37, 13);//<<
		printf("%c", 174);
		break;
	case 5:

		gotoXY(2, 20);
		printf("%c", 188);
		gotoXY(2, 24);
		printf("%c", 187);
		gotoXY(18, 20);
		printf("%c", 200);
		gotoXY(18, 24);
		printf("%c", 201);
		gotoXY(5, 22); //>>
		printf("%c", 175);
		gotoXY(15, 22);//<<
		printf("%c", 174);
		break;
	case 6:

		gotoXY(23, 20);
		printf("%c", 188);
		gotoXY(23, 24);
		printf("%c", 187);
		gotoXY(39, 20);
		printf("%c", 200);
		gotoXY(39, 24);
		printf("%c", 201);
		gotoXY(26, 22); //>>
		printf("%c", 175);
		gotoXY(36, 22);//<<
		printf("%c", 174);
		break;
	}

}
void del(int choice) {
	int x, y;
	switch (choice) {
	case 1:
		x = 2; y = 2;

		veNgang(x, y, 17, 8, 0);
		veNgang(x, y + 4, 17, 8, 0);
		veNgang(x, y + 2, 5, 8, 0);
		veNgang(x + 11, y + 2, 3, 8, 0);
		break;
	case 2:
		x = 23; y = 2;

		veNgang(x, y, 17, 8, 0);
		veNgang(x, y + 4, 17, 8, 0);
		veNgang(x, y + 2, 5, 8, 0);
		veNgang(x + 11, y + 2, 3, 8, 0);
		break;
	case 3:

		x = 2; y = 11;

		veNgang(x, y, 17, 8, 0);
		veNgang(x, y + 4, 17, 8, 0);
		veNgang(x, y + 2, 5, 8, 0);
		veNgang(x + 11, y + 2, 3, 8, 0);
		break;
	case 4:
		x = 23; y = 11;

		veNgang(x, y, 17, 8, 0);
		veNgang(x, y + 4, 17, 8, 0);
		veNgang(x, y + 2, 5, 8, 0);
		veNgang(x + 14, y + 2, 3, 8, 0);
		break;
	case 5:
		x = 2; y = 20;

		veNgang(x, y, 17, 8, 0);
		veNgang(x, y + 4, 17, 8, 0);
		veNgang(x, y + 2, 5, 8, 0);
		veNgang(x + 13, y + 2, 3, 8, 0);
		break;
	case 6:
		x = 23; y = 20;

		veNgang(x, y, 17, 8, 0);
		veNgang(x, y + 4, 17, 8, 0);
		veNgang(x, y + 2, 5, 8, 0);
		veNgang(x + 12, y + 2, 5, 8, 0);
		break;

	}
}
int lapLanh() {
	srand(time(NULL));
	return (rand() % 7) + 1;
}
void drawGate()
{
	Gate = new point;
	Gate->y = 0;
	switch (level) {
	case 1:
		Gate->x = rand() % 87 + 2; //2-88
		break;
	case 2:
		Gate->x = rand() % 66 + 12; //12-77
		break;
	case 3:
		Gate->x = rand() % 11 + 67; //67-77
		break;
	}
	gotoXY(Gate->x, Gate->y);
	SetColor(4);
	_setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L"\u2550";
	gotoXY(Gate->x - 1, Gate->y);
	wcout << L"\u2554";
	gotoXY(Gate->x - 1, Gate->y + 1);
	wcout << L"\u255D";
	gotoXY(Gate->x + 1, Gate->y);
	wcout << L"\u2557";
	gotoXY(Gate->x + 1, Gate->y + 1);
	wcout << L"\u255A";
	_setmode(_fileno(stdout), _O_TEXT);
	SetColor(7);
}
bool checkGate()
{
	if (foodEaten != 0 && foodEaten >= 4)
	{
		Food.x = -1; Food.y = -1;
		return true;
	}
	return false;
}
bool ranChuiVaoCong(point *&toaDoSnake)
{
	if (Gate == NULL)
		return false;
	else if (toaDoSnake[0].x == Gate->x && toaDoSnake[0].y == Gate->y)
	{
		return true;
	}
	return false;
}
void xuLyQuaCong(point *&toaDoSnake)
{
	del1(toaDoSnake, sl - 1);
	y--;
	if (sl == 0) {
		countAdd = 0;
		x = 1, y = 13;
		speed++;
		sl = length;
		level++;
		foodEaten = 0;
		if (level <= 3) {
			Gate = NULL;
			delete[] toaDoSnake;
			NormalMode();
		}
		else
		{
			Gate = NULL;
			system("cls");
			chuanCongra();
			exit(0);
		}
	}
}
void Start(int mode)
{
	if (mode == 1) {
		system("cls");
		userName = userNameInput();
		system("cls");
		demGiay();
		system("cls");
		
		NormalMode();
	}
	else if (mode == 2) {
		system("cls");
		userName = userNameInput();
		system("cls");
		demGiay();
		system("cls");
		InfinityMode();
	}
}
void modeSauStart() {
	system("cls");
	int n = 0;
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH + 2; j++) {
			SetColor1(0, 0);
			cout << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < 120; i++) {
		gotoXY(i, 0);
		SetColor1(0, 0);
		cout << " ";
	}
	ranSauStart(1, 2, 3);
}
void ranSauStart(int choice, int maunen, int mauchu) {
	char kitu = '0';
	int choice5 = 1, color1 = 15, color2 = 15;

	//O mode snake
	nut(55, 0, 4, 0);
	for (int i = 0; i < 5; i++) {
		veNgang(56, 1 + i, 17, 8, 0);
	}
	gotoXY(59, 3);
	SetColor1(0, 4);
	cout << "SNAKE MODE";
	do {
		Sleep(10);
		//choice1
		if (choice5 == 1) {
			color2 = 6;
		}
		else {
			color2 = 15;
		}
		SetColor1(0, color1);
		gotoXY(80, 3);
		cout << "---_ ......._-_--.";
		gotoXY(79, 4);
		cout << "(|\\ /      / /| \\  \\";
		gotoXY(79, 5);
		cout << "  /  /     .'  -=-'   `.";
		gotoXY(78, 6);
		cout << "  /  /    .'             )";
		gotoXY(77, 7);
		cout << "_/  /   .'        _.)   /";
		gotoXY(76, 8);
		cout << "/ o   o        _.-' /  .'";
		gotoXY(77, 9);
		cout << "\\          _.-'    / .'*|";
		gotoXY(78, 10);
		cout << " \\______.-'//    .'.' \*|";
		gotoXY(79, 11);
		cout << "\\|  \\ | //   .'.' _ |*|";
		gotoXY(80, 12);
		cout << "`   \|//  .'.'_ _ _|*|";
		gotoXY(81, 13);
		cout << ".  .// .'.' | _ _ \\*|";
		gotoXY(82, 14);
		cout << " \`-|\\_/ /    \\ _ _ \\*\\";
		gotoXY(83, 15);
		cout << " `/'\\__/      \ _ _ \\*\\";
		gotoXY(82, 16);
		cout << " /^|            \\ _ _ \\*";
		gotoXY(81, 17);
		cout << "'  `             \\ _ _ \\";
		//choice2
		if (choice5 == 2) {
			color1 = 4;
		}
		else {
			color1 = 15;
		}
		SetColor1(0, color2);
		gotoXY(25, 3);
		cout << ".-'`     '.";
		gotoXY(24, 4);
		cout << "__/  __       \\";
		gotoXY(22, 5);
		cout << "/  \ /  \       |    ___";
		gotoXY(21, 6);
		cout << "| /`\\| /`\\|      | .-'  /^\\/^\\";
		gotoXY(21, 7);
		cout << "| \(/|  \(/|        |/     |) |)|";
		gotoXY(20, 8);
		cout << ".-\\__/ \\__/       |      \\_/\\_/__..._";
		gotoXY(12, 9);
		cout << "_...---'-.                /   _              '.";
		gotoXY(11, 10);
		cout << "/,      ,             \\   '|  `\\                \\";
		gotoXY(10, 11);
		cout << "| ))     ))           /`|   \    `.       /)  /) |";
		gotoXY(10, 12);
		cout << "| `      `          .'       |     `-._         /";
		gotoXY(10, 13);
		cout << "\                 .'         |     ,_  `--....-'";
		gotoXY(11, 14);
		cout << "`.           __.' ,         |     / /`'''`";
		gotoXY(12, 15);
		cout << "`'-.____.-' /  /,         |    / /";
		gotoXY(13, 16);
		cout << "`. `-.-` .'  \        /   / |";
		gotoXY(14, 17);
		cout << "`-.__.'|    \\      |   |  |-.";
		gotoXY(17, 17);
		cout << "_.._|     |     /   |  |  `'.";

		gotoXY(11, 18);
		cout << ".'`         /      /     /  |   |        '.";
		gotoXY(9, 19);
		cout << "/`           /      /     |   /   |\\         \\";
		gotoXY(8, 20);
		cout << "/            |      |      |   |   /\          |";
		gotoXY(7, 21);
		cout << "||            |      /      |   /     '.        |";
		gotoXY(7, 22);
		cout << "|\\            \\      |      /   |       '.      /";
		gotoXY(7, 23);
		cout << "\\ `.           '.    /      |    \\        '---'/";
		gotoXY(8, 24);
		cout << " \\  '.           `-./        \\    '.          /";
		gotoXY(9, 25);
		cout << "'.  `'.            `-._     '.__  '-._____.'--'''''--.";
		gotoXY(10, 26);
		cout << "'-.  `'--._          `.__     `';----`              \\";
		gotoXY(12, 27);
		cout << "`-.     `-.          `. '```                     ;";
		gotoXY(14, 28);
		cout << "`'-..,_ `-.         `'-.                     /";
		gotoXY(21, 29);
		cout << "'.  '.           '.                 .'";
		//normal
		if (choice5 == 1) {
			nut(65, 19, 3, 0);
			for (int i = 0; i < 5; i++) {
				veNgang(66, 20 + i, 17, 6, 0);
			}
			SetColor1(0, 5);
			gotoXY(71, 22);
			cout << "NORMAL";
		}
		else {
			nut(65, 19, 4, 0);
			for (int i = 0; i < 5; i++) {
				veNgang(66, 20 + i, 17, 8, 0);
			}
			SetColor1(8, 15);
			gotoXY(71, 22);
			cout << "NORMAL";
		}
		//infinity
		if (choice5 == 2) {
			nut(90, 19, 3, 0);
			for (int i = 0; i < 5; i++) {
				veNgang(91, 20 + i, 17, 6, 0);
			}
			SetColor1(0, 5);
			gotoXY(95, 22);
			cout << "INFINITY";
		}
		else {
			nut(90, 19, 4, 0);
			for (int i = 0; i < 5; i++) {
				veNgang(91, 20 + i, 17, 8, 0);
			}
			SetColor1(8, 15);
			gotoXY(95, 22);
			cout << "INFINITY";
		}
		if (_kbhit())
		{
			//Nhan vao ki tu cua ban phim
			kitu = _getch();
			if ((kitu == 'd' || kitu == 'D') && choice5 == 1) {
				choice5 = 2;
				continue;
			}
			else if ((kitu == 'a' || kitu == 'A') && choice5 == 2) {
				choice5 = 1;
				continue;
			}
			else if ((kitu == '\r') && choice5 == 2) {
				
				Start(2);
				break;
				//Ban dau ran di chuyen qua phai
			}
			else if ((kitu == '\r') && choice5 == 1) {
				Start(1);
				break;
				//Ban dau ran di chuyen qua phai
			}
			else if (kitu == 27) {
				CloseBackgroundMusic();
				drawMenu();
			}
		}
	} while (kitu != 27 );
}

void setting() {
	system("cls");
	char x = '0';
	int choice = 1;

	int xx = 52;

	for (int i = 0; i < HEIGHT + 1; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			SetColor1(8, 0);
			cout << " ";
		}
		cout << "\n";
	}
	veDoc(0, 0, 29, 4, 0);
	veNgang(0, 0, 119, 4, 0);
	veNgang(0, 29, 119, 4, 0);
	veDoc(15, 0, 29, 4, 0);
	veDoc(119, 0, 30, 4, 0);

	//nut giua
	veNgang(0, 11, 15, 4, 0);
	veNgang(0, 17, 15, 4, 0);
	gotoXY(2, 14);
	SetColor1(0, 15);
	cout << "Snake'sColor";

	//nut tren
	veNgang(0, 3, 15, 3, 0);
	veNgang(0, 9, 15, 3, 0);
	veDoc(0, 3, 7, 3, 0);
	veDoc(15, 3, 7, 3, 0);
	SetColor1(0, 15);
	gotoXY(1, 4);
	printf("%c", 188);
	gotoXY(1, 8);
	printf("%c", 187);
	gotoXY(14, 4);
	printf("%c", 200);
	gotoXY(14, 8);
	printf("%c", 201);
	gotoXY(5, 6);
	cout << "Sound";
	//nut duoi
	veNgang(0, 19, 15, 4, 0);
	veNgang(0, 25, 15, 4, 0);
	gotoXY(5, 22);
	SetColor1(0, 15);
	cout << "???";
	//speaker
	SetColor1(14, 0);
	gotoXY(xx, 5);
	cout << "                     ,   |      ";
	gotoXY(xx, 6);
	cout << "  _,,._              |  0'      ";
	gotoXY(xx, 7);
	cout << ",'     `.__,--.     0'          ";
	gotoXY(xx, 8);
	cout << "/   .--.        |           ,,, ";
	gotoXY(xx, 9);
	cout << "| [=========|==|==|=|==|=|==___]";
	gotoXY(xx, 10);
	cout << "\\   \"--\"  __    |           ''' ";
	gotoXY(xx, 11);
	cout << "`._   _,'  `--'                 ";
	gotoXY(xx, 12);
	cout << "   \"\"'     ,   ,0     ,         ";
	gotoXY(xx, 13);
	cout << "           |)  |)   ,'|         ";
	gotoXY(xx, 14);
	cout << " ____     0'   '   | 0'         ";
	gotoXY(xx, 15);
	cout << " |  |             0'            ";
	gotoXY(xx, 16);
	cout << "0' 0'                           ";
	chuO(xx + 7, 18, 4, 0);
	chuN(xx + 15, 18, 4, 0);

	do {
		if (_kbhit())
		{
			x = _getch();
			if (choice == 1 && (x == 's' || x == 'S')) {
				snakeColor=rancolor = 1;
				choice = 2;
				//xoa 1
				veNgang(0, 3, 15, 4, 0);
				veNgang(0, 9, 15, 4, 0);
				veDoc(0, 3, 7, 4, 0);
				veDoc(15, 3, 7, 4, 0);
				SetColor1(8, 0);
				gotoXY(1, 4);
				printf(" ");
				gotoXY(1, 8);
				printf(" ");
				gotoXY(14, 4);
				printf(" ");
				gotoXY(14, 8);
				printf(" ");
				SetColor1(8, 15);
				gotoXY(5, 6);
				cout << "Sound";
				//tao 2
				veNgang(0, 11, 15, 3, 0);
				veNgang(0, 17, 15, 3, 0);
				veDoc(0, 11, 7, 3, 0);
				veDoc(15, 11, 7, 3, 0);
				SetColor1(0, 15);
				gotoXY(1, 12);
				printf("%c", 188);
				gotoXY(1, 16);
				printf("%c", 187);
				gotoXY(14, 12);
				printf("%c", 200);
				gotoXY(14, 16);
				printf("%c", 201);
				gotoXY(2, 14);
				cout << "Snake'sColor";
				SetColor1(8, 0);
				for (int i = 5; i <= 28; i++) {
					veNgang(xx - 2, i, 38, 8, 0);
				}
				ranMenu(2);
				//bo mau 1
				if (bomau == 1) {
					veNgang(80, 4, 5, 14, 0);
					veDoc(80, 4, 5, 14, 0);
					veDoc(85, 4, 5, 14, 0);
					veNgang(80, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(81, i, 4, 10, 0);
					}
				}
				else {
					veNgang(80, 4, 5, 0, 0);
					veDoc(80, 4, 5, 0, 0);
					veDoc(85, 4, 5, 0, 0);
					veNgang(80, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(81, i, 4, 10, 0);
					}
				}
				//bo mau 2
				if (bomau == 2) {
					veNgang(88, 4, 5, 14, 0);
					veDoc(88, 4, 5, 14, 0);
					veDoc(93, 4, 5, 14, 0);
					veNgang(88, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(89, i, 4, 11, 0);
					}
				}
				else {
					veNgang(88, 4, 5, 0, 0);
					veDoc(88, 4, 5, 0, 0);
					veDoc(93, 4, 5, 0, 0);
					veNgang(88, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(89, i, 4, 11, 0);
					}
				}
				//bo mau 3
				if (bomau == 3) {
					veNgang(96, 4, 5, 14, 0);
					veDoc(96, 4, 5, 14, 0);
					veDoc(101, 4, 5, 14, 0);
					veNgang(96, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(97, i, 4, 12, 0);
					}
				}
				else {
					veNgang(96, 4, 5, 0, 0);
					veDoc(96, 4, 5, 0, 0);
					veDoc(101, 4, 5, 0, 0);
					veNgang(96, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(97, i, 4, 12, 0);
					}
				}

			}
			else if (choice == 2 && (x == 'D' || x == 'd') && bomau == 1) {
				rancolor = 2;
				snakeColor = rancolor;
				bomau = 2;
				ranMenu(2);
				//bo mau 1
				if (bomau == 1) {
					veNgang(80, 4, 5, 14, 0);
					veDoc(80, 4, 5, 14, 0);
					veDoc(85, 4, 5, 14, 0);
					veNgang(80, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(81, i, 4, 10, 0);
					}
				}
				else {
					veNgang(80, 4, 5, 0, 0);
					veDoc(80, 4, 5, 0, 0);
					veDoc(85, 4, 5, 0, 0);
					veNgang(80, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(81, i, 4, 10, 0);
					}
				}
				//bo mau 2
				if (bomau == 2) {
					veNgang(88, 4, 5, 14, 0);
					veDoc(88, 4, 5, 14, 0);
					veDoc(93, 4, 5, 14, 0);
					veNgang(88, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(89, i, 4, 11, 0);
					}
				}
				else {
					veNgang(88, 4, 5, 0, 0);
					veDoc(88, 4, 5, 0, 0);
					veDoc(93, 4, 5, 0, 0);
					veNgang(88, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(89, i, 4, 11, 0);
					}
				}
				//bo mau 3
				if (bomau == 3) {
					veNgang(96, 4, 5, 14, 0);
					veDoc(96, 4, 5, 14, 0);
					veDoc(101, 4, 5, 14, 0);
					veNgang(96, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(97, i, 4, 12, 0);
					}
				}
				else {
					veNgang(96, 4, 5, 0, 0);
					veDoc(96, 4, 5, 0, 0);
					veDoc(101, 4, 5, 0, 0);
					veNgang(96, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(97, i, 4, 12, 0);
					}
				}
			}
			else if (choice == 2 && (x == 'a' || x == 'A') && bomau == 1) {
				rancolor = 3;
				snakeColor = rancolor;
				bomau = 3;
				ranMenu(2);
				//bo mau 1
				if (bomau == 1) {
					veNgang(80, 4, 5, 14, 0);
					veDoc(80, 4, 5, 14, 0);
					veDoc(85, 4, 5, 14, 0);
					veNgang(80, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(81, i, 4, 10, 0);
					}
				}
				else {
					veNgang(80, 4, 5, 0, 0);
					veDoc(80, 4, 5, 0, 0);
					veDoc(85, 4, 5, 0, 0);
					veNgang(80, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(81, i, 4, 10, 0);
					}
				}
				//bo mau 2
				if (bomau == 2) {
					veNgang(88, 4, 5, 14, 0);
					veDoc(88, 4, 5, 14, 0);
					veDoc(93, 4, 5, 14, 0);
					veNgang(88, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(89, i, 4, 11, 0);
					}
				}
				else {
					veNgang(88, 4, 5, 0, 0);
					veDoc(88, 4, 5, 0, 0);
					veDoc(93, 4, 5, 0, 0);
					veNgang(88, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(89, i, 4, 11, 0);
					}
				}
				//bo mau 3
				if (bomau == 3) {
					veNgang(96, 4, 5, 14, 0);
					veDoc(96, 4, 5, 14, 0);
					veDoc(101, 4, 5, 14, 0);
					veNgang(96, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(97, i, 4, 12, 0);
					}
				}
				else {
					veNgang(96, 4, 5, 0, 0);
					veDoc(96, 4, 5, 0, 0);
					veDoc(101, 4, 5, 0, 0);
					veNgang(96, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(97, i, 4, 12, 0);
					}
				}
				if (isPlayingMusic) {
					CloseBackgroundMusic();
				}
				else
					PlayBackgroundMusic("BACKGROUND.wav");
			}
			else if (choice == 2 && (x == 'd' || x == 'D') && bomau == 2) {
				rancolor = 3;
				snakeColor = rancolor;
				bomau = 3;
				ranMenu(2);
				//bo mau 1
				if (bomau == 1) {
					veNgang(80, 4, 5, 14, 0);
					veDoc(80, 4, 5, 14, 0);
					veDoc(85, 4, 5, 14, 0);
					veNgang(80, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(81, i, 4, 10, 0);
					}
				}
				else {
					veNgang(80, 4, 5, 0, 0);
					veDoc(80, 4, 5, 0, 0);
					veDoc(85, 4, 5, 0, 0);
					veNgang(80, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(81, i, 4, 10, 0);
					}
				}
				//bo mau 2
				if (bomau == 2) {
					veNgang(88, 4, 5, 14, 0);
					veDoc(88, 4, 5, 14, 0);
					veDoc(93, 4, 5, 14, 0);
					veNgang(88, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(89, i, 4, 11, 0);
					}
				}
				else {
					veNgang(88, 4, 5, 0, 0);
					veDoc(88, 4, 5, 0, 0);
					veDoc(93, 4, 5, 0, 0);
					veNgang(88, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(89, i, 4, 11, 0);
					}
				}
				//bo mau 3
				if (bomau == 3) {
					veNgang(96, 4, 5, 14, 0);
					veDoc(96, 4, 5, 14, 0);
					veDoc(101, 4, 5, 14, 0);
					veNgang(96, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(97, i, 4, 12, 0);
					}
				}
				else {
					veNgang(96, 4, 5, 0, 0);
					veDoc(96, 4, 5, 0, 0);
					veDoc(101, 4, 5, 0, 0);
					veNgang(96, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(97, i, 4, 12, 0);
					}
				}
			}
			else if (choice == 2 && (x == 'a' || x == 'A') && bomau == 2) {
				rancolor = 1;
				snakeColor = rancolor;
				bomau = 1;
				ranMenu(2);
				//bo mau 1
				if (bomau == 1) {
					veNgang(80, 4, 5, 14, 0);
					veDoc(80, 4, 5, 14, 0);
					veDoc(85, 4, 5, 14, 0);
					veNgang(80, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(81, i, 4, 10, 0);
					}
				}
				else {
					veNgang(80, 4, 5, 0, 0);
					veDoc(80, 4, 5, 0, 0);
					veDoc(85, 4, 5, 0, 0);
					veNgang(80, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(81, i, 4, 10, 0);
					}
				}
				//bo mau 2
				if (bomau == 2) {
					veNgang(88, 4, 5, 14, 0);
					veDoc(88, 4, 5, 14, 0);
					veDoc(93, 4, 5, 14, 0);
					veNgang(88, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(89, i, 4, 11, 0);
					}
				}
				else {
					veNgang(88, 4, 5, 0, 0);
					veDoc(88, 4, 5, 0, 0);
					veDoc(93, 4, 5, 0, 0);
					veNgang(88, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(89, i, 4, 11, 0);
					}
				}
				//bo mau 3
				if (bomau == 3) {
					veNgang(96, 4, 5, 14, 0);
					veDoc(96, 4, 5, 14, 0);
					veDoc(101, 4, 5, 14, 0);
					veNgang(96, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(97, i, 4, 12, 0);
					}
				}
				else {
					veNgang(96, 4, 5, 0, 0);
					veDoc(96, 4, 5, 0, 0);
					veDoc(101, 4, 5, 0, 0);
					veNgang(96, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(97, i, 4, 12, 0);
					}
				}
			}
			else if (choice == 2 && (x == 'a' || x == 'A') && bomau == 3) {
				rancolor = 2;
				snakeColor = rancolor;
				bomau = 2;
				ranMenu(2);
				//bo mau 1
				if (bomau == 1) {
					veNgang(80, 4, 5, 14, 0);
					veDoc(80, 4, 5, 14, 0);
					veDoc(85, 4, 5, 14, 0);
					veNgang(80, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(81, i, 4, 10, 0);
					}
				}
				else {
					veNgang(80, 4, 5, 0, 0);
					veDoc(80, 4, 5, 0, 0);
					veDoc(85, 4, 5, 0, 0);
					veNgang(80, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(81, i, 4, 10, 0);
					}
				}
				//bo mau 2
				if (bomau == 2) {
					veNgang(88, 4, 5, 14, 0);
					veDoc(88, 4, 5, 14, 0);
					veDoc(93, 4, 5, 14, 0);
					veNgang(88, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(89, i, 4, 11, 0);
					}
				}
				else {
					veNgang(88, 4, 5, 0, 0);
					veDoc(88, 4, 5, 0, 0);
					veDoc(93, 4, 5, 0, 0);
					veNgang(88, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(89, i, 4, 11, 0);
					}
				}
				//bo mau 3
				if (bomau == 3) {
					veNgang(96, 4, 5, 14, 0);
					veDoc(96, 4, 5, 14, 0);
					veDoc(101, 4, 5, 14, 0);
					veNgang(96, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(97, i, 4, 12, 0);
					}
				}
				else {
					veNgang(96, 4, 5, 0, 0);
					veDoc(96, 4, 5, 0, 0);
					veDoc(101, 4, 5, 0, 0);
					veNgang(96, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(97, i, 4, 12, 0);
					}
				}
			}
			else if (choice == 2 && (x == 'd' || x == 'D') && bomau == 3) {
				rancolor = 1;
				snakeColor = rancolor;
				bomau = 1;
				ranMenu(2);
				//bo mau 1
				if (bomau == 1) {
					veNgang(80, 4, 5, 14, 0);
					veDoc(80, 4, 5, 14, 0);
					veDoc(85, 4, 5, 14, 0);
					veNgang(80, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(81, i, 4, 10, 0);
					}
				}
				else {
					veNgang(80, 4, 5, 0, 0);
					veDoc(80, 4, 5, 0, 0);
					veDoc(85, 4, 5, 0, 0);
					veNgang(80, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(81, i, 4, 10, 0);
					}
				}
				//bo mau 2
				if (bomau == 2) {
					veNgang(88, 4, 5, 14, 0);
					veDoc(88, 4, 5, 14, 0);
					veDoc(93, 4, 5, 14, 0);
					veNgang(88, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(89, i, 4, 11, 0);
					}
				}
				else {
					veNgang(88, 4, 5, 0, 0);
					veDoc(88, 4, 5, 0, 0);
					veDoc(93, 4, 5, 0, 0);
					veNgang(88, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(89, i, 4, 11, 0);
					}
				}
				//bo mau 3
				if (bomau == 3) {
					veNgang(96, 4, 5, 14, 0);
					veDoc(96, 4, 5, 14, 0);
					veDoc(101, 4, 5, 14, 0);
					veNgang(96, 9, 6, 14, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(97, i, 4, 12, 0);
					}
				}
				else {
					veNgang(96, 4, 5, 0, 0);
					veDoc(96, 4, 5, 0, 0);
					veDoc(101, 4, 5, 0, 0);
					veNgang(96, 9, 6, 0, 0);
					for (int i = 5; i <= 8; i++) {
						veNgang(97, i, 4, 12, 0);
					}
				}
			}
			else if (choice == 1 && (x == 'D' || x == 'd' || x == 'a' || x == 'A') && mute == 0) {
				mute = 1;
				if (isPlayingMusic) {
					CloseBackgroundMusic();
				}
				else {
					PlayBackgroundMusic("BACKGROUND.wav");
				}
				SetColor1(0, 14);
				gotoXY(xx, 6);
				cout << "  _,,._                         ";
				gotoXY(xx, 7);
				cout << ",'     `.__,--.                 ";
				gotoXY(xx, 8);
				cout << "/   .--.        |           ,,, ";
				gotoXY(xx, 9);
				cout << "| [=========|==|==|=|==|=|==___]";
				gotoXY(xx, 10);
				cout << "\\   \"--\"  __    |           ''' ";
				gotoXY(xx, 11);
				cout << "`._   _,'  `--'                 ";
				gotoXY(xx, 12);
				cout << "         	                    ";
				veNgang(xx, 5, 32, 0, 0);
				veNgang(xx, 6, 32, 0, 0);
				for (int i = 12; i <= 16; i++) {
					veNgang(xx, i, 32, 0, 0);
				}
				chuO(xx + 7, 18, 4, 0);
				chuN(xx + 15, 18, 8, 0);
				chuF(xx + 15, 18, 4, 0);
				chuF(xx + 22, 18, 4, 0);
				veCheoXuongPhaiQuaTrai(xx, 18, 2, 4, 0);
				veCheoXuong(xx - 2, 20, 2, 4, 0);
				veCheoXuong(xx + 31, 18, 2, 4, 0);
				veCheoXuongPhaiQuaTrai(xx + 33, 20, 2, 4, 0);
			}
			else if (choice == 1 && (x == 'a' || x == 'A' || x == 'D' || x == 'd') && mute == 1) {
				//speaker
				mute = 0;
				if (isPlayingMusic) {
					CloseBackgroundMusic();
				}
				else
					PlayBackgroundMusic("BACKGROUND.wav");
				
				SetColor1(14, 0);
				gotoXY(xx, 5);
				cout << "                     ,   |      ";
				gotoXY(xx, 6);
				cout << "  _,,._              |  0'      ";
				gotoXY(xx, 7);
				cout << ",'     `.__,--.     0'          ";
				gotoXY(xx, 8);
				cout << "/   .--.        |           ,,, ";
				gotoXY(xx, 9);
				cout << "| [=========|==|==|=|==|=|==___]";
				gotoXY(xx, 10);
				cout << "\\   \"--\"  __    |           ''' ";
				gotoXY(xx, 11);
				cout << "`._   _,'  `--'                 ";
				gotoXY(xx, 12);
				cout << "   \"\"'     ,   ,0     ,         ";
				gotoXY(xx, 13);
				cout << "           |)  |)   ,'|         ";
				gotoXY(xx, 14);
				cout << " ____     0'   '   | 0'         ";
				gotoXY(xx, 15);
				cout << " |  |             0'            ";
				gotoXY(xx, 16);
				cout << "0' 0'                           ";
				chuO(xx + 7, 18, 4, 0);

				chuF(xx + 15, 18, 8, 0);
				chuF(xx + 22, 18, 8, 0);
				chuN(xx + 15, 18, 4, 0);
			}
			else if (choice == 2 && (x == 's' || x == 'S')) {
				choice = 3;
				ranMenu(0);

				veNgang(88, 4, 5, 8, 0);
				veDoc(88, 4, 5, 8, 0);
				veDoc(93, 4, 5, 8, 0);
				veNgang(88, 9, 6, 8, 0);
				for (int i = 5; i <= 8; i++) {
					veNgang(89, i, 4, 8, 0);
				}

				veNgang(96, 4, 5, 8, 0);
				veDoc(96, 4, 5, 8, 0);
				veDoc(101, 4, 5, 8, 0);
				veNgang(96, 9, 6, 8, 0);
				for (int i = 5; i <= 8; i++) {
					veNgang(97, i, 4, 8, 0);
				}
				veNgang(80, 4, 5, 8, 0);
				veDoc(80, 4, 5, 8, 0);
				veDoc(85, 4, 5, 8, 0);
				veNgang(80, 9, 6, 8, 0);
				for (int i = 5; i <= 8; i++) {
					veNgang(81, i, 4, 8, 0);
				}



				//xoa 2
				veNgang(0, 11, 15, 4, 0);
				veNgang(0, 17, 15, 4, 0);
				veDoc(0, 11, 7, 4, 0);
				veDoc(15, 11, 7, 4, 0);
				SetColor1(8, 15);
				gotoXY(1, 12);
				printf(" ");
				gotoXY(1, 16);
				printf(" ");
				gotoXY(14, 12);
				printf(" ");
				gotoXY(14, 16);
				printf(" ");
				gotoXY(2, 14);
				cout << "Snake'sColor";
				//tao 3
				veNgang(0, 19, 15, 3, 0);
				veNgang(0, 25, 15, 3, 0);
				veDoc(0, 19, 7, 3, 0);
				veDoc(15, 19, 7, 3, 0);
				SetColor1(0, 15);
				gotoXY(1, 20);
				printf("%c", 188);
				gotoXY(1, 24);
				printf("%c", 187);
				gotoXY(14, 20);
				printf("%c", 200);
				gotoXY(14, 24);
				printf("%c", 201);
				gotoXY(5, 22);
				cout << "???";
			}
			else if (choice == 2 && (x == 'w' || x == 'W') && mute == 0) {
				choice = 1;
				ranMenu(0);
				veNgang(88, 4, 5, 8, 0);
				veDoc(88, 4, 5, 8, 0);
				veDoc(93, 4, 5, 8, 0);
				veNgang(88, 9, 6, 8, 0);
				for (int i = 5; i <= 8; i++) {
					veNgang(89, i, 4, 8, 0);
				}

				veNgang(96, 4, 5, 8, 0);
				veDoc(96, 4, 5, 8, 0);
				veDoc(101, 4, 5, 8, 0);
				veNgang(96, 9, 6, 8, 0);
				for (int i = 5; i <= 8; i++) {
					veNgang(97, i, 4, 8, 0);
				}
				veNgang(80, 4, 5, 8, 0);
				veDoc(80, 4, 5, 8, 0);
				veDoc(85, 4, 5, 8, 0);
				veNgang(80, 9, 6, 8, 0);
				for (int i = 5; i <= 8; i++) {
					veNgang(81, i, 4, 8, 0);
				}
				//tao 1
				veNgang(0, 3, 15, 3, 0);
				veNgang(0, 9, 15, 3, 0);
				veDoc(0, 3, 7, 3, 0);
				veDoc(15, 3, 7, 3, 0);
				SetColor1(0, 15);
				gotoXY(1, 4);
				printf("%c", 188);
				gotoXY(1, 8);
				printf("%c", 187);
				gotoXY(14, 4);
				printf("%c", 200);
				gotoXY(14, 8);
				printf("%c", 201);
				gotoXY(5, 6);
				cout << "Sound";
				//xoa 2
				veNgang(0, 11, 15, 4, 0);
				veNgang(0, 17, 15, 4, 0);
				veDoc(0, 11, 7, 4, 0);
				veDoc(15, 11, 7, 4, 0);
				SetColor1(8, 15);
				gotoXY(1, 12);
				printf(" ");
				gotoXY(1, 16);
				printf(" ");
				gotoXY(14, 12);
				printf(" ");
				gotoXY(14, 16);
				printf(" ");
				gotoXY(2, 14);
				cout << "Snake'sColor";

				SetColor1(14, 0);
				gotoXY(xx, 5);
				cout << "                     ,   |      ";
				gotoXY(xx, 6);
				cout << "  _,,._              |  0'      ";
				gotoXY(xx, 7);
				cout << ",'     `.__,--.     0'          ";
				gotoXY(xx, 8);
				cout << "/   .--.        |           ,,, ";
				gotoXY(xx, 9);
				cout << "| [=========|==|==|=|==|=|==___]";
				gotoXY(xx, 10);
				cout << "\\   \"--\"  __    |           ''' ";
				gotoXY(xx, 11);
				cout << "`._   _,'  `--'                 ";
				gotoXY(xx, 12);
				cout << "   \"\"'     ,   ,0     ,         ";
				gotoXY(xx, 13);
				cout << "           |)  |)   ,'|         ";
				gotoXY(xx, 14);
				cout << " ____     0'   '   | 0'         ";
				gotoXY(xx, 15);
				cout << " |  |             0'            ";
				gotoXY(xx, 16);
				cout << "0' 0'                           ";
				chuO(xx + 7, 18, 4, 0);
				chuN(xx + 15, 18, 4, 0);
				veCheoXuongPhaiQuaTrai(xx, 18, 2, 4, 0);
				veCheoXuong(xx - 2, 20, 2, 4, 0);
				veCheoXuong(xx + 31, 18, 2, 4, 0);
				veCheoXuongPhaiQuaTrai(xx + 33, 20, 2, 4, 0);
			}
			else if (choice == 2 && (x == 'w' || x == 'W') && mute == 1) {
				ranMenu(0);
				veNgang(88, 4, 5, 8, 0);
				veDoc(88, 4, 5, 8, 0);
				veDoc(93, 4, 5, 8, 0);
				veNgang(88, 9, 6, 8, 0);
				for (int i = 5; i <= 8; i++) {
					veNgang(89, i, 4, 8, 0);
				}

				veNgang(96, 4, 5, 8, 0);
				veDoc(96, 4, 5, 8, 0);
				veDoc(101, 4, 5, 8, 0);
				veNgang(96, 9, 6, 8, 0);
				for (int i = 5; i <= 8; i++) {
					veNgang(97, i, 4, 8, 0);
				}
				veNgang(80, 4, 5, 8, 0);
				veDoc(80, 4, 5, 8, 0);
				veDoc(85, 4, 5, 8, 0);
				veNgang(80, 9, 6, 8, 0);
				for (int i = 5; i <= 8; i++) {
					veNgang(81, i, 4, 8, 0);
				}
				choice = 1;
				//tao 1
				veNgang(0, 3, 15, 3, 0);
				veNgang(0, 9, 15, 3, 0);
				veDoc(0, 3, 7, 3, 0);
				veDoc(15, 3, 7, 3, 0);
				SetColor1(0, 15);
				gotoXY(1, 4);
				printf("%c", 188);
				gotoXY(1, 8);
				printf("%c", 187);
				gotoXY(14, 4);
				printf("%c", 200);
				gotoXY(14, 8);
				printf("%c", 201);
				gotoXY(5, 6);
				cout << "Sound";
				//xoa 2
				veNgang(0, 11, 15, 4, 0);
				veNgang(0, 17, 15, 4, 0);
				veDoc(0, 11, 7, 4, 0);
				veDoc(15, 11, 7, 4, 0);
				SetColor1(8, 15);
				gotoXY(1, 12);
				printf(" ");
				gotoXY(1, 16);
				printf(" ");
				gotoXY(14, 12);
				printf(" ");
				gotoXY(14, 16);
				printf(" ");
				gotoXY(2, 14);
				cout << "Snake'sColor";
				SetColor1(0, 14);
				gotoXY(xx, 6);
				cout << "  _,,._                         ";
				gotoXY(xx, 7);
				cout << ",'     `.__,--.                 ";
				gotoXY(xx, 8);
				cout << "/   .--.        |           ,,, ";
				gotoXY(xx, 9);
				cout << "| [=========|==|==|=|==|=|==___]";
				gotoXY(xx, 10);
				cout << "\\   \"--\"  __    |           ''' ";
				gotoXY(xx, 11);
				cout << "`._   _,'  `--'                 ";
				gotoXY(xx, 12);
				cout << "         	                    ";
				veNgang(xx, 5, 32, 0, 0);
				veNgang(xx, 6, 32, 0, 0);
				for (int i = 12; i <= 16; i++) {
					veNgang(xx, i, 32, 0, 0);
				}
				chuO(xx + 7, 18, 4, 0);
				chuN(xx + 15, 18, 8, 0);
				chuF(xx + 15, 18, 4, 0);
				chuF(xx + 22, 18, 4, 0);
				veCheoXuongPhaiQuaTrai(xx, 18, 2, 4, 0);
				veCheoXuong(xx - 2, 20, 2, 4, 0);
				veCheoXuong(xx + 31, 18, 2, 4, 0);
				veCheoXuongPhaiQuaTrai(xx + 33, 20, 2, 4, 0);
			}

			else if (choice == 3 && (x == 'w' || x == 'W')) {
				choice = 2;
				//xoa 3
				veNgang(0, 19, 15, 4, 0);
				veNgang(0, 25, 15, 4, 0);
				veDoc(0, 19, 7, 4, 0);
				veDoc(15, 19, 7, 4, 0);
				SetColor1(8, 15);
				gotoXY(1, 20);
				printf(" ");
				gotoXY(1, 24);
				printf(" ");
				gotoXY(14, 20);
				printf(" ");
				gotoXY(14, 24);
				printf(" ");
				gotoXY(5, 22);
				cout << "???";
				//tao 2
				veNgang(0, 11, 15, 3, 0);
				veNgang(0, 17, 15, 3, 0);
				veDoc(0, 11, 7, 3, 0);
				veDoc(15, 11, 7, 3, 0);
				SetColor1(0, 15);
				gotoXY(1, 12);
				printf("%c", 188);
				gotoXY(1, 16);
				printf("%c", 187);
				gotoXY(14, 12);
				printf("%c", 200);
				gotoXY(14, 16);
				printf("%c", 201);
				gotoXY(5, 6);
				cout << "Sound";

			}
			else if (x == 'x') {
				break;
			}
		}
	} while (x != 27);
	system("cls");
	for (int i = 0; i < HEIGHT + 1; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			SetColor1(8, 0);
			cout << " ";
		}
		cout << "\n";
	}
	chuMenuHunting(1, 1);
	chuMenuCredit(1, 1);
	ranMenu(3);
	return;
}
void nuttutorial(int x, int y, int maunen) {

	veDoc(x, y, 7, maunen, 0);
	veDoc(x + 12, y, 7, maunen, 0);
	veNgang(x, y, 12, maunen, 0);
	veNgang(x, y + 6, 13, maunen, 0);
}
void tutorial() {
	needChange = false;
	abutton = true;
	system("cls");
	char x = '0';
	int check = 0;
	int choice = 1;
	for (int i = 0; i < HEIGHT + 1; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			SetColor1(8, 0);
			cout << " ";
		}
		cout << "\n";
	}
	veDoc(0, 0, 29, 4, 0);
	veNgang(0, 0, 119, 4, 0);
	veNgang(0, 29, 119, 4, 0);
	veDoc(15, 0, 29, 4, 0);
	veDoc(119, 0, 30, 4, 0);

	//nut giua
	veNgang(0, 11, 15, 4, 0);
	veNgang(0, 17, 15, 4, 0);
	veDoc(0, 11, 7, 4, 0);
	veDoc(15, 11, 7, 4, 0);
	gotoXY(5, 14);
	SetColor1(0, 15);
	cout << "Normal";

	//nut tren
	veNgang(0, 3, 15, 13, 0);
	veNgang(0, 9, 15, 13, 0);
	veDoc(0, 3, 7, 13, 0);
	veDoc(15, 3, 7, 13, 0);
	SetColor1(0, 14);
	gotoXY(1, 4);
	printf("%c", 188);
	gotoXY(1, 8);
	printf("%c", 187);
	gotoXY(14, 4);
	printf("%c", 200);
	gotoXY(14, 8);
	printf("%c", 201);
	gotoXY(2, 6);
	cout << "How To Play";
	//nut duoi
	veNgang(0, 19, 15, 4, 0);
	veNgang(0, 25, 15, 4, 0);
	veDoc(0, 19, 7, 4, 0);
	veDoc(15, 19, 7, 4, 0);
	gotoXY(4, 22);
	SetColor1(0, 15);
	cout << "Infinity";
	thread h(AnimationButton);
	do {
		if (choice == 1) {
			//50 86

			if (abutton == false) {
				abutton = true;

			}
			std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
			if (check == 2) {
				SetColor1(8, 0);
				gotoXY(34, 1);
				cout << "                                                   ";
				gotoXY(34, 2);
				cout << "                                                                              ";
				gotoXY(34, 3);
				cout << "                                                                               ";
				gotoXY(34, 5);
				cout << "                                                                            ";
				gotoXY(34, 6);
				cout << "                                                                               ";
				gotoXY(34, 7);
				cout << "                                                          ";
				gotoXY(34, 8);
				cout << "                                                         ";
				gotoXY(64, 12);
				cout << "         ";
				gotoXY(60, 13);
				cout << "                                  ";
				gotoXY(60, 14);
				cout << "                                     ";
				gotoXY(60, 15);
				cout << "                                   ";
				gotoXY(60, 16);
				cout << "                                         ";
				gotoXY(60, 17);
				cout << "                                              ";
			}
			check = 0;

			veNgang(50, 11, 36, 0, 0);
			veNgang(50, 17, 36, 0, 0);
			veDoc(50, 11, 7, 0, 0);
			veDoc(86, 11, 7, 0, 0);
			veDoc(62, 5, 13, 0, 0);
			veDoc(74, 5, 13, 0, 0);
			veNgang(62, 5, 12, 0, 0);
			SetColor1(0, 14);
			gotoXY(56, 14);
			cout << "A";
			gotoXY(68, 14);
			cout << "S";
			gotoXY(80, 14);
			cout << "D";
			gotoXY(68, 8);
			cout << "W";
			cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
			lock.unlock(); // Mở khóa mutex
			//left down right up
		}
		if (choice == 2) {
			abutton = false;
			cv.notify_one();
			std::unique_lock<std::mutex> lock(mtx); // Khóa mutex
			if (check == 0) {
				veNgang(50, 11, 36, 8, 0);
				veNgang(50, 17, 36, 8, 0);
				veDoc(50, 11, 7, 8, 0);
				veDoc(86, 11, 7, 8, 0);
				veDoc(62, 5, 13, 8, 0);
				veDoc(74, 5, 13, 8, 0);
				veNgang(62, 5, 12, 8, 0);
				SetColor1(8, 10);
				gotoXY(56, 14);
				cout << " ";
				gotoXY(68, 14);
				cout << " ";
				gotoXY(80, 14);
				cout << " ";
				gotoXY(68, 8);
				cout << " ";
				for (int i = 1; i <= 4; i++) {
					huongMuiTen(i, 8);
				}
				check = 1;
			}
			if (check == 1) {
				SetColor1(8, 0);
				gotoXY(34, 1);
				cout << "		        __    __    __    __";
				gotoXY(34, 2);
				cout << "                     /  \\  /  \\  /  \\  /  \\";
				gotoXY(34, 3);
				cout << "____________________/  __\\/  __\\/  __\\/  __\\_____________________________";
				gotoXY(34, 5);
				cout << "___________________/  /__/  /__/  /__/  /________________________________";
				gotoXY(34, 6);
				cout << "                   | / \\   / \\   / \\   / \\  \\____";
				gotoXY(34, 7);
				cout << "                   |/   \\_/   \\_/   \\_/   \\    o ";
				gotoXY(34, 8);
				cout << "                                           \\_____/--<";

				check = 2;
			}
			SetColor1(8, 0);
			gotoXY(64, 12);
			cout << "RULES:";
			gotoXY(60, 13);
			cout << "- An du thuc an de qua man!                         ";
			gotoXY(60, 14);
			cout << "- Khong can duoi!                     ";
			gotoXY(60, 15);
			cout << "- Khong dung tuong!        ";
			gotoXY(60, 16);
			cout << "- khong dung vat can!    ";
			gotoXY(60, 17);
			cout << "- Khong di sai huong vao cong!          ";
			lock.unlock(); 

		}
		if (choice == 3) {
			SetColor1(8, 0);
			gotoXY(64, 12);
			cout << "RULES:";
			gotoXY(60, 13);
			cout << "- An cang nhieu thuc an de      ";
			gotoXY(60, 14);
			cout << "dat duoc cang nhieu diem!       ";
			gotoXY(60, 15);
			cout << "- Khong can duoi!        ";
			gotoXY(60, 16);
			cout << "- khong dung vat can!         ";
			gotoXY(60, 17);
			cout << "- Co the di xuyen tuong!           ";
		}
		if (_kbhit())
		{
			x = _getch();
			if (choice == 1 && (x == 's' || x == 'S')) {
				choice = 2;
				//xoa 1
				std::unique_lock<std::mutex> lock(mtx); // Khóa mutex


				veNgang(0, 3, 15, 4, 0);
				veNgang(0, 9, 15, 4, 0);
				veDoc(0, 3, 7, 4, 0);
				veDoc(15, 3, 7, 4, 0);
				SetColor1(8, 0);
				gotoXY(1, 4);
				printf(" ");
				gotoXY(1, 8);
				printf(" ");
				gotoXY(14, 4);
				printf(" ");
				gotoXY(14, 8);
				printf(" ");
				SetColor1(8, 15);
				gotoXY(2, 6);
				cout << "How To Play";
				//tao 2
				veNgang(0, 11, 15, 13, 0);
				veNgang(0, 17, 15, 13, 0);
				veDoc(0, 11, 7, 13, 0);
				veDoc(15, 11, 7, 13, 0);
				SetColor1(0, 14);
				gotoXY(1, 12);
				printf("%c", 188);
				gotoXY(1, 16);
				printf("%c", 187);
				gotoXY(14, 12);
				printf("%c", 200);
				gotoXY(14, 16);
				printf("%c", 201);
				gotoXY(5, 14);
				cout << "Normal";
				cv.notify_one(); // Chờ đợi cho đến khi có thông báo từ luồng khác
				lock.unlock(); // Mở khóa mutex
			}
			else if (choice == 2 && (x == 's' || x == 'S')) {
				choice = 3;
				//xoa 2
				veNgang(0, 11, 15, 4, 0);
				veNgang(0, 17, 15, 4, 0);
				veDoc(0, 11, 7, 4, 0);
				veDoc(15, 11, 7, 4, 0);
				SetColor1(8, 15);
				gotoXY(1, 12);
				printf(" ");
				gotoXY(1, 16);
				printf(" ");
				gotoXY(14, 12);
				printf(" ");
				gotoXY(14, 16);
				printf(" ");
				gotoXY(5, 14);
				cout << "Normal";
				//tao 3
				veNgang(0, 19, 15, 13, 0);
				veNgang(0, 25, 15, 13, 0);
				veDoc(0, 19, 7, 13, 0);
				veDoc(15, 19, 7, 13, 0);
				SetColor1(0, 15);
				gotoXY(1, 20);
				printf("%c", 188);
				gotoXY(1, 24);
				printf("%c", 187);
				gotoXY(14, 20);
				printf("%c", 200);
				gotoXY(14, 24);
				printf("%c", 201);
				gotoXY(4, 22);
				cout << "Infinity";
			}
			else if (choice == 2 && (x == 'w' || x == 'W')) {
				choice = 1;
				//tao 1
				veNgang(0, 3, 15, 13, 0);
				veNgang(0, 9, 15, 13, 0);
				veDoc(0, 3, 7, 13, 0);
				veDoc(15, 3, 7, 13, 0);
				SetColor1(0, 15);
				gotoXY(1, 4);
				printf("%c", 188);
				gotoXY(1, 8);
				printf("%c", 187);
				gotoXY(14, 4);
				printf("%c", 200);
				gotoXY(14, 8);
				printf("%c", 201);
				gotoXY(2, 6);
				cout << "How To Play";
				//xoa 2
				veNgang(0, 11, 15, 4, 0);
				veNgang(0, 17, 15, 4, 0);
				veDoc(0, 11, 7, 4, 0);
				veDoc(15, 11, 7, 4, 0);
				SetColor1(8, 15);
				gotoXY(1, 12);
				printf(" ");
				gotoXY(1, 16);
				printf(" ");
				gotoXY(14, 12);
				printf(" ");
				gotoXY(14, 16);
				printf(" ");
				gotoXY(5, 14);
				cout << "Normal";
			}
			else if (choice == 3 && (x == 'w' || x == 'W')) {
				choice = 2;
				//xoa 3
				veNgang(0, 19, 15, 4, 0);
				veNgang(0, 25, 15, 4, 0);
				veDoc(0, 19, 7, 4, 0);
				veDoc(15, 19, 7, 4, 0);
				SetColor1(8, 15);
				gotoXY(1, 20);
				printf(" ");
				gotoXY(1, 24);
				printf(" ");
				gotoXY(14, 20);
				printf(" ");
				gotoXY(14, 24);
				printf(" ");
				gotoXY(4, 22);
				cout << "Infinity";
				//tao 2
				veNgang(0, 11, 15, 13, 0);
				veNgang(0, 17, 15, 13, 0);
				veDoc(0, 11, 7, 13, 0);
				veDoc(15, 11, 7, 13, 0);
				SetColor1(0, 15);
				gotoXY(1, 12);
				printf("%c", 188);
				gotoXY(1, 16);
				printf("%c", 187);
				gotoXY(14, 12);
				printf("%c", 200);
				gotoXY(14, 16);
				printf("%c", 201);
				gotoXY(5, 14);
				cout << "Normal";

			}
			else if (x == 27) {
				break;
			}
		}
	} while (x != 27);
	abutton = false;
	h.join();
	cv.notify_one();
	system("cls");


	for (int i = 0; i < HEIGHT + 1; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			SetColor1(8, 0);
			cout << " ";
		}
		cout << "\n";
	}
	chuMenuHunting(1, 1);
	chuMenuCredit(1, 1);
	ranMenu(2);
	return;
}
bool compareHighScore(const highScore& a, const highScore& b) {
	return a.score > b.score;
}
vector<highScore> readHighScoresFromFile() {
	vector<highScore> highScores;
	const string& filename = "highScoresList.txt";
	ifstream file(filename);
	string line;

	while (getline(file, line)) {
		istringstream iss(line);
		highScore highScore;
		int temp;
		iss >> temp >> highScore.name >> highScore.score >> highScore.length;
		highScores.push_back(highScore);
	}
	return highScores;
}

void printHighScore() {
	ifstream file("highScoresList.txt");
	if (file.is_open()) {
		string line;
		highScore temp;
		int yLine = 15;
		int count;
		while (getline(file, line)) {
			istringstream iss(line);

			iss >> count >> temp.name >> temp.score >> length;
			gotoXY(13, yLine);
			cout << count;
			gotoXY(43, yLine);
			cout << temp.name;
			gotoXY(73, yLine);
			cout << temp.score << endl;
			gotoXY(103, yLine);
			cout << temp.score << endl;
			yLine++;
		}
		file.close();
	}
}
void printHighScoreNormal() {
	ifstream file("highScoresNormalList.txt");
	if (file.is_open()) {
		string line;
		highScoreNormal temp;
		int yLine = 15;
		int count;
		while (getline(file, line)) {
			istringstream iss(line);
			iss >> count >> temp.name >> temp.level >> temp.score >> temp.length;

			gotoXY(10, yLine);
			cout << count;
			gotoXY(13, yLine);
			cout << temp.name;
			gotoXY(43, yLine);
			cout << level;
			gotoXY(73, yLine);
			cout << temp.score << endl;
			gotoXY(103, yLine);
			cout << temp.length << endl;
			yLine++;
		}
		file.close();
	}
}
void saveHighScore(int diem, const string& name, int length)
{
	vector<highScore> highScores = readHighScoresFromFile();
	highScore temp;
	temp.score = diem;
	temp.name = name;
	temp.length = length;
	highScores.push_back(temp);
	sort(highScores.begin(), highScores.end(), compareHighScore);
	if (highScores.size() > 10)
	{
		highScores.resize(10);
	}
	const string& filename = "highScoresList.txt";
	ofstream file(filename);
	if (file.is_open())
	{
		for (size_t i = 0; i < highScores.size(); i++) {
			file << (i + 1) << '\t' << highScores[i].name << '\t' << highScores[i].score << '\t'<<highScores[i].length << '\n';
		}
		file.close();
	}
}
vector<savedData> readSavedData() {
	vector<savedData> dataList;
	const string filename = "savedGameList.txt";
	ifstream file(filename);
	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			stringstream ss(line);
			savedData data;
			int temp;
			ss >> temp >> data.name >> data.level >> data.score >> data.foodEaten >> data.length >> data.speed;
			dataList.push_back(data);
		}
		file.close();
	}
	return dataList;
}
void writeDataToFile() {
	vector<savedData> dataList;
	dataList = readSavedData();
	savedData temp;
	temp.foodEaten = foodEaten;
	temp.name = userName;
	temp.length = sl;
	temp.level = level;
	temp.score = score;
	temp.speed = speed;
	dataList.insert(dataList.begin(), temp);
	if (dataList.size() > 10) {
		dataList.pop_back();
	}
	const string filename = "savedGameList.txt";
	ofstream file(filename);
	if (file.is_open()) {
		for (int i = 0; i < dataList.size(); i++) {
			const savedData& data = dataList[i];
			file << i + 1 << " " << data.name << " " << data.level << " " << data.score << " " << data.foodEaten << " " << data.length << " " << data.speed << endl;
		}
		file.close();
	}
}
void loadGameInit(point*& toaDoSnake, int gameIndex)
{
	savedData temp;
	temp = readSavedData()[gameIndex];
	sl = temp.length;
	length = temp.length;
	score = temp.score;
	speed = temp.speed;
	userName = temp.name;
	foodEaten = temp.foodEaten;
	level = temp.level;
	toaDoSnake = new point[MAX];
	int x = 1, y = 13;
	for (int i = 0; i < sl; i++)
	{
		toaDoSnake[i].x = x;
		toaDoSnake[i].y = y;
		x--;
	}
}
bool compareNormalHighScore(const highScoreNormal& a, const highScoreNormal& b) {
	return a.score > b.score;
}
vector<highScoreNormal> readNormalHighScoresFromFile() {
	vector<highScoreNormal> highScores;
	const string& filename = "highScoresNormalList.txt";
	ifstream file(filename);
	string line;
	while (getline(file, line)) {
		istringstream iss(line);
		highScoreNormal highScore;
		int temp;
		iss >> temp >> highScore.name >> highScore.level >> highScore.score >> highScore.length;
		highScores.push_back(highScore);
	}
	return highScores;
}
void saveNormalHighScore(int diem, const string& name, int level, int length)
{
	vector<highScoreNormal> highScores = readNormalHighScoresFromFile();
	highScoreNormal temp;
	temp.score = diem;
	temp.name = name;
	temp.level = level;
	temp.length = length;
	highScores.push_back(temp);
	sort(highScores.begin(), highScores.end(), compareNormalHighScore);
	if (highScores.size() > 10)
	{
		highScores.resize(10);
	}
	const string& filename = "highScoresNormalList.txt";
	ofstream file(filename);
	if (file.is_open())
	{
		for (size_t i = 0; i < highScores.size(); i++) {
			file << (i + 1) << '\t' << highScores[i].name << '\t' << highScores[i].level << '\t' << highScores[i].score << '\t'<< highScores[i].length << '\n';
		}
		file.close();
	}
}
string userNameInput() {
	for (int i = 0; i < 120; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			gotoXY(i, j);
			SetColor1(8, 0);
			cout << " ";
		}
	}
	int choice = 1;
	char x = '0';
	int color = 14;
	veNgang(45, 8, 25, color, 0);
	veDoc(45, 8, 6, color, 0);
	veDoc(70, 8, 6, color, 0);
	veNgang(45, 14, 26, color, 0);
	for (int i = 9; i <= 12; i++) {
		veNgang(46, i, 24, 8, 0);
	}
	SetColor1(14, 0);
	gotoXY(50, 8);
	cout << "ENTER YOUR NAME";
	gotoXY(46, 12);
	SetColor1(8, 16);
	cout << "Press Enter to continue!";

	string userName;
	bool check = false;
	while (!check) {
		gotoXY(46, 10);
		SetColor1(8, 14);
		cout << "Username: ";
		userName = getLimitedInput(12);
		bool coKiTuDacBiet = false;
		for (char ch : userName) {
			if (!isalpha(ch)&&!isdigit(ch)) {
				coKiTuDacBiet = true;
				break;
			}
		}
		if (userName.length() > 15|| coKiTuDacBiet || userName.empty()) {
			gotoXY(54, 10);
			SetColor1(8, 15);
			for (int i = 0; i < 15; i++)
			{
				cout << " ";
			}
			gotoXY(46, 11);
			SetColor1(8, 14);
			cout << "Invalid!, enter again\n";
			continue;
		}
		check = true;
	}
	return userName;
}
void ResetGameData()
{
	userName = {};
	countAdd = 0;
	x = 1, y = 13;
	score = 0;
	sl = 4;
	level = 1;
	speed = 1;
	length = 4;
	foodEaten = 0;
	Gate = NULL;
	toaDoSnake = NULL;
}

void map(int level) {
	int len = 6;
	switch (level) {
	case 1:
		ve_tuong1();
		break;
	case 2:
		vetuongformat();
		//So 2
		veNgang(105, 6, 7, 12, 0);
		veDoc(111, 6, 4, 12, 0);
		veNgang(105, 12, 7, 12, 0);
		veDoc(105, 9, 3, 12, 0);
		veNgang(105, 9, 6, 12, 0);

		//veDoc(44, 14, 1, 3, 0);
		veCheoLenPhaiQuaTrai(44, 14, 10, 3, 0);
		obs.x = 44; obs.y = 14;
		for (int i = 0; i < 10; i++)
		{
			obstacles_2.push_back(obs);
			obs.x--;
			obs.y--;
		}
		veCheoXuong(44, 14, 10, 3, 0);
		obs.x = 44; obs.y = 14;
		for (int i = 10; i < 20; i++)
		{
			obstacles_2.push_back(obs);
			obs.x++;
			obs.y++;
		}
		veCheoLen(44, 14, 10, 3, 0);
		obs.x = 44; obs.y = 14;
		for (int i = 20; i < 30; i++)
		{
			obstacles_2.push_back(obs);
			obs.x++;
			obs.y--;
		}
		veCheoXuongPhaiQuaTrai(44, 14, 10, 3, 0);
		obs.x = 44; obs.y = 14;
		for (int i = 30; i < 40; i++)
		{
			obstacles_2.push_back(obs);
			obs.x--;
			obs.y++;
		}
		//Center 
		for (int i = 0; i < 3; i++) {
			veNgang(41 + i, 11 + i, len, 3, 0);
			veNgang(41 + i, 17 - i, len, 3, 0);
			len -= 2;
		}
		obs.x = 41; obs.y = 11;
		for (int i = 83; i < 89; i++)
		{
			obstacles_2.push_back(obs);
			obs.x++;
		}
		obs.x = 42; obs.y = 12;
		for (int i = 89; i < 93; i++)
		{
			obstacles_2.push_back(obs);
			obs.x++;
		}
		obs.x = 43; obs.y = 13;
		for (int i = 93; i < 95; i++)
		{
			obstacles_2.push_back(obs);
			obs.x++;
		}
		obs.x = 41; obs.y = 17;
		for (int i = 95; i < 101; i++)
		{
			obstacles_2.push_back(obs);
			obs.x++;
		}
		obs.x = 42; obs.y = 16;
		for (int i = 101; i < 105; i++)
		{
			obstacles_2.push_back(obs);
			obs.x++;
		}
		obs.x = 43; obs.y = 15;
		for (int i = 105; i < 107; i++)
		{
			obstacles_2.push_back(obs);
			obs.x++;
		}
		veNgang(43, 14, 3, 3, 0);
		obs.x = 43; obs.y = 14;
		for (int i = 40; i < 43; i++)
		{
			obstacles_2.push_back(obs);
			obs.x++;
		}
		//Trai-Tren
		veCheoXuongPhaiQuaTrai(10, 1, 9, 3, 0);
		obs.x = 10; obs.y = 1;
		for (int i = 43; i < 53; i++)
		{
			obstacles_2.push_back(obs);
			obs.x--;
			obs.y++;
		}
		obs.x = 10; obs.y = 1;
		len = 10;
		for (int i = 0; i < 10; i++)
		{
			point block = { obs.x - 1,obs.y };
			for (int j = 0; j < len - 1; j++)
			{
				obstacles_2.push_back(block);
				block.x--;
			}
			obs.x--;
			obs.y++;
			len--;
		}
		//Phai_Duoi
		veCheoLen(79, 28, 9, 3, 0);
		obs.x = 79; obs.y = 28;
		for (int i = 53; i < 63; i++)
		{
			obstacles_2.push_back(obs);
			obs.x++;
			obs.y--;
		}
		len = 10;
		obs.x = 79; obs.y = 28;
		for (int i = 0; i < 10; i++)
		{
			point block = { obs.x + 1,obs.y };
			for (int j = 0; j < len - 1; j++)
			{
				obstacles_2.push_back(block);
				block.x++;
			}
			obs.x++;
			obs.y--;
			len--;
		}
		//Phai-Tren
		veCheoXuong(79, 1, 9, 3, 0);
		obs.x = 79; obs.y = 1;
		for (int i = 63; i < 73; i++)
		{
			obstacles_2.push_back(obs);
			obs.x++;
			obs.y++;
		}
		len = 10;
		obs.x = 79; obs.y = 1;
		for (int i = 0; i < 10; i++)
		{
			point block = { obs.x + 1,obs.y };
			for (int j = 0; j < len - 1; j++)
			{
				obstacles_2.push_back(block);
				block.x++;
			}
			obs.x++;
			obs.y++;
			len--;
		}
		//Trai-Duoi
		veCheoLenPhaiQuaTrai(10, 28, 9, 3, 0);
		obs.x = 10; obs.y = 28;
		for (int i = 73; i < 83; i++)
		{
			obstacles_2.push_back(obs);
			obs.x--;
			obs.y--;
		}
		obs.x = 10; obs.y = 28;
		len = 10;
		for (int i = 0; i < 10; i++)
		{
			point block = { obs.x - 1,obs.y };
			for (int j = 0; j < len - 1; j++)
			{
				obstacles_2.push_back(block);
				block.x--;
			}
			obs.x--;
			obs.y--;
			len--;
		}
		SetColor1(7, 0);
		break;
	case 3:
		vetuongformat();
		//3
		//Số 3
		veNgang(105, 6, 6, 12, 0);
		veDoc(110, 6, 7, 12, 0);
		veNgang(105, 12, 6, 12, 0);
		veNgang(105, 9, 6, 12, 0);

		veNgang(1, 3, 66, 12, 0);
		obs.x = 1; obs.y = 3;
		for (int i = 0; i < 66; i++)
		{
			obstacles_3.push_back(obs);
			obs.x++;
		}
		veNgang(6, 25, 16, 12, 0);
		obs.x = 6; obs.y = 25;
		for (int i = 66; i < 82; i++)
		{
			obstacles_3.push_back(obs);
			obs.x++;
		}
		
		veDoc(22, 7, 22, 12, 0);
		obs.x = 22; obs.y = 7;
		for (int i = 120; i < 142; i++)
		{
			obstacles_3.push_back(obs);
			obs.y++;
		}
		veDoc(30, 4, 22, 12, 0);
		obs.x = 30; obs.y = 4;
		for (int i = 142; i < 164; i++)
		{
			obstacles_3.push_back(obs);
			obs.y++;
		}
		veDoc(38, 7, 22, 12, 0);
		obs.x = 38; obs.y = 7;
		for (int i = 164; i < 186; i++)
		{
			obstacles_3.push_back(obs);
			obs.y++;
		}
		veNgang(38, 7, 42, 12, 0);
		obs.x = 38; obs.y = 7;
		for (int i = 186; i < 228; i++)
		{
			obstacles_3.push_back(obs);
			obs.x++;
		}
		veNgang(45, 13, 44, 12, 0);
		obs.x = 45; obs.y = 13;
		for (int i = 228; i < 272; i++)
		{
			obstacles_3.push_back(obs);
			obs.x++;
		}
		veNgang(38, 19, 42, 12, 0);
		obs.x = 38; obs.y = 19;
		for (int i = 272; i < 314; i++)
		{
			obstacles_3.push_back(obs);
			obs.x++;
		}
		veNgang(45, 25, 44, 12, 0);
		obs.x = 45; obs.y = 25;
		for (int i = 314; i < 358; i++)
		{
			obstacles_3.push_back(obs);
			obs.x++;
		}
		SetColor1(7, 0);
		break;
	case 4:
		vetuongformat();
		//4
		veCheoXuongPhaiQuaTrai(108, 6, 3, 12, 0);
		veDoc(111, 6, 7, 12, 0);
		veNgang(106, 9, 6, 12, 0);
		//

		break;
	case 5:
		vetuongformat();
		break;
	case 6:
		vetuongformat();
		break;
	}
}
void vetuongformat() {
	for (int i = 0; i < HEIGHT; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			SetColor1(7, 0);
			cout << " ";
		}
		cout << "\n";
	}
	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_trai();
	ve_tuong_phai();
	ve_tuong_phai_ngoai_cung();
	veNgang(90, 22, 29, 10, 0);
	//Chu L

	veDoc(92, 1, 4, 12, 0);
	veNgang(92, 5, 4, 12, 0);
	//Chu E
	veDoc(92, 7, 5, 12, 0);
	veNgang(92, 7, 4, 12, 0);
	veNgang(92, 9, 4, 12, 0);
	veNgang(92, 11, 4, 12, 0);
	//Chu V
	veCheoXuong(91, 13, 2, 12, 0);
	veCheoLen(93, 15, 2, 12, 0);
	//Chu E
	veDoc(92, 17, 5, 12, 0);
	veNgang(92, 17, 4, 12, 0);
	veNgang(92, 19, 4, 12, 0);
	veNgang(92, 21, 4, 12, 0);
	//Chu L
	veDoc(98, 17, 4, 12, 0);
	veNgang(98, 21, 4, 12, 0);

	//Khung
	veDoc(103, 5, 9, 9, 0);
	veNgang(103, 5, 10, 9, 0);
	veDoc(113, 5, 9, 9, 0);
	veNgang(103, 13, 10, 9, 0);

	gotoXY(108, 14);
	SetColor1(7, 2);
	cout << "_";
	cout << "_";
	gotoXY(107, 15);
	cout << "{00}";
	gotoXY(107, 16);
	cout << "\\__/";
	gotoXY(107, 17);
	cout << "/^/";
	gotoXY(106, 18);
	cout << "( (";
	gotoXY(106, 19);
	cout << "\\_\\____";
	gotoXY(106, 20);
	cout << "(______)";
	gotoXY(105, 21);
	cout << "(_______()0o";

	//Ghi chữ
	gotoXY(95, 24);
	SetColor(4);
	cout << "Level: " << level << "/3";
	gotoXY(95, 25);
	cout << "Food: " << foodEaten << "/4";
	gotoXY(95, 26);
	cout << "Score: " << score;
	gotoXY(95, 27);
	cout << "Length: " << length;
	gotoXY(91, 23);
	for (int i = 0; i < 28; i++) {
		cout << "=";
	}
	gotoXY(91, 28);
	for (int i = 0; i < 28; i++) {
		cout << "=";
	}
}
void pause(point*& toaDoSnake) {
	drawSnake(toaDoSnake, Food);
	int len = 6;
	int choice = 1;
	char x = '0';
	int color = 14;
	veNgang(45, 8, 25, color, 0);
	veDoc(45, 8, 8, color, 0);
	veDoc(70, 8, 8, color, 0);
	veNgang(45, 16, 26, color, 0);
	gotoXY(48, 10);
	SetColor1(3, 14);
	cout << "Save & Back to Menu";
	gotoXY(52, 12);
	SetColor1(0, 15);
	cout << "Back to Menu";
	gotoXY(48, 14);
	cout << "Press P to continue";
	shouldContinue = true;
	thread t(ChangeColor);
	do {
		if (_kbhit()) {
			x = _getch();
			if ((x == 's' || x == 'S') && choice == 1) {
				choice = 2;
				gotoXY(48, 10);
				SetColor1(0, 15);
				cout << "Save & Back to Menu";
				gotoXY(52, 12);
				SetColor1(3, 14);
				cout << "Back to Menu";
			}
			else if ((x == 'w' || x == 'W') && choice == 2) {
				choice = 1;
				gotoXY(48, 10);
				SetColor1(3, 14);
				cout << "Save & Back to Menu";
				gotoXY(52, 12);
				SetColor1(0, 15);
				cout << "Back to Menu";
			}
			else if (x == '\r' && choice == 1) {
				/*writeDataToFile();
				delete[] toaDoSnake;
				if (Gate != NULL)delete Gate;
				system("cls");
				ResetGameData();
				SetColor1(7, 0);
				CloseBackgroundMusic();
				drawMenu();
				return;*/
				choice = 1;
				shouldContinue = false;
				break;
			}
			else if (x == '\r' && choice == 2) {
				choice = 2;
				shouldContinue = false;
				break;
				/*delete[] toaDoSnake;
				if (Gate != NULL)delete Gate;
				system("cls");
				ResetGameData();
				SetColor1(7, 0);
				CloseBackgroundMusic();
				drawMenu();
				return;*/
			}
			else if (x == 'p' || x == 'P') {
				choice = 3;
				shouldContinue = false;
				SetColor1(7, 0);
				break;
			}
		}
	} while (x != 'p' && x != 'P');
	t.join();
	switch (choice) {
	case 1:
		writeDataToFile();
		delete[] toaDoSnake;
		if (Gate != NULL)delete Gate;
		system("cls");
		ResetGameData();
		SetColor1(7, 0);
		CloseBackgroundMusic();
		drawMenu();
		return;
	case 2:
		delete[] toaDoSnake;
		if (Gate != NULL)delete Gate;
		system("cls");
		ResetGameData();
		SetColor1(7, 0);
		CloseBackgroundMusic();
		drawMenu();
		return;
	case 3:
		switch (level)
		{
		case 1:
			for (int i = 45; i <= 70; i++)
			{
				for (int j = 8; j <= 16; j++)
				{
					gotoXY(i, j);
					SetColor1(7, 0);
					cout << " ";
				}
			}
			break;
		case 2:
			for (int i = 45; i <= 70; i++)
			{
				for (int j = 8; j <= 16; j++)
				{
					gotoXY(i, j);
					SetColor1(7, 0);
					cout << " ";
				}
			}
			//veDoc(44, 14, 1, 3, 0);
			veCheoLenPhaiQuaTrai(44, 14, 10, 3, 0);

			veCheoXuong(44, 14, 10, 3, 0);

			veCheoLen(44, 14, 10, 3, 0);

			veCheoXuongPhaiQuaTrai(44, 14, 10, 3, 0);

			//Center 
			for (int i = 0; i < 3; i++) {
				veNgang(41 + i, 11 + i, len, 3, 0);
				veNgang(41 + i, 17 - i, len, 3, 0);
				len -= 2;
			}
			veNgang(43, 14, 3, 3, 0);

			//Trai-Tren
			veCheoXuongPhaiQuaTrai(10, 1, 9, 3, 0);

			//Phai_Duoi
			veCheoLen(79, 28, 9, 3, 0);

			//Phai-Tren
			veCheoXuong(79, 1, 9, 3, 0);

			//Trai-Duoi
			veCheoLenPhaiQuaTrai(10, 28, 9, 3, 0);
			break;
		case 3:
			for (int i = 45; i <= 70; i++)
			{
				for (int j = 8; j <= 16; j++)
				{
					gotoXY(i, j);
					SetColor1(7, 0);
					cout << " ";
				}
			}
			vector<point>temp = obstacles_3;
			for (int i = 0; i < temp.size(); i++)
			{
				gotoXY(temp[i].x, temp[i].y);
				SetColor1(12, 0);
				cout << " ";
			}
			break;
		}
		gotoXY(toaDoSnake[sl - 1].x, toaDoSnake[sl - 1].y);
		SetColor1(7, 0);
		cout << " ";
		gotoXY(Food.x, Food.y);
		_setmode(_fileno(stdout), _O_U16TEXT);
		wcout << L"\u25CF";
		_setmode(_fileno(stdout), _O_TEXT);
		SetColor(7);//mau trang
		return;
	}
}
void ChangeColor() {
	int seconds = 15;
	while (shouldContinue) {
		//chuMenuHunting(seconds, 0);
		//chuMenuCredit(seconds, 0);
		if (seconds == 0)seconds = 15;
		mtx.lock();
		gotoXY(48, 14);
		SetColor1(0, seconds);
		cout << "Press P to continue";
		mtx.unlock();
		this_thread::sleep_for(chrono::seconds(1));
		seconds--;
	}

}
void ChangeColorMenu() {

	while (needChange) {

		if (mauchumenu == 15) mauchumenu = 0;
		if (mauchucredit == 15) mauchucredit = 0;
		if (mauchumenu == 2) mauchumenu = 3;
		if (mauchucredit == 2) mauchucredit = 3;
		if (mauchumenu == 8) mauchumenu = 9;
		if (mauchucredit == 8) mauchucredit = 9;
		if (mauchucredit == 10) mauchucredit = 11;
		unique_lock<std::mutex> lock(mtx); // Khóa mutex
		cv.wait(lock);
		// Thực hiện thay đổi màu màn hình console
		chuMenuHunting(mauchumenu, 0);
		chuMenuCredit(mauchucredit, 0);


		lock.unlock(); // Mở khóa mutex
		cv.notify_one();
		this_thread::sleep_for(chrono::seconds(1));
		mauchumenu++; mauchucredit++;
	}
	needChange = false;
	TerminateThread;
}

//dem nguoc tu 3
void demGiay() {
	system("cls");
	for (int i = 0; i < HEIGHT + 1; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			SetColor1(14, 0);
			cout << " ";
		}
		cout << "\n";
	}
	int seconds = 3;
	PlaySound("COUNTDOWN.wav", NULL, SND_ASYNC);
	while (seconds >= 0) {
		if (seconds == 3) {
			veNgang(57, 9, 6, 0, 0);
			veDoc(62, 9, 7, 0, 0);
			veNgang(57, 15, 6, 0, 0);
			veNgang(57, 12, 6, 0, 0);
		}
		else if (seconds == 2) {
			veNgang(57, 9, 6, 14, 0);
			veDoc(62, 9, 7, 14, 0);
			veNgang(57, 15, 6, 14, 0);
			veNgang(57, 12, 6, 14, 0);
			veNgang(57, 9, 6, 0, 0);
			veDoc(62, 9, 3, 0, 0);
			veNgang(57, 12, 6, 0, 0);
			veDoc(57, 12, 3, 0, 0);
			veNgang(57, 15, 6, 0, 0);
		}
		else if (seconds == 1) {
			veNgang(57, 9, 6, 14, 0);
			veDoc(62, 9, 3, 14, 0);
			veNgang(57, 12, 6, 14, 0);
			veDoc(57, 12, 3, 14, 0);
			veNgang(57, 15, 6, 14, 0);

			veCheoLen(60, 11, 2, 0, 0);
			veDoc(62, 9, 6, 0, 0);
			veNgang(60, 15, 5, 0, 0);
		}
		else {
			veCheoLen(60, 11, 2, 14, 0);
			veDoc(62, 9, 6, 14, 0);
			veNgang(60, 15, 5, 14, 0);
			chuG(55, 10, 0, 0);
			chuO(61, 10, 0, 0);
			veDoc(67, 10, 3, 0, 0);
			veDoc(67, 14, 1, 0, 0);
		}

		Sleep(1000);
		seconds--;
	}
	return;

}
void huongMuiTen(int num, int maunen) {
	switch (num) {
	case 1:
		veNgang(37, 14, 12, maunen, 0);
		veCheoLen(37, 14, 2, maunen, 0);
		veCheoXuong(37, 14, 2, maunen, 0);
		break;
	case 2:
		veNgang(88, 14, 12, maunen, 0);
		veCheoLenPhaiQuaTrai(100, 14, 2, maunen, 0);
		veCheoXuongPhaiQuaTrai(100, 14, 2, maunen, 0);
		break;
	case 3:
		veDoc(68, 1, 4, maunen, 0);
		veCheoXuongPhaiQuaTrai(68, 1, 2, maunen, 0);
		veCheoXuong(68, 1, 2, maunen, 0);
		break;
	case 4:
		veDoc(68, 21, 5, maunen, 0);
		veCheoLenPhaiQuaTrai(68, 26, 2, maunen, 0);
		veCheoLen(68, 26, 2, maunen, 0);
		break;
	}
}
void AnimationButton() {
	int x = 50, y = 11;
	int mau = 1;
	int solan = 1;

	while (abutton) {

		if (mau == 15)mau = 1;
		if (mau == 8)mau = 9;
		if (solan == 5) {
			solan = 1;
			x = 50;
			y = 11;
		}
		if (solan <= 3) {
			unique_lock<std::mutex> lock(mtx); // Khóa mutex
			cv.wait(lock, [] { return abutton; }); // Chỉ thực hiện thay đổi màu nếu biến changeColor là true
			nuttutorial(x, y, mau);

			if (solan == 1) {
				huongMuiTen(3, 8);
				huongMuiTen(1, mau);
			}
			else if (solan == 2) {
				huongMuiTen(1, 8);
				huongMuiTen(4, mau);
			}
			else if (solan == 3) {
				huongMuiTen(4, 8);
				huongMuiTen(2, mau);
			}
			Sleep(1000);
			nuttutorial(x, y, 0);

			lock.unlock(); // Mở khóa mutex
			cv.notify_one();
			this_thread::sleep_for(chrono::seconds(1));
			mau++; x += 12; solan++;
		}
		else if (solan == 4) {
			x = 62, y = 5;
			unique_lock<std::mutex> lock(mtx); // Khóa mutex
			cv.wait(lock, [] { return abutton; }); // Chỉ thực hiện thay đổi màu nếu biến changeColor là true
			nuttutorial(x, y, mau);
			if (solan == 4) {
				huongMuiTen(2, 8);
				huongMuiTen(3, mau);
			}
			Sleep(1000);
			nuttutorial(x, y, 0);

			lock.unlock(); // Mở khóa mutex
			cv.notify_one();
			this_thread::sleep_for(chrono::seconds(1));
			solan++;
		}
	}

	//TerminateThread;
}
void highScoress() {//47 1 47
	system("cls"); int choice = 1;
	for (int i = 0; i < HEIGHT + 1; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			SetColor1(14, 0);
			cout << " ";
		}
		cout << "\n";
	}
	int x = 44; char oke = '7'; int omg = 0;
	SetColor1(14, 0);
	gotoXY(x, 0);
	cout << "        ,     \\    /      , ";
	gotoXY(x, 1);
	cout << "       / \\    )\\__/(     / \\ ";
	gotoXY(x, 2);
	cout << "      /   \\  (_\\  /_)   /   \\";
	gotoXY(x, 3);
	cout << " ____/_____\\__\\@  @/___/_____\\____ ";
	gotoXY(x, 4);
	cout << "|             |\\../|              |";
	gotoXY(x, 5);
	cout << "|              \\VV/               |";
	gotoXY(x, 6);
	cout << "|           HIGH SCORE            |";
	gotoXY(x, 7);
	cout << "|_________________________________|";
	gotoXY(45, 8);
	cout << "|    /\\ /      \\\\       \\ /\\    | ";
	gotoXY(45, 9);
	cout << "|  /   V        ))       V   \\  | ";
	gotoXY(45, 10);
	cout << "|/     `       //        '     \\| ";
	gotoXY(45, 11);
	cout << "`              V                ' ";


	nut(40, 15, 0, 0);
	for (int i = 15; i < 20; i++) {
		veNgang(41, 1 + i, 17, 13, 0);
	}
	gotoXY(46, 18);
	SetColor1(14, 0);
	cout << "NORMAL";
	nut(62, 15, 0, 0);
	gotoXY(68, 18);
	cout << "INFINITY";

	do {
		SetColor1(14, 0);
		gotoXY(x, 0);
		cout << "        ,     \\    /      , ";
		gotoXY(x, 1);
		cout << "       / \\    )\\__/(     / \\ ";
		gotoXY(x, 2);
		cout << "      /   \\  (_\\  /_)   /   \\";
		gotoXY(x, 3);
		cout << " ____/_____\\__\\@  @/___/_____\\____ ";
		gotoXY(x, 4);
		cout << "|             |\\../|              |";
		gotoXY(x, 5);
		cout << "|              \\VV/               |";
		gotoXY(x, 6);
		cout << "|           HIGH SCORE            |";
		gotoXY(x, 7);
		cout << "|_________________________________|";
		gotoXY(45, 8);
		cout << "|    /\\ /      \\\\       \\ /\\    | ";
		gotoXY(45, 9);
		cout << "|  /   V        ))       V   \\  | ";
		gotoXY(45, 10);
		cout << "|/     `       //        '     \\| ";
		gotoXY(45, 11);
		cout << "`              V                ' ";

		if (choice == 1 && omg == 0) {
			nut(40, 15, 0, 0);
			for (int i = 15; i < 20; i++) {
				veNgang(41, 1 + i, 17, 13, 0);
			}
			gotoXY(46, 18);
			SetColor1(14, 0);
			cout << "NORMAL";
			nut(62, 15, 0, 0);
			for (int i = 15; i < 20; i++) {
				veNgang(63, 1 + i, 17, 14, 0);
			}
			gotoXY(68, 18);
			SetColor1(14, 0);
			cout << "INFINITY";
		}
		else if (choice == 2 && omg == 0) {

			nut(40, 15, 0, 0);
			for (int i = 15; i < 20; i++) {
				veNgang(41, 1 + i, 17, 14, 0);
			}
			gotoXY(46, 18);
			SetColor1(14, 0);
			cout << "NORMAL";
			nut(62, 15, 0, 0);
			for (int i = 15; i < 20; i++) {
				veNgang(63, 1 + i, 17, 13, 0);
			}
			gotoXY(68, 18);
			SetColor1(14, 0);
			cout << "INFINITY";
		}
		if (_kbhit()) {
			oke = _getch();
			if (oke == '\r' && choice == 1) {
				nut(40, 15, 14, 0);
				for (int i = 15; i < 20; i++) {
					veNgang(41, 1 + i, 17, 14, 0);
				}
				gotoXY(46, 18);
				SetColor1(14, 0);
				cout << "        ";
				nut(62, 15, 14, 0);
				for (int i = 15; i < 20; i++) {
					veNgang(63, 1 + i, 17, 14, 0);
				}
				veNgang(0, 12, 119, 0, 0);
				veDoc(0, 12, 17, 0, 0);
				veDoc(120, 12, 17, 0, 0);
				veNgang(0, 29, 119, 0, 0);
				veNgang(0, 14, 119, 0, 0);
				veDoc(30, 12, 17, 0, 0);
				veDoc(60, 12, 17, 0, 0);
				veDoc(90, 12, 17, 0, 0);
				veDoc(119, 12, 18, 0, 0);
				gotoXY(13, 13);
				SetColor1(14, 0);
				cout << "NAME";
				gotoXY(43, 13);
				cout << "LEVEL";
				gotoXY(73, 13);
				cout << "SCORE";
				gotoXY(103, 13);
				cout << "LENGTH";
				omg = 1;
				printHighScoreNormal();
			}
			else if ((oke == 'd' || oke == 'D' || oke == 'a' || oke == 'A') && choice == 1) {
				choice = 2;

			}
			else if ((oke == 'a' || oke == 'A' || oke == 'D' || oke == 'd') && choice == 2) {
				choice = 1;

			}
			else if (oke == '\r' && choice == 2) {
				nut(40, 15, 14, 0);
				for (int i = 15; i < 20; i++) {
					veNgang(41, 1 + i, 17, 14, 0);
				}
				gotoXY(46, 18);
				SetColor1(14, 0);
				cout << "        ";
				nut(62, 15, 14, 0);
				for (int i = 15; i < 20; i++) {
					veNgang(63, 1 + i, 17, 14, 0);
				}
				veNgang(0, 12, 119, 0, 0);
				veDoc(0, 12, 17, 0, 0);
				veDoc(120, 12, 17, 0, 0);
				veNgang(0, 29, 119, 0, 0);
				veNgang(0, 14, 119, 0, 0);
				veDoc(30, 12, 17, 0, 0);
				veDoc(60, 12, 17, 0, 0);
				veDoc(90, 12, 17, 0, 0);
				veDoc(119, 12, 18, 0, 0);
				gotoXY(13, 13);
				SetColor1(14, 0);
				cout << "RANK";
				gotoXY(43, 13);
				cout << "NAME  ";
				gotoXY(73, 13);
				cout << "SCORE";
				gotoXY(103, 13);
				cout << "LENGTH";
				omg = 1;
				printHighScore();
			}
			else if ((oke == 'x' || oke == 'X') && omg == 1) {
				omg = 0;
				veNgang(0, 12, 119, 14, 0);
				veDoc(0, 12, 17, 14, 0);
				veDoc(120, 12, 17, 14, 0);
				veNgang(0, 29, 119, 14, 0);
				veNgang(0, 14, 119, 14, 0);
				veDoc(30, 12, 17, 14, 0);
				veDoc(60, 12, 17, 14, 0);
				veDoc(90, 12, 17, 14, 0);
				veDoc(119, 12, 18, 14, 0);
				gotoXY(13, 13);
				SetColor1(14, 0);
				cout << "     ";
				gotoXY(43, 13);
				cout << "       ";
				gotoXY(73, 13);
				cout << "     ";
				gotoXY(103, 13);
				cout << "     ";
				continue;
			}
			else if (oke == 27 && omg == 0) { break; }
		}
	} while (oke != 27);


	system("cls");

	for (int i = 0; i < HEIGHT + 1; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			SetColor1(8, 0);
			cout << " ";
		}
		cout << "\n";
	}
	chuMenuHunting(1, 1);
	chuMenuCredit(1, 1);
	ranMenu(2);
	return;
}

string getLimitedInput(int limit) {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD irInputRecord;
	DWORD dwEventsRead;
	char c;
	string input;

	while (true) {
		ReadConsoleInput(hStdin, &irInputRecord, 1, &dwEventsRead);

		if (irInputRecord.EventType == KEY_EVENT && irInputRecord.Event.KeyEvent.bKeyDown) {
			c = irInputRecord.Event.KeyEvent.uChar.AsciiChar;

			switch (c) {
			case '\r':
				return input;
			default:
				if (input.size() < limit) {
					input += c;
					cout << c;
				}
			}
		}
	}
}
void loadGame() {
	for (int i = 0; i < HEIGHT + 1; i++) {
		for (int j = 0; j < WIDTH + 1; j++) {
			SetColor1(14, 0);
			cout << " ";
		}
		cout << "\n";
	}
	int x = 0, y = 16, y1 = 0;
	int x1 = 8;
	vector<savedData> dataList;
	dataList = readSavedData();

	gotoXY(x, y);
	cout << "            __.-/|-";
	gotoXY(x, y + 1);
	cout << "            \\`o_O'/";
	gotoXY(x, y + 2);
	cout << "             🙁 🙁  +------+";
	gotoXY(x, y + 3);
	cout << "               U|   | LOAD |";
	gotoXY(x, y + 4);
	cout << "     /\\  /\\   / |   +------+";
	gotoXY(x, y + 5);
	cout << "     ) /^\\) ^\\/ _)\\     |";
	gotoXY(x, y + 6);
	cout << "     )   /^\\/   _) \\    |";
	gotoXY(x, y + 7);
	cout << "     )   _ /  / )  \\___|";
	gotoXY(x, y + 8);
	cout << " /\\  )/\\/ ||  | )_)\\___,|))";
	gotoXY(x, y + 9);
	cout << "<  >      |(,,) )__)    |";
	gotoXY(x, y + 10);
	cout << " ||      /    \\)___)\\";
	gotoXY(x, y + 11);
	cout << " | \\____(      )___) )____";
	gotoXY(x, y + 12);
	cout << "  \\______(_____;;;)__;;;)";

	//hourglass
	gotoXY(x1, y1);
	cout << "+8-=-=-=-=-=-8+";
	gotoXY(x1, y1 + 1);
	cout << "| ,.-'\"'-., |";
	gotoXY(x1, y1 + 2);
	cout << "|/         \\|";
	gotoXY(x1, y1 + 3);
	cout << "|\\:.  . :  /|";
	gotoXY(x1, y1 + 4);
	cout << "| \\:::::::/ |";
	gotoXY(x1, y1 + 5);
	cout << "|  \\:::::/  |";
	gotoXY(x1, y1 + 6);
	cout << "|   \\:::/   |";
	gotoXY(x1, y1 + 7);
	cout << "|    ):(    |";
	gotoXY(x1, y1 + 8);
	cout << "|   / . \\   |";
	gotoXY(x1, y1 + 9);
	cout << "|  /  .  \\  |";
	gotoXY(x1, y1 + 10);
	cout << "| /   .   \\ |";
	gotoXY(x1, y1 + 11);
	cout << "|/   .:.   \\|";
	gotoXY(x1, y1 + 12);
	cout << "|\\.:::::::./|";
	gotoXY(x1, y1 + 13);
	cout << "| '--___--' |";
	gotoXY(x1, y1 + 14);
	cout << "+8-=-=-=-=-=-8+";




	veDoc(30, 0, 30, 0, 0);
	veNgang(30, 0, 90, 0, 0);
	veNgang(30, 29, 90, 0, 0);
	veDoc(60, 0, 3, 0, 0);
	veDoc(90, 0, 3, 0, 0);
	veNgang(30, 2, 90, 0, 0);
	SetColor1(14, 0);
	gotoXY(43, 1);
	cout << "NAME";
	gotoXY(73, 1);
	cout << "LEVEL";
	gotoXY(103, 1);
	cout << "SCORE";
	//printSavedGame();
	char oke1 = 'x'; int choice222 = 1;	int yLine = 3;
	int size = dataList.size();
	ifstream file("savedGameList.txt");
	veNgang(31, 3, 89, 6, 0);
	if (file.is_open()) {
		string line;
		for (int i = 0; i < 10; i++) {
			if (i == 0) {
				SetColor1(6, 0);
				gotoXY(43, yLine);
				cout << dataList[i].name;
				gotoXY(75, yLine);
				cout << dataList[i].level;
				gotoXY(105, yLine);
				cout << dataList[i].score << endl;
				yLine++;
			}
			else {
				SetColor1(14, 0);
				gotoXY(43, yLine);
				cout << dataList[i].name;
				gotoXY(75, yLine);
				cout << dataList[i].level;
				gotoXY(105, yLine);
				cout << dataList[i].score << endl;
				yLine++;
			}
		}
		file.close();
	}
	yLine = 3; int i = 0;
	do {
		if (_kbhit()) {
			oke1 = _getch();
			if (oke1 == 27) {
				break;
			}
			else if ((oke1 == 's' || oke1 == 'S')) {
				if (yLine == 2)yLine == 3;
				if (i > size - 1) { yLine = 3; i = 0; }
				if (i < 0) {
					i = size - 1;
					yLine = 3 + size - 1;
				}
				veNgang(31, yLine, 89, 14, 0);
				SetColor1(14, 0);
				gotoXY(43, yLine);
				cout << dataList[i].name;
				gotoXY(75, yLine);
				cout << dataList[i].level;
				gotoXY(105, yLine);
				cout << dataList[i].score << endl;
				i++; yLine++;
				if (i > size - 1) { yLine = 3; i = 0; }
				if (i < 0) {
					i = size - 1;
					yLine = 3 + size - 1;
				}
				veNgang(31, yLine, 89, 6, 0);
				SetColor1(6, 0);
				gotoXY(43, yLine);
				cout << dataList[i].name;
				gotoXY(75, yLine);
				cout << dataList[i].level;
				gotoXY(105, yLine);
				cout << dataList[i].score << endl;
			}
			else if ((oke1 == 'w' || oke1 == 'W')) {
				if (yLine == 2)yLine == 3;
				if (i > size - 1) { yLine = 3; i = 0; }
				if (i < 0) {
					i = size - 1;
					yLine = 3 + size - 1;
				}
				veNgang(31, yLine, 89, 14, 0);
				SetColor1(14, 0);
				gotoXY(43, yLine);
				cout << dataList[i].name;
				gotoXY(75, yLine);
				cout << dataList[i].level;
				gotoXY(105, yLine);
				cout << dataList[i].score << endl;
				i--; yLine--;
				if (i > size - 1) { yLine = 3; i = 0; }
				if (i < 0) {
					i = size - 1;
					yLine = 3 + size - 1;
				}
				veNgang(31, yLine, 89, 6, 0);
				SetColor1(6, 0);
				gotoXY(43, yLine);
				cout << dataList[i].name;
				gotoXY(75, yLine);
				cout << dataList[i].level;
				gotoXY(105, yLine);
				cout << dataList[i].score << endl;
			}
			if (oke1 == '\r') {
				loadGameInit(toaDoSnake, i);
				switch (level) {
				case 1:
					map(1);
					break;
				case 2:
					map(2);
					break;
				case 3:
					map(3);
					break;
				}
				drawSnake(toaDoSnake, Food);
				srand(time(NULL));
				makeFood(Food, toaDoSnake);
				xuLyDiChuyen();
			}
		}
	} while (oke1 != 27);
	CloseBackgroundMusic();
	drawMenu();
	return;
}
void printSavedGame() {
	ifstream file("savedGameList.txt");
	if (file.is_open()) {
		string line;
		vector<savedData> dataList;
		dataList = readSavedData();
		int yLine = 3;
		for (int i = 0; i < 10; i++) {
			gotoXY(43, yLine);
			cout << dataList[i].name;
			gotoXY(73, yLine);
			cout << dataList[i].level;
			gotoXY(109, yLine);
			cout << dataList[i].score << endl;
			yLine++;
		}
		file.close();
	}
}
void Congratulation(int x, int y, int maunen, int mauchu) {
	
	system("cls");
	int len = 4;
	int a = maunen, b = mauchu;
	chuC(x, y, maunen, 0);
	chuO(x + 6, y, maunen, 0);
	chuN(x + 12, y, maunen, 0);
	chuG(x + 18, y, maunen, 0);
	chuR(x + 24, y, maunen, 0);
	chuA(x + 33, y, maunen, 0);
	chuT(x + 39, y, maunen, 0);
	chuU(x + 43, y, maunen, 0);
	chuL(x + 50, y, maunen, 0);
	chuA(x + 60, y, maunen, 0);
	chuT(x + 66, y, maunen, 0);
	chuI(x + 70, y, maunen, 0);
	chuO(x + 72, y, maunen, 0);
	chuN(x + 78, y, maunen, 0);
}
void chuanCongra() {
	Congratulation(19, 10, 5, 0);

	int seconds = 15;
	while (--seconds >= 11) {
		Sleep(1000);
		Congratulation(19, 10, seconds, 0);
	}
	return;
}
void chuC(int x, int y, int maunen, int mauchu) {
	const int len = 4;
	int a = maunen, b = mauchu;
	veDoc(x, y, len, a, b);
	veNgang(x, y, len + 1, a, b);
	veNgang(x, y + len, len + 1, a, b);
}
void chuT(int x, int y, int maunen, int mauchu) {
	const int len = 5;
	int a = maunen, b = mauchu;
	veDoc(x, y, len, a, b);
	veNgang(x - 2, y, len, a, b);

}
void chuU(int x, int y, int maunen, int mauchu) {
	const int len = 5;
	int a = maunen, b = mauchu;
	veDoc(x, y, len - 1, a, b);
	veNgang(x, y + len - 1, len, a, b);
	veDoc(x + len, y, len, a, b);
}
void chuL(int x, int y, int maunen, int mauchu) {
	const int len = 5;
	int a = maunen, b = mauchu;
	veDoc(x, y, len - 1, a, b);
	veNgang(x, y + len - 1, len, a, b);
}
void chuI(int x, int y, int maunen, int mauchu) {
	const int len = 5;
	int a = maunen, b = mauchu;
	veDoc(x, y, len, a, b);
}
void PlayBackgroundMusic(const string& fileName) {
	std::string command = "open \"" + fileName + "\" type mpegvideo alias Music";
	mciSendString(command.c_str(), NULL, 0, NULL);
	mciSendString("play Music repeat", NULL, 0, NULL);
	isPlayingMusic = 1;
}
void CloseBackgroundMusic() {
	mciSendString("close Music", NULL, 0, NULL);
	isPlayingMusic = 0;
}
void SetLeftVolume(DWORD volume) {
    waveOutSetVolume(NULL, ((DWORD)volume << 16) | volume); // Thiết lập âm lượng cho kênh trái
}

void SetRightVolume(DWORD volume) {
    waveOutSetVolume(NULL, (volume | ((DWORD)volume << 16))); // Thiết lập âm lượng cho kênh phải
}