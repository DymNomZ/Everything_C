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
    for(int row = y1; row < y2; row++){
        for(int col = x1; col < x2; col++){
            if(row == 0 && col == 0) printf("*");
            else if(row == 0 && col == x2-1) printf("*");
            else if(row == 0) printf("*");
            else if(row == y2-1 && col == 0) printf("*");
            else if(row == y2-1 && col == x2-1) printf("*");
            else if(col == 0 || col == x2-1) printf("*");
            else if(row == y2-1) printf("*");
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

int main(){
    menu();
    return 0;
}