void convertTime(int time, int* hours, int* mins, int* sec){
    *hours = time / 3600;
    *mins = (time % 3600) / 60;
    *sec = (time % 3600) % 60;
}

void displayTime(int time, int* hours, int* mins, int* sec){
    printf("displays %d seconds is equal to %d hour(s), %d minute(s) and %d second(s).", time, *hours, *mins, *sec);
}

void computeCoin(int coinValue, int* quarter, int* dime, int* penny){
    *quarter = coinValue / 25;
    *dime = (coinValue % 25) / 10;
    *penny = (coinValue % 25) % 10;
}

void displayCoin(int coinValue, int* quarter, int* dime, int* penny){
    printf("%d cents can be given as %d quarter(s) %d dime(s) and %d penny (pennies)", coinValue, *quarter, *dime, *penny);
}