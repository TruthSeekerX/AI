/********************************************************************************************************************************************
* This file is part of the Neural Nod project. It is meant for first year C programming introduction course lectured by Johan Dams.
* It includes ai_detec() function.  
* Language: C
* Author:Siyuan e2002077
* Version: v0.2
*	   In this version:
*	   1. ui_get_ans() and ui_opt() are added for more modular strcture.
*	   2. ui_opt() is added for more modular structure.
*	   3. ai_analys_man() and ai_analys_rand() are added for more modular structure.
*	   4. 
* 14.03.2021
*********************************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "dot_prdt.h"		//for dot_prdt() function
#include "sigmoid.h"		//for sigmoid related functions
#include "ai_generator.h"	//for rand_genf() function

void ai_detec(double rgb[], double snptc_wghts[],uint8_t *ptr_flg){
	//This function take rgb[], snpt_wghts[] as input and *ptr_flg as output. It calculates the possibility of red colour using the inputs. A ture(1) or false(0) will be assigned to *ptr_flg.
	
	double result;
	
	result = sigmoid(dot_prdt(rgb, snptc_wghts, 3));	//The result of sigmoid function of dot product of rgb values with corresponding synaptic weights. 
	*ptr_flg = (result >= 0.6) * 1;		//ptr_flg is ture(1) if the possibilty is equal to or more than 60%. Otherwise ptr_flg is false(0).
	
	printf("The possibility of input colour is red = %lf%%.\n", result * 100); //result x 100
}

int ui_get_ans(char *ptr_ans){
	printf("Would you like to try again? Press y to continue, press any key else to quit.\n");
	scanf(" %c",ptr_ans);
	return 0;
}

int ui_opt(uint8_t *ptr_opt){
	printf("1. Input a colour manually.\n2. Find a red colour from randomly generated colours.\n Please choose 1 or 2 and press enter.\n");
	scanf(" %hhu",ptr_opt);
	
	return 0;
}

int ai_analys_man(double snptc_wghts[]){
	//This function takes user input colour (r:g:b values) and pass them for dectection. It give the possibilty of the colour is red and a website link for viewing the colour will be given. After that user can choose to continue or quit. 
	char ans;		//for storing user input answer
	double rgb[3];		//for storing user input r:g:b values of a colour
	uint8_t flg = 0;	//a flag for indicating true(1) or false(0)
	do{
		printf("please input the colour in R:G:B format. Beawre the RGB values are within range [0,1]. For example, '1:0.1:0.1'.\n");
		scanf(" %lf:%lf:%lf",&rgb[0],&rgb[1],&rgb[2]);
		
		ai_detec(rgb,snptc_wghts,&flg);	//ai_detec() for checking the possibility of input colour is being red. 
		
		printf("Click the link too see your colour. https://convertingcolors.com/rgb-color-%hhu_%hhu_%hhu.html\n",(uint8_t)(rgb[0]*255),(uint8_t)(rgb[1]*255),(uint8_t)(rgb[2]*255));
		
		ui_get_ans(&ans);	//get answer from user to continue or quit.						
		
		if(ans != 'y')break;	//loop breaks when user input 'y' as answer
	} while(1);
	return 0;
}

int ai_analys_rand(double snptc_wghts[]){
	//This function generates random colours and pass them for dectection. When red colour is found, the possibility and a website link for viewing the colourwill be given. After that user can choose to continue or quit. 
	
	char ans;		//for storing user input answer
	double rgb[3];		//for storing user input r:g:b values of a colour
	uint8_t flg = 0;	//a flag for indicating true(1) or false(0)
	do{
		uint32_t cnt = 0;	//for counting how many times of trails.
		do{			
			cnt++;
			printf("Generating and analysing colours...Please wait.\n");	
			rand_genf(0, 1.0, rgb, 3);	//rand_genf() generates double precision sudo-random floating number between [0,1] and fill rgb[] with them.

			ai_detec(rgb,snptc_wghts,&flg);	//ai_detec() for checking the possibility of input colour is being red. 
		} while (flg != 1);			//loop keeps running untill the 
		
		printf("Found red colour after %u times.\n",cnt);
		printf("Click the link too see your colour. https://convertingcolors.com/rgb-color-%hhu_%hhu_%hhu.html\n",(uint8_t)(rgb[0]*255),(uint8_t)(rgb[1]*255),(uint8_t)(rgb[2]*255));
		
		ui_get_ans(&ans);	//ask user for weather to continue or quit
		
		if(ans != 'y')break;	//answer is 'y' to continue, otherwise quit
	} while(1);
	return 0;
}
