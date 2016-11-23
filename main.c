#include <stdio.h>
#include <stdlib.h>
#include "grade_manage.h"

int main()
{
	Stu *stu, *stuTail;
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
	/*distribute memory for Stu */
	stu = (Stu *)calloc(sizeof(Stu),1);
	Stu *temp=stu;
	stuTail=stu;
	for(i=0;i<n-1;i++)
	{
		stuTail->next=(Stu *)calloc(sizeof(Stu),1);
		stuTail=stuTail->next;
	}
	stuTail->next=NULL;

	do
	{
		Menu();
		fflush(stdin);
		scanf("%d", &selection);

		/*make sure the input is valid*/
		if (selection<0 || selection>13)
		{
			printf("Input error!\n");
			continue;
		}

		/*get into selection*/
		switch(selection)
		{
		case 0:
			printf("End of program!\n");
			exit(0);
		case 1:
			ReadScore(stu, n, &m);
			break;
		case 2:
			AverSumofEveryCourse(stu,n ,m);
			break;
		case 3:
			AverSumofEveryStudent(stu,n, m);
			break;
		case 4:
			SortbyScore(stu, Descending);
			break;
		case 5:
			SortbyScore(stu,Ascending);
			break;
		case 6:
			AsSortbyNum(stu);
			break;
		case 7:
			SortbyName(stu);
			break;
		case 8:
			SearchbyNum(stu, m);
			break;
		case 9:
			SearchbyName(stu, m);
			break;
		case 10:
			StatisticAnalysis(stu, m);
			break;
		case 11:
			PrintScore(stu, n, m);
			break;
		case 12:
			WritetoFile(stu,n, m);
			break;
		case 13:
			ReadfromFile(stu,&n, &m);
			break;
		}
	}while(1);

	return 0;
}