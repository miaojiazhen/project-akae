#include <stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node *next;
};
struct node *creat(struct node *op,int num)
{
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->next=op;
    p->num=num;
    return p;
}
void show(struct node *p,int n)
{
    int i=0;
    while(1)
    {
        printf("%d\n",p->num);
        p=p->next;
        i++;if(i==n)break;
    }
}

int main(int argc, const char *argv[])
{
    struct node *p,*head;
    p=creat(NULL,1);
    p->next =p;
    p = p->next = creat(p->next,2);
    p = p->next = creat(p->next,3);
    show(p->next,6);
    return 0;
}
