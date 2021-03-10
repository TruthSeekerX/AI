/********************************************************************************************************************************************
* This file is part of the Neural Nod project. It is meant for first year C programming introduction course lectured by Johan Dams.
* It includes ai_train() function.  
* Language: C
* Author:Siyuan e2002077
* Version: v0.2
*	   In this version
* 10.03.2021
*********************************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "dot_prdt.h"		//for dot_prdt() function
#include "sigmoid.h"		//for sigmoid related functions

void ai_train(double trn_inpts[][3],double trn_otpts[], double snptc_wghts[], uint32_t iterations){
	
	double outputs[4];
	double error[4];
	double trs_trn_inpts[3][4];
	
	for(uint32_t i=0;i<iterations;i++){
		for(uint8_t j=0;j<4;j++){
		/**************************************************************
		think_train(traning_set_inputs,output);
		--> dot product input * weight
		--> output[]: pass the result of the above though sigmoid()
		**************************************************************/

			outputs[j] = sigmoid(dot_prdt(trn_inpts[j], snptc_wghts, 3));
//			printf("    outputs[%hhd] is: %9lf |",j,outputs[j]);
		}
//		printf("\n");
		
		for(uint8_t j=0;j<4;j++){
		/**************************************************************
		calculate error[]
		--> trn_otpts - output
		--> multiply error with sigmoid_derivative of the output
		**************************************************************/		
		
		error[j] = (trn_otpts[j] - outputs[j]) * sigmoid_d(outputs[j]);
//		printf("      error[%hhd] is: %9lf |",j,error[j]);
		}
//		printf("\n");
		
		for(uint8_t r = 0;r < 4;r++){
		/**************************************************************
		Transpose trn_inpts
		--> because inputs per color group dot product with error gives the adjustments
		--> add the adjustments to the synaptic weights
		**************************************************************/		
			for(uint8_t c=0;c<3;c++){
				trs_trn_inpts[c][r]=trn_inpts[r][c];
			}	
		}
		
		for(uint8_t k = 0;k < 3; k++){

		double adjmnts=dot_prdt(trs_trn_inpts[k],error,4);
		snptc_wghts[k] += adjmnts;
		
//		printf("adjustments[%hhd] is: %9lf |",k,adjmnts);
//		printf("snptc_wghts[%hhd] is: %9lf |",k,snptc_wghts[k]);
		}
		
//		printf("\n");
		printf("-------------------------------------------------------------------------------------------------------------------------\n");
	printf("error:   %9lf, %9lf, %9lf, %9lf \n", error[0],error[1],error[2],error[3]);
	printf("outputs: %9lf, %9lf, %9lf, %9lf \n", outputs[0],outputs[1],outputs[2],outputs[3]);
	printf("wghts  : %9lf, %9lf, %9lf \n", snptc_wghts[0],snptc_wghts[1],snptc_wghts[2]);
	}
}
