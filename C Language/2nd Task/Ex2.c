#include<stdio.h>
#include<math.h>
int main()
{
	int month, year;
	printf("Give the month: ");
	scanf("%d",&month);
	printf("Give the year: ");
	scanf("%d", &year);
	if(((month==2) && (year%400==0)) || ((year%100!=0) && (year%4==0)))
	{
		printf("The days of this month in this year are 29.");
	}
	else if(month==2)
	{
		printf("The days of this month in this year are 28.");
	}
	else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
	{
		printf("The days of this month in this year are 31.");
	}
	else
	{
		printf("The days of this month in this year are 30.");
	}
	return 0;
}
