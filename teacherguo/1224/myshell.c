#include <stdio.h>
struct CMD
{
    char *co[8];
    char *in;
    char *out;
}cmd;
void shell(char *a)
{
    char *p = a;
    int n=0;
    while(*p != '\0')
    {
        if(*p == ' ' || *p == 10)
        {
            *p = '\0';
            p++;
            continue;
        }
        if(*p == '<')
        {
            p++;
            while(*(p++) == ' ');
            cmd.in = --p;
        }
        if(*p == '>')
        {
            p++;
            while(*p++ == ' ');
            cmd.out = --p;
        }
        if(*p != ' ' && *(p-1) == '\0' || p == a)
        {
            cmd.co[n] = p;
            n++;
        }
    p++;
    }
}
void show(void)
{
    int i;
    for(i=0;i<8;i++)
    {
        if(cmd.co[i] == 0)continue;
        if(i == 0)
        {
        printf("comand :%s\n",cmd.co[i]);
        }
        else printf("argment :%s\n",cmd.co[i]);
    }
    if(cmd.in !=0 || cmd.out !=0 )
    printf("infile =%s    outfile =%s\n",cmd.in,cmd.out);
}
int main(int argc, const char *argv[])
{
    char a[256]; //"ls -all -all < in.txt > text";
    while(1)
    {
        fgets(a,256,stdin);
        shell(a);
        show();
    }
    return 0;
}
