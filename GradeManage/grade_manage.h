#ifndef _GRADEMANAGEMENT_H_
#define _GRADEMANAGEMENT_H_

#define   MAX_LEN  10   /* 字符串最大长度 */
#define   Stu_NUM 30    /* 最多的学生人数 */
#define   COURSE_NUM 6  /* 最多的考试科目数 */

/*student struct*/
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

struct Grade
{
	int a,b,c,d,e,f;
	float aRate,bRate,cRate,dRate,eRate,fRate;
};
typedef struct Grade Grade;

/*func  n=stu num , m=course num*/
int   Menu(void);
void  ReadScore(Stu *stu,int *m);
void  PrintScore(Stu *stu, int m);
void  WritetoFile(Stu *stu,int n, int m);
void  ReadfromFile(Stu *stu,int *n, int *m);
void display(Stu *stu, int m);

void  AverSumofEveryStudent(Stu *stu, int m);
void  AverSumofEveryCourse(Stu *stu, int n, int m);

void sort(Stu *head, int (*compare)(float,float));
void swap(Stu *stu1, Stu *stu2);
void  SortbyScore(Stu *stuHead,int (*compare)(float,float));
void  AsSortbyNum(Stu *stu);
void  SortbyName(Stu *stu);

void  SearchbyNum(Stu *stu, int m);
void  SearchbyName(Stu *stu, int m);

void  StatisticAnalysis(Stu *stu, int m);
void countRate(Grade *course);
void showAnalize(Grade *course, int num);

int   Ascending(float a, float b) ;
int   Descending(float a, float b) ;

void distribute(Stu *stu, int n);

#endif
