#include <stdio.h>
struct maxstr
{
    int max_len;
    char *p;
};
struct maxstr m_l=
{
};
void max(char *s)
{
    int i=0,len=1;
    char *temp;
    m_l.max_len=1;
    m_l.p=s;
    temp=(s+i);
    while(*(s+i))
    {
        i++;
        if(*temp==*(s+i))
        {
            len++;
        }
        else
        {
            if(m_l.max_len>len){}
            else {m_l.max_len=len;m_l.p=temp;}
            temp=(s+i);
            len=1;
        }
    }
}
int main(int argc, const char *argv[])
{
    int i;
    char *s="abcccddffffffdddddddddddddddddddaabb";
    max(s);
    //printf("%s\n",m_l.p);
    for(i=0;i<m_l.max_len;i++)
    {
    printf("%c",*(m_l.p+i));
    }
    printf("\n");
    return 0;
}
