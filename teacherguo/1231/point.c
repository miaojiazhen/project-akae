#include <stdio.h>
#include <stdlib.h>
void m(char **p)
{
    char *x=(char *)malloc(100);
    *p=x;
}
int main(int argc, const char *argv[])
{
    char *p=NULL;
    m(&p);
    printf("%p\n",p);
    return 0;
}
