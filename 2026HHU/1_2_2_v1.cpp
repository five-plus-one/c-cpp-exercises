#include<iostream>
using namespace std;
struct st{
    string name;
    int scholarship;
    int score1;
    int score2;
    char islear;
    char iswesternprovinces;
    int articles;
};
int main(){
    st student_max,student_current;
    student_max.scholarship  = -1;
    int total = 0,n;
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    while(n--){
        cin>>student_current.name>>student_current.score1>>student_current.score2>>student_current.islear>>student_current.iswesternprovinces>>student_current.articles;
        student_current.scholarship = 8000 * (student_current.score1 > 80 && student_current.articles >=1) + 4000 * (student_current.score1 > 85 && student_current.score2 > 80) + 2000 * (student_current.score1 > 90) + 1000 * (student_current.score1 > 85 && student_current.iswesternprovinces == 'Y') + 850 *(student_current.score2 > 80 && student_current.islear == 'Y');
        total += student_current.scholarship;
        if(student_current.scholarship > student_max.scholarship) student_max = student_current;
    }
    cout<<student_max.name<<endl<<student_max.scholarship<<endl<<total<<endl;
    return 0;
}