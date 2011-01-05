#include <stdio.h>
//typedef int (*fun_x)(int ,int );
int add(int x,int y)   {    return x+y;}
int sub(int x,int y)   {    return x-y;}
int mul(int x,int y)   {    return x*y;}
int dev(int x,int y)   {    return x/y;}
int mod(int x,int y)   {    return x%y;}
struct cmd
{
    char op;
    int (*fun_x)(int ,int );
};
struct cmd arr[]=
{
      {'+',add},
      {'-',sub},
      {'*',mul},
      {'/',dev},
      {'%',mod}
};
int main(int argc, const char *argv[])
{
    int a=2,b=3,res,i;
    char op,t;
    while(1)
    {
        //scanf("%c",&op);
    op=getchar();
    if(op=='#')break;
    printf("flag");
    scanf("%d %d",&a,&b);
    getchar();
        for(i=0;i<5;i++)
        {
        if(arr[i].op==op)
        res=arr[i].fun_x(a,b);
        }
        //t=getchar();
        printf("res = %d\n",res);
    }
    return 0;
}
