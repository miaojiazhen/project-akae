#include <stdio.h>

int a;
int add(int x,int y)
{
    printf("&x = %p\n",&x);
    return x+y;
}
int (*fun2)(int ,int );
int main(int argc, const char *argv[])
{
    int res;
    int (*fun1)(int , int );
    fun1=add;
    res=(*fun1)(1,2);
    printf("%d\n",res);
    printf("&res = %p\n",&res);
    printf("fun1 = %p\n",fun1);
    printf("fun2 = %p\n",fun2);
    printf("&res = %x\n",&res);
    printf("fun1 = %x\n",fun1);
    printf("fun2 = %x\n",fun2);
    printf("&a = %p\n",&a);
    return 0;
}
