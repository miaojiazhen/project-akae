#include <stdio.h>
typedef int (*fun_x)(int ,int );
int add_two(int x,int y){   return x+y;}
int jian(int x,int y)   {    return x-y;}
int cheng(int x,int y)  {    return x*y;}
int chu(int x,int y)    {    return x/y;}
int main(int argc, const char *argv[])
{
    int a=2,b=3,res;
    char flag,end;
    while(1)
    {
        printf("putin flag : ");
        scanf("%c",&flag);
        if(flag=='#')break;
        if(flag=='+')
        {
            scanf("%d %d",&a,&b);
            fun_x p1;
            p1=add_two;
            res=p1(a,b);
            printf("res = %d\n",res);
        }
        if(flag=='-')
        {
            scanf("%d %d",&a,&b); 
            fun_x p2;
            p2=jian;
            res=p2(a,b);
            printf("res = %d\n",res);
        }
        if(flag=='*')
        {
            scanf("%d %d",&a,&b);
            fun_x p3;
            p3=cheng;
            res=p3(a,b);
            printf("res = %d\n",res);
        }
        if(flag=='/')
        {
            scanf("%d %d",&a,&b);
            fun_x p4;
            p4=chu;
            res=p4(a,b);
            printf("res = %d\n",res);
        }
    }
    //fun_x p1;
    //p1=add_two;
    //res=p1(a,b);
    //printf("%d\n",res);
    return 0;
}
