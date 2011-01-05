#include <stdio.h>
#include<string.h>
void print_1(void) {printf("* ");}
void print_2(void) {printf("# ");}
struct stu_t
{
    char name[50];
    int id;
    int chinese;
    void (*fun)(void);
};
struct stu_t arr[5]=
{
    {"lihua   ",1011,98,print_1},
    {"zhanghua",1012,100,print_2},
    {"xiaocui ",1013,99,print_1},
    {"lisi    ",1014,60,print_2},
    {"liwu    ",1016,58,print_1}
};
int main(int argc, const char *argv[])
{
    int i;
    for(i=0;i<5;i++)
    {
    printf("%s id= %d chinese= %d",arr[i].name,arr[i].id,arr[i].chinese);
    arr[i].fun();
    printf("\n");
    }
    return 0;
}
