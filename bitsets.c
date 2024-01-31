#include <stdio.h>
#define MAX 10

typedef int BitSet[MAX];

void initialize(BitSet s1, BitSet s2); //✅
void display(char* name1, char* name2, BitSet s1, BitSet s2); //✅
void display2(BitSet result); //✅
void display3(BitSet result); //✅
void display4(BitSet result); //✅
void add(BitSet temp, int x); //✅
void addInput(BitSet s1, BitSet s2, int x); //✅
int cardinality(BitSet temp); //✅
int isEmpty(BitSet temp); //✅
void printEmpty(int count); //✅
int isSubset(BitSet s1,BitSet s2, int card2); //✅
void printSubset(int count); //✅
int areDisjoint(BitSet s1,BitSet s2); //✅
void printDisjoint(int count); //✅
void getUnion(BitSet result,BitSet s1,BitSet s2); //✅
void getIntersection(BitSet result,BitSet s1,BitSet s2); //✅
void getDifference(BitSet result,BitSet s1,BitSet s2); //✅
int isUniversal(BitSet temp); //✅
void printUniversal(int count); //✅

int main()
{
    BitSet result, s1, s2;
    int x, count;
    initialize(s1, s2);
    display("s1", "s2", s1, s2);
    addInput(s1, s2, x);
    display("s1", "s2", s1, s2);

    int card1 = cardinality(s1);
    int card2 = cardinality(s2);
    printf("Cardinality of s1: %d\n", card1);
    printf("Cardinality of s2: %d\n", card2);

    printf("Is s1 empty? ");
    count = isEmpty(s1);
    printEmpty(count);
    printf("Is s2 empty? ");
    count = isEmpty(s2);
    printEmpty(count);

    printf("Is s2 a subset of s1? ");
    count = isSubset(s1, s2, card2);
    printSubset(count);

    printf("Is s1 and s2 disjointed sets? ");
    count = areDisjoint(s1, s2);
    printDisjoint(count);

    getUnion(result, s1, s2);
    display2(result);

    getIntersection(result, s1, s2);
    display3(result);

    getDifference(result, s1, s2);
    display4(result);

    printf("Is s1 a universal set? ");
    count = isUniversal(s1);
    printUniversal(count);
    printf("Is s2 a universal set? ");
    count = isUniversal(s2);
    printUniversal(count);

    return 0;
}

void initialize(BitSet s1, BitSet s2)
{
    for (int i=0; i < MAX; i++)
    {
        s1[i] = 0;
        s2[i] = 0;
    } 
}

void display(char* name1, char* name2, BitSet s1, BitSet s2)
{
    printf("\n%s = {", name1); 
    for (int i=0; i < MAX; i++)
    {
        if (s1[i])
        {
            printf("%d ",i);
        }    
    }   
    printf("}");
    printf("\n%s = {", name2); 
    for (int i=0; i < MAX; i++)
    {
        if (s2[i])
        {
            printf("%d ",i);
        }    
    }   
    printf("}\n");
}

void addInput(BitSet s1, BitSet s2, int x)
{
    for(int i = 0; i<MAX; i++)
    {
        printf("Enter numbers for s1(if that is all, enter the rest as any number above 10): ");
        scanf("%d", &x);
        add(s1, x);
    }
    for(int i = 0; i<MAX; i++)
    {
        printf("Enter numbers for s2(if that is all, enter the rest as any number above 10): ");
        scanf("%d", &x);
        add(s2, x);
    }
}

void add(BitSet temp, int x)
{
    if (x >=0 && x < MAX)
    {
        temp[x] = 1;
    }    
}

int cardinality(BitSet temp)
{
    int count = 0;
    for(int i = 0; i<MAX; i++)
    {
        if(temp[i])
        {
            count++;
        }
    }
    return count;
}

int isEmpty(BitSet temp)
{
    int count = 0;
    for(int i = 0; i<MAX; i++)
    {
        if(temp[i]==1)
        {
            count = 1;
            break;
        }
    }
    return count;
}

void printEmpty(int count)
{
    if(count==0)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}

int isSubset(BitSet s1,BitSet s2, int card2)
{
    int count = 0;
    int ans = 0;
        for(int i = 0; i<MAX; i++)
        {
            if(s2[i]&&s1[i])
            {
                count++;
            }
        }
    if(count!=card2)
    {
        ans = 1;
    }
    return ans;
}

void printSubset(int count)
{
    if(count==0)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}

int areDisjoint(BitSet s1, BitSet s2)
{
    int count = 0;
        for(int i = 0; i<MAX; i++)
        {
            if(s2[i]&&s1[i])
            {
                count = 1;
                break;
            }
        }
    return count;
}

void printDisjoint(int count)
{
    if(count==0)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}

void getUnion(BitSet result,BitSet s1,BitSet s2)
{
    for(int i=0; i< MAX; i++)
    {
        result[i] = s1[i] || s2[i];
    }
}

void display2(BitSet result)
{
    printf("\ns1 U s2 = {"); 
    for (int i=0; i < MAX; i++)
    {
        if (result[i])
        {
            printf("%d ",i);
        }    
    }   
    printf("}\n");
}

void getIntersection(BitSet result, BitSet s1, BitSet s2)
{
    for(int i=0; i< MAX; i++)
    {
        result[i] = s1[i] && s2[i];
    }
}

void display3(BitSet result)
{
    printf("\ns1 n s2 = {"); 
    for (int i=0; i < MAX; i++)
    {
        if (result[i])
        {
            printf("%d ",i);
        }    
    }   
    printf("}\n");
}

void getDifference(BitSet result, BitSet s1, BitSet s2)
{
    for(int i=0; i< MAX; i++)
    {
        result[i] = s1[i] - s2[i];
    }
}

void display4(BitSet result)
{
    printf("\ns1 - s2 = {"); 
    for (int i=0; i < MAX; i++)
    {
        if (result[i])
        {
            printf("%d ",i);
        }    
    }   
    printf("}\n");
}

int isUniversal(BitSet temp)
{
    int count = 0;
    int ans = 0;
    for(int i=0; i< MAX; i++)
    {
        if(temp[i])
        {
            count++;
        }
    }
    if(count==MAX)
    {
        ans = 1;
    }
    return ans;
}

void printUniversal(int count)
{
    if(count==1)
    {
        printf("yes\n");
    }
    else
    {
        printf("no\n");
    }
}