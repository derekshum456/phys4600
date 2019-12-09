#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	
#include "amplitude_value.h"

float amplitude_value(float* data,int count)
{
	float k[count], max =0, min=0, amp;

	for (int a = 0; a <count; a++)
	{
		
		if (data[a]>max)
		{
			max=k[a];
		}
		if (min<k[a])
		{
			min=k[a];
		}
	}

	amp= (max-min)/2;

	return(amp);
}