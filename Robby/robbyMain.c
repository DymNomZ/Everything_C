#include <stdio.h>
#include <ctype.h>
#include <windows.h>
#include "robby.h"

int main(){
	int x, y;
	char choice;
	initialize(&x, &y);
	while(choice != 'd'){
		choice = tolower(printCommand());
		switch (choice) {
			case 'a':
				initialize(&x, &y);
				break;
			case 'b':
				printLocation(x, y) ;
				break;
			case 'c':
				move(&x, &y);
				break;
			case 'd':
				Exit();
				break;
				
		}
	}
	
	return 0;
}
