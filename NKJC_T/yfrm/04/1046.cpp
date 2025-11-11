#include<iostream>
using namespace std;
char a1,a2,a3;
void convert(int n){
    a3 = n%26+'a';
    n/=26;a2 = n%26+'a';
    n/=26;a1 = n%26+'a';
}
int main(){
    convert(2);
    int T;
    scanf("%d",&T);
    while(T--){
        int l;
        scanf("%d",&l);getchar();//处理换行符（
        l /=5;
        while(l--){
            int n = 0;
            for(int i=1;i<=5;i++){
                n=n*10+getchar()-'0';
            }
            
            convert(n);
            printf("%c%c%c",a1,a2,a3);
        }
        printf("\n");
    }
}