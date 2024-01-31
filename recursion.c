#include <stdio.h>

int countPartitions(int n, int m)
{
    if (n==0)
    {
        return 1;
    }
    else if(m==0||n<0)
    {
        return 0;
    }
    else
    {
        return countPartitions(n-m, m) + countPartitions (n, m-1);
    }
}

int main()
{
    int n,m;
    printf("Enter: ");
    scanf("%d %d", &n, &m);
    int count = countPartitions(n,m);
    printf("%d", count);
}

/* FIND NUMBER OF POSSIBLE PATHS
int lol(int n, int m)
{
    int count = 1;
    if(n == 1|| m == 1) return count;
    count = (lol(n,m-1) + lol(n-1,m));
    return count;
}

int main()
{
    int n,m;
    printf("Enter: ");
    scanf("%d %d", &n, &m);
    int count = lol(n,m);
    printf("%d", count);
    return 0;
}*/

/* DIRECT RECURSION
int fun(int n)
{
    if(n==0)
    {
        return 1;
    }
    else
    {
        return n * fun(n-1);
    }
}

int main()
{
    int n;
    printf("Enter: ");
    scanf("%d", &n);
    printf("%d", fun(n));
}
*/