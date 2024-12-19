#include<stdio.h>
#include<string.h>
#include<math.h>
#include "malloc.h"
#include <stdlib.h>

#define max_name_lengh  30
#define max_sub_lengh  30

//用一个结构放每个学生的信息
    typedef struct Student
    {
	    long id;	                    
	    char name[max_name_lengh];            	
	    float score1;	   
	    float score2;                      
	    float score3;		
        char subject1[max_sub_lengh];
        char subject2[max_sub_lengh];
        char subject3[max_sub_lengh];
	    char mbti[4];   
	    struct Student *next;
    }STU,*nodeptr;
    //nodeptr是用来指向新节点的指针//是链表的其中一节 (代表一个学生)

    //头尾指针（指向的是链表的头，尾）
    typedef struct{
        STU *head;
        STU *tail;
    }plist;

    //初始链表
    void initlist(plist *list)
    {
        list->head = NULL;
        list->tail = NULL;
    }


    
//登陆界面
//学生端
//个人基本信息（学号，姓名，密码）
//教师端
//是否是班主任
//教授科目
int main(void)
{

    plist studentlist;
    initlist(&studentlist);
    int choice;
    long stu_id;
    printf("欢迎使用uestcer成绩信息管理系统！\n"
            "请选择您的身份：（1.教师 2.学生）");
    scanf("%d",&choice);
    switch (choice)
    {
    //教师端的管理系统
    case 1:
        printf("请选择您是否是班主任：（1.是 2.否）");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("查看本班成绩请输入1\n查看任教科目成绩请输入2\n");
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                searchStu();
                break;
            default:
                searchSubject();
                break;
            }
            break;
        
        default:
            searchSubject();
            break;
        }
        break;
    //学生端的管理系统
    default:
        printf("请输入您的学号：");
        scanf("%ld",&stu_id);
        for(nodeptr p =studentlist.head->next;p != studentlist.tail;p = p->next)
        {
            if(p -> id == stu_id)
            break;
            else
            printf("抱歉，数据库中没有此学生信息");
        }

        break;
    }

}
//初始页面展示（班主任）
int menu1 ()
{



    
    printf("\n\n");
	printf("\t\t\t                         学生成绩管理系统\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\t\t\t*                Management for Students' scores                             *\n");
	printf("\t\t\t*                1.  Input record                                            *\n");
	printf("\t\t\t*                2.  Caculate total and average score of every student       *\n");
	printf("\t\t\t*                3.  Caculate total and average score of every course        *\n");
	printf("\t\t\t*                4.                                                          *\n");
	printf("\t\t\t*                5.  Sort in descending order by score                       *\n");
	printf("\t\t\t*                6.  Sort in ascending order by score                        *\n");
	printf("\t\t\t*                7.  Sort in ascending order by number                       *\n");
	printf("\t\t\t*                8.  Sort in dictionary order by name                        *\n");
	printf("\t\t\t*                9.  Search by number                                        *\n");
	printf("\t\t\t*                10. Search by name                                          *\n");
	printf("\t\t\t*                11. Statistic analysis                                      *\n");
	printf("\t\t\t*                12. List record                                             *\n");
	printf("\t\t\t*                13. add mbti data                                           *\n");
	printf("\t\t\t*                14. find out the correlation of mbti and scores             *\n");
	printf("\t\t\t*                15.                                                         *\n");
	printf("\t\t\t*                16.                                                         *\n");
	printf("\t\t\t*                0.  Exit                                                    *\n");
	printf("\t\t\t******************************************************************************\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\t\t*****************Please Input your choice:");
}


//学生查分系统
//仅针对学生端
void getScoreAdvance()
{
    int choice;
    printf("请输入本次考试类型：（1.体测 2.期末考试）");
    scanf("%d",&choice);
    switch (choice)
    {
        double time50;
        int timelongrun;
        int gender;
        int vjf,xd,cs;
        double averagescore,gpa;
    case 1:
        printf("请输入您的性别(1.男 2.女)");
        switch (gender)
        {
        case 1:
            printf("请输入您的50m跑步时间：");
            scanf("%lf",&time50);
            printf("请输入您的1000m跑步时间：");
            scanf("%lf",&timelongrun);
            printf("您的最终成绩是：%d",(nan50(time50)+nannvlongrun(timelongrun))/2);
            break;
        
        default:
            printf("请输入您的50m跑步时间：");
            scanf("%lf",&time50);
            printf("请输入您的800m跑步时间：");
            scanf("%lf",&timelongrun);
            printf("您的最终成绩是：%d",(nv50(time50)+nannvlongrun(timelongrun))/2);
            break;
        }
    
    default:
        printf("请输入您的微积分成绩：");
        scanf("%d",&vjf);
        printf("请输入您的线性代数与空间解析几何成绩：");
        scanf("%d",&xd);
        printf("请输入您的程序设计与算法基础成绩：");
        scanf("%d",&cs);
        averagescore = (vjf+xd+cs)/3.0 ;
        gpa = thegpa(vjf,xd,cs);
        printf("您的平均分是：%.2lf \n您的绩点是:%.2lf",averagescore,gpa);
        break;
    }
}
int nan50(double time50)
{
    int grade = (int)round(time50 / 0.5);
    switch (grade)
    {
    case 12:
        return 100;
    case 13:
        return 95;
    case 14:
        return 90;
    case 15:
        return 85;
    case 16:
        return 80;
    case 17:
        return 75;
    case 18:
        return 70;
    case 19:
        return 60;
    default:
        return 0;
    }
}
int nv50(double time50)
{
    int grade = (int)round(time50 / 0.5);
    switch (grade)
    {
    case 14:
        return 100;
    case 15:
        return 95;
    case 16:
        return 85;
    case 17:
        return 80;
    case 18:
        return 75;
    case 19:
        return 70;
    case 20:
        return 60;
    default:
        return 0;
    }
}
int nannvlongrun(int timelongrun)
{
    int grade = timelongrun/15 -14;
    switch (grade)
    {
    case 0:
    return 100;
    case 1:
    return 90;
    case 2:
    return 80;
    case 3:
    return 70;
    case 4:
    return 60;
    default:
    return 0;
    }
}
double thegpa(int vjf,int xd,int cs)
{
    double gradevjf,gradexd,gradecs;
    if(vjf>=85)
    gradevjf = 4.0;
    else if(vjf>=60)
    gradevjf = 0.9+(vjf-55)/10;
    else
    gradevjf = 0.0;

    if(xd>=85)
    gradexd = 4.0;
    else if(xd>=60)
    gradexd = 0.9+(xd-55)/10;
    else
    gradexd = 0.0;

    if(cs>=85)
    gradecs = 4.0;
    else if(cs>=60)
    gradecs = 0.9+(cs-55)/10;
    else
    gradecs = 0.0;

    return (gradecs+gradevjf+gradexd)/3.0;
}

//查找学生
//针对教师端（班主任）
void searchStu(STU *head,STU *tail)
{
    long stu_id;
    printf("请输入您的学号：");
    scanf("%ld",&stu_id);
    for (nodeptr p = head->next;//从这个链表的头节点开始
                                p != tail;//直到遇到尾
                                        p = p->next//往后移
                                                    )
    {
        if(stu_id == p->id)//判断（如果能将文件中的id转换成long int）
        {
            printf("id:%lf\n name:%s \n score:%d\t%d\t%d\n  ",p->id,p->name,p->score1,p->score2,p->score3);
        }
    }
}
//查找某个科目
//针对教师端（任课教师）
void searchSubject(STU *head,STU *tail)
