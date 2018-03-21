#include<iostream>
using namespace std;
struct Pos2D {
   int x; int y;
   int ox; int oy;
};
int boardW, boardH; // k�ch thu?c c?a m�n h�nh game
Pos2D snake[100]; // m?ng c�c � c?a con r?n
int snakeLength; // d? d�i m?ng snake d�
Pos2D direction; // hu?ng di chuy?n
bool endGame; // bi?n ki?m tra k?t th�c game
void init() {
    // kh?i t?o m?t s? gi� tr? ban d?u
    endGame = false;
    boardW = 50; boardH = 20;
    // kh?i t?o con r?n g?m c� 5 �
    snake[0].x = 5; snake[0].y = 5;
    snake[1].x = 4; snake[1].y = 5;
    snake[2].x = 3; snake[2].y = 5;
    snake[3].x = 2; snake[3].y = 5;
    snake[4].x = 1; snake[4].y = 5;
    snakeLength = 5;
    // hu?ng di chuy?n ban d?u l� di xu?ng
    direction.x = 0; direction.y = 1;
    // d?t m�u n?n cho m�n h�nh
    SetBGColor(8);
    for (int i = 0; i < boardW; i++) {
        for (int j = 0; j < boardH; j++) {
            gotoxy(i, j);
            printf(" ");
        }
    }
    // d?t m�u ch?
    SetColor(14);
}
void moveSnake(Pos2D dir) {
    for (int i = 0; i < snakeLength; i++) {
        if (i == 0) {
            // di chuy?n d? r?n
            snake[0].ox = snake[0].x; snake[0].oy = snake[0].y;
            snake[0].x += dir.x; snake[0].y += dir.y;
        }else{
            // di chuy?n ph?n th�n r?n
            snake[i].ox = snake[i].x; snake[i].oy = snake[i].y;
            snake[i].x = snake[i - 1].ox; snake[i].y = snake[i - 1].oy;
        }
         
        // khi r?n vu?t ra kh?i m�n h�nh th� cho n� xu?t hi?n l?i
        if (snake[i].x >= boardW) snake[i].x = 0;
        if (snake[i].x < 0) snake[i].x = boardW - 1;
        if (snake[i].y >= boardH) snake[i].y = 0;
        if (snake[i].y < 0) snake[i].y = boardH - 1;
         
        // ki?m tra coi con r?n c� c?n tr�ng n� kh�ng
        if 
(i != 0 && (snake[0].x == snake[i].x && snake[0].y == snake[i].y)) endGame = true;
    }
}
void drawSnake() {
    for (int i = 0; i < snakeLength; i++) {
        gotoxy(snake[i].x, snake[i].y);
        printf("%c", 4); // d�ng k� t? h�nh kim cuong d? v? con r?n
    }
    gotoxy(snake[snakeLength-1].ox, snake[snakeLength-1].oy);
    printf(" "); // x�a ph?n du�i tru?c d� c?a n�
}
int main() {
    init();
    ShowCur(false); // ?n con tr?
    while (!endGame){
        Tick(50, mainloop, drawgame); // Mainloop
    }
    return 0;
}
void drawgame() {
    drawSnake();
}
void mainloop() {
    moveSnake(direction);
 
    if (checkKey(KEY_LEFT)) {
        if (direction.x != 1) {
            direction.x = -1; direction.y = 0;
        }
    }
    else if (checkKey(KEY_RIGHT)) {
        if (direction.x != -1) {
            direction.x = 1; direction.y = 0;
        }
    }
    else if (checkKey(KEY_UP)) {
        if (direction.y != 1) {
            direction.y = -1; direction.x = 0;
        }
    }
    else if (checkKey(KEY_DOWN)) {
 
        if (direction.y != -1) {
            direction.y = 1; direction.x = 0;
        }
    }
 
    if (checkKey(KEY_ESC)) {
        endGame = true;
    }
}

