#include <stdlib.h>	
#include <stdio.h>




int main()
{
	float inputx;
	int correct;

	do{
		printf("please enter a number\n");
		fflush(stdout);	
		fflush(stdin);	
		correct = scanf("%f", &inputx);

			//printf("number = %d %f\n",correct,inputx); test to show values
	
	  



		if(correct == 1)
		{
			printf("number = %f\n %d",inputx,correct);

		}
	
		else
		{
			printf("try again\n");
		}
	   }
	   while(scanf("%f",&inputx) == 0);	

}