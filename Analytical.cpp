/***************************************************************
  Student Name: Adam Prusiecki
  File Name: Analytical.cpp
  DSA2-Project2

The analytical class that contains all the formulas for the
predicted values.

Takes in user values from Driver.cpp and computes and returns those
values when called by Driver.cpp
***************************************************************/

#include "Analytical.hpp"
#include <iostream>
#include <math.h>

Analytical::Analytical(float lambda,float mu,float M)
{
	this->lambda = lambda;
	this->mu = mu;
	this->M = M;
}

//Private function that returns 'number!'
int Analytical::GetFactorial(int number)
{
	int factorial = 1;
	for(int i = 1; i < number + 1; i++)
	{
		factorial = factorial * i;
	}
	return factorial;
}

float Analytical::CalculatePo()
{
	float Po = 0.0;
	float localLambda = this->lambda;
	float localMu = this->mu;
	float localM = this->M;

	float sum = 0;
	float number = 0;

	//Get the summation, aka the left half of the denominator in the formula
	for(int i = 0; i < this->M; i++)
	{
		number = (1/(this->GetFactorial(i))) * pow((localLambda/localMu),i);
		sum += number;
	}
	
	//Get the right half of the denominator int the formula
	double rightHalf = 1;
	rightHalf = (1.0/this->GetFactorial(localM))
				* (pow((localLambda/localMu),localM)) 
	 			* ((localM * localMu)/(localM * localMu - localLambda));

	Po = 1 / (sum + rightHalf); //put it all together

	//truncate
	Po = (int)(Po * 10000 + 0.5);
	Po = (float)(Po / 10000);

	return Po;
}

float Analytical::CalculateL()
{
	float L = 0.0;
	float localLambda = this->lambda;
	float localMu = this->mu;
	float localM = this->M;

	float top = localLambda * localMu * (pow((localLambda/localMu),localM));
	float bottom = (this->GetFactorial(localM - 1)) *(pow(((localM * localMu)- localLambda),2));

	L = (top/bottom) * this->CalculatePo() + (localLambda/localMu);

	//truncate
	L = (int)(L * 10000 + 0.5);
	L = (float)(L / 10000);

	return L;
}

float Analytical::CalculateW()
{
	float W = this->CalculateL() / this->lambda;

	//truncate
	W = (int)(W * 10000 + 0.5);
	W = (float)(W / 10000);

	return W;
}

float Analytical::CalculateLq()
{
	float Lq = this->CalculateL() - (this->lambda/this->mu);

	//truncate
	Lq = (int)(Lq * 10000 + 0.5);
	Lq = (float)(Lq / 10000);

	return Lq;
}

float Analytical::CalculateWq()
{
	float Wq = this->CalculateLq() / this->lambda;

	//truncate
	Wq = (int)(Wq * 10000 + 0.5);
	Wq = (float)(Wq / 10000);

	return Wq;
}

float Analytical::CalculateRho()
{
	float Rho = this->lambda /(this->M * this->mu);
	
	//truncate
	Rho = (int)(Rho * 10000 + 0.5);
	Rho = (float)(Rho / 10000);

	return Rho;
}