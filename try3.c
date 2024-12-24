#include<stdio.h>
#include<string.h>

typedef struct _stu
{
	//数据域
	int id;
	char *name;
	double math_grade;
	double english_grade;
	double literature_grade;
	char *mbti;
	double sum_grade;
	//单向链表指针域
	struct _stu *next;
}STU;

typedef struct _list
{
	STU *head;
	STU *tail;
}List;

//mbti的总分平均分计算器
double mbti_sumgrades_counter(List *pList,char *aim_mbti)
{
	STU *p;
	double sum_of_sum = 0;		//计算总分的总分
	int cnt = 0;				//计数器统计该mbti有多少个学生
	for(p=pList->head;p;p=p->next)
	{
		if(strcmp(aim_mbti,p->mbti)==0)
		{
			sum_of_sum += (p->sum_grade);
			cnt++;
		}
	}
	 double average;
	 average = sum_of_sum / cnt;
	 return average;
}

//根据名字删除某一个学生的信息
void delete(List *pList,char *name)
{
	STU *p;
	STU *q;
	for(q=NULL , p=pList->head ; p ; q=p , p=p->next)
	{
		if(strcmp(name,p-name)==0)
		{
			if(q)
			{
				q->next = p->next;
			}
			else
			{
				pList->head = p->next;
			}
			free(p);
			break;
		}
	}
}

//新建一个学生的信息
void add(List *pList,int id,char *name,double math_grade,double english_grade,double literature_grade,double sum_grade,char *mbti,)
{
	//新建一个节点存储学生信息
	STU *p = (STU*)malloc(sizeof(STU));
	p->id = id;
	p->name =name;
	p->math_grade = math_grade;
	p->english_grade = english_grade;
	p->literature_grade = literature_grade;
	p->mbti = mbti;
	p->sum_grade = sum_grade;
	//接在链表的最后面
	if(pList->tail)
	{
		pList->tail->next = p;
		pList->tail = p;
	}	
	else
	{
		pList->head = p;
		pList->tail = p;
	}
}

//求某一指定学科的平均分,指定学科名请输入literatu、english或math
double avrg_grades_counter(List *pList,char *grade_name)
{
	STU *p;
	char *eng = "english";
	char *lite = "literature";
	char *math = "math";
	double sum = 0;
	int cnt = 0;
	if(strcmp(grade_name,eng)==0)
	{
		for(p=pList->head;p;p=p->next)
		{
			sum += p->english_grade;
			cnt++;
		}
	}
	if(strcmp(grade_name,lite)==0)
	{
		for(p=pList->head;p;p=p->next)
		{
			sum += p->literature_grade;
			cnt++;
		}		
	}
	if(strcmp(grade_name,math)==0)
	{
		for(p=pList->head;p;p=p->next)
		{
			sum += p->math_grade;
			cnt++;
		}
	}

	double average_grade;
	average_grade = sum / cnt;

	return average_grade;
}