#include <stdio.h>

int main(int argc, const char *argv[])
{
    int *p[4];
    char c[10]={1,2,3,4,5,6,7},*q;
    p[1]=(int *)c;
    q=(char *)p[1];
    printf("%d %d %d \n",*q,*(q+1),*(q+3));
    printf("%d \n",*((char *)p[1]));
    return 0;
}
