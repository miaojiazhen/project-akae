#include <stdio.h>
void sort(int *p,int len)
{
    int temp,i,j;
    for(j=0;j<len-1;j++)
    {
        for(i=j+1;i<len;i++)
        {
            if(*(p+j) > *(p+i))
            {
            }
            else 
            {
                temp = *(p+j);
                *(p+j) = *(p+i);
                *(p+i) =temp;
            }
        }
    }
}
int main(int argc, const char *argv[])
{
    int a[10]={0,3,2,4,5,1,9,8,7,6},i;
    sort(a,10);
    for(i=0;i<10;i++)
    {
        printf("%d  ",a[i]);
    }
    printf("\n");
    return 0;
}
