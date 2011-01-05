#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a,b;
    char f[100];
    FILE *file1,*file2;
    file1=fopen(argv[1],"r");
    file2=fopen(argv[2],"w");
    int i=0;
    while(1)
    {
        fgets(f,100,file1);
        if(feof(file1)!=0)break;
        printf("%s",f);
        fputs(f,file2);i++;
    }
    printf("i =%d\n",i);
    fclose(file1);
    fclose(file2);
 #if 0
    while(1)
    {
        a= fgetc(file1);
        //if(a==EOF)break;
        b=feof(file1);if(b!=0)break;
        fputc(a,file2);
        printf("%c",a);
    }
#endif
    printf("\n");
    return 0;
}
