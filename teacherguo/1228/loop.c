#include <stdio.h>
#include <stdlib.h>
struct stu
{
    int item;
    struct stu *next;
};
struct stu *creat(struct stu *op, int num)
{
    struct stu *p =(struct stu *)malloc(sizeof(struct stu ));
    p->next =NULL;
    op->next = p;
    p->item =num;
    return p;
}
void show(struct stu *op,int n)
{
    int i=0;
    while(op)
    {
        
        printf("%d\n",op->item);
        op = op->next;
        i++;if(i==n)break;
    }
}
void jo(struct stu *op,int m)
{
    int n;
    struct stu *temp;
    while(op !=op->next)
    {
        for(n=2;n<m;n++)
        {
            op =op->next;
        }
        printf("%d\n",op->next->item);
        temp=op->next->next;
        free(op->next);op->next=NULL;
        op->next =temp;
        op=op->next;

    }
    printf("live %d\n",op->item);
}
int main(int argc, const char *argv[])
{
    int i;
    struct stu *p,*head = (struct stu *)malloc(sizeof(struct stu ));
    head->next =NULL;
    head->item =1;
    p=head;
    for(i=2;i<=10;i++)
    {
        p = creat(p,i);
    }
    p->next =head;
    jo(head,3);
    //show(head,20);

    return 0;
}
