#include <stdio.h>
//typedef int myint;
typedef int (*fun_t)(int ,int );

int add(int a,int b)
{
    return a+b;
}
int main(int argc, const char *argv[])
{
    int c;
    fun_t p1;
    p1=add;
    c= p1(1,2);
    printf("%d\n",c);
    return 0;
}
