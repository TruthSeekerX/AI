/********************************************************************************************************************************************
* This is the main file of the Neural Nod project. It is meant for first year C programming introduction course lectured by Johan Dams.  
* Language: C
* Author:Siyuan e2002077
* Version: v0.3
*	   In this version:
*		1. rand_genf() and rand_gen() is added for more moduler structure
*		2. ui_opt() is added for more modular structure
*		3. ai_analys_man() and ai_analys_rand() are added for more modular structure.
*		4. funtion pointer array int (*ptr_opt[2])(double *) is replaced switch...case... from last version for speed.
*		5. More training data are added
* 14.03.2021
*********************************************************************************************************************************************/
#include <stdio.h>		//for standard IO
#include <stdint.h>		//for int datatype
#include "ai_train.h"		//for ai_train() function
#include "ai_detec.h"		//for ai_detec() function
#include "ai_generator.h" 	//for rand_genf() function

int main(int argc, char *argv[]){
	double snptc_wghts[3];		//declare synaptic weights
	uint32_t itrt;			//declare iteration number variable 
	
	rand_genf(-1.0, 1.0, snptc_wghts, 3);		//function for generates sudo-random number between user defined [-1,1] in this case,
							//and fill the array snptc_wghts, 3 indicates the the size of the array. 

	double	trn_inpts_1[4][3] = {{0.0,0.5,1},{0.5,0,0},{0.9,0.1,0.1},{0.5,0.9,0.9}};		//training inputs data
	double	otpts_1[4] = {0,1,1,0};								//training outputs data
	
	double	trn_inpts_2[4][3] = {{0,0,0},{1,1,1},{0.95,0.76,0.76},{0.44,0,0}};
	double	otpts_2[4] = {0,0,0,1};
	
	double	trn_inpts_3[4][3] = {{1,0.96,0.93},{0.54,0.47,0.36},{0.82,0.62,0.91},{0.3647,0.2235,0.3294}};
	double	otpts_3[4] = {0,0,0,0};
										
	
	printf("How many times of iterations per training would you like to have? There will be three trainings sesseons.\n");
	scanf(" %ud", &itrt);
	
	ai_train(trn_inpts_1, otpts_1, snptc_wghts, itrt); 		//calling ai_train() function to calculate optimal synaptic wights for each colour 
	ai_train(trn_inpts_2, otpts_2, snptc_wghts, itrt);		//and output the result to snptc_wghts[]
	ai_train(trn_inpts_3, otpts_3, snptc_wghts, itrt);
	
	printf("AI has just done %d times of traning. Now please make your choice: \n",itrt * 3);

	uint8_t opt = 0;			//options from user input

	ui_opt(&opt);				//asks user for choosing an option
	
	int (*ptr_opt[2])(double *);		//delcaration of the function pointer array for calling functions accroding to user choices

	ptr_opt[0] = ai_analys_manual_input;		//pointing to the desired function
	ptr_opt[1] = ai_analys_rand;
	
	ptr_opt[opt-1](snptc_wghts);		//opt

	return 0;
}
