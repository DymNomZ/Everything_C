#include <stdio.h>
#include <windows.h>

COORD coord={0,0};
void gotoxy(int x,int y) 
{ 
    coord.X=x; 
    coord.Y=y; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord); 
} 

void drawSBox(int x1,int y1, int x2, int y2){
int row = 0, col = 0;
    for(row = y1; row < y2; row++){
        for(col = x1; col < x2; col++){
            if(row == 0 && col == 0) printf("%c", 218);
            else if(row == 0 && col == x2-1) printf("%c", 191);
            else if(row == 0 || row == y2-1) printf("%c", 196);
            else if(row == y2-1 && col == 0) printf("%c", 192);
            else if(row == y2-1 && col == x2-1) printf("%c", 217);
            else if(col == 0 || col == x2-1) printf("%c", 179);
            else printf(" ");
        }
        printf("\n");
    }
}

void menu(){
    drawSBox(0, 0, 20, 20);
    gotoxy(5, 3);
    printf("lol");
}