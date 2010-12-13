#include <stdio.h>
int main(int argc, const char *argv[])
{
    int i=0,j=0x1f,res=0,bit,abit,x=0,y=0,a1=0,a2=0;
    char a[10],b[10],c[50],temp;
    gets(a);                                    //stdin a
    gets(b);                                    //stdin b                    
   while(a[i]!='\0')                    //exchange a[] to 0x
    {
    i++;
    }
    bit=i;
    abit =i;
    bit=0;
    for(i=0;i<abit;i++,bit++)
    {
        if(a[bit]>47&a[bit]<58)
        {
        x=(a[bit]-48);
        }
        if(a[bit]>96&a[bit]<103)
        {
        x=a[bit]-87;
        }
        a1=(a1<<4)|x; 
    }        
    i=0;
   while(b[i]!='\0')                    //change b[] to 0x
    {
    i++;
    }
    bit=i;
    abit =i;
    bit=0;
    for(i=0;i<abit;i++,bit++)
    {
        if(b[bit]>47&b[bit]<58)
        {
        x=(b[bit]-48);
        }
        if(b[bit]>96&b[bit]<103)
        {
        x=b[bit]-87;
        }
        a2=(a2<<4)|x; 
    }  
    res=a1+a2;
    printf("a1=%x a2=%x\n",a1,a2);
    printf("a1+a2=0x%x\n",res);           //the result of a1+a2 is 0x
    for(bit=0,i=0;i<8;i++)                //change result to c[]
    {
    bit=i*4;
        temp=0x0f&res>>bit;
        if(temp<10&temp>=0)
        {
        temp=temp+48;
        }
        if(temp>=10&temp<16)
        {
        temp=temp+87;
        }
        c[i]=temp;
    }
    c[8]='\0';
    j=7;
    for(i=0;i<4;i++)
    {
    temp=c[i];
    c[i]=c[j];
    c[j]=temp;
    j--;
    }
    printf("a1+a2=c[]=%s\n",c);
    //fgets(a,100,stdin);
    //scanf("%s",a);   
    //printf("\n%x\n",res);
    return 0;
}
