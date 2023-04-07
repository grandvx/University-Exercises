#include <stdio.h>
#include <math.h>
int main()
{
	double a, b, c, det, x1, x2;
	printf("I have the quadratic equation ax^2 + bx + c = 0. \n");
	printf("Give a, b, c: ");
	scanf("%lf %lf %lf", &a, &b, &c);
	
	det = b*b-4*a*c;
	
	if (det > 0)
	{
		x1 = (-b + sqrt(det)) / (2 * a);
		x2 = (-b - sqrt(det)) / (2 * a);
		printf("Two real roots: x1 = %lf and x2 = %lf", x1, x2);
	}
	else if (det == 0)
	{
		x1 = -b / (2 * a);
		printf("A double root: x = %lf", x1);
	}
	else if (det < 0)
	{
		printf("It's not possible in R.");
	}
	return 0;
}
