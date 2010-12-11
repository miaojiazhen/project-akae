#include <stdio.h>

int main(int argc, const char *argv[])
{
    int i=97;
    char x=97;
    printf("0x%x\n",&i);
    printf("%c\n",i);
    printf("%d\n",i);
    printf("sizeof int is : %d\n",sizeof(int));
    printf("sizeof char is : %d\n",sizeof(char));
    printf("sizeof double is : %d\n",sizeof(double));
    printf("sizeof float is : %d\n",sizeof(float));
//    printf("hello world\n");
    return 0;
}
