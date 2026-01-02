/*
 * 学生成绩管理系统
 * 功能：实现学生信息的添加、查询、修改、删除、显示及文件存取
 * 作者：[您的姓名]
 * 日期：[日期]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LEN 50
#define MAX_ID_LEN 20
#define FILENAME "student.txt"

/* 学生信息结构体 */
typedef struct {
    char id[MAX_ID_LEN];        // 学号
    char name[MAX_NAME_LEN];    // 姓名
    char gender;                // 性别 (M/F)
    float chinese;              // 语文成绩
    float math;                 // 数学成绩
    float english;              // 英语成绩
    float average;              // 平均分
} Student;

/* 全局变量 */
Student students[MAX_STUDENTS];
int studentCount = 0;

/* 函数声明 */
void showMenu();
void addStudent();
void queryStudent();
void modifyStudent();
void deleteStudent();
void displayAllStudents();
void saveToFile();
void loadFromFile();
float calculateAverage(float chinese, float math, float english);
int isValidScore(float score);
int isValidGender(char gender);
int findStudentById(const char *id);
void clearInputBuffer();

/* 主函数 */
int main() {
    int choice;
    
    // 程序启动时从文件加载数据
    loadFromFile();
    
    while (1) {
        showMenu();
        printf("请输入您的选择: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n输入错误！请输入数字。\n");
            clearInputBuffer();
            continue;
        }
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                queryStudent();
                break;
            case 3:
                modifyStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                displayAllStudents();
                break;
            case 6:
                saveToFile();
                break;
            case 7:
                loadFromFile();
                break;
            case 0:
                saveToFile();
                printf("\n感谢使用！再见！\n");
                return 0;
            default:
                printf("\n无效的选择，请重新输入！\n");
        }
    }
    
    return 0;
}

/* 显示主菜单 */
void showMenu() {
    printf("\n========================================\n");
    printf("       学生成绩管理系统\n");
    printf("========================================\n");
    printf("  1. 添加学生信息\n");
    printf("  2. 查询学生信息\n");
    printf("  3. 修改学生信息\n");
    printf("  4. 删除学生信息\n");
    printf("  5. 显示所有学生信息\n");
    printf("  6. 保存到文件\n");
    printf("  7. 从文件加载\n");
    printf("  0. 退出系统\n");
    printf("========================================\n");
}

/* 计算平均分 */
float calculateAverage(float chinese, float math, float english) {
    return (chinese + math + english) / 3.0;
}

/* 验证成绩是否合法 */
int isValidScore(float score) {
    return score >= 0 && score <= 100;
}

/* 验证性别是否合法 */
int isValidGender(char gender) {
    return gender == 'M' || gender == 'F' || gender == 'm' || gender == 'f';
}

/* 按学号查找学生，返回索引，未找到返回-1 */
int findStudentById(const char *id) {
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(students[i].id, id) == 0) {
            return i;
        }
    }
    return -1;
}

/* 清空输入缓冲区 */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* 添加学生信息 */
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("\n错误：学生数量已达上限！\n");
        return;
    }
    
    Student newStudent;
    
    printf("\n--- 添加学生信息 ---\n");
    
    // 输入学号并验证唯一性
    printf("请输入学号: ");
    scanf("%s", newStudent.id);
    clearInputBuffer();
    
    if (findStudentById(newStudent.id) != -1) {
        printf("\n错误：该学号已存在！\n");
        return;
    }
    
    // 输入姓名
    printf("请输入姓名: ");
    scanf("%s", newStudent.name);
    clearInputBuffer();
    
    // 输入性别并验证
    printf("请输入性别 (M/F): ");
    scanf(" %c", &newStudent.gender);
    clearInputBuffer();
    
    // 转换为大写
    if (newStudent.gender >= 'a' && newStudent.gender <= 'z') {
        newStudent.gender -= 32;
    }
    
    if (!isValidGender(newStudent.gender)) {
        printf("\n错误：性别输入不合法！请输入 M 或 F。\n");
        return;
    }
    
    // 输入语文成绩并验证
    printf("请输入语文成绩 (0-100): ");
    scanf("%f", &newStudent.chinese);
    clearInputBuffer();
    
    if (!isValidScore(newStudent.chinese)) {
        printf("\n错误：语文成绩不合法！应在0-100之间。\n");
        return;
    }
    
    // 输入数学成绩并验证
    printf("请输入数学成绩 (0-100): ");
    scanf("%f", &newStudent.math);
    clearInputBuffer();
    
    if (!isValidScore(newStudent.math)) {
        printf("\n错误：数学成绩不合法！应在0-100之间。\n");
        return;
    }
    
    // 输入英语成绩并验证
    printf("请输入英语成绩 (0-100): ");
    scanf("%f", &newStudent.english);
    clearInputBuffer();
    
    if (!isValidScore(newStudent.english)) {
        printf("\n错误：英语成绩不合法！应在0-100之间。\n");
        return;
    }
    
    // 计算平均分
    newStudent.average = calculateAverage(newStudent.chinese, 
                                         newStudent.math, 
                                         newStudent.english);
    
    // 添加到数组
    students[studentCount++] = newStudent;
    
    printf("\n成功添加学生信息！平均分: %.2f\n", newStudent.average);
}

/* 查询学生信息 */
void queryStudent() {
    int choice;
    printf("\n--- 查询学生信息 ---\n");
    printf("1. 按学号精确查询\n");
    printf("2. 按姓名模糊查询\n");
    printf("请选择查询方式: ");
    
    if (scanf("%d", &choice) != 1) {
        printf("\n输入错误！\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();
    
    if (choice == 1) {
        // 按学号查询
        char id[MAX_ID_LEN];
        printf("请输入学号: ");
        scanf("%s", id);
        clearInputBuffer();
        
        int index = findStudentById(id);
        if (index != -1) {
            printf("\n找到学生信息:\n");
            printf("%-15s %-15s %-8s %-8s %-8s %-8s %-8s\n", 
                   "学号", "姓名", "性别", "语文", "数学", "英语", "平均分");
            printf("%-15s %-15s %-8c %-8.2f %-8.2f %-8.2f %-8.2f\n",
                   students[index].id,
                   students[index].name,
                   students[index].gender,
                   students[index].chinese,
                   students[index].math,
                   students[index].english,
                   students[index].average);
        } else {
            printf("\n未找到该学号的学生！\n");
        }
    } else if (choice == 2) {
        // 按姓名模糊查询
        char keyword[MAX_NAME_LEN];
        printf("请输入姓名关键字: ");
        scanf("%s", keyword);
        clearInputBuffer();
        
        int found = 0;
        printf("\n查询结果:\n");
        printf("%-15s %-15s %-8s %-8s %-8s %-8s %-8s\n", 
               "学号", "姓名", "性别", "语文", "数学", "英语", "平均分");
        
        for (int i = 0; i < studentCount; i++) {
            if (strstr(students[i].name, keyword) != NULL) {
                printf("%-15s %-15s %-8c %-8.2f %-8.2f %-8.2f %-8.2f\n",
                       students[i].id,
                       students[i].name,
                       students[i].gender,
                       students[i].chinese,
                       students[i].math,
                       students[i].english,
                       students[i].average);
                found = 1;
            }
        }
        
        if (!found) {
            printf("\n未找到匹配的学生！\n");
        }
    } else {
        printf("\n无效的选择！\n");
    }
}

/* 修改学生信息 */
void modifyStudent() {
    char id[MAX_ID_LEN];
    
    printf("\n--- 修改学生信息 ---\n");
    printf("请输入要修改的学生学号: ");
    scanf("%s", id);
    clearInputBuffer();
    
    int index = findStudentById(id);
    if (index == -1) {
        printf("\n未找到该学号的学生！\n");
        return;
    }
    
    printf("\n当前学生信息:\n");
    printf("姓名: %s, 性别: %c, 语文: %.2f, 数学: %.2f, 英语: %.2f, 平均分: %.2f\n",
           students[index].name,
           students[index].gender,
           students[index].chinese,
           students[index].math,
           students[index].english,
           students[index].average);
    
    int choice;
    printf("\n请选择要修改的项:\n");
    printf("1. 姓名\n");
    printf("2. 性别\n");
    printf("3. 语文成绩\n");
    printf("4. 数学成绩\n");
    printf("5. 英语成绩\n");
    printf("6. 修改所有信息\n");
    printf("请输入选择: ");
    
    if (scanf("%d", &choice) != 1) {
        printf("\n输入错误！\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();
    
    int needRecalculate = 0;
    
    switch (choice) {
        case 1:
            printf("请输入新姓名: ");
            scanf("%s", students[index].name);
            clearInputBuffer();
            break;
        case 2:
            printf("请输入新性别 (M/F): ");
            scanf(" %c", &students[index].gender);
            clearInputBuffer();
            if (students[index].gender >= 'a' && students[index].gender <= 'z') {
                students[index].gender -= 32;
            }
            if (!isValidGender(students[index].gender)) {
                printf("\n错误：性别输入不合法！\n");
                return;
            }
            break;
        case 3:
            printf("请输入新语文成绩: ");
            scanf("%f", &students[index].chinese);
            clearInputBuffer();
            if (!isValidScore(students[index].chinese)) {
                printf("\n错误：成绩不合法！\n");
                return;
            }
            needRecalculate = 1;
            break;
        case 4:
            printf("请输入新数学成绩: ");
            scanf("%f", &students[index].math);
            clearInputBuffer();
            if (!isValidScore(students[index].math)) {
                printf("\n错误：成绩不合法！\n");
                return;
            }
            needRecalculate = 1;
            break;
        case 5:
            printf("请输入新英语成绩: ");
            scanf("%f", &students[index].english);
            clearInputBuffer();
            if (!isValidScore(students[index].english)) {
                printf("\n错误：成绩不合法！\n");
                return;
            }
            needRecalculate = 1;
            break;
        case 6:
            printf("请输入新姓名: ");
            scanf("%s", students[index].name);
            clearInputBuffer();
            
            printf("请输入新性别 (M/F): ");
            scanf(" %c", &students[index].gender);
            clearInputBuffer();
            if (students[index].gender >= 'a' && students[index].gender <= 'z') {
                students[index].gender -= 32;
            }
            if (!isValidGender(students[index].gender)) {
                printf("\n错误：性别输入不合法！\n");
                return;
            }
            
            printf("请输入新语文成绩: ");
            scanf("%f", &students[index].chinese);
            clearInputBuffer();
            
            printf("请输入新数学成绩: ");
            scanf("%f", &students[index].math);
            clearInputBuffer();
            
            printf("请输入新英语成绩: ");
            scanf("%f", &students[index].english);
            clearInputBuffer();
            
            if (!isValidScore(students[index].chinese) || 
                !isValidScore(students[index].math) || 
                !isValidScore(students[index].english)) {
                printf("\n错误：成绩不合法！\n");
                return;
            }
            needRecalculate = 1;
            break;
        default:
            printf("\n无效的选择！\n");
            return;
    }
    
    // 如果修改了成绩，重新计算平均分
    if (needRecalculate) {
        students[index].average = calculateAverage(students[index].chinese,
                                                   students[index].math,
                                                   students[index].english);
    }
    
    printf("\n修改成功！\n");
}

/* 删除学生信息 */
void deleteStudent() {
    char id[MAX_ID_LEN];
    
    printf("\n--- 删除学生信息 ---\n");
    printf("请输入要删除的学生学号: ");
    scanf("%s", id);
    clearInputBuffer();
    
    int index = findStudentById(id);
    if (index == -1) {
        printf("\n未找到该学号的学生！\n");
        return;
    }
    
    printf("\n学生信息:\n");
    printf("学号: %s, 姓名: %s\n", students[index].id, students[index].name);
    printf("确认删除？(Y/N): ");
    
    char confirm;
    scanf(" %c", &confirm);
    clearInputBuffer();
    
    if (confirm == 'Y' || confirm == 'y') {
        // 将后面的学生前移
        for (int i = index; i < studentCount - 1; i++) {
            students[i] = students[i + 1];
        }
        studentCount--;
        printf("\n删除成功！\n");
    } else {
        printf("\n已取消删除操作。\n");
    }
}

/* 显示所有学生信息 */
void displayAllStudents() {
    if (studentCount == 0) {
        printf("\n当前没有学生信息！\n");
        return;
    }
    
    printf("\n--- 所有学生信息 ---\n");
    printf("%-15s %-15s %-8s %-8s %-8s %-8s %-8s\n", 
           "学号", "姓名", "性别", "语文", "数学", "英语", "平均分");
    printf("-------------------------------------------------------------------\n");
    
    for (int i = 0; i < studentCount; i++) {
        printf("%-15s %-15s %-8c %-8.2f %-8.2f %-8.2f %-8.2f\n",
               students[i].id,
               students[i].name,
               students[i].gender,
               students[i].chinese,
               students[i].math,
               students[i].english,
               students[i].average);
    }
    
    printf("\n共 %d 名学生\n", studentCount);
}

/* 保存到文件 */
void saveToFile() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("\n错误：无法打开文件进行保存！\n");
        return;
    }
    
    fprintf(file, "%d\n", studentCount);
    
    for (int i = 0; i < studentCount; i++) {
        fprintf(file, "%s,%s,%c,%.2f,%.2f,%.2f,%.2f\n", 
                students[i].id,
                students[i].name,
                students[i].gender,
                students[i].chinese,
                students[i].math,
                students[i].english,
                students[i].average);
    }
    
    fclose(file);
    printf("\n数据已成功保存到文件 %s！\n", FILENAME);
}

/* 从文件加载 */
void loadFromFile() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        printf("\n提示：未找到数据文件，将从空白开始。\n");
        return;
    }
    
    if (fscanf(file, "%d\n", &studentCount) != 1) {
        printf("\n错误：文件格式错误！\n");
        fclose(file);
        studentCount = 0;
        return;
    }
    
    for (int i = 0; i < studentCount; i++) {
        if (fscanf(file, "%[^,],%[^,],%c,%f,%f,%f,%f\n",
                   students[i].id,
                   students[i].name,
                   &students[i].gender,
                   &students[i].chinese,
                   &students[i].math,
                   &students[i].english,
                   &students[i].average) != 7) {
            printf("\n错误：读取第 %d 条数据失败！\n", i + 1);
            studentCount = i;
            break;
        }
    }
    
    fclose(file);
    printf("\n成功从文件加载 %d 条学生记录！\n", studentCount);
}
