#include <stdio.h>
#include<stdlib.h>
struct stu
{
    int id;
    char name[100];
    int chinese;
    int math;
    int ave;
    struct stu *next;
};
void read_txt_c(const char *s,struct stu *p)
{
    struct stu *op,*temp;
    FILE *file1;
    file1 = fopen(s,"r");
    while(1)
    {
        fscanf(file1,"%d %s %d %d %d",&p->id,p->name,&p->chinese,&p->math,&p->ave);
        if(feof(file1)!=0)break;
        op =(struct stu *)malloc(sizeof(struct stu));
        temp =p;
        p->next =op;
        op->next =NULL;
        p=p->next;
    }
    free(p);
    temp->next=NULL;
    fclose(file1);
}
void write_txt(const char *s,struct stu *p,int m)
{
    int i=0;
    FILE *file1;
    file1 = fopen(s,"w");
    //fscanf(stdin,"%d %s %d %d",&id,name,&chinese,&math);
    for(i=0;i<m;i++)
    {
        fprintf(file1, "%d %s %d %d %d\n",p->id,p->name, p->chinese,p->math,p->ave);
        p++;
    }
    fflush(file1);
    fclose(file1);
    
}
void write_head_txt(struct stu *p)
{
    FILE *file1;
    file1 = fopen("a.txt","w");
    while(p)
    {
        fprintf(file1, "%d %s %d %d %d\n",p->id,p->name, p->chinese,p->math,p->ave);
        p=p->next;
    }
    fflush(file1);fclose(file1);
}
void creat(struct stu *p,int m)
{
    struct stu *op;
    int i;
    for(i=1;i<m;i++)
    {
        op = (struct stu *)malloc(sizeof(struct stu));
        op->next =NULL;
        p->next =op;
        p =p->next;
    }
}
struct stu *sort(struct stu *p)
{
    struct stu *p1,*op,*temp,*head1;
    
    head1 =(struct stu *)malloc(sizeof(struct stu));
    head1->next =NULL;
    p1 =head1;
    *head1 =*p;
    head1->next =NULL;
    temp=p->next;
    free(p);p=NULL;
    p=temp;
    while(p)
    {
        if(p->ave > head1->ave  )
        {
            op =(struct stu *)malloc(sizeof(struct stu));
            *op =* p;
            op->next = head1;
            head1 =op;
            temp=p->next;free(p);p=NULL;p=temp;continue;
        }
        p1=head1;
        while(p1->next !=NULL)
        {
            if(p->ave > p1->next->ave)
            {
                op =(struct stu *)malloc(sizeof(struct stu));
                *op =*p;
                op->next = p1->next;
                p1->next =op;
                temp=p->next;free(p);p=NULL;p=temp;
                break;
            }
            else { p1=p1->next;    }
        }
        if(p1->next ==NULL)
        {
            op =(struct stu *)malloc(sizeof(struct stu));
            *op =*p;
            op->next =NULL;
            p1->next =op;
            temp=p->next;free(p);p=NULL;p=temp;
        }
    }
    return head1;
}
void tishi(void)
{
    printf("Please select the option :\n");
    printf("1. Display all student\n");
    printf("2. Sort by average \n");
    printf("3. insert a new info\n");
    printf("4. Delete a record\n");
    printf("5. quit \n");
    printf("Please input your choice:");
}
struct stu *del(struct stu *head)
{
    int num=0;
    struct stu *p=head,*temp;
    if(head->next==NULL)read_txt_c("a.txt",head);
    printf("delete by num:");
    scanf("%d",&num);
        if(head->id == num)
        {
            temp =head->next;
            free(head);head=NULL;
            return temp;
        }
    while(p)
    {
        if(p->next->id ==num)
        {
            p->next =p->next->next;
            temp =p->next;
            free(temp);temp=NULL;
            return head;
        }
        else
        {
            p=p->next;
        }
    }

}
int main(int argc, const char *argv[])
{
    struct stu stu1[5]=
    {
        {1,"zhang",80,90,85},
        {2,"wang",70,90,80},
        {3,"li",100,90,95},
        {4,"zhao",80,86,100},
        {5,"mi",90,90,90}
    };
    struct stu temp;
    int flag=0;
    char c;
    FILE *file1;
    struct stu *head,*p,*head1;
    head = (struct stu *)malloc(sizeof(struct stu));
    head->next =NULL;
    //write_txt("a.txt",stu1,5);
    while(1)
    {
        tishi();
        scanf("%d",&flag);
        getchar();
        if(flag==5)break;
        if(flag==1)
        {
            flag =0;
            read_txt_c("a.txt",head); 
            p = head;
            while(p)
            {
                printf("%d %s %d %d %d\n",p->id,p->name,p->chinese,p->math,p->ave);
                p =p->next;
            }
            printf("please enter to next:");
            while(1){c=getchar();if(c==10){c=0;break;} }
            }
     
        if(flag==2)
        {
            flag=0;
            file1 = fopen("b.txt","w");
            if(head->next==NULL)read_txt_c("a.txt",head);
            head1 =sort(head);
            p=head1;
            int num=0;
            while(p)
            {
                num++;
                printf("%d %s %d %d %d \n",num,p->name,p->chinese,p->math,p->ave);
                fprintf(file1,"%d %s %d %d %d\n",num,p->name,p->chinese,p->math,p->ave);
                p =p->next;
            }
            fclose(file1);
            printf("please enter to next:");
            while(1){c=getchar();if(c==10){c=0;break;} }
        }
        if(flag==3)
        {
            flag=0;
            int num=0;
            file1 = fopen("a.txt","a");
            scanf("%d %s %d %d %d",&num,temp.name,&temp.chinese,&temp.math,&temp.ave);
            fprintf(file1,"%d %s %d %d %d\n",num,temp.name,temp.chinese,temp.math,temp.ave);
            fflush(file1);
            fclose(file1);
            printf("please enter to next:");
            while(1){c=getchar();if(c==10){c=0;break;} }
        }
            if(flag==4)
            {
                head =del(head);
                write_head_txt(head); 
                printf("please enter to next:");
                while(1){c=getchar();if(c==10){c=0;break;} }
            }
        }
    return 0;
}
