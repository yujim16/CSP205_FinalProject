#include <iostream>
#include <cmath>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <ctime>
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

int main(){
    system("cls");

    Vector player1; /// X
    player1.x = 1;
    player1.y = 2;
    Point p1(1, 6);

    Vector Enemy; /// O

    Sleep(3000);
    gotoxy(player1.x, player1.y);
    cout << ">";

    gotoxy(50, 1); cout << "|";
    gotoxy(50, 2); cout << "|";
    gotoxy(50, 3); cout << "|";
    gotoxy(50, 4); cout << "|";
    gotoxy(50, 5); cout << "|";
    gotoxy(50, 6); cout << "|";
    gotoxy(50, 7); cout << "|";
    gotoxy(50, 8); cout << "|";
    gotoxy(50, 9); cout << "|";
    gotoxy(50, 10); cout << "|";
    gotoxy(50, 11); cout << "|";

    Sleep(5000);

    return 0;
}
