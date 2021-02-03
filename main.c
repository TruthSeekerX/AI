/********************************************************************************************************************************************
* This is the main file of the Neural Nod project. It is meant for first year C programming introduction course lectured by Johan Dams.  
* Language: C
* Author:Siyuan e2002077
* Version: v0.1 In this version the program prints 200 results of sigmoid function f(x)=f(x)=1/(1+e^(-x)) and the derivative of
*          the sigmoid function where x∈[-10,10] with increment of 0.1. There is break line "*******" between the two sets of the results.  
*********************************************************************************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include "sigmoid.h"

int main(int argc, char *argv[]){
	
	for(float i=-10.0;i<10.0;i+=0.1){		
	
	/* For Loop (float i)
	   Loops the following procedure 200 times. Calls sigmoid() function with ipunt i∈[-10,10] on each loop,
	   and print the result at the end of each loop.
	*/
		float r=sigmoid(i);
		printf("%f\n",r);
	}
	
	printf("***************************\n");
	
	float i=-10.0;
	while(i>=-10.0&&i<=10.0){
		
	/* While Loop ()
	   Loops the following procedure 200 times. Calls sigmoid_d() function with ipunt i∈[-10,10] on each loop,
	   i starts with -10 and increament by 0.1 on each loop, and print the result at the end of each loop.
	*/
		float r=sigmoid_d(i);
		i+=0.1;
		printf("%f\n",r);
	}

	return 0;
}
