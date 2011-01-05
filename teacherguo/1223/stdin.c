#include <stdio.h>
#include<stdlib.h>
int main(int argc, const char *argv[])
{
    int x,i=0,len=0,n=1,j=1;
    int *p;
    p=(int *)malloc(40);
    if(p==NULL)return 1;
    while(1)
    {
    scanf("%d",&x);
    if(x==-1)break;
    *(p+len)=x;
    len++;if(len==j*10){j++;p=realloc(p,j*40+40);}
    //if(len>=20){printf("more\n");break;}
    }
    for(i=0;i<len;i++)
    {
        printf("%d\t",*(p++));
        if(n%5==0){printf("\n");}
        n++;
    }
    printf("\n");
    return 0;
}
