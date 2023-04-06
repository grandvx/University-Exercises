#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	float a,area,vol,area_sph,vol_sph;
	const float pi = 3.14;
	system ("chcp 1253");
	
	printf("Give the length of the edge of the cube in metres: \n");
	scanf("%f", &a);
	area = 6*a*a;
	printf("The area of the cube is: %f \n",area);
	vol = a*a*a;
	printf("The volume of the cube is: %f \n",vol);
	area_sph = 4*pi*a*a;
	printf("The area of a sphere with a radius of the same length as the edge of the cube is: %f \n",area_sph);
	vol_sph = (4/3)*pi*a*a*a;
	printf("The volume of a sphere with a radius of the same length as the edge of the cube is: %f \n",vol_sph);
	return 0;
}
