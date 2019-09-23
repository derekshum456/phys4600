#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	


//float output;


int main()
{

	int i;

	FILE* inputfile;
	inputfile =fopen("sin_func","w");
	

	for (int i = 0; i <=360; i+=1)
	{
		float input = i;
		float output = sin(i/(2*M_PI));

		fprintf(inputfile,"%f %f\n",input, output);
	}











}