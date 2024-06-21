/*#include <stdio.h>

int main()
{
    char lol = 'a';
    printf("%c", lol);
}*/

/*
int main()
{
    printf("WASSSUP DYM");
    return 0;
}*/

/*int main(){
    FILE *pF = fopen("C:\\Users\\User\\Desktop\\C Files\\test.txt", "r");

    char buffer [255];

    while(fgets(buffer, sizeof(buffer), pF) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(pF);

    return 0;
}*/

/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(0));

    int num = (rand()%6)+1;

    printf("%d", num);

    return 0;
}*/

/*GUESSING GAME
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int guess(int* a);
struct Player player1Name();
struct Player player2Name();

struct Player{
    char name [50];
};

int main(){

    const int min = 1;
    const int max = 100;
    int temp, answer, p1, p2;
    struct Player player1, player2;
    player1 = player1Name();
    player2 = player2Name();

    srand(time(0));

    answer = (rand()%max)+min;
    temp = answer;

    printf("%s is up!\n", player1.name);
    p1 = guess(&temp);
    printf("%s is up!\n", player2.name);
    p2 = guess(&temp);

    printf("Answer: %d\n%s Guesses: %d\n%s Guesses: %d\n", answer, player1.name, p1, player2.name, p2);
    (p1<p2) ? printf("%s WINS!\n", player1.name) : printf("%s WINS!\n", player2.name);
    
    system("PAUSE");
    return 0;
}

struct Player player1Name(){
    struct Player p1;
    printf("Enter Player 1: ");
    scanf("%s", p1.name);
    return p1;
}

struct Player player2Name(){
    struct Player p2;
    printf("Enter Player 2: ");
    scanf(" %s", p2.name);
    return p2;
}

int guess(int* a){
    int guess, guesses = 0;
    do{
        printf("Guess: ");
        scanf("%d", &guess);
        if(guess>*a){
            printf("TOO HIGH!\n");
        }
        else if(guess<*a){
            printf("TOO LOW\n");
        }
        else{
            printf("YOU GUESSED IT!\n");
        } 
        guesses++;
    }while(guess != *a);
    return guesses;
}*/

/* TYPEDEF AND ENUM
#include <stdio.h>
#include <string.h>

typedef struct{
    char name [20];
    int score;
} Player;

typedef enum{Goated = 100, Excellent = 90, Good = 80, GetGud = 70} Grades;

int main(){

    Player player1 = {"Dymier", 13};
    Player player2 = {"Melanie", 14};
    Player players[] = {player1, player2};

    for(int i = 0; i < sizeof(players)/sizeof(players[0]); i++){
        printf("%-6s\t", players[i].name);
        printf("%d\n", players[i].score);
    }

    printf("%d", Goated);

    return 0;
}*/

/*#include <stdio.h>
#include <string.h>

char lol(int res){

    char ans;

    if (res == 1)
    {
        ans = 'N';
    } else {
        ans = 'Y';
    }
     ;

    return ans;

}

int main(){

    char a[] = "gyyy";
    char b[] = "lmao";

    int ttete = strnicmp(a,b, 1);

    char answer = lol(ttete);

    printf("%c", answer);

}
*/

/*// C program for Merge Sort
#include <stdio.h>
#include <stdlib.h>

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l,
		int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays
	// L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	// Merge the temp arrays back
	// into arr[l..r]
	// Initial index of first subarray
	i = 0;

	// Initial index of second subarray
	j = 0;

	// Initial index of merged subarray
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements
	// of L[], if there are any
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of
	// R[], if there are any
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted
void mergeSort(int arr[],
			int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids
		// overflow for large l and h
		int m = l + (r - l) / 2;

		// Sort first and second halves
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);

		merge(arr, l, m, r);
	}
}

// UTILITY FUNCTIONS
// Function to print an array
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

// Driver code
int main()
{
	int arr[] = {4,2,1,3,5,7,8,6,9};
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	printf("Given array is \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}*/


// BUBBLE SORT
#include <stdio.h>

void ayy(int lol[], int lmao){

    for(int i = 0; i < lmao - i - 1; i++){
        for(int j = 0; j < lmao - i - 1; j++){
            if(lol[j]>lol[j+1]){
                int temp = lol[j];
                lol [j] = lol [j+1];
                lol [j+1] = temp;
            }
        }
    }

}

void moai(int lol[], int lmao){
    for(int i = 0; i < lmao; i++){
        printf("%d ",lol[i]);
    }
}

int main (){

    int lol[] = {4,2,1,3,5,7,8,6,9};
    int lmao = sizeof(lol)/sizeof(lol[0]);

    ayy(lol, lmao);
    
    moai(lol, lmao);

}

/*SELECTION SORT
#include <stdio.h>

void ayy(int lol[], int lmao){

    for(int i = 0; i < lmao; i++){
        int min = i;
        for(int j = i + 1; j < lmao - 1; j++){
            if(lol[j]<lol[min]){
                min = j;
            }
        }
        if (min != i){
            int temp = lol[i];
            lol [i] = lol[min];
            lol [min] = temp;
        }
    }

}

void moai(int lol[], int lmao){
    for(int i = 0; i < lmao; i++){
        printf("%d ",lol[i]);
    }
}

int main (){

    int lol[] = {4,2,1,3,5,7,8,6,9};
    int lmao = sizeof(lol)/sizeof(lol[0]);

    ayy(lol, lmao);
    
    moai(lol, lmao);

}*/

/* INSERTION SORT
#include <stdio.h>

void ayy(int lol[], int lmao){

    for(int i = 1; i < lmao; i++){
        int temp = lol[i];
        int j = i - 1;
        
        while(j >= 0 && lol[j] > temp){
            lol[j+1] = lol[j];
            j--;
        }
        lol[j+1] = temp;
    }

}

void moai(int lol[], int lmao){
    for(int i = 0; i < lmao; i++){
        printf("%d ",lol[i]);
    }
}

int main (){

    int lol[] = {4,2,1,3,5,7,8,6,9};
    int lmao = sizeof(lol)/sizeof(lol[0]);

    ayy(lol, lmao);
    
    moai(lol, lmao);

}*/

