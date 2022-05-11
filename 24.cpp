#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

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
int main() {
    /*cout << "Hello World" << endl;
    gotoxy(5, 3);
    cout << "I";
    gotoxy(6, 4);
    cout << "LOVE";
    gotoxy(10, 5);
    cout << "YOU";*/
    
    srand((unsigned) time(0));
    int nX = 0, nY = 0;
    for (int x = 0; x<= 10; x++){
        nX = 1 + (rand()%20);
        nY = 1 + (rand()%20);
        gotoxy(nX, nY);
        cout << 1 + (rand()%20);
    }
    return 0;
}