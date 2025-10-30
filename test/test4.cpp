#include<iostream>
using namespace std;
void solve(int n,char from,char to,char other){
    if(n==0){
        return;
    }
    solve(n-1,from,other,to);
    cout<<"将"<<n<<"号盘子从"<<from<<"移动到"<<to<<endl;
    solve(n-1,other,to,from);

}
int main(){
    int n;
    cin>>n;
    solve(n,'A','C','B');
    return 0;
    
}