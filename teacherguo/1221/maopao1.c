#include <stdio.h>
int sort_int(void *o,void *p)
{
    int temp;
    if(*((int *)o) > *((int *)p) ){}
    else 
    {
    temp = *((int *)o);
    *((int *)o) = *((int *)p);
    *((int *)p) = temp;
    }
}
int sort_char(void *o,void *p)
{
    char temp;
    if(*((char *)o) > *((char *)p) ){}
    else 
    {
    temp = *((char *)o);
    *((char *)o) = *((char *)p);
    *((char *)p) = temp;
    }
}
void sort(void *p,int len,int size,int (*fun)(void *o,void *p))
{
    int i,j;
    for(j=0;j<len-1;j++)
    {
        for(i=j+1;i<len;i++)
        {
        fun((p+(j*size)),(p+(i*size)) );
        }
    }
}
int main(int argc, const char *argv[])
{
    int a[10]={0,3,2,4,5,1,9,8,7,6},i;
    char b[10]={11,3,15,33,55,34,23,21,28,1};
    sort(b,10,1,sort_char);
    for(i=0;i<10;i++)
    {
        printf("%d  ",b[i]);
    }
    printf("\n");
    return 0;
}
