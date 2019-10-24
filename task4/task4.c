#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	

#include "amplitude.h"



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
	//printf("%d\n",count);

	rewind(inputfile);
	fflush(stdout);

	amplitude();

	/*
	float j[count], k[count], big =0, small=0, amplitude;

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

	amplitude= (big-small)/2;

	printf("%f\n", big);
	printf("%f\n", small);
	printf("%f\n", amplitude);
*/




}