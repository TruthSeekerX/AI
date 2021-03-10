/********************************************************************************************************************************************
* This is the main file of the Neural Nod project. It is meant for first year C programming introduction course lectured by Johan Dams.  
* Language: C
* Author:Siyuan e2002077
* Version: v0.2
*	   In this version
* 10.03.2021
*********************************************************************************************************************************************/
#include <stdio.h>		//for standard IO
#include <stdint.h>		//for int datatypes
#include <stdlib.h>		//for rand() and srand() functions
#include <time.h>		//for time() function
#include "ai_train.h"		//for ai_train() function

int main(int argc, char *argv[]){
	double snptc_wghts[3];		//global variable for synaptic weights
	uint32_t itrt;
	
	srand(time(NULL));	//NULL is equivalent as 0 here. srand initialise the sudo-random function with base of time() function.
	
	snptc_wghts[0]=2.0 * (float)rand() / RAND_MAX -1.0;		//normalise the sudo-random number between [-1,1]. And store the value to snptc_wghts[]
	snptc_wghts[1]=2.0 * (float)rand() / RAND_MAX -1.0;
	snptc_wghts[2]=2.0 * (float)rand() / RAND_MAX -1.0;
	
	double	trn_inpts[4][3] = {{0.0,0.5,1},{0.5,0,0},{0.9,0.1,0.1},{0.5,0.9,0.9}};
	double	trn_otpts[4]={0,1,1,0};
	
	
	printf("How many time of iterations would you like to ai_train?\n");
	scanf(" %ud", &itrt);
	
	ai_train(trn_inpts, trn_otpts, snptc_wghts, itrt); 		//calling ai_train() function
	
	return 0;
}
