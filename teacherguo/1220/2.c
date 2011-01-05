#include <stdio.h>
#include <string.h>
union day
{
    int a;
    char b;
    char c[20];
};
union day day1;
int main(int argc, const char *argv[])
{
    day1.a=121;
    day1.b='d';
    strcpy(day1.c,"abc");
    printf("%x\n",day1.a);
    printf("%c\n",day1.b);
    return 0;
}
