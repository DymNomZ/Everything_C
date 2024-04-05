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
            else if(row == y2-1 && col == 0) printf("%c", 192);
            else if(row == y2-1 && col == x2-1) printf("%c", 217);
            else if(row == 0 && col == x2-1) printf("%c", 191);
            else if(row == 0 || row == y2-1) printf("%c", 196);
            else if(col == 0 || col == x2-1) printf("%c", 179);
            else printf(" ");
        }
        printf("\n");
    }
}

void menu(){
     int time = 0, hours = 0, mins = 0, sec = 0;
	 int coinValue = 0, quarter = 0, dime = 0, penny = 0;
     char choice;
     while(choice != 'd' && choice != 'D'){
     system("cls");
     drawSBox(0, 0, 30, 13);
     gotoxy(9, 1);
     printf("Conversion");
     gotoxy(2, 3);
     printf("[a]Time");
     gotoxy(2, 4);
     printf("[b]Coin");
     gotoxy(2, 5);
     printf("[c]Display");
     gotoxy(2, 6);
     printf("\t[1]Time");
     gotoxy(2, 7);
     printf("\t[2]Coin");
     gotoxy(2, 8);
     printf("[d]Exit");
     gotoxy(2, 10);
     printf("Enter your choice: ");
     scanf(" %c", &choice);
     if(choice == 'a' || choice =='A'){
     gotoxy(2, 15);
     printf("Enter time: ");
     scanf(" %d", &time);
     convertTime(time, &hours, &mins, &sec);
     }
     if(choice == 'b' || choice == 'B'){
     gotoxy(2, 15);
     printf("Enter coin: ");
     scanf(" %d", &coinValue);
     computeCoin(coinValue, &quarter, &dime, &penny);
     }
     if(choice == 'c' || choice == 'C'){
     gotoxy(22, 10);
     scanf(" %c", &choice);
     if(choice == '1'){
     gotoxy(1, 15);
     displayTime(time, &hours, &mins, &sec);
     gotoxy(1, 16);
     system("pause");
     }
     else if(choice == '2'){
     gotoxy(1, 15);
     displayCoin(coinValue, &quarter, &dime, &penny);
     gotoxy(1, 16);
     system("pause");
     }
     }
     }
     gotoxy(1, 15);
}
