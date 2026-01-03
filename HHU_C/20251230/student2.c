#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>  // 添加math.h以使用fabs函数

/* ==================== 宏定义 ==================== */
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

/* ==================== 结构体定义 ==================== */

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

/* ==================== 函数声明 ==================== */
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
int homepageinputvalid(int input);
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
void delstudent(struct info *sysinfo);
void modify(struct info *sysinfo);
void savetofile(struct info *sysinfo);
int parse_student_record(const char *line, struct student *stu);
void loadfromfile(struct info *sysinfo);

/* ==================== 函数实现 ==================== */

/**
 * @brief 清空输入缓冲区
 * @details 读取并丢弃缓冲区中的所有字符，直到遇到换行符或EOF
 */
void clearinput() {
    char ch = getchar();
    while (ch != '\n' && ch != EOF) {
        ch = getchar();
    }
    return;
}

/**
 * @brief 通用输入函数
 * @param type 输入类型：'f'浮点数，'c'字符，'d'整数，'s'字符串
 * @param maxinput 字符串最大输入长度（仅对字符串类型有效）
 * @return 包含输入数据和错误信息的结构体
 */
struct in input(char type, int maxinput) {
    struct in input;
    input.type = type;
    input.error = 0;
    
    switch (type) {
        case 'f':  // 浮点数输入
            scanf("%f", &input.in.f);
            break;
        case 'c':  // 字符输入
            scanf("%c", &input.in.c);
            break;
        case 'd':  // 整数输入
            scanf("%d", &input.in.d);
            break;
        case 's':  // 字符串输入
            fgets(input.in.str, sizeof(input.in.str), stdin);
            // 去除换行符
            input.in.str[strcspn(input.in.str, "\n")] = '\0';
            
            // 检查字符串长度
            if ((int)strlen(input.in.str) > maxinput) {
                input.error = -5;  // 字符串过长错误
            }
            
            // 检查输入是否被截断
            if (input.in.str[strlen(input.in.str) - 1] == '\0' && 
                input.in.str[strlen(input.in.str) - 2] != '\n') {
                input.error = -6;  // 输入被截断错误
                clearinput();
            }
            break;
    }
    
    // 检查输入缓冲区是否有多余字符（字符串类型已单独处理）
    if (type != 's' && (type != 'c' || (type == 'c' && input.in.c != '\n'))) {
        char ch = getchar();
        if (ch != '\n' && ch != EOF) {
            input.error = -2;  // 输入格式错误
            clearinput();
        }
    }
    
    return input;
}

/**
 * @brief 带验证的输入函数
 * @param type 输入类型
 * @param p 存储输入数据的指针
 * @param maxinput 最大输入长度
 * @param func 验证函数指针
 * @param sysinfo 系统信息指针
 * @return 错误码（0表示成功）
 */
int inputinfo(char type, void *p, int maxinput, 
              int (*func)(void *data, struct info *sysinfo), 
              struct info *sysinfo) {
    struct in res = input(type, maxinput);
    if (res.error) {
        return res.error;
    }
    
    switch (type) {
        case 'f':
            if ((*func)(&res.in.f, sysinfo)) {
                (*(float*)p) = res.in.f;
                return 0;
            } else {
                return -3;  // 数据不合法
            }
            break;
        case 'c':
            if ((*func)(&res.in.c, sysinfo)) {
                (*(char*)p) = res.in.c;
                return 0;
            } else {
                return -3;
            }
            break;
        case 'd':
            if ((*func)(&res.in.d, sysinfo)) {
                (*(int*)p) = res.in.d;
                return 0;
            } else {
                return -3;
            }
            break;
        case 's':
            if ((*func)(res.in.str, sysinfo)) {
                strcpy((char*)p, res.in.str);
                return 0;
            } else {
                return -3;
            }
            break;
    }
    return -4;  // 未知错误
}

/**
 * @brief 带提示和验证的输入函数
 * @param type 输入类型
 * @param p 存储输入数据的指针
 * @param maxinput 最大输入长度
 * @param func 验证函数指针
 * @param guide 提示信息
 * @param sysinfo 系统信息指针
 * @return 错误码（0表示成功）
 */
int inputinfowithguide(char type, void *p, int maxinput, 
                       int (*func)(void *data, struct info *sysinfo), 
                       char *guide, struct info *sysinfo) {
    printf("请输入%s:", guide);
    int res = -100;
    
    // 循环直到输入合法
    while (res != 0) {
        res = inputinfo(type, p, maxinput, func, sysinfo);
        if (res == 0) {
            return 0;
        }
        printf("输入不合法，请重新输入%s(错误代码：%d):", guide, res);
    }
    return 0;
}

/**
 * @brief 打印n个相同字符
 * @param n 打印次数
 * @param ch 要打印的字符
 */
void printn(int n, char ch) {
    while (n--) {
        printf("%c", ch);
    }
    return;
}

/**
 * @brief 清空控制台（通过打印空行）
 */
void clearconsole() {
    printn(INTERVAL_LINES, '\n');
    return;
}

/**
 * @brief 打印分隔线
 */
void printline() {
    printn(INTERVAL_LEN, '#');
    printf("\n");
    return;
}

/**
 * @brief 打印标题
 */
void printtitle() {
    printline();
    printf("  学生信息管理系统 V1.0 by 王煜冉\n");
    printline();
}

/**
 * @brief 显示菜单
 * @param id1 菜单ID
 */
void showmenu(int id1) {
    clearconsole();
    printtitle();
    printf("当前位置: ");
    
    switch (id1) {
        case 0:
            printf("首页\n");
            printline();
            printf("1. 添加学生信息\n");
            printf("2. 查询学生信息\n");
            printf("3. 修改学生信息\n");
            printf("4. 删除学生信息\n");
            printf("5. 显示所有学生信息\n");
            printf("6. 读取文件\n");
            printf("7. 保存文件\n");
            printf("0. 退出系统\n");
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
    }
    printline();
}

/**
 * @brief 显示退出信息
 */
void goodbye() {
    clearconsole();
    printtitle();
    printf("感谢使用该学生管理系统，再见！\n");
}

/**
 * @brief 打印学生信息表头
 */
void printstudentinfo_title() {
    printf("%-15s %-15s %-12s %-9s %-12s %-12s %-12s\n", 
           "学号", "姓名", "性别", "语文", "数学", "英语", "平均分");
}

/**
 * @brief 打印单个学生信息
 * @param info 学生信息指针
 */
void printstudentinfo_solestudent(struct student *info) {
    printf("%-15s %-15s %-2c %-10.2f %-10.2f %-10.2f %-10.2f\n",
           info->id, info->name, info->gender, 
           info->score[0], info->score[1], info->score[2], 
           info->averagescore);
}

/**
 * @brief 验证首页输入是否合法
 * @param input 输入值
 * @return 1表示合法，0表示不合法
 */
int homepageinputvalid(int input) {
    return input >= 0 && input <= 7;
}

/**
 * @brief 按学号查找学生
 * @param id 学号
 * @param sysinfo 系统信息指针
 * @return 学生索引（-1表示未找到）
 */
int findstudentbyid(char *id, struct info *sysinfo) {
    for (int i = 0; i < sysinfo->studentcount; i++) {
        if (strcmp(id, sysinfo->students[i].id) == 0) {
            return i;
        }
    }
    return -1;
}

/**
 * @brief 验证学号是否唯一
 * @param data 学号数据指针
 * @param sysinfo 系统信息指针
 * @return 1表示唯一，0表示重复
 */
int isvalidstudentid(void *data, struct info *sysinfo) {
    char *id = (char*)data;
    return (findstudentbyid(id, sysinfo) == -1);
}

/**
 * @brief 总是返回真（用于不需要验证的情况）
 * @param data 数据指针（未使用）
 * @param sysinfo 系统信息指针（未使用）
 * @return 总是返回1
 */
int always_true(void *data, struct info *sysinfo) {
    return 1;
}

/**
 * @brief 验证性别是否合法
 * @param data 性别数据指针
 * @param sysinfo 系统信息指针（未使用）
 * @return 1表示合法，0表示不合法
 */
int isvalidgender(void *data, struct info *sysinfo) {
    char gender = toupper(*(char*)data);
    return (gender == 'M' || gender == 'F');
}

/**
 * @brief 验证成绩是否合法
 * @param data 成绩数据指针
 * @param sysinfo 系统信息指针（未使用）
 * @return 1表示合法，0表示不合法
 */
int isvalidscore(void *data, struct info *sysinfo) {
    float score = *(float*)data;
    return score >= 0 && score <= 100;
}

/**
 * @brief 验证查询选择是否合法
 * @param data 选择数据指针
 * @param sysinfo 系统信息指针
 * @return 1表示合法，0表示不合法
 */
int isvalidquerychoice(void *data, struct info *sysinfo) {
    int choice = (*(int*)data);
    int pageid = sysinfo->page_id;
    int maxnum = sysinfo->pages.choices_max[pageid];
    int minnum = sysinfo->pages.choices_min[pageid];
    return (choice >= minnum && choice <= maxnum);
}

/**
 * @brief 获取用户选择
 * @param sysinfo 系统信息指针
 * @return 用户选择的值
 */
int querychoice(struct info *sysinfo) {
    int res;
    inputinfowithguide('d', &res, 0, isvalidquerychoice, 
                      "你需要使用的功能编号", sysinfo);
    return res;
}

/**
 * @brief 模糊查询学生信息
 * @param keyword 关键词
 * @param sysinfo 系统信息指针
 */
void fuzzyquery(char *keyword, struct info *sysinfo) {
    sysinfo->queryresult.studentcount = 0;
    
    for (int i = 0; i < sysinfo->studentcount; i++) {
        if (strstr(sysinfo->students[i].name, keyword) != NULL) {
            sysinfo->queryresult.result[sysinfo->queryresult.studentcount++] = i;
        }
    }
}

/**
 * @brief 打印查询结果
 * @param sysinfo 系统信息指针
 */
void printqueryresult(struct info *sysinfo) {
    printline();
    
    if (sysinfo->queryresult.studentcount == 0) {
        printf("未查询到相关学生信息");
    } else {
        printstudentinfo_title();
        for (int i = 0; i < sysinfo->queryresult.studentcount; i++) {
            printstudentinfo_solestudent(&sysinfo->students[sysinfo->queryresult.result[i]]);
        }
    }
    
    printline();
}

/**
 * @brief 打印所有学生信息
 * @param sysinfo 系统信息指针
 */
void printallstudents(struct info *sysinfo) {
    printline();
    printstudentinfo_title();
    
    for (int i = 0; i < sysinfo->studentcount; i++) {
        printstudentinfo_solestudent(&sysinfo->students[i]);
    }
    
    printline();
}

/**
 * @brief 确认操作
 * @param ch1 确认操作描述
 * @param ch2 取消操作描述
 * @return 1表示确认，0表示取消
 */
int confirm(char *ch1, char *ch2) {
    printf("是否%s?输入Y/y以%s,输入其他内容则%s:", ch1, ch1, ch2);
    struct in res = input('c', 0);
    
    if (res.error) {
        return 0;
    } else {
        return (res.in.c == 'y' || res.in.c == 'Y');
    }
}