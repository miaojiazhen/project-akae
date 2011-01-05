#include <stdio.h>

int cmp_int(void *o,void *p)
{
    return *((int *)o) - *((int *)p);
}
int cmp_char(void *o,void *p)
{
    return *((char *)o) - *((char *)p);
}
void * get_max(void *a,int size,int len,int (*cmp_t)(void *x,void *y))
{
    int i;
    void *max;
    max=a;
            for(i=1;i<=10;i++)
            {
                if(cmp_t(max,a+i*size) >= 0){}
                else max = a+i*size;
            }
    return max;
}

int main(int argc, const char *argv[])
{
    int a[10]={1,5,3,6,8,10,0,88,77,11};   
    char b[10]={2,5,4,7,11,15,2,8,9,0};
    void *res;
    res = get_max(b, 1, 10, cmp_char);
    printf("max = %d\n",*((char *)res) );
    return 0;
}
