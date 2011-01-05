#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stu
{
    int id;
    int chinese;
    char name[256];
    struct stu *next;
};

struct stu *creat(struct stu *pro, int id, int chinese, char *name)
{
    struct stu *p = (struct stu*)malloc(sizeof( struct stu));
    p->id = id;
    p->chinese =chinese;
    strcpy(p->name,name);
    p->next =NULL;
    pro->next = p;
    return p;
}
void bianli(struct stu *op)
{
    while(op)
    {
        printf("%d %d %s \n",op->id,op->chinese,op->name);
        op = op->next;
    } 
}
struct stu * fr(struct stu *op, int id)
{
    struct stu *temp,*head;
    head = op;
    if(op->id==id)
    {
         head = op->next;
         free(op);
         op=NULL;
         return head;
    }
    else
    {
        while(op)
        {
            if(op->next->id ==id)
            {
                temp =op->next->next;
                free(op->next);
                //op->next=NULL;
                op->next=temp;
                return head;
                break;
            }
            op = op->next;
        }
    }
}
void insert_next(struct stu *op,int id,int newid,int chinese,char *s)
{
    struct stu *temp,*stru;
    stru = (struct stu *)malloc(sizeof(struct stu));
    stru->id = newid;
    stru->chinese = chinese;
    strcpy(stru->name,s);
    while(op)
    {
        if(op->id == id)
        {
            temp = op->next;
            op->next = stru;
            stru->next = temp;
            break;
        }
        op = op->next;
    }
}
struct stu *insert_b(struct stu *op ,int id, int newid, int chinese, char *s)
{
    printf("****************************\n");
    struct stu *temp, *stru, *head=op;
    stru = (struct stu *)malloc(sizeof(struct stu));
    stru->id = newid;
    stru->chinese = chinese;
    strcpy(stru->name,s);
    if(op->id == id)
    {
        stru->next = op;
        return stru;
    }
    while(op)
    {
    printf("################\n");
    if(op->next==NULL){printf("the id not\n");return head;}
        if(op->next->id == id)
        {
            temp = op->next;
            op->next = stru;
            stru->next = temp;
            return head;
            //break;
        }
        op = op->next;
    }
    
}
int main(int argc, const char *argv[])
{
    struct stu *op,*head;
    head = (struct stu *)malloc(sizeof(struct stu));
    head->id = 1;
    head->chinese = 97;
    strcpy(head->name,"zhang");
    op=creat(head,2,60,"shazi");
    op=creat(op,3,60,"bendan");
    op=creat(op,4,70,"danben");
    op=creat(op,5,80,"haha");
    op=creat(op,6,90,"haha1");
    op=creat(op,7,100,"huakai");
    //head = fr(head,1); 
    //insert_next(head,3,8,59,"ladeng");
    head = insert_b(head,20,9,58,"ladeng");
    bianli(head);
    return 0;
}
