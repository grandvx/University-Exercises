#include <stdio.h>
#include <math.h>
#ifndef PI
#define PI (3.14)
#endif

double sin(double x)
{
	double term = x;
	double result = term;
	int n = 1;
	
	while (fabs(term) >= 1e-6)
	{
		term *= -x * x / ((2 * n) * (2 * n + 1));
		result += term;
		n++;
	}
	
	return result;
}

int main()
{
	double x;
	printf("Give the value of x: ");
	scanf("%lf", &x);
	
	while (x < 0 || x > 2 * PI)
	{
		printf("The value of x must be in the interval [0...2π]. Give again the value of x: ");
		scanf("%lf", &x);
	}
	
	double result = sin(x);
	printf("sin(%.2f) = %.6f\n", x, result);
	return 0;
}
