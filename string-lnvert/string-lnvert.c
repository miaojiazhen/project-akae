#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a[100],temp;
    int *pa,i=0,j=0,k=0,num=0,word=0,aleng=0,abit=0;
    pa=a;
    gets(a);
    printf("%s\n",a);
    while(a[i]!='\0')                  //srue to string length 
    {
        abit++;
        i++;
    }
    aleng=abit;                       //abit store string length
    num=(abit)/2;
    for(i=0,aleng--;i<num;aleng--,i++)      //whole string lnvert
    {
    temp=a[i];
    a[i]=a[aleng];
    a[aleng]=temp;
    }
//   a[0]=temp;
    i=0;   
/*****************  each  word lnvert      **********************************/

    while(i<=abit)
    {
        k=i;
        while(a[i]!=' '&a[i]!='\0')                 //sure the length of word
        {
        i++;
        }
        aleng=i;
        
        num=((aleng-k)/2+k);
        for(j=k,aleng--;j<num;aleng--,j++)          //word lnvert
        {
        temp=a[j];
        a[j]=a[aleng];
        a[aleng]=temp;
        }
        i++;
     }
    printf("%s\n",a);
    //printf("%s\n",a);
    //printf("%d\n",aleng);
    return 0;
}
