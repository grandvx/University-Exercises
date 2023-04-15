#include <stdio.h>
#include <math.h>
int main()

{
	int i, j, space, rows, stars;
	
	//1st Figure
	printf ("Give the number of the lines: ");
	scanf("%d", &rows);
	
	for (i=1; i<=rows; ++i)
	{
		for (j=1; j<=i; ++j)
		{
			printf("* ");
		}
		printf("\n");
	}
	
	//2nd Figure
	for(i=1; i<=rows; ++i)
	{
		for(j=i; j<rows; ++j)
		{
			printf("  ");
		}
		for(j=1; j<=i; ++j)
		{
			printf("* ");
		}
		printf("\n");
	}
	
	//3rd Figure
	for (i=0; i<rows; i++)
	{
		space = rows -1 -i;
		for (j=0; j<space; j++)
		{
			printf(" ");
		}
		stars = 2 * i + 1;
		for(j=0; j<stars; j++)
		{
			if (j==stars / 2)
			{
				printf(".");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");
	}
	
	//4th Figure
 	for (i=1; i<=rows; i++)
 	{
 		for (j=1; j<=rows; j++)
 		{
 			if (j==rows || j==1 || i==1 || i==rows || j==rows)
 			printf("*");
 			else if (j==i || j==rows-(i-1))
 			printf(".");
 			else
 			printf(" ");
		}
		 printf("\n");
	}
	return 0;
 }