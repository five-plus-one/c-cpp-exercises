#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_STUDENTS  1000
#define MAX_LEN_ID 50
#define MAX_LEN_NAME 50
#define MAX_LEN_SUBJECT 3
#define FILE "student.txt"
#define SCORE_NUM 3
#define INTERVAL_LINES 100
#define INTERVAL_LEN 40
#define MAX_INPUT 100

struct student{
    char id[MAX_LEN_ID];
    char name[MAX_LEN_NAME];
    char gender;
    float score[SCORE_NUM];
    float averagescore;
};
struct info{
    int studentcount;
    struct student students[MAX_INPUT];
};

struct in{
    union{
        float f;
        char c;
        int d;
        char str[MAX_INPUT];
    }in;
    char type;
    int error;
};

//清空输入缓冲区
void clearinput(){
    char ch =getchar();
    while(ch!='\n'&&ch!=EOF) ch = getchar();
    return ;
}

struct in input(char type,int maxinput){
    struct in input;
    input.type = type;
    input.error = 0;
    switch (type)
    {
    case 'f':
        scanf("%f",&input.in.f);
        break;
    case 'c':
        scanf("%c",&input.in.c);
        break;
    case 'd' :
        scanf("%d",&input.in.d);
        break;
    case 's':
        fgets(input.in.str,sizeof(input.in.str),stdin);
        input.in.str[strcspn(input.in.str,"\n")] = '\0'; //如果有换行符，那么去除掉
        if((int)strlen(input.in.str)>maxinput){
            input.error = -5;
        }
        if(input.in.str[strlen(input.in.str)-1] == '\0' &&input.in.str[strlen(input.in.str)-2] != '\n'){ //被截断了
            input.error = -6;
            clearinput();
        }
        break;
    }
    
    if(type !='s'){
        char ch = getchar();
        if(ch!='\n' && ch!= EOF){
            input.error = -2;
            clearinput();
        }
    }
    return input;
}

int inputinfo(char type,void *p,int maxinput,int (*func)(void *data,struct info *sysinfo),struct info *sysinfo){
    struct in res = input(type,maxinput);
    if(res.error) return res.error;
    switch (type)
    {
    case 'f':
        if((*func)(&res.in.f,sysinfo)){
            (*(float*)p) = res.in.f;
            return 0;
        }else return -3; //不合法
        break;
    case 'c':
        if((*func)(&res.in.c,sysinfo)){
            (*(char*)p) = res.in.c;
            return 0;
        }else return -3;
        break;
    case 'd':
        if((*func)(&res.in.d,sysinfo)){
            (*(int*)p) = res.in.d;
            return 0;
        }else return -3;
        break;
    case 's':
        if((*func)(res.in.str,sysinfo)){
            // 使用 strcpy 复制字符串到目标位置
            strcpy((char*)p, res.in.str);
            return 0;
        }else return -3;
        break;
    }
    return -4;    
}
int inputinfowithguide(char type,void *p,int maxinput,int (*func)(void *data,struct info *sysinfo),char *guide,struct info *sysinfo){
    printf("请输入%s:",guide);
    int res = -100;
    while(res!=0){
        res = inputinfo(type,p,maxinput,(func),sysinfo);
        if(res == 0 ) return 0;
        printf("输入不合法，请重新输入%s(错误代码：%d):",guide,res);
    }
    return 0;
}

void printn(int n,char ch){
    while(n--) printf("%c",ch);
    return;
}
// 打印空行，来达到分隔/清空控制台的目的
void clearconsole(){
   printn(INTERVAL_LINES,'\n');
   return;
}
void printline(){
    printn(INTERVAL_LEN,'#');
    printf("\n");
    return;
}
void printtitle(){
    printline();
    printf("  学生信息管理系统 V1.0 by 王煜冉\n");
    printline();
}
//菜单打印函数
void showmenu(int id1){
    clearconsole();
    printtitle();
    printf("当前位置: ");
    switch (id1)
    {
    case 0:
        printf("首页\n");
        printline();
        printf("1. 添加学生信息\n2. 查询学生信息\n3. 修改学生信息\n4. 删除学生信息\n5. 显示所有学生信息\n6. 读取文件\n7. 保存文件\n0. 退出系统\n");
        break;
    case 1:
        printf("添加学生信息\n");
        break;
    case 2:
        printf("查询学生信息\n");
        printline();
        printf("1. 按学号精确查询\n");
        printf("2. 按姓名精确查询");
        break;
    case 3:
        printf("修改学生信息\n");
        break;
    case 4:
        printf("删除学生信息\n");
        break;
    case 5:
        printf("显示所有学生信息\n");
        break;
    case 6:
        printf("读取文件\n");
        break;
    case 7:
        printf("保存文件\n");
    }
    printline();
}
void goodbye(){
    clearconsole();
    printtitle();
    printf("感谢使用该学生管理系统，再见！\n");
}

int homepageinputvalid(int input){
    return input>=0 && input<=7;
}
int homepageinput(){
    struct in res;
    res.in.d = -2;
    showmenu(0);
    printf("请输入你需要使用的功能编号: ");
    while(!homepageinputvalid(res.in.d)){
        res =input('d',0);
        if(res.error){
            showmenu(0);
            printf("编号无效，请重新输入：");
        }
    }
    return res.in.d;
}
int findstudentbyid(char *id,struct info *sysinfo){
    for(int i =0;i< (*sysinfo).studentcount;i++){
        if(strcmp(id,(*sysinfo).students[i].id) == 0){
            return i;
        }
    }
    return -1;
}
int isvalidstudentid(void *data,struct info *sysinfo){
    char *id = (char*)data;
    return (findstudentbyid(id,sysinfo) )== -1;
}
int isvalidname(void *data ,struct info *sysinfo){
    return 1;
}
int isvalidgender(void *data,struct info *sysinfo){
    char gender = toupper(*(char*)data);
    return (gender == 'M' || gender == 'F');
}
int isvalidscore(void *data,struct info *sysinfo){
    float score = *(float*)data;
    return score>=0 && score<=100;
}
int confirm(char *ch1,char *ch2 ){
    printf("确认%s?输入Y/y以确认%s,否则%s:",ch1,ch1,ch2);
    struct in res = input('c',0);
    if(res.error) return 0;
    else return (res.in.c == 'y' || res.in.c == 'Y');
}
void calaveragescore(struct student* studentinfo){
    float totalscore = 0;
    for(int i = 0;i<SCORE_NUM;i++){
        totalscore+=(*studentinfo).score[i];
    }
    (*studentinfo).averagescore = totalscore / SCORE_NUM;
    return;
}
void printsolestudentinfo(struct student* info){
    printf("该生信息如下\n学号:%s\n姓名:%s\n性别:%c\n语文成绩:%f\n数学成绩:%f\n英语成绩:%f\n平均分:%f\n",
    (*info).id,(*info).name,(*info).gender,(*info).score[0],(*info).score[1],(*info).score[2],(*info).averagescore
    );

}
void addstudentinfo(struct info *sysinfo){
    showmenu(1);
    struct student newstudent;
    inputinfowithguide('s',&newstudent.id,MAX_LEN_ID,isvalidstudentid,"学号",sysinfo);
    inputinfowithguide('s',&newstudent.name,MAX_LEN_NAME,isvalidname,"姓名",sysinfo);
    inputinfowithguide('c',&newstudent.gender,0,isvalidgender,"性别(M/F)",sysinfo);
    if(newstudent.gender > 97) newstudent.gender -=32;
    inputinfowithguide('f',&newstudent.score[0],0,isvalidscore,"语文成绩",sysinfo);
    inputinfowithguide('f',&newstudent.score[1],0,isvalidscore,"数学成绩",sysinfo);
    inputinfowithguide('f',&newstudent.score[2],0,isvalidscore,"英语成绩",sysinfo);
    calaveragescore(&newstudent);
    printline();
    printsolestudentinfo(&newstudent);
    printline();
    if(confirm("保存","取消")){
        int n=++(*sysinfo).studentcount;
        (*sysinfo).students[n] = newstudent;
        printline();
        printf("已成功保存,现在共有%d个学生信息。按下回车键返回首页",n);
    }else{
        printf("已取消，按下回车键以返回首页");
    }
    clearinput();
    return;
}
int main(){
    struct info sysinfo;
    sysinfo.studentcount = 0;
    
    // 之后添加，预读取
    while(1){
        int op = homepageinput();
        showmenu(op);
        if(op == 0){
            goodbye();
            break;
        }
        switch (op)
        {
        case 1:
            addstudentinfo(&sysinfo);
            break;
        }
    }
    return 0;

}