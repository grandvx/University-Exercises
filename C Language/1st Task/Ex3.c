#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	double a,b,c,s,area;
	
	printf("Give the length of the 1st side: \n");
	scanf("%lf", &a);
	printf("Give the length of the 2nd side: \n");
	scanf("%lf", &b);
	printf("Give the length of the 3rd side: \n");
	scanf("%lf", &c);
	s = (a + b + c) / 2;
	area = sqrt(s * (s - a) * (s - b) * (s - c));
	printf("The area of the triangle is: %.2lf \n", area);
	return 0;
}