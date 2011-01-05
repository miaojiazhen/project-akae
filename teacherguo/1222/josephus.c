#include <stdio.h>
#define N 10
#define M 3
struct people
{
    int id;
    int out;
};
struct people a[N];
int main(int argc, const char *argv[])
{
    int i,j,num=N;
    int n=10,m=3;
    for(i=0;i<10;i++)
    {
            a[i].id=i+1;
            a[i].out=0;
    }
    for(i=0;i<N;i++)
    {
        printf("people = %d out =%d \n",a[i].id,a[i].out);
    }
    i=0;
    while(num!=1)
    {
        for(n=0;n<M;)
        {
            if(a[i].out==0)n++;
            if(n==M){a[i].out=1;printf("out %d \n",a[i].id);}
            i++;if(i==N)i=0;
        }
        num--;
    }      
    for(i=0;i<N;i++)
    {
        if(a[i].out==0)
        printf("the last people is %d \n",a[i].id);
    }
    for(i=0;i<N;i++)
    {
        printf("people = %d out =%d \n",a[i].id,a[i].out);
    }
    return 0;
}
