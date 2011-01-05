#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct stu
{
    int seq;
    int id;
    char name[50];
    int chinese;
    int math;
    int ave;
    struct stu *next;
};
struct stu stu[5]=
{
    {0,1,"aaa",80,80,80},
    {0,2,"bbb",81,69,75},
    {0,3,"ccc",95,95,95},
    {0,4,"ddd",60,60,60},
    {0,5,"eee",61,61,61}
};
void creat(char *s,int num)
{
    int i;
    FILE *file1;
    file1 =fopen(s,"w");
    for( i=0;i<num;i++)
    {
    fprintf(file1,"%d\t %d\t %s\t %d\t %d\t %d\n",stu[i].seq,stu[i].id, stu[i].name,stu[i].chinese,stu[i].math,stu[i].ave);
    }
    fclose(file1);
}
struct stu *read_txt_to_list(char *s, struct stu *head)
{
    FILE *file;
    struct stu *p,*op,*temp;
    head =(struct stu *)malloc(sizeof(struct stu));
    head->next =NULL;
    p =head;
    file = fopen(s,"r");
    while(1)
    {
        fscanf(file,"%d %d %s %d %d %d",&p->seq,&p->id,p->name,&p->chinese,&p->math,&p->ave);
        if(feof(file)!=0)break;
        op =(struct stu *)malloc(sizeof(struct stu));
        op->next =NULL;
        temp =p;
        p =p->next =op;
    }
    fclose(file);    
    temp->next =NULL;
    free(p);p=NULL;
    return head;
}
void show_list(struct stu *head)
{
    struct stu *p;
    p =head;
    fprintf(stdout, "%s\t %s\t %s\t %s\t %s\t %s\t\n","seq","id","name","chinese","math","ave");
    printf("*****************************************************\n");
    while(p)
    {
        printf("%d\t %d\t %s\t %d\t\t %d\t %d\n",p->seq,p->id,p->name,p->chinese,p->math,p->ave);
        p =p->next;
    }
    printf("*****************************************************\n");
}
void free_list(struct stu *head)
{
    struct stu *p;
    while(head)
    {
        p=head;
        head =head->next;
        free(p);p=NULL;
    }

}
void show_info(void)
{
    printf("Please select the option:\n");
    printf("1.Display all student's info\n");
    printf("2.Sort by average\n");
    printf("3.Insert a new info\n");
    printf("4.Delete a record\n");
    printf("5.Quit\n");
    printf("Please input your choose:");
}
struct stu *sort_list(struct stu *head)
{
    struct stu *p,*temp,*head1;
    int i=1;
    head1 = head;
    head =head->next;
    head1->next =NULL;
    p=head1;
    while(head)
    {
        if(head->ave >head1->ave)
            {
                temp =head->next;
                head->next = head1;
                head1 =head;
                head =temp;
                continue;
            }
        p =head1;
        while(1)
        {
            if(p->next ==NULL)
            {
                temp =head->next;
                p->next =head;
                p->next->next =NULL;
                head =temp;
                break;
            }
            if(head->ave > p->next->ave )
            {
                temp =head->next;
                head->next =p->next;
                p->next =head;
                head =temp;
                break;
            }
            p =p->next;
        }
        
    }
    p =head1;
    while(p)
    {
        p->seq =i;
        i++;
        p =p->next;
    }
    return head1;
}
void write_txt_from_list(char *s,struct stu *head)
{
    FILE *file;
    struct stu *p;
    p =head;
    file =fopen(s,"w");
    while(p)
    {
        fprintf(file,"%d\t %d\t %s\t %d\t %d\t %d\n",p->seq,p->id,p->name,p->chinese,p->math,p->ave);
        p =p->next;
    }
    fclose(file);
}
void continu(void)
{
    char a;
    a=0;
    printf("Please input ENTRY to continue:");
    while(1)
    {
        a =getchar();
        if(a==10)break;
    };
    printf("\n\n\n");
}
void insert_new_stu(struct stu *head)
{
    struct stu *p,*temp;
    temp =malloc(sizeof(struct stu));
    temp->seq =0;
    temp->next =NULL;
    p =head;
    while(p->next)
    {
        p =p->next;
    }
    p->next =temp;
    p =p->next;
    printf("Please input a new info (id name chinese math ave):\n");
    scanf("%d %s %d %d %d",&p->id,p->name,&p->chinese,&p->math,&p->ave);
    printf("insert successful\n");
    getchar();
}
struct stu *del_stuinfo_from_list(struct stu *head)
{
    int flag=0,flag1=0,num=0;
    char a[50];
    int i=0;
    struct stu *p,*temp;
    p =head;
    while(p)
    {
        num++;
        p =p->next;
    }
    p =head;
    printf("Please choose the way:\n");
    printf("1.delete by id\n");
    printf("2.delete by name\n");
    printf("3. EXIT\n");
    scanf("%d",&flag);
    getchar();
    if(flag ==1)
    {
        printf("you should choose the number id 1-%d:",num);
        scanf("%d",&flag1);
        getchar();
        if(head->id ==flag1)
        {
            temp =head;
            head =head->next;
            free(temp);temp=NULL;
            return head;
        }
        while(p->next)
        {
            if(p->next->id == flag1)
            {
                temp =p->next;
                p->next =p->next->next;
                free(temp);temp=NULL;
                return head;
            }
            p =p->next;
        }
    }
    if(flag==2)
    {
        printf("you should input a name:");
        while((a[i++] =getchar()) != '\n');
        a[i-1]='\0';
        if(strcmp(a,p->name)==0)
        {
            temp =head;
            head =head->next;
            free(temp);temp=NULL;
            return head;
        }
        while(p->next)
        {
            if(strcmp(a,p->next->name) ==0)
            {
                temp =p->next;
                p->next =p->next->next;
                free(temp);temp=NULL;
                return head;
            }
            p =p->next;
        }
    }
    if(flag==3){return head;}

}
int main(int argc, const char *argv[])
{
    FILE *file1;
    int flag =0;
    struct stu *head=NULL;
    creat("a.txt",5);
    while(1)
    {
        show_info();
        scanf("%d",&flag);
        getchar();
        if(flag ==1)
        {
            head = read_txt_to_list("a.txt",head);
            show_list(head);
            free_list(head);
            continu();
        }
        if(flag ==2)
        {
            head = read_txt_to_list("a.txt",head);
            head =sort_list(head);
            show_list(head);
            free_list(head);
            continu();
        }
        if(flag ==3)
        {
            head = read_txt_to_list("a.txt",head);
            insert_new_stu(head);
            write_txt_from_list("a.txt",head);
            head =sort_list(head);
            write_txt_from_list("b.txt",head);
            free_list(head);
            continu();
        }
        if(flag ==4)
        {
            head = read_txt_to_list("a.txt",head);
            head = del_stuinfo_from_list(head);
            write_txt_from_list("a.txt",head);
            head =sort_list(head);
            write_txt_from_list("b.txt",head);
            free_list(head);
            continu();
        }
        if(flag ==5)break;
    }
    //head = read_txt_to_list("a.txt",head);
    //head =sort_list(head);
    //write_txt_from_list("b.txt",head);
    //show_list(head);
    return 0;
}
