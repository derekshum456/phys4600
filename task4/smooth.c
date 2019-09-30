#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	
#include <time.h>




float main(int argc, char** argv)
{
	FILE* inputfile;
	inputfile =fopen(argv[1],"r");

	int count = 0;
	float x, y;

	if (inputfile != NULL)
	{
	
	while(fscanf(inputfile, "%f %f", &x, &y) !=EOF)
		{
			++count;
		}	
	}
	
	rewind(inputfile);
	fflush(stdout);
	float j[count], k[count], avg = 0, sum = 0;
	int smooth = 5, b =0;
	for (int a = 0; a <count-smooth; a++)
	{
		fscanf(inputfile, "%f", &j[a]);
			
			for(b = 0; b<smooth; b++)
			{
				sum += j[a+b];
				avg = sum/smooth;
				printf("%f\n", avg);
			}

		//avg=(j[a]+j[a+1]+j[a+2]+j[a+3]+j[a+4])/5;
		//printf("%f\n", avg);
	}

}