#include <stdio.h>
#include "airlines.h"

int main(){
	int seats[10], choice = 0, firstClass = 0, economyClass = 0;
	
	initSeats(seats, 10);
	
	printf("Welcome to MGM Airlines!\n");
	
	while(1){
		displaySeats(seats, 10);
		
		printf("Please type 1 for \"first class\"\nPlease type 2 for \"economy\" : ");
		scanf("%d", &choice);
		
		if(choice == 1){
			int seat = assignSeat(seats, 1);
			if(seat > 0){
				boardPass(seat);
			}else{
				printf("\nFirst Class Section is full, do you wish to move to the Economy Section?");
				printf("\nPress Y for yes | N for no: ");
				
				char decision;
				scanf(" %c", &decision);
				
				if(decision == 'Y' || decision == 'y'){
					int seat = assignSeat(seats, 2);
					boardPass(seat);
					displaySeats(seats, 10);
					seat = assignSeat(seats, 2);
					
					if(seat > 0){
						printf("Welcome to MGM Airlines!\n");
						printf("Please type 1 for \"first class\"\nPlease type 2 for \"economy\" : ");
						scanf("%d", &choice);
					}else{
						dymExit();
						printf("All seats are taken, please wait... Next flight leaves in 3 hours.");
						break;
					}
				}else{
					dymExit();
					printf("Please wait... Next flight leaves in 3 hours.");
					break;
				}
			}
		}else if(choice == 2){
			int seat = assignSeat(seats, 2);
			if(seat > 0){
				boardPass(seat);
			}else{
				printf("\nEconomy Section is full, do you wish to move to the First Class Section?");
				printf("\nPress Y for yes | N for no: ");
				
				char decision;
				scanf(" %c", &decision);
				
				if(decision == 'Y' || decision == 'y'){
					int seat = assignSeat(seats, 1);
					boardPass(seat);
					displaySeats(seats, 10);
					seat = assignSeat(seats, 1);
					
					if(seat > 0){
						printf("Welcome to MGM Airlines!\n");
						printf("Please type 1 for \"first class\"\nPlease type 2 for \"economy\" : ");
						scanf("%d", &choice);
					}else{
						dymExit();
						printf("All seats are taken, please wait... Next flight leaves in 3 hours.");
						break;
					}
				}else{
					dymExit();
					printf("Please wait... Next flight leaves in 3 hours.");
					break;
				}
			}
		}else{
			printf("Invalid input\n");
		}
	}
	
	return 0;
}
