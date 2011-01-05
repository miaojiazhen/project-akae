#include <stdio.h>
#include <stdarg.h>
void myprintf(const char *format, ...)
{
    char *p;
    int i;
    va_list ap;
    va_start(ap,format);
    for(i=1;i<=3;i++)
    {
        p =va_arg(ap,char *);
        printf("%s\n",p);
    }
    va_end(ap);
}
int main(int argc, const char *argv[])
{
    myprintf("","how ","are ","you");
    return 0;
}
