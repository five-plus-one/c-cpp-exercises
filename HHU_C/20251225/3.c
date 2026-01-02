#include<stdio.h>
struct st{  //结构体，存储学生学号，姓名，三科分数，平均分
    int id;
    char name[11];
    int score[3];
    float avgscore;
};
void input(struct st student[],int n){ //自定义函数，输入
    for(int i=0;i<n;i++){ 
        //输入对应数据
        scanf("%d %s %d %d %d",&student[i].id,student[i].name,&student[i].score[0],&student[i].score[1],&student[i].score[2]);
        //计算平均分
        student[i].avgscore= (student[i].score[0]+student[i].score[1]+student[i].score[2])*1.0/3;
    }
}
float avgScore(struct st student[],int n){ //计算平均分
    int totalnum = 0;
    for(int i=0;i<n;i++){ //两轮遍历加和
        for(int j=0;j<3;j++){
            totalnum += student[i].score[j];
        }
    }
    return totalnum *1.0 / (n * 3); //返回平均分
}
int maxScore(struct st student[],int n){ //计算最高分对应id
    int maxscore = -1,maxid = -1,currentscore; //先将最高分设为-1,最高的对应id也设为-1
    for(int i=0;i<n;i++){ //遍历0到n-1
        currentscore = 0;
        for(int j=0;j<3;j++){
            currentscore+=student[i].score[j];
        } //计算当前的总分
        if(currentscore > maxscore){ //当前总分大于最高分，替换
            maxscore = currentscore;
            maxid = i;
        }
    }
    return maxid; //返回最高分的id
}
int main(){
    struct st student[100];
    int T,n;
    scanf("%d",&T); //输入T
    while(T--){ //循环T次
        scanf("%d",&n); //输入n
        input(student,n); //输入n行学生信息
        printf("%.2f\n",avgScore(student,n)); //计算并输出总平均分
        int maxid = maxScore(student,n); //计算最高分对应id
        //打印最高分的信息
        printf("%d %s %d %d %d %.2f\n",student[maxid].id,student[maxid].name,student[maxid].score[0],student[maxid].score[1],student[maxid].score[2],student[maxid].avgscore);
    }
}