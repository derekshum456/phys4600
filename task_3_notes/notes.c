#include <stdlib.h>	
#include <stdio.h>

int main()
{
	FIlE * input_file;

	input_file = fopen("file.name","r"); //reads the file

	fscanf(input_file, "%f %f", &x, &y); //open file

	fclose(input_file;); //close file

	input_file =fopen("hello.txt","w");

	fprintf(input_file,"\n%f %f",x,y)

}