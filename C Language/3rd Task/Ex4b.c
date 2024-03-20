#include <stdio.h>

int main()
{
	double x = 0.0;
	int i = 1;
	
	while (x <= 10.0)
	{
		x += 0.1;
		
		printf("Step: %d, x: %lf\n", i, x);
		i++;
	}
	
	return 0;
}