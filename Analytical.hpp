/***************************************************************
  Student Name: Adam Prusiecki
  File Name: Analytical.hpp
  DSA2-Project2

Header file for the analytical class
***************************************************************/

#ifndef ANALYTICAL_HPP_
#define ANALYTICAL_HPP_

class Analytical
{
	private:
		float lambda;
		float mu;
		float M;
		int GetFactorial(int number);
	public:
		Analytical(float lambda,float mu, float M);
		float CalculatePo();
		float CalculateL();
		float CalculateW();
		float CalculateLq();
		float CalculateWq();
		float CalculateRho();
};

#endif // ANALYTICAL_HPP_