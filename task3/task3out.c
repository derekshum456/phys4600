#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	


/*JAMES: Separate out printing and calculating. Catch if array_length = 0 */

float mean(float* input,int array_length)
{
	int i;
	float sum = 0;
	float avg;
	for(i=0; i<array_length; i++)
	{
    sum += input[i];
	}
	avg = sum/array_length;
	printf("mean = %f\n", avg);
	return(avg);
}

float stddev(float* input, int array_length)
{
	int i;
	float sum = 0;
	float sum2;
	float avg;
	float avg2;
	float standarddev;

	for(i=0; i<array_length; i++)
	{
    sum += input[i];

	}
	avg = sum/array_length;
    //printf("mean=%f", avg);
    

	for(i=0;i<array_length;i++)
	{
		sum2 += pow((input[i] - avg),2);
	}

	avg2 = sum2/array_length;
	standarddev= sqrt(avg2);
	printf("standard deviation = %f", standarddev);
}



void main(int argc, char** argv)
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
	printf("%d\n",count);

	rewind(inputfile);
	fflush(stdout);
	float j[count], k[count];

	for (int a = 0; a <count; a++)
	{
		fscanf(inputfile, "%f %f", &j[a], &k[a]);
	}
	/*JAMES: So your stddev function also calculates the mean, so with this you have calculated the mean twice. 
	Maybe your stddev could return the mean through a pointer variable so you only have to calculate it once */
	mean(k,count);
	stddev(k,count);


}



