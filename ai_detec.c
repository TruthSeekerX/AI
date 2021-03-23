/********************************************************************************************************************************************
* This file is part of the Neural Nod project. It is meant for first year C programming introduction course lectured by Johan Dams.
* It includes miscellaneous functions needed for ai project.
* Language: C
* Author:Siyuan e2002077
* Version: v0.3
*	   In this version:
*	   1. ui_get_ans() and ui_opt() are added for more modular strcture.
*	   2. ui_opt() is added for more modular structure.
*	   3. ai_analys_man() and ai_analys_rand() are added for more modular structure.
*	   4. 
* 23.03.2021
*********************************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "dot_prdt.h"		//for dot_prdt() function
#include "sigmoid.h"		//for sigmoid related functions
#include "ai_generator.h"	//for rand_genf() function

void ai_detec(double rgb[], double snptc_wghts[],uint8_t *ptr_flg){
/***************************************************************************************************************************************************
*****************
* Function : void ai_detec(double rgb[], double snptc_wghts[],uint8_t *ptr_flg)
* Input    : double rgb[], double snptc_wghts[], uint8_t *ptr_flg
* Output   : *ptr_flg
* Procedure: This function takes rgb[], snpt_wghts[] as input and *ptr_flg as output. It calculates the possibility of red colour using the inputs.
*	     The result ture(1) or false(0) will be assigned to *ptr_flg.  
*****************************************************************************************************************************************************
****************/
	
	double result;
	
	result = sigmoid(dot_prdt(rgb, snptc_wghts, 3));	//The result of sigmoid function of dot product of rgb values with corresponding synaptic weights. 
	*ptr_flg = (result > 0.6) * 1;			//ptr_flg is ture(1) if the possibilty is equal to or more than 60%. Otherwise ptr_flg is false(0).
	
	printf("The possibility of input colour is red = %lf%%.\n", result * 100);	//result x 100
}

int ui_get_ans(char *ptr_ans){	//This function asks if user to try again and store the answer to *ptr_ans
	printf("Would you like to try again? Press y to continue, press any key else to quit.\n");
	scanf(" %c",ptr_ans);
	
	return 0;
}

int ui_opt(uint8_t *ptr_opt){		//This function asks user to choose one of the two options and store the answer to *ptr_opt
	uint8_t flg_err;		//delcare a flag for error, the value is 1 when error detected, otherwise is 0
	
	do{
		flg_err = 0;
		printf("1. Input a colour manually.\n2. Find a red colour from randomly generated colours.\n Please choose 1 or 2 and press enter.\n");
		
		if (scanf(" %hhu",ptr_opt) == EOF){
			printf("Input error, please try again.\n");
			flg_err = 1;	//error code 1
			}
		else if(*ptr_opt != 1 && *ptr_opt !=2){
			printf("Input error, please try again.\n");
			flg_err = 2;	//error code 2
		} 
	}while(flg_err != 0);		//the loop runs infinitly untill flg_err = 0, no error detected 
	
	return 0;
}

int ppm_gen(double rgb[]){
/***************************************************************************************************************************************************
*****************
* Function : int ppm_gen(double rgb[])
* Input    : double rgb[]
* Output   : coulour_sample.ppm 
* Procedure: This function takes the value from rgb[] and write them into 1000x1000 pixels monocoloured .ppm file.
*****************************************************************************************************************************************************
****************/
	FILE *pic;		//declare FILE pointer
	pic = fopen("colour_sample.ppm","w+");	//create a file for read and write
	
	if(pic == NULL){				//check for failure. Don't pass NULL pointer to fclose().
		printf("Error: can't create the file.\n");
		return 1;				//return if error.
	}
	else{
		printf("File created successfully.\n");
		fprintf(pic,"P3\n1000 1000\n255\n");	//write the header for the .ppm file.
		
		uint32_t i,j;
		for(i = 0;i < 1000000; i++){		//1000 * 1000 pixels
			for(j = 0; j < 3; j++){
				fprintf(pic, "%hhu ",(uint8_t)(rgb[j]*255));
				}
			fprintf(pic,"\n");		//put a new line for easier reading by humans
		}
		fclose(pic);				//close the file
		printf("file is ready.");
		
//		system("./colour_sample.ppm");	//pessmision denied. Maybe not good idea for security reason
		return 0;				//return 0 if sucess
	}
}

int ai_analys_manual_input(double snptc_wghts[]){
/***************************************************************************************************************************************************
*****************
* Function : int ai_analys_manual_input(double snptc_wghts[])
* Input    : double snpt_wghts[]
* Output   : return 0 if success
* Procedure: This function takes user input colour (r:g:b values) and pass them together with corresponding snptc_wghts to detect() function 
*	     for calculating the possibilty of the input colour is being red. Then a website url link and a .ppm file will be generated for
*	     viewing the colour. At last user will be asked to choose continue or quit. 
*****************************************************************************************************************************************************
****************/
	
	char ans;		//for storing user input answer
	double rgb[3];		//for storing user input r:g:b values of a colour
	uint8_t flg = 0;	//a flag for indicating true(1) or false(0)
	
	do{
		printf("please input the colour in R:G:B format. Beawre the RGB values are within range [0,1]. For example, '1:0.1:0.1'.\n");
		scanf(" %lf:%lf:%lf",&rgb[0],&rgb[1],&rgb[2]);
		
		ai_detec(rgb,snptc_wghts,&flg);	//ai_detec() for checking the possibility of input colour is being red. 
		
		printf("Open the link to see your colour.");
		printf("https://convertingcolors.com/rgb-color-%hhu_%hhu_%hhu.html\n",(uint8_t)(rgb[0]*255),(uint8_t)(rgb[1]*255),(uint8_t)(rgb[2]*255));
		
		ppm_gen(rgb);		//generates a monocoloured .ppm file by giving colour RGB values
		
		ui_get_ans(&ans);	//get answer from user to continue or quit.						
		
		if(ans != 'y')break;	//loop breaks when user input 'y' as answer
	} while(1);
	return 0;
}

int ai_analys_rand(double snptc_wghts[]){
/***************************************************************************************************************************************************
*****************
* Function : int ai_analys_manual_input(double snptc_wghts[])
* Input    : double snpt_wghts[]
* Output   : return 0 if success
* Procedure: This function generates colour RGB values and pass them together with corresponding snptc_wghts to detect() function 
*	     for calculating the possibilty of the input colour is being red. New colours will be generated untill red colour is found. 
*	     Then a website url link and a .ppm file will be generated for viewing the colour. At last user will be asked to choose continue or quit. 
*****************************************************************************************************************************************************
****************/
	
	char ans;		//for storing user input answer
	double rgb[3];		//for storing user input r:g:b values of a colour
	uint8_t flg = 0;	//a flag for indicating true(1) or false(0)
	
	do{
	//This loop asks user at last to continue or quit
		uint32_t cnt = 0;	//for counting how many colours are generated when red colour is found
		
		do{
		//this loop keeps generating new sudo-random colours untill red colour is found			
			cnt++;
			printf("Generating and analysing colours...Please wait.\n");	
			
			rand_genf(0, 1.0, rgb, 3);	//rand_genf() generates double precision sudo-random floating number between [0,1] and fill rgb[] with them.

			ai_detec(rgb,snptc_wghts,&flg);	//ai_detec() for checking the possibility of input colour is being red. 
		} while (flg != 1);			//loop keeps running untill the value of red colour indicator flg is ture(1)  
		
		system("cowsay Found red color");	//using system call to excute program "cowsay" from terminal, linux only. requires "cowsay" is installed.
		puts("");
		
		printf("There were totally %u random colours generated.\n",cnt);
		
		printf("Click the link too see your colour.");
		printf("https://convertingcolors.com/rgb-color-%hhu_%hhu_%hhu.html\n",(uint8_t)(rgb[0]*255),(uint8_t)(rgb[1]*255),(uint8_t)(rgb[2]*255));
		
		ppm_gen(rgb);
				
		ui_get_ans(&ans);	//ask user for weather to continue or quit
		
		if(ans != 'y')break;	//answer is 'y' to continue, otherwise quit
	} while(1);
	
	return 0;
}
