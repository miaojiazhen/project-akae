#include <stdio.h>

int main(int argc, const char *argv[])
{
    char a[100]={1};int i;
    for(i = 0; i < 100; i++)
        a[i] = '1';
    FILE *file1,*file2;
    int num=0;    
    int x=0;
    file1 =fopen(argv[1],"r");
    file2 =fopen(argv[2],"w");
    while(1)
    {
        num =fread(a,1,1,file1);
        if(feof(file1)!=0)break;
        printf("num =%d\n",num);
        fwrite(a,1,1,file2);
        //printf("%s\n",a);x++;
    }
    fclose(file1);
    fclose(file2);
    printf("x************=%d\n",x);
    return 0;
}
