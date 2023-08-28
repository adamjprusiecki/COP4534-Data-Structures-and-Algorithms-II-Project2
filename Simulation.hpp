/***************************************************************
  Student Name: Adam Prusiecki
  File Name: Simulation.hpp
  DSA2-Project2

Header file for the simulation class
***************************************************************/

#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

//#include "Customer.hpp"
#include "MyPriorityQueue.hpp"
#include "Fifo.hpp"

class Simulation
{
	private:
		float time;
		float simulationLambda;
		float simulationMu;
		int maxServers;
		int serverAvailableCnt;

		Fifo fifoQueue;
		MyPriorityQueue priorityQueue;

		int numOfArrivals;
		float totalIdleTime;
		float totalServiceTime;
		float totalWaitTime;
		int customerWaitCount;
		float idleInterval;

		//Private Functions
		Customer* MakeCustomer();
		void ProcessStatistics(Customer* c);
		int GetFactorial(int number);

	public:
		Simulation(float simulationLambda,float simulationMu,int maxServers);
		void PopulatePQueue();
		void ProcessNextEvent();
		float GetNextRandomInterval(float avg);
		int GetPriorityQueueSize();
		int GetNumOfArrivals();
		float GetTotalIdleTime();
		int GetCustomerWaitCount();

		//Getters for all simulated values
		float GetSimulatedPo();
		float GetSimulatedL();
		float GetSimulatedW();
		float GetSimulatedLq();
		float GetSimulatedWq();
		float GetSimulatedRho();

		void PrintSimulatedModel();

};

#endif // SIMULATION_HPP_