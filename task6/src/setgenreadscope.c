#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>
#include <string.h>
#include "setfgreadscope.h"
#include "amplitude_value.h"
#include "smooth.h"
#include "inputdata.h"

#define DATA_LENGTH 2500

void setfgreadscope(ViSession funcHandle,ViSession scopeHandle,double* amplitude,double* frequency,int* datacount,char* filename)
{
	ViStatus status = VI_SUCCESS;
	ViUInt32 num_inst;
	ViUInt32 resultCount;
	char* commandstart=":SOUR1:FREQ %d\n"; //adjestable frequency
	char command[36], dataBuffer[DATA_LENGTH];
	unsigned char division[30];
	float voltscale, conversion;
	double data[DATA_LENGTH], smoothData[DATA_LENGTH];
	int startfrequceny, endfrequency;
	int step = 1000,run=0;

	inputdata(&startfrequceny,&endfrequency,filename);

	printf("start=%d end=%d",startfrequceny,endfrequency);

	viWrite(scopeHandle,"DAT:SOU CH1\n",12,&resultCount); //set to read oscilloscope from ch1

	for(int i=startfrequceny;i<=endfrequency;i+=step)
	{
		viWrite(funcHandle,":SOUR1:FUNC SIN\n",16,&resultCount); //set the waveform of CH1 to sine
		sprintf(command,commandstart,i);
		viWrite(funcHandle,command,strlen(command),&resultCount); //set the frequency
		viWrite(funcHandle,":OUTP1 ON\n",9,&resultCount);

		viWrite(scopeHandle,"AUTOS EXEC\n",11,&resultCount); //autoscale
		sleep(3);

		viWrite(scopeHandle,"CH1:SCA?\n",9,&resultCount);
		viRead(scopeHandle,division,256,&resultCount); //read osilloscope scale
		sscanf(division,"%f",&voltscale); //convert character to float
		printf("\nscale = %fV\n",voltscale);
		conversion = voltscale*10/256; //convert from devision to volt

		viWrite(scopeHandle,"CURV?\n",6,&resultCount); 
		viRead(scopeHandle,dataBuffer,DATA_LENGTH,&resultCount); //put the curve in databuffer
		for(int j=0;j<DATA_LENGTH;j++)
		{
			data[j]=dataBuffer[j]*conversion;
			//printf("\nfrequency=%d, volt = %f",i,data[j]);
		}
		smooth(data, DATA_LENGTH, 5, smoothData);

		frequency[run]=i;
		amplitude[run] = find_amplitude(smoothData, DATA_LENGTH);
		*datacount = ((endfrequency-startfrequceny)/step)+1;
		printf("frequency=%lf, amplitude = %lf",frequency[run],amplitude[run]);
		run++;
	}
}