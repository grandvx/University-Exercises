#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415
#define STOP 1e-6

int main (int argc, char **argv)
{	
	int t, pros, paran;
	double x, oros, prog, sum;
	printf("Give the corner: \n");
	scanf("%d", &t);
	x=2*PI*t/360;
	paran=3;
	oros=x;
	sum=oros;
	pros=-1;
	do
	{
		prog=oros;
		oros=oros*x*x/(paran*(paran-1));
		sum+=oros*oros;
		pros*=-1;
		paran+2;
	}
	while(fabs(oros-prog)>STOP);
	printf("The sin of the angle %d is: %f\n",t,sum);
	printf("%f\n", sin(x));
	return 0;
}