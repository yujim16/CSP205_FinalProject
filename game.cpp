#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

#define treePos 74

using namespace std;

class Vector{
    public:
    Vector() {}
    Vector(float X, float Y){
        x = X;
        y = Y;
    }
    float Length() const;
    float LengthSqr() const;

    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    Vector operator*(float s) const;
    Vector operator/(float s) const;

    Vector Normalized() const;

    float x, y;
};

Vector Vector::operator+(const Vector& v) const{
   Vector retV;
   retV.x = x + v.x;
   retV.y = y + v.y;
   return retV;
}
Vector Vector::operator-(const Vector& v) const{
   return Vector(x - v.x, y - v.y);
}

class Point{
    public:
    Point() {}
    Point(float X, float Y){
        x = X;
        y = Y;
    }
    Point AddVector(Vector c);
    float x, y;
};

Vector Vector:: Normalized() const {
    Vector normalized;

    normalized = (*this) / Length();
    return normalized;
}

 Vector Vector::operator* (float s) const {
    Vector scaled;
    scaled.x = x * s;
    scaled.y = y * s;
    return scaled;
}

Vector Vector::operator/(float s) const {
    Vector scaled;
    scaled.x = x / s;
    scaled.y = y / s;
    return scaled;
}

float Vector::Length() const {
    float length;
    length = sqrt((x * x) + (y * y));
    return length;
}

float Vector::LengthSqr() const {
    float length;
    length = ((x * x) + (y * y));
    return length;
}

Vector operator-(Point a, Point b) {
    Vector v;
    v.x = a.x - b.x;
    v.y = a.y - b.y;
    return v;
}

Point Point::AddVector(Vector v) {
    Point pPrime;

    pPrime.x = x + v.x;
    pPrime.y = y + v.y;
    return pPrime;
}

void gotoxy(int col, int In){
  COORD coord;
  coord.X = col;
  coord.Y = In;
  SetConsoleCursorPosition(
     GetStdHandle(STD_OUTPUT_HANDLE),
     coord);
}
int wherex(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD result;
    if(!GetConsoleScreenBufferInfo(
        GetStdHandle(STD_OUTPUT_HANDLE), &csbi));
        return -1;
    return result.X;
}
int wherey(){
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD result;
    if(!GetConsoleScreenBufferInfo(
        GetStdHandle(STD_OUTPUT_HANDLE), &csbi));
        return -1;
    return result.Y;
}

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

int manY;
int speed = 40;
int gameover = 0;

void setcursor(bool visible, DWORD size){
    if (size == 0) {
        size = 20; // default cursor size Changing to numbers from 1 to 20, decreases cursor width
    }
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, & lpCursor);
}

void init() {
    system("cls");
    gameover = 0;
    gotoxy(3, 2); cout<<"SCORE : ";
    for (int i = 0; i < 79; i++){
    	gotoxy(1+i, 1); cout<<"ß";
    	gotoxy(1+i, 25); cout<<"ß";
	}
}

void move(int jump = 0) {

    Vector player1; /// X
    player1.x = 2;
    player1.y = manY;
    Point p1(player1.x, 19 - player1.y);
    gotoxy(player1.x, player1.y);



    if(jump == 0)
        manY = 0;
    else if(jump == 2)
        manY--;
    else manY++;

    gotoxy(player1.x, 15 - player1.y);cout<<"                 ";
    gotoxy(player1.x, 16 - player1.y);cout<<"       ÛÛÛ       ";
    gotoxy(player1.x, 17 - player1.y);cout<<"     ÛÛÛÛÛÛÛ     ";
    gotoxy(player1.x, 18 - player1.y);cout<<"       ÛÛÛ       ";
    gotoxy(player1.x, 19 - player1.y);cout<<"  ÛÛÛÛÛÛÛÛÛÛÛÛÛ  ";
    gotoxy(player1.x, 20 - player1.y);cout<<"      ÛÛÛÛÛ      ";
    gotoxy(player1.x, 21 - player1.y);cout<<"      ÛÛÛÛÛÛÛÛÛ  ";
    gotoxy(player1.x, 22 - player1.y);cout<<"      ÛÛ         ";
    gotoxy(player1.x, 23 - player1.y);cout<<"      ÛÛ         ";
    gotoxy(player1.x, 24 - player1.y);

    gotoxy(2, 25 - player1.y);
    if (jump == 0) {
        cout<<"                ";
    } else {
        cout<<"                ";
    }
    Sleep(speed);
}
void Hurdle() {
    static int treeX = 0;
	static int score = 0;


    if (treeX == 57 && manY < 4) {        // where it would hit
        score = 0;
        speed = 40;
        gotoxy(36, 8);cout<<"Game Over";
        getch();
        gameover = 1;
    }

    gotoxy(treePos - treeX, 20);cout<<"  ÛÛ    ";
    gotoxy(treePos - treeX, 21);cout<<" ÛÛÛÛ   ";
    gotoxy(treePos - treeX, 22);cout<<"ÛÛÛÛÛÛ  ";
    gotoxy(treePos - treeX, 23);cout<<"  ÛÛ    ";
    gotoxy(treePos - treeX, 24);cout<<"  ÛÛ    ";

    treeX++;

    if (treeX == 73) {
        treeX = 0;
        score++;
        gotoxy(11, 2);cout<<"     ";
        gotoxy(11, 2);cout<<score;
        if (speed > 20)
            speed--;
    }
}

void play(){
	system("cls");
    char ch;
    int i;
	init();
    while (true) {
        while (!kbhit()) {
            if( gameover==1 ){
            	return;
			}
			move();
            Hurdle();
        }
        ch = getch();
        if (ch == 32) {              // if user clicks space. 32 is space in ASCII
        	i = 0;
            while( i < 12) {
                move(1);
                Hurdle();
                i++;
            }
            while(i > 0) {
                move(2);
                Hurdle();
                i--;
        	}
        }
    }
}


int main() {
    setcursor(0, 0);
    play();
	return 0;
}