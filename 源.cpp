#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;
#define N 10
struct student;
typedef struct student //AI�޸�
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

//������ �����е���������ʦ�Ե�
void menu()
{
    printf("\n��ӭʹ��ѧ��ѧ������ϵͳ!\n");
    printf("\n");
    int n;
    {
        printf("�˵�\n");
        printf("ѧ��ѧ������ϵͳ\n");
        printf("1����������\n");
        printf("2����ѯ�ɼ�\n");
        printf("3��ɾ����¼\n");
        printf("4������ѧ���ɼ�\n");
        printf("5������ѧ��\n");
        printf("��ѡ���������(1~5):");
        scanf("%d", &n);
    }
}


//�������
void input()
{
    void menu();
    int i, o, p, q;
    printf("�����ѧ������:");
    scanf("%d", &q);
    while (q<1 || q>N)
    {
        printf("erorr!��");
        scanf("%d", &q);
    }
    for (i = 0; i < q; i++)
    {
        printf("\n�������%d��ѧ������Ϣ!\n", i);
    }
    {
        printf("��%d��ѧ����������", i);
        scanf("%s", stu[i].name);
        printf("��%d��ѧ����ѧ�ţ�", i);
        scanf("%d", &stu[i].number);
        printf("��%d��ѧ�������ķ�����", i);
        scanf("%d", &stu[i].ch);
        printf("��%d��ѧ������ѧ������", i);
        scanf("%d", &stu[i].math);
        printf("��%d��ѧ����Ӣ�������", i);
        scanf("%d", &stu[i].eng);
        count++;
        sprintf(stu[i].num, "%d", count);
    }
    {
        printf("�밴0���ز˵�:");
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

//��ѯ����
void find()
{
    struct student s;
    int i, o = -1, r;

    printf("������������ҵ�ѧ����ѧ��:");
    scanf("%s", s.number);
    for (i = 0; i < N; i++) {
        if (strcmp(s.num, stu[i].number) == 0) {
            o = i;
            break;
        }
    }

    if (o == -1) {
        printf("\nδ�ҵ����ѧ������Ϣ!\n");
        printf("\n1.����  2.���ز˵�\n��ѡ�������һ������:");
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
        printf("\n�ҵ�ѧ����Ϣ:\n");
        printf("ѧ�ţ�%s, ������%s, ���ģ�%s, ��ѧ��%s, Ӣ�%s\n",
            stu[o].num, stu[o].name,
            stu[o].ch, stu[o].math, stu[o].eng);
        printf("\n1.����  2.���ز˵�\n��ѡ�������һ������:");
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

//ɾ����¼
void del(char* target_number)//������AI�޸�
{
    for (int i = 0; i < count; ++i) {
        if (strcmp(stu[i].number, target_number) == 0)
        {
            for (int j = i; j < count - 1; ++j)
            {
                stu[j] = stu[j + 1];
            }
            count--;
            printf("ɾ���ɹ�\n");
            return;
        }
    }
    printf("δ�ҵ���ѧ��\n");
}

//����
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

//����
void fail(Student stu[], int count) {
    int f = 0;
    printf("��Ҫ������ѧ����\n");

    for (int i = 0; i < count; i++) {
        stu[i].chf = (stu[i].ch < 60);
        stu[i].mathf = (stu[i].math < 60);
        stu[i].engf = (stu[i].eng < 60);

        if (stu[i].chf || stu[i].mathf || stu[i].engf) {
            printf("ѧ�ţ�%s, ������%s, ���ģ�%s, ��ѧ��%s, Ӣ�%s\n",
                stu[i].num, stu[i].name,
                stu[i].chf ? "����" : "ͨ��",
                stu[i].mathf ? "����" : "ͨ��",
                stu[i].engf ? "����" : "ͨ��");
            f++;
        }
    }

    printf("�ܹ��� %d ��ѧ����Ҫ������\n", f);
}


int main() {
    char targetNumber[10];
    int n, m = 1;
    while (m) {
        menu();
        printf("��ѡ���������(1~5): ");
        scanf("%d", &n);
        if (n < 1 || n > 5) {
            system("cls");
            printf("\n��������!\n");
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
                printf("������Ҫɾ����ѧ����ѧ��: ");
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
                printf("\nû�����ѡ��!\n");
                break;
            }
        }
        if (n == 0) {
            m = 0;
        }
    }

    return 0;
}