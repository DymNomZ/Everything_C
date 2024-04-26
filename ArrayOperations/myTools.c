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

void drawDBox(int x1,int y1, int x2, int y2){
     int row = 0, col = 0;
     for(row = y1; row < y2; row++){
     	gotoxy(35, row);
        for(col = x1; col < x2; col++){
            if(row == 0 && col == 0) printf("%c", 218);
            else if(row == y2-1 && col == 0) printf("%c", 192);
            else if(row == y2-1 && col == x2-1) printf("%c", 217);
            else if(row == 0 && col == x2-1) printf("%c", 191);
            else if(row == 0 || row == y2-1) printf("%c", 196);
            else if(col == 0 || col == x2-1) printf("%c", 179);
            else printf(" ");
        }
    }
}

void menu(){
     int choice, size = 1, item, k, prevSize, index, result;
     int la[100];
     
     while(choice != 11){
     system("cls");
     drawDBox(0, 0, 50, 17);
     gotoxy(46, 1);
     printf("~~~~~~ ARRAY OPERATIONS  ~~~~");
     gotoxy(50, 3);
     printf("1.CREATEArray");
     gotoxy(50, 4);
     printf("2.PRINTArray");
     gotoxy(50, 5);
     printf("3.INSERTAtPos");
     gotoxy(50, 6);
     printf("4.INSERTFront");
     gotoxy(50, 7);
     printf("5.REMOVEAtPos");
     gotoxy(50, 8);
     printf("6.REMOVEItem");
     gotoxy(50, 9);
     printf("7.REMOVEFront");
     gotoxy(50, 10);
     printf("8.LOCATEIndx");
     gotoxy(50, 11);
     printf("9.LOCATEItem");
     gotoxy(50, 12);
     printf("10.SORT(Ascending& Descending");
     gotoxy(50, 13);
     printf("11.EXIT");
     gotoxy(50, 14);
     printf("Enter a valid choice[1-11]: ");
     scanf("%d", &choice);
     gotoxy(0, 18);
     switch(choice){
     	case 1:
     		printf("Enter size: ");
     		scanf("%d", &size);
             createArray(la, size);
             system("pause");
             break;
        case 2:
             printArray(la, size);
             system("pause");
             break;
        case 3:
             size = inserAtPos(la, size, item, k);
             system("pause");
             break;
        case 4:
             insertFront(la, &size, item);
             system("pause");
             break;
        case 5:
             removeAtPos(la, &size, k);
             system("pause");
             break;
        case 6:
             prevSize = size;
             size = removeItem(la, size, item);
             if(size == -1){
             size = prevSize-1;
             }
             system("pause");
             break;
        case 7:
             size = removeFront(la, size);
             system("pause");
             break;
        case 8:
             index = locateIndex(la, size, item);
             if(index != -1){
             printf("Item found at index %d!\n", index);
             }else{
             printf("Item not found\n");
             }
             system("pause");
             break;
        case 9:
             result = locateItem(la, size, item);
             if(result == 1){
             printf("Item found!\n");
             }else if(result == 0){
             printf("Item not found\n");
             }
             system("pause");
             break;
        case 10:
             sortAscending(la, size);
             printArray(la, size);
             sortDescending(la, size);
             printArray(la, size);
             system("pause");
             break;
     }
}
}
