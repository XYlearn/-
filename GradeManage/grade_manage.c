#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "grade_manage.h"

inline int   Ascending(float a, float b) {return a>b?1:0;}
inline int   Descending(float a, float b) {return a<b?1:0;}

/*内存分配*/
void distribute(Stu **stu, int n)
{
	int i;
	*stu = (Stu *)calloc(sizeof(Stu),1);
	Stu *stuTail=*stu;
	for(i=0;i<n-1;i++)
	{
		stuTail->next=(Stu *)calloc(sizeof(Stu),1);
		stuTail=stuTail->next;
	}
	stuTail->next=NULL;
}

/*---IO函数---*/
/*显示菜单*/
int Menu(void)
{
	printf("Management for Students' scores\n");
	printf("1.Input record\n");
	printf("2.Caculate total and average score of every course\n");
	printf("3.Caculate total and average score of every studen\n");
	printf("4.Sort in descending order by score\n");
	printf("5.Sort in ascending order by score\n");
	printf("6.Sort in ascending order by number\n");
	printf("7.Sort in dictionary order by name\n");
	printf("8.Search by number\n");
	printf("9.Search by name\n");
	printf("10.Statistic analysis\n");
	printf("11.List record\n");
	printf("12.Write to a file\n");
	printf("13.Read from a file\n");
	printf("0.Exit\n");
	printf("Please Input your choice:\n");
   return 0;
}

/*从键盘读取成绩*/
void  ReadScore(Stu *stu, int *m)
{
	int j;
	do
	{
		printf("Input course number(m<=6):\n");
		scanf("%d", m);
	}while(*m<0 || *m>6);

	printf("Input student's ID, name and score:\n");
	for(;stu!=NULL;stu=stu->next)
	{
		scanf("%ld%s", &stu->num,stu->name); /*get student id and name*/
		/*read score of each student*/
		for(j=0;j<*m;j++)
			scanf("%f", &stu->score[j]);
	}
}

/*在屏幕上打印全班成绩*/
void  PrintScore(Stu *stu,int m)
{
	for(;stu!=NULL;stu=stu->next)
		display(stu, m);
}

/*显示某学生成绩情况*/
void display(Stu *stu, int m)
{
	int j;
	printf("%10ld%10s\t", stu->num, stu->name);
	for(j=0;j<m;j++)
	{
		printf("%.0f\t", stu->score[j]);
	}
	printf("%.0f\t%.0f\n", stu->sum, stu->aver );
}

/*将数据写入文件*/
void  WritetoFile(Stu *stu,int n, int m)
{
	FILE  *fp;
	int i,j;
	if((fp = fopen("student.txt", "w"))==NULL)
	{
		printf("file cant be opened!\n");
		return;
	}
	else
	{
		fprintf(fp, "%d\t%d\n", n, m);
		for(i=0;i<n;i++)
		{
			fprintf(fp, "%10ld%10s\t", stu->num, stu->name);
			for(j=0;j<m;j++) 	
			{
				fprintf(fp,"%.0f\t", stu->score[j]);
			}
			fprintf(fp,"%.0f\t%.0f\n", stu->sum, stu->aver );
			stu=stu->next;
		}
	}
	fclose(fp);
}

/*从文件中读取成绩*/
void  ReadfromFile(Stu *stu,int *n, int *m)
{
	FILE *fp;
	int i,j;
	int temp = *n;
	if((fp = fopen("student.txt", "r")) == NULL)
	{ 	
		printf(" Fail to open student.txt \n");
		return ;
	}
	else
	{

		fscanf(fp, "%d\t%d\n",n, m);
		if(temp<*n)
		{
			free(stu);
			distribute(stu, *n);
		}

		for(i=0;i<*n;i++)
		{
			fscanf(fp, "%10ld%10s\t", &stu->num, stu->name);
			for(j=0;j<*m;j++)
			{
				fscanf(fp,"%f\t", &stu->score[j]);
			}
			fscanf(fp, "%f\t%f\n", &stu->sum, &stu->aver);
			stu=stu->next;
		}
		printf("Import Successfully!\n");
	}
}

/*---计算平均成绩的函数---*/
/*计算每个学生的平均成绩*/
void  AverSumofEveryStudent(Stu *stu, int m)
{
	int j;
	for(;stu!=NULL;stu=stu->next)
	{
		for(j=0;j<m;j++)
		{
			stu->sum+=stu->score[j];
		}
		stu->aver=stu->sum/m;
		printf("student %ld: sum=%.0f,aver=%.0f\n", stu->num, stu->sum, stu->aver);
	}
}

/*计算没门课的平均成绩*/
void  AverSumofEveryCourse(Stu *stu, int n, int m)
{
	int i,j;
	float aver,sum=0;
	Stu *temp;
	for(i=0;i<m;i++)
	{
		temp=stu;
		sum=0;
		for(j=0;j<n;j++, temp=temp->next)
			sum+=temp->score[i];
		aver=sum/n;
		printf("course %d:sum=%.0f,aver=%.0f\n", i+1, sum, aver);
	}
}

/*---排序函数---*/
/*排序函数模板*/
void sort(Stu *head, int (*compare)(float,float))
{
	Stu  *i,*j;
	Stu  *term;
	for(i=head;i!=NULL;i=i->next)
	{
		term = i;
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(compare(term->sum, j->sum))
				term = j;
		}
		if(term!=i)
			swap(i, term);
	}
}

/*交换学生数据*/
void swap(Stu *stu1, Stu *stu2)
{
	Stu temp;
	temp = *stu1;
	*stu1 = *stu2;
	*stu2 = temp;
	temp.next=stu1->next;
	stu1->next=stu2->next;
	stu2->next=temp.next;
}

/*按分数排序*/
void  SortbyScore(Stu *stuHead,int  (*compare)(float,float) )
{
	sort(stuHead,compare);
}

/*按学号排序*/
void  AsSortbyNum(Stu *stu)
{
	Stu  *i,*j;
	Stu  *term;
	for(i=stu;i!=NULL;i=i->next)
	{
		term = i;
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(Ascending(term->num, j->num))
				term = j;
		}
		if(term!=i)
			swap(i, term);
	}
}

/*按名字排序*/
void  SortbyName(Stu *stu)
{
	Stu  *i,*j;
	Stu  *term;
	for(i=stu;i!=NULL;i=i->next)
	{
		term = i;
		for(j=i->next;j!=NULL;j=j->next)
		{
			if(strcmp(term->name, j->name)>0)
				term = j;
		}
		if(term!=i)
			swap(i, term);
	}
}

/*---搜索函数---*/
/*按学号搜索*/
void  SearchbyNum(Stu *stu, int m)
{
	long search;
	printf("Input the number you want to search:\n");
	scanf("%ld", &search);
	while(stu!=NULL && stu->num!=search)
		stu=stu->next;
	if(stu==NULL)
		printf("Not found!\n");
	else
		display(stu, m);
}

/*按姓名搜索*/
void  SearchbyName(Stu *stu, int m)
{
	char name[30];
	printf("Input the name you want to search:\n");
	scanf("%s",name);
	while(stu!=NULL && strcmp(stu->name, name))
		stu=stu->next;
	if(stu==NULL)
		printf("Not found\n");
	else
		display(stu, m);
}

/*---统计函数---*/
/*分析成绩状况*/
void  StatisticAnalysis(Stu *stu,  int m)
{
	Grade *grade = calloc(sizeof(Grade), m);
	Stu *current;
	int j;
	for(current=stu;current!=NULL;current=current->next)
	{
		for(j=0;j<m;j++)
		{
			if(current->score[j]==100)
				grade[j].a++;
			else if(current->score[j]>=90 && current->score[j]<100)
				grade[j].b++;
			else if(current->score[j]>=80 && current->score[j]<90)
				grade[j].c++;
			else if(current->score[j]>=70 && current->score[j]<80)
				grade[j].d++;
			else if(current->score[j]>=60 && current->score[j]<70)
				grade[j].e++;
			else
				grade[j].f++;
		}
	}
	for(j=0;j<m;j++)
	{
		countRate(&grade[j]);
		showAnalize(&grade[j], j+1);
	}

}
/*计算各个分数段学生比例*/
void countRate(Grade *course)
{
	int sum=0;
	sum+=course->a+course->b+course->c+course->d+course->e+course->f;
	course->aRate = (float)course->a/sum*100;
	course->bRate = (float)course->b/sum*100;
	course->cRate = (float)course->c/sum*100;
	course->dRate = (float)course->d/sum*100;
	course->eRate = (float)course->e/sum*100;
	course->fRate = (float)course->f/sum*100;
}
/*打印分析结果*/
void showAnalize(Grade *course, int num)
{
	printf("For course %d:\n", num);
	printf("<60\t%d\t%.2f%%\n", course->f, course->fRate );
	printf("60-69\t%d\t%.2f%%\n", course->e, course->eRate );
	printf("70-79\t%d\t%.2f%%\n", course->d, course->dRate );
	printf("80-89\t%d\t%.2f%%\n", course->c, course->cRate );
	printf("90-99\t%d\t%.2f%%\n", course->b, course->bRate );
	printf("100\t%d\t%.2f%%\n", course->a, course->aRate );
}



