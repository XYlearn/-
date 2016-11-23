#include <stdio.h>
#include <stdlib.h>
#include "grade_manage.h"

int main()
{
	Stu *stu;
	int n=0;	/*stuNum*/
	int m=0;		/*courseNum*/
	int selection=0,i;
	printf("Input student number(n<30):\n");
	do
	{
		if(!scanf("%d", &n) || n<=0 || n>30)
		{
			fflush(stdin);
			printf("Input student number(n<30):\n");
		}
		else break;
	}while(1);

	/*初始化分配内存*/
	distribute(&stu, n);

   /*进入选择菜单*/
	do
	{
		Menu();       /*打印菜单*/
		fflush(stdin);  /*刷新缓冲区*/
		scanf("%d", &selection);

		/*确保选择正确*/
		if (selection<0 || selection>13)
		{
			printf("Input error!\n");
			continue;
		}

		/*主体*/
		switch(selection)
		{
		case 0:/*结束程序*/
			printf("End of program!\n");
			exit(0);
		case 1:/*从键盘读取*/
			ReadScore(stu, &m);
			break;
		case 2:/*计算各课程平均成绩与总成绩*/
			AverSumofEveryCourse(stu, n, m);
			break;
		case 3:/*计算每个学生的平均成绩与总成绩*/
			AverSumofEveryStudent(stu, m);
			break;
		case 4:/*根据总分降序排序*/
			SortbyScore(stu, Descending);
			break;
		case 5:/*根据总分升序排序*/
			SortbyScore(stu,Ascending);
			break;
		case 6:/*根据学号升序排序*/
			AsSortbyNum(stu);
			break;
		case 7:/*根据名字在字母表中顺序排序*/
			SortbyName(stu);
			break;
		case 8:/*根据学号查询*/
			SearchbyNum(stu, m);
			break;
		case 9:/*根据名字查询*/
			SearchbyName(stu, m);
			break;
		case 10:/*数据分析*/
			StatisticAnalysis(stu, m);
			break;
		case 11:/*打印成绩*/
			PrintScore(stu, m);
			break;
		case 12:/*写入程序*/
			WritetoFile(stu,n, m);
			break;
		case 13:/*从程序读取*/
			ReadfromFile(stu,&n, &m);
			break;
		}
	}while(1);

	return 0;
}
