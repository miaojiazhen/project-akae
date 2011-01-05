#include <stdio.h>
#include <stdarg.h>
char add(int num,...)
{
    char x,i,res=0;
     
    va_list ap;
    va_start(ap,num);
    //printf("%x\n",&num);
    //printf("num =%d\n",num);
    //printf("%x\n",ap);
    //printf("%d\n",*(char *)ap);
    for(i=0;i<num;i++)
    {
        res += va_arg(ap,int);
        printf("abc");
        //printf("%x\n",ap);
        //printf("%d\n",*(char *)ap);
    }
    va_end(ap);
    return res;
}
int main(int argc, const char *argv[])
{
    char a=1,b=2,c=3,d=4;
    int t=4;
    printf("%d\n",add(t,a,b,c,d));    
    return 0;
}
