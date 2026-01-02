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
#define MAX_PAGES 30

struct student{
    char id[MAX_LEN_ID];
    char name[MAX_LEN_NAME];
    char gender;
    float score[SCORE_NUM];
    float averagescore;
};
struct info{
    int studentcount;
    struct student students[MAX_STUDENTS];
    int page_id;
    struct query{
        int studentcount;
        int result[MAX_STUDENTS];
    }queryresult;
    struct page{
        int choices_max[MAX_PAGES];
        int choices_min[MAX_PAGES];
    }pages;
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
    
    if(type !='s' && (type != 'c' || (type == 'c'&&input.in.c!='\n'))){
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
        printf("2. 按姓名模糊查询\n");
        printf("0. 返回首页\n");
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
void printstudentinfo_title(){
    printf("%-15s %-15s %-12s %-9s %-12s %-12s %-12s\n", 
    "学号", "姓名", "性别", "语文", "数学", "英语", "平均分");
}
void printstudentinfo_solestudent(struct student *info){
    printf("%-15s %-15s %-2c %-10.2f %-10.2f %-10.2f %-10.2f\n",
        (*info).id,(*info).name,(*info).gender,(*info).score[0],(*info).score[1],(*info).score[2],(*info).averagescore);
}
int homepageinputvalid(int input){
    return input>=0 && input<=7;
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
int always_true(void *data ,struct info *sysinfo){
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
int isvalidquerychoice(void *data,struct info *sysinfo){
    int choice = (*(int*)data);
    int pageid = (*sysinfo).page_id;
    int maxnum = (*sysinfo).pages.choices_max[pageid];
    int minnum = (*sysinfo).pages.choices_min[pageid];
    return (choice >=minnum && choice <=maxnum);
}
int querychoice(struct info *sysinfo){
    int res;
    inputinfowithguide('d',&res,0,isvalidquerychoice,"你需要使用的功能编号",sysinfo);
    return res;
}
void fuzzyquery(char *keyword,struct info *sysinfo){
    (*sysinfo).queryresult.studentcount = 0;
    for(int i=0;i<(*sysinfo).studentcount;i++){
        if(strstr((*sysinfo).students[i].name,keyword)!=NULL){
            (*sysinfo).queryresult.result[(*sysinfo).queryresult.studentcount++] = i;
        }
    }
}
void printqueryresult(struct info *sysinfo){
    printline();
    if((*sysinfo).queryresult.studentcount == 0){
        printf("未查询到相关学生信息");
    }else{
        printstudentinfo_title();
        for(int i=0;i<(*sysinfo).queryresult.studentcount;i++){
            printstudentinfo_solestudent(&(*sysinfo).students[(*sysinfo).queryresult.result[i]]);
        }
    }
    printline();
}
void printallstudents(struct info *sysinfo){
    printline();
    printstudentinfo_title();
    for(int i=0;i<(*sysinfo).studentcount;i++){
        printstudentinfo_solestudent(&(*sysinfo).students[i]);
    }
    printline();
}
int confirm(char *ch1,char *ch2 ){
    printf("是否%s?输入Y/y以%s,输入其他内容则%s:",ch1,ch1,ch2);
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
    printf("该生信息如下\n");
    printline();
    printstudentinfo_title();
    printstudentinfo_solestudent(info);
    printline();
    // printf("该生信息如下\n学号:%s\n姓名:%s\n性别:%c\n语文成绩:%f\n数学成绩:%f\n英语成绩:%f\n平均分:%f\n",
    // (*info).id,(*info).name,(*info).gender,(*info).score[0],(*info).score[1],(*info).score[2],(*info).averagescore
    // );

}
void inputstudentinfo(int type,struct student *info,struct info *sysinfo){
    switch (type)
    {
    case -3:
        inputinfowithguide('s',(*info).id,MAX_LEN_ID,isvalidstudentid,"学号",sysinfo);
        return;
    case -2:
        inputinfowithguide('s',(*info).name,MAX_LEN_NAME,always_true,"姓名",sysinfo);
        return;
    case -1:
        inputinfowithguide('c',&(*info).gender,0,isvalidgender,"性别(M/F)",sysinfo);
        if((*info).gender > 97) (*info).gender -=32;
        return;
    case 0:
        inputinfowithguide('f',&(*info).score[0],0,isvalidscore,"语文成绩",sysinfo);
        calaveragescore(info);
        return;
    case 1:
        inputinfowithguide('f',&(*info).score[1],0,isvalidscore,"数学成绩",sysinfo);
        calaveragescore(info);
        return;
    case 2:
        inputinfowithguide('f',&(*info).score[2],0,isvalidscore,"英语成绩",sysinfo);
        calaveragescore(info);
        return;
    case -10:
        for(int i=-3;i<=SCORE_NUM-1;i++){
            inputstudentinfo(i,info,sysinfo);
        }
        return;
    }
    return;
}
void addstudentinfo(struct info *sysinfo){
    showmenu(1);
    struct student newstudent;
    inputstudentinfo(-10,&newstudent,sysinfo);
    // inputinfowithguide('s',newstudent.id,MAX_LEN_ID,isvalidstudentid,"学号",sysinfo);
    // inputinfowithguide('s',newstudent.name,MAX_LEN_NAME,always_true,"姓名",sysinfo);
    // inputinfowithguide('c',&newstudent.gender,0,isvalidgender,"性别(M/F)",sysinfo);
    // if(newstudent.gender > 97) newstudent.gender -=32;
    // inputinfowithguide('f',&newstudent.score[0],0,isvalidscore,"语文成绩",sysinfo);
    // inputinfowithguide('f',&newstudent.score[1],0,isvalidscore,"数学成绩",sysinfo);
    // inputinfowithguide('f',&newstudent.score[2],0,isvalidscore,"英语成绩",sysinfo);
    // calaveragescore(&newstudent);
    printline();
    printsolestudentinfo(&newstudent);
    // printline();
    if(confirm("保存","取消")){
        int n=++(*sysinfo).studentcount;
        (*sysinfo).students[n-1] = newstudent;
        printline();
        printf("已成功保存,现在共有%d个学生信息。按下回车键返回首页",n);
    }else{
        printf("已取消，按下回车键以返回首页");
    }
    clearinput();
    return;
}
int inquerystudentinfo_byid(struct info *sysinfo){
    struct student studentinfo;
    inputinfowithguide('s',studentinfo.id,MAX_LEN_ID,always_true,"学号",sysinfo);
    int n = findstudentbyid(studentinfo.id,sysinfo);
    if(n == -1){
        printf("不存在学号为\"%s\"的学生信息\n",studentinfo.id);
        return -404;
    }else{
        studentinfo = (*sysinfo).students[n];
        printsolestudentinfo(&studentinfo);
        return n;
    }
    
}
void inquerystudentinfo_byfuzzy(struct info *sysinfo){
    char keyword[MAX_INPUT];
    inputinfowithguide('s',keyword,MAX_LEN_NAME,always_true,"姓名关键字",sysinfo);
    fuzzyquery(keyword,sysinfo);
    printqueryresult(sysinfo);
}
void inquerystudentinfo(struct info *sysinfo){
    showmenu(2);
    int choice = querychoice(sysinfo);
    switch (choice)
    {
    case 0:
        return;
        break;
    case 1:
        inquerystudentinfo_byid(sysinfo);
        break;
    case 2:
        inquerystudentinfo_byfuzzy(sysinfo);
    }
    if(confirm("继续查询","返回首页")){
        inquerystudentinfo(sysinfo);
        return;
    }else{
        return;
    }
}
void delsolestudent(int i,struct info *sysinfo){
    (*sysinfo).studentcount--;
    for(;i<(*sysinfo).studentcount;i++){
        (*sysinfo).students[i] = (*sysinfo).students[i+1];
    }
}
void init_sysinfo_pagechoices(int pageid,int maxnum,int minnum,struct info *sysinfo){
    (*sysinfo).pages.choices_max[pageid] = maxnum;
    (*sysinfo).pages.choices_min[pageid] = minnum;
}
void init_sysinfo(struct info *sysinfo){
    (*sysinfo).studentcount = 0;
    (*sysinfo).page_id = 0;
    init_sysinfo_pagechoices(0,7,0,sysinfo);
    init_sysinfo_pagechoices(2,2,0,sysinfo);
}
int homepageinput(struct info * sysinfo){
    // struct in res;
    // res.in.d = -2;
    showmenu(0);
    // printf("请输入你需要使用的功能编号: ");
    // while(!homepageinputvalid(res.in.d)){
    //     res =input('d',0);
    //     if(res.error){
    //         showmenu(0);
    //         printf("编号无效，请重新输入：");
    //     }
    // }
    // return res.in.d;
    return querychoice(sysinfo);
}
void showallstudents(struct info *sysinfo){
    if((*sysinfo).studentcount){
        printf("所有学生信息如下\n");
        printallstudents(sysinfo);
    }else{
        printf("当前还没有学生\n");
        printline();
    }
    printf("按下回车回到首页\n");
    clearinput();
}
void delstudent(struct info *sysinfo){
    int res = inquerystudentinfo_byid(sysinfo);
    if(res>=0){
        if(confirm("删除该学生","取消")){
            delsolestudent(res,sysinfo);
            printf("删除成功,剩余%d个学生\n",(*sysinfo).studentcount);
        }else{
            printf("已取消\n");
        }
    }
    printline();
    printf("按下回车回到首页\n");
    clearinput();
}
int main(){
    struct info sysinfo;
    init_sysinfo(&sysinfo);
    // 之后添加，预读取
    while(1){
        sysinfo.page_id = 0;
        sysinfo.page_id = homepageinput(&sysinfo);
        showmenu(sysinfo.page_id);
        if(sysinfo.page_id == 0){
            goodbye();
            break;
        }
        switch (sysinfo.page_id)
        {
        case 1:
            addstudentinfo(&sysinfo);
            break;
        case 2:
            inquerystudentinfo(&sysinfo);
            break;
        case 5:
            showallstudents(&sysinfo);
            break;
        case 4:
            delstudent(&sysinfo);
            break;
        }
    }
    return 0;

}