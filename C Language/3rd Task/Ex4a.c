#include <stdio.h>

int main()
{
	float x = 0.0;
	int i = 1;
	
	while (x <= 10.0)
	{
		x += 0.1;
		
		printf("Step: %d, x: %f\n", i, x);
		i++;
	}
	
	return 0;
}