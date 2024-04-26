#include <stdio.h>
#include <ctype.h>
//COPYRIGHT DYMIER BORGONIA

char printCommand(){
	char choice;
	printf("a] Origin  b] Location  c] Move   d] Exit\n");
	printf("Enter your choice: ");
	scanf(" %c", &choice);
	choice = tolower(choice);
	if(choice != 'a' && choice != 'b' && choice != 'c' && choice != 'd'){
		printf("Invalid choice\n\n");
	}
	return choice;
}

void initialize(int *x,int *y){
	*x = 0;
	*y = 0;
}

void printLocation(int x,int y){
	printf("Location = (%d, %d)\n\n", x, y);
}

void move(int *x, int *y){
	int choice, spaces;
	printf("Enter 6-East, 4-West, 8-North, 2-South: ");
	scanf("%d", &choice);
	if(choice != 6 && choice != 4 && choice != 8 && choice != 2){
		printf("Invalid choice\n");
	}else if(choice == 6){
		printf("How many spaces: ");
		scanf("%d", &spaces);
		*x += spaces;
	}else if(choice == 4){
		printf("How many spaces: ");
		scanf("%d", &spaces);
		*x -= spaces;
	}else if(choice == 8){
		printf("How many spaces: ");
		scanf("%d", &spaces);
		*y += spaces;
	}else if(choice == 2){
		printf("How many spaces: ");
		scanf("%d", &spaces);
		*y -= spaces;
	}else{
		printf("Invalid choice");
	}
	printf("\n");
}

void Exit(){
	printf("Program terminated. Thank you!");
}
