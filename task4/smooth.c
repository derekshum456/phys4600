#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	
#include <time.h>

float main(int argc, char** argv)
{
	FILE* inputfile;
	inputfile =fopen(argv[1],"r");

	int count = 0;
	float x;

	if (inputfile != NULL)
	{
	
	while(fscanf(inputfile, "%f", &x) !=EOF)
		{
			++count;
		}	
	}
	
	rewind(inputfile);
	fflush(stdout);

	float j[count], avg[count], sum;
	int smooth = 5;

	for (int i=0; i<count;i++)
	{
		fscanf(inputfile, "%f", &j[i]);
		//printf("%f", j[a]);
	}


	for (int b=0; b <count-smooth; b++)
	{
	sum = 0;	

	for(int a=0; a<smooth; a++)
			{
				sum += j[a+b];
				avg[b] = sum/smooth;
				printf("%f\n", avg[b]);
			}	

	}
	
}
