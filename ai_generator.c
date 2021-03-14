/********************************************************************************************************************************************
* This file is part of the Neural Nod project. It is meant for first year C programming introduction course lectured by Johan Dams.
* It includes vairias data generating functions.
* 	  1. int rand_gen(int num_1, int num_2, double array[], uint8_t size)
* Language: C
* Author:Siyuan e2002077
* Version: v0.1
* 12.03.2021
*********************************************************************************************************************************************/

#include <stdint.h>		//for int datatypes
#include <stdlib.h>		//for rand() and srand() functions
#include <time.h>		//for time() function



int rand_genf(int num_1, int num_2, double array[], uint8_t size){
/**********************************************************************
*****************
*Function : int rand_gen(int num_1, int num_2, double array[], uint8_t size)
*Input    : int num_1, int num_2 defines the space to which the random number belongs. 
*		doube array[] stores the results. 
*		uint8_t size indicates the size of the array.
*Output   : Return 0 when succeded.
*Procedure: Generates sudo-random double precicion floating numbers with giving arguments.  
************************************************************************
****************/
srand(time(NULL));	//NULL is equivalent as 0 here. srand initialise the sudo-random function with base of time() function.

	int temp,i;
	if (num_1 > num_2) {
	// sort num_1 and num_2 as num_1 is the smaller one and num_2 is the bigger one
		temp = num_1;
		num_1 = num_2;
		num_2 = temp;
	}
	
	for (i=0; i < size; i++){
	array[i] = 2 * num_2 * (double)rand() / RAND_MAX - num_1;	//formular for define the space of generated sudo-random number to [num_1,num_2]
	}
	
	return 0;
}

int rand_gen(int num_1, int num_2, int array[], uint8_t size){
/**********************************************************************
*****************
*Function : int rand_gen(int num_1, int num_2, int array[], uint8_t size)
*Input    : int num_1, int num_2 defines the space to which the random number belongs. 
*		int array[] stores the results. 
*		uint8_t size indicates the size of the array.
*Output   : Return 0 when succeded.
*Procedure: Generates sudo-random integer numbers with giving arguments. 
************************************************************************
****************/
srand(time(NULL));	//NULL is equivalent as 0 here. srand initialise the sudo-random function with base of time() function.

	int temp,i;
	if (num_1 > num_2) {
	// sort num_1 and num_2 as num_1 is the smaller one and num_2 is the bigger one
		temp = num_1;
		num_1 = num_2;
		num_2 = temp;
	}
	
	for (i=0; i < size; i++){
	array[i] = 2 * num_2 * (double)rand() / RAND_MAX - num_1;	//formular for define the space of generated sudo-random number to [num_1,num_2]
	}
	return 0;
}
