/********************************************************************************************************************************************
* This file is part of the Neural Nod project. It is meant for first year C programming introduction course lectured by Johan Dams.
* It includes ai_detec() function.  
* Language: C
* Author:Siyuan e2002077
* Version: v0.1
* 10.03.2021
*********************************************************************************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include "dot_prdt.h"		//for dot_prdt() function
#include "sigmoid.h"		//for sigmoid related functions

void ai_detec(double rgb[], double snptc_wghts[],uint8_t *ptr_flg){
	double result;
	
	result = sigmoid(dot_prdt(rgb, snptc_wghts, 3));
	*ptr_flg = (result >= 0.6) * 1;
	
	printf("The possibility of input colour is red = %lf%%.\n",result*100);
}
