#include <stdio.h>
struct CMD
{
    char *arg[8];
    int len[8];
    char outfile[30];
    char infile[30];
};
struct CMD cmd;
void shell(char *p)
{
    int i=0,j=0,flag1=0,leng=0,n=0;
    while(*(p+i))
    {
        if(flag1==0)
        {
              if(*(p+i)!=' '){cmd.arg[j]=p+i;flag1=1;}
        }
        if(flag1==1)
        {
            if(*(p+i)!=' ')
            leng++;
            if(*(p+i)==' '){cmd.len[j]=leng;leng=0;j++;flag1=0;}
            if(*(p+i)==10){cmd.len[j]=--leng;leng=0;j++;flag1=0;}
        }
        if(*(p+i)=='<'|*(p+i)=='>')break;
    i++;
    }
    while(*(p+i)!=10)
    {
    if(*(p+i)=='<')
        {
            while(1)
            {
            i++;
            if(*(p+i)=='>'|*(p+i)==0|*(p+i)==10){cmd.infile[n]=0;n=0;break;}
            if(*(p+i)==' ')continue;
            cmd.infile[n]=*(p+i);n++;
            }
        }
        n=0;
    if(*(p+i)=='>')
    {
        while(1)
        {
            i++;
            if(*(p+i)==0|*(p+i)=='<'|*(p+i)==10){cmd.outfile[n]=0;n=0;break;}
            if(*(p+i)==' ')continue;
            cmd.outfile[n]=*(p+i);n++;
        }
    }if(*(p+i)==0|*(p+i)==10)break;
    }
}
int main(int argc, const char *argv[])
{
    int i=0,j=0,flag1=0,leng=0,x;
    char *p;
    char a[100];
    p=a;
    for(x=0;x<8;x++)
    {
    cmd.arg[x]=NULL;
    }
    cmd.outfile[0]=0;
    cmd.infile[0]=0;
    fgets(p,100,stdin);
    shell(p);
    for(i=0;i<8;i++)
    {
    if(cmd.len[i]!=NULL)
        {
            if(i==0)printf("comand :");
            else printf("argment :");
            for(x=0;x<cmd.len[i];x++)
            {printf("%c",*(cmd.arg[i]+x));}
        printf("\n");
        }
    }
    //if(cmd.infile[0]!=0)
    printf("infile :%s\n",cmd.infile);
    if(cmd.outfile[0]!=0)
    printf("outfile :%s\n",cmd.outfile);
    return 0;
}
