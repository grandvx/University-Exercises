#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

//Degrees to radian conversion
double degtorad(double degrees)
{
	return degrees * M_PI / 180.0;
}

//Exponential function for positive and negative exponents
double custompow(int base, int exponent)
{
	double result = 1.0;
	
	if (exponent >= 0)
	{
		for (int i = 0; i < exponent; ++i)
		{
			result *= base;
		}
	}
	else
	{
		for (int i = 0; i > exponent; --i)
		{
			result /= base;
		}
	}
	
	return result;
}

int main()
{
	
	int choice, base, exponent, N, K;
	double *numbers, angle;
	
	//Menu
	do
	{
		printf("\nMenu:\n");
        printf("1. Sine calculation: \n");
        printf("2. Cosine calculation: \n");
        printf("3. Exponentiation calculation: \n");
        printf("4. Combinations calculation: \n");
        printf("5. Average calculation: \n");
        printf("6. Exit: \n");
        printf("Choose number (1-6): ");
        
        //Reads the user's selection in the menu
        scanf("%d", &choice);
        
        switch (choice)
        {
        	case 1:
        		//Sine calculation
        		printf("Give the angle in degrees: ");
        		scanf("%lf", &angle);
        		printf("sin(%lf) = %lf\n", angle, sin(degtorad(angle)));
        		break;
        		
        	case 2:
        		//Cosine calculation
        		printf("Give the angle in degrees: ");
        		scanf("%lf", &angle);
        		printf("cos(%lf) = %lf\n", angle, cos(degtorad(angle)));
        		break;
        		
        	case 3:
        		//Exponentiation calculation
        		printf("Give the base and the exponent: ");
        		scanf("%d %d", &base, &exponent);
        		printf("Exponentiation(%d, %d) = %lf\n", base, exponent, custompow(base, exponent));
        		break;
        		
        	case 4:
        		//Combinations calculation
        		printf("Give the N and the K: ");
        		scanf("%d %d", &N, &K);
        		
        		if (N < K)
        		{
        			printf("Invalid entry. N must be >= (greater than or equal to) K..");
				}
				else
				{
					int result = 1;
					int minK = (K < N -K) ? : (N - K); //Using the formula C(N,K) = N!/K!(N-K)! where N! is the factorial of N.
					
					//Calculation of combinations using the factorial
					for (int i = 1; i <= minK; ++i)
					{
						result *= N - i + 1;
						result /= i;
					}
					
					printf("Combinations(%d, %d) = %d\n", N, K, result);
				}
				break;
				
			case 5:
				//Average calculation
				printf("Give the N: ");
				scanf("%d", &N);
				
				numbers = (double *)malloc(N * sizeof(double)); //I use malloc and free below to avoid overflow (I point this out because while I run the code without these two it crashed or didn't even output anything in the cmd).
				
				for (int i = 0; i < N; i++)
				{
					printf("Give number %d: ", i + 1);
					scanf("%lf", &numbers[i]);
				}
				
				double sum = 0.0;
				
				//Calculating the sum of N numbers.
				for (int i = 0; i < N; i++)
				{
					sum += numbers[i];
				}
				
				printf("Average: %lf\n", sum / N);
				
				free(numbers); //Free dynamically allocated memory
				break;
				
			case 6:
				printf("Exit program.\n");
				break;
				
			default:
				printf("Invalid option. Try again.\n");
		}
	}
	while (choice != 6);
	
	return 0;
}
