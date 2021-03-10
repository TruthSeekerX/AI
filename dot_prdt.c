/******************************************************************************************************
* This file includes function dot_prdt() for calculating dot product of two equally lenthed arrays. 
* Language: C
* Author:Siyuan e2002077
* Version: v0.2
* Changes:  
*	   1. data type of the function dot_prdt() is changed from float to double for more precision
*	   2. data type of the arguments of the function dot_prdt() are changed from float to double for more precision
* 10.03.2021 (dd.mm.yyyy)
*******************************************************************************************************/
#include<stdint.h>

double dot_prdt(double *array1,double *array2,uint8_t size){			//double *array1 is equivalent of double array1[]. The value is the address of the first element of the array.
	double p=0;
	for(uint8_t i=0;i<size;i++){
		p+=array1[i]*array2[i];
	}
	return p;
}
