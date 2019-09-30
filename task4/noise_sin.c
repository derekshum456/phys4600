#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	
#include <time.h>




int main()
{

	int i;

	FILE* inputfile;
	inputfile =fopen("sin_func","w");
	
	srand(time(NULL));
	float r;

	for (int i = 0; i <=360; i+=1)
	{
		float input = i;
		float output = sin(i*M_PI/(180));
		r = (float)rand()/(float)RAND_MAX;
		output+=(r/10);

		fprintf(inputfile,"%f\n", output);
	}


}