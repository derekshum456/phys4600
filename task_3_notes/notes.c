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

NOTES
ViSession scopeHandle;
 ViSession FGHandle;

 viFindRsrc(defaultRM, "USB[0-9]::0x0699?*INSTR", ...., dscription);
 viOpen(defaultM, description, ....., scopehandle);

 viFindRsrc(defaultRM, "USB[0-9]::0x1AB1?*INSTR", ...., dscription);
 viOpen(defaultM, description, ....., FGHandle);

 viWrite(scapeHandle, "IDN?/n",6,...);

 viWrite(FGHandle, "IDN?/n",6,...);