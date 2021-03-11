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
#include "ai_train.h"	//for ai_train() function
#include "ai_detec.h"	//for ai_detec() function

int main(int argc, char *argv[]){
	double snptc_wghts[3];		//global variable for synaptic weights
	uint32_t itrt;
	double rgb[3];
	char ans;
	uint8_t flg_r=0,opt=0;
	uint8_t *ptr_flg_r;
	
	
	ptr_flg_r = &flg_r;
	
	srand(time(NULL));	//NULL is equivalent as 0 here. srand initialise the sudo-random function with base of time() function.
	
	snptc_wghts[0]=2.0 * (float)rand() / RAND_MAX -1.0;		//normalise the sudo-random number between [-1,1]. And store the value to snptc_wghts[]
	snptc_wghts[1]=2.0 * (float)rand() / RAND_MAX -1.0;
	snptc_wghts[2]=2.0 * (float)rand() / RAND_MAX -1.0;
	
	double	trn_inpts_1[4][3] = {{0.0,0.5,1},{0.5,0,0},{0.9,0.1,0.1},{0.5,0.9,0.9}};
	double	trn_otpts[4]={0,1,1,0};
	
	
	printf("How many time of iterations would you like to ai_train?\n");
	scanf(" %ud", &itrt);
	
	ai_train(trn_inpts_1, trn_otpts, snptc_wghts, itrt); 		//calling ai_train() function
	
	printf("1. Input a colour manually.\n2. Find a red colour from randomly generated colours.\n Please choose 1 or 2 and press enter.\n");
	scanf(" %hhu",&opt);
	
	uint32_t cnt = 0;
	
	switch(opt){
		case 1 :
			do{
				printf("please input the colour in R:G:B format. Beawre the RGB values are within range [0,1]. For example, '1:0.1:0.1'.\n");
				scanf(" %lf:%lf:%lf",&rgb[0],&rgb[1],&rgb[2]);
				ai_detec(rgb,snptc_wghts,ptr_flg_r);
				printf("Click the link too see your colour. www.colours.com/%hhu:%hhu:%hhu\n",(uint8_t)(rgb[0]*255),(uint8_t)(rgb[1]*255),(uint8_t)(rgb[2]*255));
				printf("Would you like to input another colour? Press y to continue, press any key else to quit.\n");
				scanf(" %c",&ans);
				if(ans != 'y')break;
			} while(1);
			break;
		case 2 :
			do{
				
				cnt++;
				printf("Generating and analysing colours...Please wait.\n");
				rgb[0] = (float)rand() / RAND_MAX;
				rgb[1] = (float)rand() / RAND_MAX;
				rgb[2] = (float)rand() / RAND_MAX;
				
				ai_detec(rgb,snptc_wghts,ptr_flg_r);
			} while (flg_r != 1);
			printf("Found red colour after %u times.\n",cnt);
			printf("Click the link too see your colour. www.colours.com/%hhu:%hhu:%hhu\n",(uint8_t)(rgb[0]*255),(uint8_t)(rgb[1]*255),(uint8_t)(rgb[2]*255));
			break;
	}
	return 0;
}
