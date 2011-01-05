#include <stdio.h>
#pragma(1)
struct stu
{
    int id;
    int chinese;
    char name[256];
};
struct stu stu1={123,99,"ladeng"};
struct stu stu2={456,60,"ligangxxxx"};
void swap(struct stu *stu1,struct stu *stu2)
{
    struct stu tmp,*temp;
    temp=&tmp;
    *temp=*stu1;
    *stu1=*stu2;
    *stu2=*temp;

}
int main(int argc, const char *argv[])
{
    //printf("%d %d %s\n",stu1.id,stu1.chinese,stu1.name);
    swap(&stu1,&stu2);
    printf("%d %d %s\n",stu1.id,stu1.chinese,stu1.name);
    //printf("%s\n",stu1.name);
    //printf("xxxxxxxxxxxxxxxxxxxxxx\n");
    return 0;
}
