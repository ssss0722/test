#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
#define N 10
struct student;
typedef struct student //AI修改
{
    char num[10];
    char name[20];
    char number[10];
    int ch;
    int math;
    int eng;
    bool chf : 1; //AI
    bool mathf : 1;
    bool engf : 1;
    float average;
}Student;

Student stu[N];
int count = 0;

//主界面 加载有点慢还请老师稍等
void menu()
{
    printf("\n欢迎使用学生学籍管理系统!\n");
    printf("\n");
    int n;
    {
        printf("菜单\n");
        printf("学生学籍管理系统\n");
        printf("1、输入数据\n");
        printf("2、查询成绩\n");
        printf("3、删除记录\n");
        printf("4、排序学生成绩\n");
        printf("5、补考学生\n");
        printf("请选择服务种类(1~5):");
        scanf("%d", &n);
    }
}


//输入程序
void input()
{
    void menu();
    int i, o, p, q;
    printf("输入的学生人数:");
    scanf("%d", &q);
    while (q<1 || q>N)
    {
        printf("erorr!：");
        scanf("%d", &q);
    }
    for (i = 0; i < q; i++)
    {
        printf("\n请输入第%d个学生的信息!\n", i);
    }
    {
        printf("第%d个学生的姓名：", i);
        scanf("%s", stu[i].name);
        printf("第%d个学生的学号：", i);
        scanf("%d", &stu[i].number);
        printf("第%d个学生的语文分数：", i);
        scanf("%d", &stu[i].ch);
        printf("第%d个学生的数学分数：", i);
        scanf("%d", &stu[i].math);
        printf("第%d个学生的英语分数：", i);
        scanf("%d", &stu[i].eng);
        count++;
        sprintf(stu[i].num, "%d", count);
    }
    {
        printf("请按0返回菜单:");
        scanf("%d", &o);
        if (o == 0)
        {
            system("cls");
            menu();
        }
        else
            p = 0;
    }
    while (p == 0);
}

//查询功能
void find()
{
    struct student s;
    int i, o = -1, r;

    printf("请输入您想查找的学生的学号:");
    scanf("%s", s.number);
    for (i = 0; i < N; i++) {
        if (strcmp(s.num, stu[i].number) == 0) {
            o = i;
            break;
        }
    }

    if (o == -1) {
        printf("\n未找到这个学生的信息!\n");
        printf("\n1.继续  2.返回菜单\n请选择进行下一个操作:");
        scanf("%d", &r);
        if (r == 1) {
            system("cls");
            find();
        }
        else if (r == 2) {
            system("cls");
            menu();
        }
    }
    else {
        printf("\n找到学生信息:\n");
        printf("学号：%s, 姓名：%s, 语文：%s, 数学：%s, 英语：%s\n",
            stu[o].num, stu[o].name,
            stu[o].ch, stu[o].math, stu[o].eng);
        printf("\n1.继续  2.返回菜单\n请选择进行下一个操作:");
        scanf("%d", &r);
        if (r == 1) {
            system("cls");
            find();
        }
        else if (r == 2) {
            system("cls");
            menu();
        }
    }
}

//删除记录
void del(char* target_number)//括号内AI修改
{
    for (int i = 0; i < count; ++i) {
        if (strcmp(stu[i].number, target_number) == 0)
        {
            for (int j = i; j < count - 1; ++j)
            {
                stu[j] = stu[j + 1];
            }
            count--;
            printf("删除成功\n");
            return;
        }
    }
    printf("未找到该学生\n");
}

//排序
void averages(Student* stu, int count)
{
    for (int i = 0; i < count; i++)
    {
        stu[i].average = (stu[i].ch + stu[i].math + stu[i].eng) / 3.0f;
    }
}
void sort_averages(Student stu[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (stu[j].average < stu[j + 1].average) {
                Student temp = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = temp;
            }
        }
    }
}

//补考
void fail(Student stu[], int count) {
    int f = 0;
    printf("需要补考的学生：\n");

    for (int i = 0; i < count; i++) {
        stu[i].chf = (stu[i].ch < 60);
        stu[i].mathf = (stu[i].math < 60);
        stu[i].engf = (stu[i].eng < 60);

        if (stu[i].chf || stu[i].mathf || stu[i].engf) {
            printf("学号：%s, 姓名：%s, 语文：%s, 数学：%s, 英语：%s\n",
                stu[i].num, stu[i].name,
                stu[i].chf ? "补考" : "通过",
                stu[i].mathf ? "补考" : "通过",
                stu[i].engf ? "补考" : "通过");
            f++;
        }
    }

    printf("总共有 %d 名学生需要补考。\n", f);
}


int main() {
    char targetNumber[10];
    int n, m = 1;
    while (m) {
        menu();
        printf("请选择服务种类(1~5): ");
        scanf("%d", &n);
        if (n < 1 || n > 5) {
            system("cls");
            printf("\n错误输入!\n");
        }
        else {
            switch (n) {
            case 1:
                system("cls");
                input();
                break;
            case 2:
                system("cls");
                find();
                break;
            case 3:
                printf("请输入要删除的学生的学号: ");
                scanf("%s", targetNumber);
                del(targetNumber);
                break;
            case 4:
                system("cls");
                averages(stu, count);
                sort_averages(stu, count);
                break;
            case 5:
                system("cls");
                fail(stu, count);
                break;
            default:
                printf("\n没有这个选项!\n");
                break;
            }
        }
        if (n == 0) {
            m = 0;
        }
    }

    return 0;
}