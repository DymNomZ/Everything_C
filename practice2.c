#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>


/*struct point 
{
    int x, y;
};

struct rectangle
{
    struct point upper_left, lower_right;
}r;

int area(struct rectangle);

int main()
{
    printf("Enter upper left coords: ");
    scanf("%d %d", &r.upper_left.x, &r.upper_left.y);
    printf("Enter lower right coords: ");
    scanf("%d %d", &r.lower_right.x, &r.lower_right.y);

    int ans = area(r);

    printf("Upper right coords: %d %d\n", r.lower_right.x, r.upper_left.y);
    printf("Lower left coords: %d %d\n", r.upper_left.x, r.lower_right.y);
    printf("%d", ans);


    return 0;
}

int area(struct rectangle r)
{
    int length = abs(r.upper_left.x - r.lower_right.x);
    int width = abs(r.upper_left.y - r.lower_right.y);
    int area = length * width;
    return area;
}*/


/*struct info
    {
        char name[50];
        char fruit[50];
        int bounty;
    };

struct info enter();

int main()
{
    struct info player[3];

    player[0] = enter();
    player[1] = enter();
    player[2] = enter();

    for(int i = 0; i < 3; i++)
    {
    printf("%s\n", player[i].name);
    printf("%s\n", player[i].fruit);
    printf("%d", player[i].bounty);
    }

    return 0;
}

struct info enter()
{
    struct info p;

    printf("Enter player name: ");
    scanf(" %[^\n]s", p.name);
    printf("Enter fruit: ");
    scanf(" %[^\n]s", p.fruit);
    printf("Enter bounty: ");
    scanf("%d", &p.bounty);
    return p;
}*/
