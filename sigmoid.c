/*******************************************************
* This file contains signmoid functions: 
* sigmoid(),sigmoid_d(),deriv().
* Language: C
* Author:Siyuan e2002077
********************************************************/

#include <math.h>			//Using -lm to link math.h when compile by gcc
#include "sigmoid.h"

float sigmoid(float x){

	/**********************************************************************
	*****************
	*Function : float sigmoid(float x)
	*Input    : float number x
	*Output   : Return r, the result
	*Procedure: Calculate the value of sigmoid function f(x)=1/(1+e^(-x))
	*           according to input x
	************************************************************************
	****************/
	float r;
	r=1/(expf(-x)+1);		//Formula of sigmoid function
	
	return r;
}

float sigmoid_d(float x){

	/**********************************************************************
	*****************
	*Function : float sigmoid_d(float x)
	*Input    : float number x
	*Output   : Return r, the result
	*Procedure: Calculate the derivative of sigmoid function f(x)=1/(1+e^(-x))
	*           according to input x
	************************************************************************
	****************/
	float r;
	r=sigmoid(x)*(1-sigmoid(x));	//Formula of the derivative of function sigmoid()
	
	return r;
}

float deriv(float x){

	/**********************************************************************
	*****************
	*Function : float deriv(float x)
	*Input    : float number x
	*Output   : Return the result of formula f(x)=x*(1-x)
	*Procedure: Calculate the derivative function f(x)=x*(1-x)
	*	    according to input x
	************************************************************************
	****************/
	return x*(1-x);		//Formula of the derivative of a function
}
