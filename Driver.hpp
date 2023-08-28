/***************************************************************
  Student Name: Adam Prusiecki
  File Name: Driver.hpp
  DSA2-Project2

Header File for my Driver class
***************************************************************/

#ifndef DRIVER_HPP_
#define DRIVER_HPP_

class Driver
{
	private:
		float n;
		float lambda;
		float mu;
		float M;
	public:
		Driver();
		void RunSimulation();
		void PromptUserForInput();
		void PrintAnalyticalModel();
};

#endif// DRIVER_HPP_