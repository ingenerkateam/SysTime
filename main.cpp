#include "D:\c++\Project1\project1\TXLib.h"
#include <iostream>
#include <conio.h>
#include <time.h>

int main()
{
    const int vremyaIgry = 10000;
    int time1 = 0;
    txCreateWindow (500, 596);

    while (!(GetAsyncKeyState(VK_ESCAPE) ||
             time1 > vremyaIgry)) {
        txSetFillColor(TX_WHITE);
        txSelectFont ("Arial", 40, 0, FW_BOLD);

        time1 = time1+50;
        txSetColor(TX_BLACK);
        txClear();

        txSetFillColor(TX_RED);
        txCircle(txMouseX(), txMouseY(), 20);

        time_t t;
        struct tm *t_m;
        t=time(NULL);
        t_m=localtime(&t);

        char vremya[100];
        sprintf (vremya, "Время = %d:%d:%d", t_m->tm_hour, t_m->tm_min, t_m->tm_sec);
        txTextOut (100, 100, vremya);

        txSleep(50);
    }

    if (time1 > vremyaIgry) {

        int seconds = time1 % 60;
        int minutes = ROUND(time1 / 60) % 60;
        int hours   = time1 / 3600;
        char gameover[3][100];
        sprintf (gameover[0], "Кончай играть!");
        sprintf (gameover[1], "Иди делай уроки!");
        sprintf (gameover[2], "Сидишь уже = %d:%d:%d", hours, minutes, seconds);
        txTextOut (100, 200, gameover[0]);
        txTextOut (100, 250, gameover[1]);
        txTextOut (100, 300, gameover[2]);
    }

    return 0;
}
