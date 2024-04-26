#include <stdio.h>
#include <windows.h>
//COPYRIGHT DYMIER BORGONIA
COORD coord={0,0};
void gotoxy(int x,int y)
{
     coord.X=x; 
     coord.Y=y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
} 

void drawPassBorder(int seat){
     int row = 0, col = 0;
     int x1 = 0, y1 = 0, x2 = 40, y2 = 7;
     for(row = y1; row < y2; row++){
        for(col = x1; col < x2; col++){
            if(row == 0 && col == 0) printf("%c", 218);
            else if(row == y2-1 && col == 0) printf("%c", 192);
            else if(row == y2-1 && col == x2-1) printf("%c", 217);
            else if(row == 0 && col == x2-1) printf("%c", 191);
            else if(row == 0 || row == y2-1) printf("%c", 196);
            else if(col == 0 || col == x2-1 && (row != 2 && row!= 3 && row != 4 && col != 2)){
            	printf("%c", 179);
			}else if(row == 2 && col == 2){
            		printf("Boarding Pass\t\t\t       %c", 179);
				}else if(row == 3 && col == 2){
					if(seat >= 1 && seat <= 5){
						printf("First Class Section\t\t       %c", 179);
					}else if(seat >= 6 && seat <= 10){
						printf("Economy Section\t\t       %c", 179);
					}
				}else if(row == 4 && col == 2){
            		printf("Seat #%d\t\t\t       %c", seat, 179);
			}
			
            else printf(" ");
        }
        printf("\n");
    }
}

void initSeats(int *seats, int size){
	int i;
	for(i = 0; i < size; i++){
		*(seats + i) = 0;
	}
}

void displaySeats(int *seats, int size){
	int i;
	printf("\nFirst Class Section: ");
	for(i = 0; i < 5; i++){
		printf("[%d]", *(seats + i));
	}
	printf("\nEconomy Section: ");
	for(i = 5; i < 10; i++){
		printf("[%d]", *(seats + i));
	}
	printf("\n\n");
}

int assignSeat(int *st, int seatType){
	if(seatType == 1){
		return assignFirstClass(st, 5);
	}else if(seatType == 2){
		return assignEconomy(st + 5, 5);
	}
}

int assignFirstClass(int *seats, int size){
	int i;
	for(i = 0; i < size; i++){
		if(*(seats + i) == 0){
			*(seats + i) = 1;
			return i + 1;
		}
	}
	return -1;
}

int assignEconomy(int *seats, int size){
	int i;
	for(i = 0; i < size; i++){
		if(*(seats + i) == 0){
			*(seats + i) = 1;
			return i + 6;
		}
	}
	return -1;
}

void boardPass(int seat){
	if(seat >= 1){
		drawPassBorder(seat);
	}else {
		printf("Invalid Seat Number");
	}
}

void dymExit(){
	return;
}
