/***************************************************************
  Student Name: Adam Prusiecki
  File Name: Driver.cpp
  DSA2-Project2

My Driver class that handles all input/output and program logic/flow
***************************************************************/

#include "Driver.hpp"
#include "Analytical.hpp"
#include "Simulation.hpp"
#include <iostream>

Driver::Driver()
{

}

void Driver::RunSimulation()
{
	this->PromptUserForInput();

	Simulation s(this->lambda,this->mu,this->M);

	s.PopulatePQueue(); //Initially populate the priority queue

	//Event Loop
	while(s.GetPriorityQueueSize() != 0)
	{
		s.ProcessNextEvent();
		if(s.GetPriorityQueueSize() <= (this->M + 1))
		{
			if(s.GetNumOfArrivals() <= (this->n)-200)
			{
				s.PopulatePQueue();
			}
		}
	}	

	std::cout << "Analytical Model Predictions" << std::endl;
	this->PrintAnalyticalModel();
	std::cout << std::endl;

	std::cout << "Simulated Model values" << std::endl;
	s.PrintSimulatedModel();

	std::cout << "The probabilty of waiting for service is " 
	<< (s.GetCustomerWaitCount() / this->n) * 100 << "%" << std::endl;
}

void Driver::PromptUserForInput()
{
	//Prompt user for number of total customers to simulate
	std::cout << "How many arrivals do you wish to simulate?(n): ";
	std::cin >> this->n;
	std::cout << std::endl;

	//Prompt user for lambda
	std::cout << "What is the average arrivals in a time period?(lambda): ";
	std::cin >> this->lambda;
	std::cout << std::endl;

	//Prompt user for mu
	std::cout << "What is the average number served in a time period?(mu): ";
	std::cin >> this->mu;
	std::cout << std::endl;

	//Prompt user for number of channels
	std::cout << "How many service channels are there?(M): ";
	std::cin >> M;
	std::cout << std::endl;

	//Simple Test code I left in for you, for quick testing
	//Comment out the above code and set the values below to what you would normally enter as the user, respectively
	
	//Test Values
	//this->n = 5000.0; //Total Arrivals
	//this->lambda = 2.0; //Lambda
	//this->mu = 3.0; //MU
	//this->M = 2.0; //Max Number of Channels
}

void Driver::PrintAnalyticalModel()
{
	Analytical model(this->lambda,this->mu,this->M);
	std::cout << "P0 = " << model.CalculatePo() << std::endl;
	std::cout << "L = " << model.CalculateL() << std::endl;
	std::cout << "W = " << model.CalculateW() << std::endl;
	std::cout << "Lq = " << model.CalculateLq() << std::endl;
	std::cout << "Wq = " << model.CalculateWq() << std::endl;
	std::cout << "Rho = " << model.CalculateRho() << std::endl;
	std::cout << std::endl;
}