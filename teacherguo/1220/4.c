#include <stdio.h>
void print_1(void)
{
    printf("* ");
}
void print_2(void (*fun)(void),int x)
{
    int i,j;
    for(i=0;i<x;i++)
    {
        for(j=0;j<x;j++){fun();}
        printf("\n");
    }    
}
int main(int argc, const char *argv[])
{
    print_2(print_1,5);
    return 0;
}
