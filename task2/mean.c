#include <stdlib.h>	/* The standard libary: a collection of common C functions. Needed in almost any useful program */
#include <stdio.h>	/* The standard input/output library: functions for inputting and outputting data. Needed in almost any useful program*/ 
#include <math.h>	/* Math library: common math functions. Needed for almost any program*/
//#include <mean.h>


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

    //return(avg);
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

int main()
{
	float array [] ={0.068038, 0.173967, 0.439303, 0.615258, 0.789436, 0.770980, 0.890924, 1.034431, 0.955555, 0.991579, 0.919359, 0.857244, 
		0.680064, 0.558250, 0.473129, 0.278329, 0.027142, -0.151631, -0.454363, -0.534177, -0.803847, -0.882892, -0.996433, -0.919950, -1.068664,
		 -1.000596, -0.997921, -0.909708, -0.607322, -0.611919, -0.380097, -0.127268};


	mean(array,32);	 
	stddev(array,32);	 

	return 0;
}