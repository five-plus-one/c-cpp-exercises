#include<stdio.h>
#include<stdlib.h>
int main(void){
    FILE *fp;
    char str[100];
    int i = 0;
    if((fp = fopen("E:\\5plus1\\ACM\\202509_nkjc\\HHU_C\\20251217\\test.txt","w"))==NULL){
        printf("can't open this file.\n");
        exit(0);
    }
    printf("input a string:\n");
    gets(str);
    while(str[i]){
        if(str[i]>='a'&& str[i]<='z') str[i] = str[i]-32;
        fputc(str[i],fp);
        i++;
    }
    if(fclose(fp)){
        printf("can't close this file\n");
        exit(0);
    }
    return 0;
}