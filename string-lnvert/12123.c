#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a[]="HELLO to WORLD",temp;
    int *pa,i=0,j=0,k=0,num=0,word=0;
    pa=a;
    printf("%s\n",a);
    while(a[i]!='\0')
    {
        i++;
        if(a[i]==' '){word++;}
    }
 while(word)
 {word--;
    i=0;
    while(a[i]!=' ')
    {
    i++;
    }
    k=i;
    
    i=0;
    for(j=0;j<k;j++,i=0)
    {
    temp=a[i];
         while(num<k)
         {   
            a[i]=a[++i];
            num++;
         }
    a[num]=temp;num=0;
    }
    //printf("%s\n",a);

    for (i=0,j = 0;j<=k;i=0, j++) 
    {
        temp=a[i];
        while(a[i]!='\0')
        {
        a[i]=a[++i];
        }
        i-=1;
        a[i]=temp;
    }
 }    
    printf("%s\n",a);

    return 0;
}
