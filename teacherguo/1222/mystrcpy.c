#include <stdio.h>
char *mystrcpy(char *a,const char *b)
{
    char *temp=a;
    while(*temp++ = *b++);
    return a;
}
int mystrlen(const char *b)
{
    int i=0;
    while(*(b+(i++)));
    return i-1;
}
int main(int argc, const char *argv[])
{
    char a[100];
    char s[]="haohaohao";
    mystrcpy(a,"abcdef");
    printf("%s\n",mystrcpy(a,"i love you "));
    printf("%d\n",mystrlen(s));
    return 0;
}
