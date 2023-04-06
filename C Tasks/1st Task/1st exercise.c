#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	int a,b,add,min,mul,div,quo,squ;
	float true_quo;
	double root;
	system("chcp 1253");
	printf("Give the 1st number: \n");
	scanf("%d", &a);
	printf("Give the 2nd number: \n");
	scanf("%d", &b);
	add = a+b;
	printf("The sum of the two numbers is: %d \n",add);
	min = a-b;
	printf("The difference between the two numbers is: %d \n",min);
	mul = a*b;
	printf("The product of the two numbers is: %d \n",mul);
	div = a/b;
	printf("The quotient of the two numbers is: %d \n",div);
	quo = a%b;
	printf("The remainder of the two numbers is: %d \n",quo);
	true_quo = (float) a/b;
	printf("The real remainder of the two numbers is: %f \n",true_quo);
	squ = a*a;
	printf("The square of the first number is: %d \n",squ);
	root = sqrt(b);
	printf("The square root of the second number is: %lf \n",root);
	return 0;
}
