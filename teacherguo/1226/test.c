#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void foo(char **p)
{
    *p=(char *)malloc(100);
}
int main(int argc, const char *argv[])
{
    char *p="hello"; 
    char a[]="world";
    char (*b)[10];
    int xx=5;
    (*b)[0]=&xx;
    printf("%d\n",(*b)[0]);
    printf("%d\n",sizeof(b));
    printf("%c\n",*p);
    printf("%s\n",a);
    return 0;
}
