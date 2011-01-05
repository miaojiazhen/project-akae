#include <stdio.h>
void print_flag()
{
    printf("* ");
}
void  print_a(int x)
{
    int i,j;
    for(i=0;i<x;i++)
    {
        for(j=0;j<x;j++)print_flag();
        printf("\n");
    }
}
int main(int argc, const char *argv[])
{
    int number=6;
    void (*p1)(int );
    p1=print_a;
    (*p1)(number);
    return 0;
}
