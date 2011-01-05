#include <stdio.h>
void print_b(void)
{
    int i,b[32],a;
    int temp=0;
    printf("Please input a number :\n");
    scanf("%d",&a);
    getchar();
    for(i=0;i<32;i++)
    {
        b[i]=a&0x01;
        a= a>>1;
    }
    printf("the binary is:");
    for(i=31;i>=0;i--)
    {
        printf("%d",b[i]);
    }
    printf("\n");
}
void  mul(void)
{
    int c=0,temp,flag;
    int i,len=sizeof(int)*8;
    int a,b;
    printf("Please input x y:\n");
    scanf("%d %d",&a,&b);
    getchar();
    for(i=0;i<len;i++)
    {
        flag=b>>i&0x01;
        if(flag==1)
        {
            temp=a<<i;
            c=c+temp;
        }
    }
    printf("%d * %d = %d\n",a,b,c);
}
void encryption(void)
{
    char c='&',en,a;
    printf("Please input a char:");
    scanf("%c",&a);
    getchar();
    en=a^c;
    if(en==' '|| en ==10|| en =='\t'|| en =='\0')
        printf("invisible\n");
    else
    printf("After encryption :%c\n",en);
}
void info(void)
{
    printf("\n\n\n");
    printf("1.decimal to binary \n");
    printf("2.x*y \n");
    printf("3.low or up exchange\n");
    printf("4.encryption \n");
    printf("5.EXIT\n");
    printf("Please choose [1-5]:");
}
void exchange_s(void)
{
    char a[256],x;
    int i=0;
    x='a'-'A';
    printf("Please input string :\n");
    scanf("%s",a);
    getchar();
    while(a[i])
    {
        if(a[i]>='a'&& a[i]<='z')
        {
            a[i]-=x;
        }
        else 
        {
            a[i]+=x;
        }
        i++;
    }
    printf("%s\n",a);
}
void continu(void)
{
    char a=0;
    printf("Please input ENTRY to continue:");
    while(1)
    {
        a=getchar();
        if(a==10){a=0;break;}
    }
}
int main(int argc, const char *argv[])
{
    int flag=0;
    while(1)
    {
        info();
        scanf("%d",&flag);
        getchar();
        if(flag==1)
        {
            print_b();    
            continu();
        }
        if(flag==2)
        {
            mul();
            continu();
        }
        if(flag==3)
        {
            flag=0;
            exchange_s();
            continu();
        }
        if(flag==4)
        {
            encryption();
            continu();
        }
        if(flag==5)
        {
            break;
        }
    }
    return 0;
}
