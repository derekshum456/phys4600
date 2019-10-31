#include <stdio.h>
#include <stdlib.h>
#include <math.h>	
#include <visa.h>

void main(int argc, char** argv)
{
	unsigned char resultBuffer[256], scale[256], freq[250];
	ViStatus status = VI_SUCCESS;
	ViFindList resourceList;
	ViUInt32 num_inst;
	ViUInt32 resultCount;

	ViSession defaultRM, scopeHandle, funcHandle;
	ViChar description[VI_FIND_BUFLEN];
	char dataBuffer[2500];

	

	int y;
	float z[2500], volts, x[2500], frequency;

	int lsb;
	int msb;

	status = viOpenDefaultRM(&defaultRM);

	if(status == VI_SUCCESS)
	{
		status = viFindRsrc(defaultRM,"USB[0-9]::0x0699?*INSTR",	&resourceList,&num_inst,description); //looks for device
		if(status == VI_SUCCESS)
		{
			status = viOpen(defaultRM,description,	VI_NULL,VI_NULL,&scopeHandle);

			if(status == VI_SUCCESS)
			{
				printf("\nOpened %s\n",description);
				
				viWrite(scopeHandle,"*IDN?\n",6,&resultCount);
				viRead(scopeHandle,resultBuffer,256,&resultCount);
				printf("\nResult buffer = %s\n",resultBuffer );

				status = viFindRsrc(defaultRM,"USB[0-9]::0x1AB1?*INSTR",	&resourceList,&num_inst,description); //looks for fg
				if(status == VI_SUCCESS)
				{
					status = viOpen(defaultRM,description,	VI_NULL,VI_NULL,&funcHandle);

					if(status == VI_SUCCESS)
					{

						printf("\nOpened %s\n",description);
				
						viWrite(scopeHandle,"*IDN?\n",6,&resultCount);
						viRead(funcHandle,resultBuffer,256,&resultCount);
						printf("\nResult buffer = %s\n",resultBuffer );

						viWrite(scopeHandle,"DAT:SOU CH1\n",12,&resultCount);
						viWrite(scopeHandle,"CURV?\n",6,&resultCount);
				
						viRead(scopeHandle,dataBuffer,2500,&resultCount);
				
				
						viWrite(scopeHandle,"CH1:SCAle?\n",11,&resultCount);
						viRead(scopeHandle,scale,256,&resultCount);
						sleep(2);
						sscanf(scale,"%f", &volts); // measures voltage depending on grid area
						float q = volts*10/256;

						for(int i = 0; i<2500; i++)
						{
							y = dataBuffer[i];
							x[i] = dataBuffer[i]*q;
					
							//printf("\nRaw = %x,  Read = %d, voltage = %f",y,y,x[i]);
						}
				
								//viWrite(scopeHandle,"CH1:VOLts 100E-2\n",16,&resultCount);
						//viWrite(scopeHandle,"CH1:POSition 1.2\n",16,&resultCount);

						viWrite(funcHandle,":SOUR1:FUNC SIN\n",17,&resultCount);
						viWrite(funcHandle,":SOUR1:VOLT 3.0\n",17,&resultCount);
					}
				}
			}
			else
			{
				printf("\nFailed to open %s",description);
			}
		}
		else
		{
			printf("\nCouldn't find any instruments");
		}
	}
	else
	{
		printf("\nFailed to open defaultRM");
	}
}