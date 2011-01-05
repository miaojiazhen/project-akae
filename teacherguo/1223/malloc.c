#include <stdio.h>
#include <stdlib.h>
struct EXAM
{
    int k[5];
    int y;
};
struct EXAM exam;
int main(int argc, const char *argv[])
{
    struct EXAM *p;
    int i,j,len,num=0;
    p=(struct EXAM *)malloc(sizeof(exam)*10);
    if(p==NULL)return 4;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            (p+i)->k[j]=++num;
            (p+i)->y=55;
        }    
    }
    free(p);
    p=NULL;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
        printf( "exam[%d].k[%d]= %d   p->y = %d \n",i,j,(p+i)->k[j],p->y);
        }    
    }
    return 0;
}
