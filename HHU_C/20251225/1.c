#include<stdio.h>
#include<string.h>

int main(){
    char ch1[1300],ch2[1300];
    fgets(ch1,sizeof(ch1),stdin);
    fgets(ch2,sizeof(ch2),stdin);
    int n1 = strlen(ch1)-1,n2 = strlen(ch2);
    int i =0, j = 0,flag = 1;
    while(i<n1 && j <n2){
        while(ch1[i]==' '){
            i++;
        }
        while(ch2[j]==' '){
            j++;
        }
        if(tolower(ch1[i]) != tolower(ch2[j] )){
            flag = 0;break;
        }
        i++;j++;
    }
    if(i<n1 || j<n2) {
        flag = 0;
        printf("%d %d\n",i,j);
    }
    if(flag){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    
}