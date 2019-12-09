#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	
#include <time.h>

float smooth(float*data, int size, int smooth_factor)
{
	FILE* inputfile;
	float average, sum
	int i=0;
	

	if(smooth>size) 
		return 0; //check if avg is largert than data size
	
		inputfile =fopen(sin_func, "w");

		if(inputfile != NULL)
			{
				for(int i=0; i<size-smooth;i++)
					{
						sum = 0;
						for(int j=0; j<smooth; j++)
							{
								sum += data[i+j];
							}
							average = sum/smooth;
							fprintf(inputfile, "%f\n", average);
					}
			}
				
}
