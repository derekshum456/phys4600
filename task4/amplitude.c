#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	

void amplitude
{
float j[count], k[count], big =0, small=0, amp;

	for (int a = 0; a <count; a++)
	{
		fscanf(inputfile, "%f %f", &j[a], &k[a]);
		if (big<k[a])
		{
			big=k[a];
		}
		if (small>k[a])
		{
			small=k[a];
		}
	}

	amp= (big-small)/2;

	printf("big = %f\n", big);
	printf("small = %f\n", small);
	printf("amplitude = %f\n", amp);


}