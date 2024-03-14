#include <stdio.h>

void drawSBox(int x1,int y1, int x2, int y2){
    for(int row = y1; row < y2; row++){
        for(int col = x1; col < x2; col++){
            if(row == 0 && col == 0) printf("\u250C");
            else if(row == 0 && col == x2-1) printf("\u2510");
            else if(row == 0) printf("\u2500");
            else if(row == y2-1 && col == 0) printf("\u2514");
            else if(row == y2-1 && col == x2-1) printf("\u2518");
            else if(col == 0 || col == x2-1) printf("\u2502");
            else if(row == y2-1) printf("\u2500");
            else printf(" ");
        }
        printf("\n");
    }
}