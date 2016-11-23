#ifndef _GRADEMANAGEMENT_H_
#define _GRADEMANAGEMENT_H_

#define   MAX_LEN  10   /* 字符串最大长度 */
#define   Stu_NUM 30    /* 最多的学生人数 */
#define   COURSE_NUM 6  /* 最多的考试科目数 */

/*学生结构（链表）*/
struct Stu
{
	long num;				/*学生学号*/
	char name[MAX_LEN];		/*学生姓名*/
	float score[COURSE_NUM];/*学生COURSE_NUM门功课的成绩*/
	float sum;				/*学生总成绩*/
	float aver;				/* 每个学生的平均成绩 */
	struct Stu *next;
};
typedef struct Stu Stu;

/*成绩结构*/
struct Grade
{
	int a,b,c,d,e,f;  /*不同成绩段*/
	float aRate,bRate,cRate,dRate,eRate,fRate; /*不同成绩段的人数比例*/
};
typedef struct Grade Grade;

/*IO函数*/
int   Menu(void);
void  ReadScore(Stu *stu,int *m);
void  PrintScore(Stu *stu, int m);
void  WritetoFile(Stu *stu,int n, int m);
void  ReadfromFile(Stu *stu,int *n, int *m);
void display(Stu *stu, int m);

/*计算平均分与总分*/
void  AverSumofEveryStudent(Stu *stu, int m);
void  AverSumofEveryCourse(Stu *stu, int n, int m);

/*排序函数*/
void sort(Stu *head, int (*compare)(float,float));
void swap(Stu *stu1, Stu *stu2);
void  SortbyScore(Stu *stuHead,int (*compare)(float,float));
void  AsSortbyNum(Stu *stu);
void  SortbyName(Stu *stu);

/*搜索函数*/
void  SearchbyNum(Stu *stu, int m);
void  SearchbyName(Stu *stu, int m);

/*统计函数*/
void  StatisticAnalysis(Stu *stu, int m);
void countRate(Grade *course);
void showAnalize(Grade *course, int num);

int   Ascending(float a, float b) ;
int   Descending(float a, float b) ;

/*内存分配*/
void distribute(Stu **stu, int n);

#endif
