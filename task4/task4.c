#include <stdlib.h>	
#include <stdio.h>	 
#include <math.h>	

#include "amplitude_value.h"
#include "smooth.h"




void main(int argc, char** argv)
{
	int count = 0;
	float x, amplitude;
	FILE* inputfile;
	inputfile =fopen(argv[1],"r");

	if (inputfile != NULL)
	{
	
		while(fscanf(inputfile, "%f", &x) !=EOF)
			{
				++count;
			}	
	

		float data[count];
		rewind(inputfile);

		for(int i=0;i<count;i++)
			{
				if(fscanf(inputfile,"%f",&data[i])== EOF)
				{
				break;
				}
			}
	
		fflush(stdout);
		fclose(inputfile);

		amplitude = amplitude_value(data, count);
	    printf("amplitude = %f\n", amplitude);

	    inputfile = fopen("sin_func","r");

	    if(inputfile != NULL)
	    	{
	    		while(fscanf(inputfile,"%f", &x) != EOF)
	    			count2++=;
	    	}
	    	float data2[count2];
	    	rewind(inputfile);
	    	for(int i=0;i<count2;i++)
	    		{
	    			if(fcanf(inputfile,"%f",&data2[i]) ==EOF)
	    			{
	    				break;
	    			}
	    		}
	    		fclose(inputfile);
	    		smooth(data2, count2, 5);
	}

	else
	{
		printf("unable to open file");
	}



}