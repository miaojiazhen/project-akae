#include <stdio.h>

int main(int argc, const char *argv[])
{
    int *p[4],a=10,i;
    char c[10]={1,2,3,3},op;
    p[0]=&a;
    c[9]='\0';
    p[1]=(int *)c;
    op=a;
    printf("%d\n",op);
    for(i=0;i<10;i++)
    printf("%d\n",*(((char *)p[1])+i) );
    printf("%d\n",*((char *)p[1]) );
    return 0;
}
