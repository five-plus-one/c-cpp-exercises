#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

/* === 宏定义 === */
#define MAX_STUDENTS  1000      // 最大学生数量
#define MAX_LEN_ID 50           // 学号最大长度
#define MAX_LEN_NAME 50         // 姓名最大长度
#define MAX_LEN_SUBJECT 3       // 科目数量（语文、数学、英语）
#define FILENAME "student.txt"  // 数据文件名
#define SCORE_NUM 3             // 成绩数量
#define INTERVAL_LINES 100      // 清屏时打印的空行数
#define INTERVAL_LEN 40         // 分隔线长度
#define MAX_INPUT 256           // 输入缓冲区大小
#define MAX_PAGES 30            // 最大页面数

/* === 结构体定义 === */

// 学生信息结构体
struct student {
    char id[MAX_LEN_ID];        // 学号
    char name[MAX_LEN_NAME];    // 姓名
    char gender;                // 性别（M/F）
    float score[SCORE_NUM];     // 成绩数组（语文、数学、英语）
    float averagescore;         // 平均分
};

// 查询结果结构体
struct query {
    int studentcount;           // 查询到的学生数量
    int result[MAX_STUDENTS];   // 查询结果索引数组
};

// 页面选择范围结构体
struct page {
    int choices_max[MAX_PAGES]; // 各页面最大选择值
    int choices_min[MAX_PAGES]; // 各页面最小选择值
};

// 系统信息结构体
struct info {
    int studentcount;           // 当前学生总数
    struct student students[MAX_STUDENTS];  // 学生数组
    int page_id;                // 当前页面ID
    struct query queryresult;   // 查询结果
    struct page pages;          // 页面选择范围
    int preloadstatus;          // 预加载状态（0:预加载，1:正常加载）
    int needtosave;             // 是否需要保存到文件（用于自动化提示保存到文件）
};

// 通用输入结构体（支持多种数据类型）
struct in {
    union {
        float f;                // 浮点数
        char c;                 // 字符
        int d;                  // 整数
        char str[MAX_INPUT];    // 字符串
    } in;
    char type;                  // 数据类型标识
    int error;                  // 错误码
};

/* === 函数声明 === */
void clearinput();
struct in input(char type, int maxinput);
int inputinfo(char type, void *p, int maxinput, 
              int (*func)(void *data, struct info *sysinfo), 
              struct info *sysinfo);
int inputinfowithguide(char type, void *p, int maxinput, 
                       int (*func)(void *data, struct info *sysinfo), 
                       char *guide, struct info *sysinfo);
void printn(int n, char ch);
void clearconsole();
void printline();
void printtitle();
void showmenu(int id1);
void goodbye();
void printstudentinfo_title();
void printstudentinfo_solestudent(struct student *info);
int findstudentbyid(char *id, struct info *sysinfo);
int isvalidstudentid(void *data, struct info *sysinfo);
int always_true(void *data, struct info *sysinfo);
int isvalidgender(void *data, struct info *sysinfo);
int isvalidscore(void *data, struct info *sysinfo);
int isvalidquerychoice(void *data, struct info *sysinfo);
int querychoice(struct info *sysinfo);
void fuzzyquery(char *keyword, struct info *sysinfo);
void printqueryresult(struct info *sysinfo);
void printallstudents(struct info *sysinfo);
int confirm(char *ch1, char *ch2);
void calaveragescore(struct student* studentinfo);
void printsolestudentinfo(struct student* info);
void inputstudentinfo(int type, struct student *info, struct info *sysinfo);
void addstudentinfo(struct info *sysinfo);
int inquerystudentinfo_byid(struct info *sysinfo);
void inquerystudentinfo_byfuzzy(struct info *sysinfo);
void inquerystudentinfo(struct info *sysinfo);
void delsolestudent(int i, struct info *sysinfo);
void init_sysinfo_pagechoices(int pageid, int maxnum, int minnum, 
                              struct info *sysinfo);
void init_sysinfo(struct info *sysinfo);
int homepageinput(struct info *sysinfo);
void showallstudents(struct info *sysinfo);
int gotopage(struct info *sysinfo);
void delstudent(struct info *sysinfo);
void modify(struct info *sysinfo);
void savetofile(struct info *sysinfo);
int parse_student_record(const char *line, struct student *stu);
void loadfromfile(struct info *sysinfo);
void autosave(struct info *sysinfo);

/* === 主函数 === */
int main(){
    struct info sysinfo;
    init_sysinfo(&sysinfo);
    showmenu(11);
    loadfromfile(&sysinfo); //预加载
    while(1){
        sysinfo.page_id = 0;
        sysinfo.page_id = homepageinput(&sysinfo);
        if(gotopage(&sysinfo)==-1) break;
        autosave(&sysinfo);
    }
    return 0;

}

/* === 函数实现 === */


//清空输入缓冲区
void clearinput(){
    char ch =getchar();
    while(ch!='\n'&&ch!=EOF) ch = getchar();
    return ;
}

//统一输入函数
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

//信息输入+校验统一函数
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
//信息输入+指引统一函数
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
//打印n个字符
void printn(int n,char ch){
    while(n--) printf("%c",ch);
    return;
}
// 打印空行，来达到分隔/清空控制台的目的
void clearconsole(){
   printn(INTERVAL_LINES,'\n');
   return;
}
//打印线
void printline(){
    printn(INTERVAL_LEN,'#');
    printf("\n");
    return;
}
//打印标题
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
        break;
    case 11:
        printf("预加载文件\n");
        break;
    case 12:
        printf("自动保存提示\n");
        break;
    }
    printline();
}
//打印退出信息
void goodbye(){
    clearconsole();
    printtitle();
    printf("感谢使用该学生管理系统，再见！\n");
}
//打印表头
void printstudentinfo_title(){
    printf("%-15s %-15s %-12s %-9s %-12s %-12s %-12s\n", 
    "学号", "姓名", "性别", "语文", "数学", "英语", "平均分");
}
//打印单个学生信息（一行）
void printstudentinfo_solestudent(struct student *info){
    printf("%-15s %-15s %-2c %-10.2f %-10.2f %-10.2f %-10.2f\n",
        (*info).id,(*info).name,(*info).gender,(*info).score[0],(*info).score[1],(*info).score[2],(*info).averagescore);
}
//根据id查找学生序号
int findstudentbyid(char *id,struct info *sysinfo){
    for(int i =0;i< (*sysinfo).studentcount;i++){
        if(strcmp(id,(*sysinfo).students[i].id) == 0){
            return i;
        }
    }
    return -1;
}
//检查id合法性
int isvalidstudentid(void *data,struct info *sysinfo){
    char *id = (char*)data;
    return (findstudentbyid(id,sysinfo) )== -1;
}
//一个用于检测统一函数，永远返回真（不做检查）的函数
int always_true(void *data ,struct info *sysinfo){
    return 1;
}
//检查是否是合法性别
int isvalidgender(void *data,struct info *sysinfo){
    char gender = toupper(*(char*)data);
    return (gender == 'M' || gender == 'F');
}
//检查是否是合法分数
int isvalidscore(void *data,struct info *sysinfo){
    float score = *(float*)data;
    return score>=0 && score<=100;
}
//检查是否是合法的选择项
int isvalidquerychoice(void *data,struct info *sysinfo){
    int choice = (*(int*)data);
    int pageid = (*sysinfo).page_id;
    int maxnum = (*sysinfo).pages.choices_max[pageid];
    int minnum = (*sysinfo).pages.choices_min[pageid];
    return (choice >=minnum && choice <=maxnum);
}
//选择功能项
int querychoice(struct info *sysinfo){
    int res;
    inputinfowithguide('d',&res,0,isvalidquerychoice,"你需要使用的功能编号",sysinfo);
    return res;
}
//模糊查询功能实现
void fuzzyquery(char *keyword,struct info *sysinfo){
    (*sysinfo).queryresult.studentcount = 0;
    for(int i=0;i<(*sysinfo).studentcount;i++){
        if(strstr((*sysinfo).students[i].name,keyword)!=NULL){
            (*sysinfo).queryresult.result[(*sysinfo).queryresult.studentcount++] = i;
        }
    }
}
//打印查询结果信息
void printqueryresult(struct info *sysinfo){
    printline();
    if((*sysinfo).queryresult.studentcount == 0){
        printf("未查询到相关学生信息\n");
    }else{
        printstudentinfo_title();
        for(int i=0;i<(*sysinfo).queryresult.studentcount;i++){
            printstudentinfo_solestudent(&(*sysinfo).students[(*sysinfo).queryresult.result[i]]);
        }
    }
    printline();
}
//打印所有学生信息
void printallstudents(struct info *sysinfo){
    printline();
    printstudentinfo_title();
    for(int i=0;i<(*sysinfo).studentcount;i++){
        printstudentinfo_solestudent(&(*sysinfo).students[i]);
    }
    printline();
}
//确认函数
int confirm(char *ch1,char *ch2 ){
    printf("是否%s?输入Y/y以%s,按下回车以%s:",ch1,ch1,ch2);
    struct in res = input('c',0);
    if(res.error) return 0;
    else return (res.in.c == 'y' || res.in.c == 'Y');
}
//计算平均分
void calaveragescore(struct student* studentinfo){
    float totalscore = 0;
    for(int i = 0;i<SCORE_NUM;i++){
        totalscore+=(*studentinfo).score[i];
    }
    (*studentinfo).averagescore = totalscore / SCORE_NUM;
    return;
}
//打印单个学生的信息
void printsolestudentinfo(struct student* info){
    printf("该生信息如下\n");
    printline();
    printstudentinfo_title();
    printstudentinfo_solestudent(info);
    printline();
}
//输入学生信息统一函数
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
    case -11:
        for(int i=-2;i<=SCORE_NUM-1;i++){
            inputstudentinfo(i,info,sysinfo);
        }
        return;
    }
    return;
}
//添加学生信息
void addstudentinfo(struct info *sysinfo){
    showmenu(1);
     if((*sysinfo).studentcount >= MAX_STUDENTS){
        printf("错误：学生数量已达到最大容量 %d,无法添加新学生！\n", MAX_STUDENTS);
        printf("按下回车返回首页\n");
        clearinput();
        return;
    }
    struct student newstudent;
    inputstudentinfo(-10,&newstudent,sysinfo);
    printline();
    printsolestudentinfo(&newstudent);
    if(confirm("保存","取消")){
        int n=++(*sysinfo).studentcount;
        (*sysinfo).students[n-1] = newstudent;
        printline();
        printf("已成功保存,现在共有%d个学生信息。\n",n);
        (*sysinfo).needtosave = 1;
    }else{
        printf("已取消。\n");
    }
    if(confirm("继续添加学生信息","退出添加")){
        addstudentinfo(sysinfo);
    }
    return;
}
//根据id查询学生信息
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
//模糊查询学生信息
void inquerystudentinfo_byfuzzy(struct info *sysinfo){
    char keyword[MAX_INPUT];
    inputinfowithguide('s',keyword,MAX_LEN_NAME,always_true,"姓名关键字",sysinfo);
    fuzzyquery(keyword,sysinfo);
    printqueryresult(sysinfo);
}
//查询学生信息
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
//删除单个学生
void delsolestudent(int i,struct info *sysinfo){
    (*sysinfo).studentcount--;
    for(;i<(*sysinfo).studentcount;i++){
        (*sysinfo).students[i] = (*sysinfo).students[i+1];
    }
}
//初始化  页面选择书鲁昂
void init_sysinfo_pagechoices(int pageid,int maxnum,int minnum,struct info *sysinfo){
    (*sysinfo).pages.choices_max[pageid] = maxnum;
    (*sysinfo).pages.choices_min[pageid] = minnum;
}
//初始化
void init_sysinfo(struct info *sysinfo){
    (*sysinfo).studentcount = 0;
    (*sysinfo).page_id = 0;
    (*sysinfo).preloadstatus = 0;
    (*sysinfo).needtosave = 0;
    init_sysinfo_pagechoices(0,7,0,sysinfo);
    init_sysinfo_pagechoices(2,2,0,sysinfo);
    init_sysinfo_pagechoices(3,6,0,sysinfo);
}
//首页输入函数
int homepageinput(struct info * sysinfo){
    showmenu(0);
    return querychoice(sysinfo);
}
//显示所有学生的信息
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
//删除学生信息
void delstudent(struct info *sysinfo){
    int res = inquerystudentinfo_byid(sysinfo);
    if(res>=0){
        if(confirm("删除该学生","取消")){
            delsolestudent(res,sysinfo);
            printf("删除成功,剩余%d个学生\n",(*sysinfo).studentcount);
            (*sysinfo).needtosave = 1;
        }else{
            printf("已取消\n");
        }
    }
    printline();
    printf("按下回车回到首页\n");
    clearinput();
}
//修改学生信息
void modify(struct info *sysinfo){
    int res = inquerystudentinfo_byid(sysinfo);
    if(res >=0){
        if(confirm("修改该学生","取消")){
            struct student currentstudent = (*sysinfo).students[res];
            while(1){
                printsolestudentinfo(&currentstudent);
                printf(" 1.姓名 2.性别 3.语文成绩 4.数学成绩 5.英语成绩 6.全部 0.退出\n");
                int choice = querychoice(sysinfo);
                if(choice == 0) break;
                if(choice == 6) inputstudentinfo(-11,&currentstudent,sysinfo);
                else inputstudentinfo(choice-3,&currentstudent,sysinfo);
                printf("修改前\n");
                printsolestudentinfo(&(*sysinfo).students[res]);
                printf("修改后\n");
                printsolestudentinfo(&currentstudent);
                if(confirm("修改","取消")){
                    (*sysinfo).students[res] = currentstudent;
                    printf("修改成功\n");
                    (*sysinfo).needtosave = 1;
                }else{
                    printf("已取消修改\n");
                    currentstudent = (*sysinfo).students[res];
                }
            }
        }else{
            printf("已取消\n");
        }
    }
    printline();
    printf("按下回车回到首页\n");
    clearinput();
}
//保存到文件
void savetofile(struct info *sysinfo){
    FILE *file = fopen(FILENAME,"w");
    if(file == NULL){
        printf("错误:无法打开文件,保存失败\n");
    }else{
        fprintf(file,"%d\n",(*sysinfo).studentcount);
        for(int i=0;i<(*sysinfo).studentcount;i++){
            fprintf(file,"%lld:%s,%lld:%s,%c,%.2f,%.2f,%.2f,%.2f\n",//为什么这里要设计存储长度？因为无法保证用户学号或姓名中不存在,本身
                // 这会导致读取时存在混乱（无法判断这个,是字符串内部的,还是分割的,，所以存储一个长度
                strlen((*sysinfo).students[i].id),
                (*sysinfo).students[i].id,
                strlen((*sysinfo).students[i].name),
                (*sysinfo).students[i].name,
                (*sysinfo).students[i].gender,
                (*sysinfo).students[i].score[0],
                (*sysinfo).students[i].score[1],
                (*sysinfo).students[i].score[2],
                (*sysinfo).students[i].averagescore
            );
        }
        if(fclose(file)){
            printf("警告：无法关闭文件\n");
        }
        printf("数据已成功保存至%s\n",FILENAME);
    }
    (*sysinfo).needtosave = 0;
    printf("按下回车以返回\n");
    clearinput();
}
// 解析函数
int parse_student_record(const char *line, struct student *stu){
    const char *p = line;
    // 1. 解析学号长度
    int id_len = 0;
    while(*p >= '0' && *p <= '9'){
        id_len = id_len * 10 + (*p - '0');
        p++;
    }
    if(*p != ':' || id_len <= 0 || id_len >= MAX_LEN_ID) return 0;
    p++;  // 跳过冒号
    // 2. 复制学号
    int i;
    for(i = 0; i < id_len && *p != '\0'; i++, p++){
        stu->id[i] = *p;
    }
    stu->id[i] = '\0';
    if(i != id_len || *p != ',') return 0;
    p++;  // 跳过逗号
    // 3. 解析姓名长度
    int name_len = 0;
    while(*p >= '0' && *p <= '9'){
        name_len = name_len * 10 + (*p - '0');
        p++;
    }
    if(*p != ':' || name_len <= 0 || name_len >= MAX_LEN_NAME) return 0;
    p++;  // 跳过冒号
    // 4. 复制姓名
    for(i = 0; i < name_len && *p != '\0'; i++, p++){
        stu->name[i] = *p;
    }
    stu->name[i] = '\0';
    if(i != name_len || *p != ',') return 0;
    p++;  // 跳过逗号
    // 5. 解析性别
    if(*p == '\0') return 0;
    stu->gender = *p;
    p++;
    // 验证性别
    if(stu->gender != 'M' && stu->gender != 'F' && 
       stu->gender != 'm' && stu->gender != 'f'){
        return 0;
    }
    // 统一转换为大写
    if(stu->gender >= 'a' && stu->gender <= 'z'){
        stu->gender -= 32;
    }
    if(*p != ',') return 0;
    p++;  // 跳过逗号
    // 6. 解析三门成绩
    for(int j = 0; j < SCORE_NUM; j++){
        // 跳过可能的空格
        while(*p == ' ') p++;
        // 解析浮点数
        char num_buf[20];
        int k = 0;
        // 读取数字和小数点
        while((*p >= '0' && *p <= '9') || *p == '.' || *p == '-'){
            if(k < 19) num_buf[k++] = *p;
            p++;
        }
        num_buf[k] = '\0';
        stu->score[j] = atof(num_buf);
        // 验证成绩范围
        if(stu->score[j] < 0 || stu->score[j] > 100){
            return 0;
        }
        if(j < SCORE_NUM - 1){
            if(*p != ',') return 0;
            p++;  // 跳过逗号
        }
    }
    if(*p != ',') return 0;
    p++;  // 跳过逗号
    // 7. 解析平均分
    // 跳过可能的空格
    while(*p == ' ') p++;
    char avg_buf[20];
    int k = 0;
    while((*p >= '0' && *p <= '9') || *p == '.' || *p == '-'){
        if(k < 19) avg_buf[k++] = *p;
        p++;
    }
    avg_buf[k] = '\0';
    stu->averagescore = atof(avg_buf);
    // 验证平均分
    float calculated_avg = (stu->score[0] + stu->score[1] + stu->score[2]) / SCORE_NUM;
    if(fabs(stu->averagescore - calculated_avg) > 0.01){
        stu->averagescore = calculated_avg;
    }
    return 1;
}
//从文件中读取
void loadfromfile(struct info *sysinfo){
    if((*sysinfo).studentcount > 0){
        printf("当前系统中已存在数据,读取会造成数据覆盖，请问是否继续?\n");
        if(!(confirm("继续读取","取消"))){
            return;
        }
    }
    FILE *file = fopen(FILENAME,"r");
    if(file == NULL) {
        if((*sysinfo).preloadstatus == 0){
            printf("未找到数据文件,将从空白开始\n");
        }else{
            printf("读取文件失败,请检查文件是否存在或先保存文件\n");
        }
        return;
    }
    // 读取学生数量
    if(fscanf(file,"%d\n",&(*sysinfo).studentcount) != 1){
        (*sysinfo).studentcount = 0;
        if((*sysinfo).preloadstatus == 0){
            printf("预读取时发生错误:文件格式错误\n");
        }else{
            printf("读取文件时发生错误:文件格式错误\n");
        }
        if(fclose(file)){
            printf("警告：无法关闭文件\n");
        }
    }else{
        // 确保不超过最大容量
        if((*sysinfo).studentcount > MAX_STUDENTS){
            printf("警告:文件中的学生数量(%d)超过系统最大容量(%d)，只读取前%d个\n",
                (*sysinfo).studentcount, MAX_STUDENTS, MAX_STUDENTS);
            (*sysinfo).studentcount = MAX_STUDENTS;
        }
        
        char line[MAX_INPUT];
        int success_count = 0;
        
        // 读取每个学生记录
        for(int i = 0; i < (*sysinfo).studentcount; i++){
            if(!fgets(line, sizeof(line), file)){
                printf("警告:文件过早结束，预期%d个学生，实际读取%d个\n",
                    (*sysinfo).studentcount, success_count);
                break;
            }
            // 移除换行符
            line[strcspn(line, "\n\r")] = '\0';
            // 解析学生记录
            if(parse_student_record(line, &(*sysinfo).students[success_count])){
                success_count++;
            }else{
                printf("警告:第%d行格式错误，跳过该记录\n", i+2);
            }
        }
        // 更新实际读取的学生数量
        (*sysinfo).studentcount = success_count;
        
        if(fclose(file)){
            printf("警告：无法关闭文件\n");
        }
        
        if((*sysinfo).preloadstatus == 0){
            printf("预读取完成，成功加载%d个学生信息\n", success_count);
        }else{
            printf("读取文件完成，成功加载%d个学生信息\n", success_count);
        }
    }
    printf("按下回车以继续\n");
    clearinput();
}

int gotopage(struct info *sysinfo){
    showmenu((*sysinfo).page_id);
    if((*sysinfo).page_id == 0){
        goodbye();
        return -1;
    }
    switch ((*sysinfo).page_id)
    {
    case 1:
        addstudentinfo(sysinfo);
        break;
    case 2:
        inquerystudentinfo(sysinfo);
        break;
    case 5:
        showallstudents(sysinfo);
        break;
    case 4:
        delstudent(sysinfo);
        break;
    case 3:
        modify(sysinfo);
        break;
    case 7:
        savetofile(sysinfo);
        break;
    case 6:
        loadfromfile(sysinfo);
        break;
    }
    return 0;
}
//自动保存提醒
void autosave(struct info *sysinfo){
    if((*sysinfo).needtosave){
        showmenu(12);
        printf("检测到你对数据进行了修改，请问是否需要保存到%s以持久化存储文件?\n",FILENAME);
        (*sysinfo).needtosave = 0;
        if(confirm("保存","暂不")){
            (*sysinfo).page_id  = 7;
            gotopage(sysinfo);
        }
    }   
}