#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	


float x;
float y;


void main(int argc, char** argv)
{
	FILE* inputfile;
	inputfile =fopen("sin_func","r");

	int count;
	if (inputfile != NULL)
	{
	
	while(fscanf(inputfile, "%f %f", &x, &y) !=EOF)
		{
			count++;
		}	
	}
	






}