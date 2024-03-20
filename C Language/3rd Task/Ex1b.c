#include <stdio.h>

int main()
{
	int N, num;
	int count = 0;
	int summultof3 = 0;
	int promultof4 = 1;
	int pronegnum = 1;
	
	printf("Give the value of N: ");
	scanf("%d", &N);
	
	if (N % 2 !=0)
	{
		printf("N must be an even number. \n");
		return 1;		
	}
	
	do {
		printf("Give an integer: ");
		scanf("%d", &num);
		count++;
		
		if (num % 3 == 0)
		{
			summultof3 += num;
		}
		
		if (num % 4 == 0)
		{
			promultof4 *= num;
		}
		
		if (num < 0)
		{
			pronegnum += num;
		}
		} while (count < N);
	
	printf("Sum of numbers given as input %d\n", count);
	if (count > 0)
	{
		printf("The average of the multiples of 3 is: %.2f\n", (float)summultof3 / count);
		printf("The product of the multiples of 4 is: %d\n", promultof4);
		if (pronegnum != 1)
		{
			printf("The product of the negative numbers is: %d\n", pronegnum);	
		}
		else
		{
			printf("No negative numbers were found.\n");
		}
	}
	
	return 0;
}
