/***************************************************************
  Student Name: Adam Prusiecki
  File Name: Simulation.cpp
  DSA2-Project2

The simulation class, where most of the action and events occur
This includes:
	making customers and assigning all relevant values
	adding customers to priority queue and fifo queue
	removing cusomters from priority queue and fifo queue
	keeping track of all relevant simulation values
	computing final simulatation values
***************************************************************/

#include "Simulation.hpp"
#include <cstdlib>
#include <math.h>
#include <ctime>

#include <iostream>

Simulation::Simulation(float simulationLambda,float simulationMu,int maxServers)
{
	this->time = 0.0;
	this->totalIdleTime = 0.0;
	this->totalWaitTime = 0.0;
	this->totalServiceTime = 0.0;
	this->customerWaitCount = 0;
	this->simulationLambda = simulationLambda;
	this->simulationMu = simulationMu;
	this->maxServers = maxServers;
	this->numOfArrivals = 0;
	this->serverAvailableCnt = this->maxServers;
	this->idleInterval = 0.0;
}

Customer* Simulation::MakeCustomer()
{
	Customer* c = new Customer();
	float interval = this->GetNextRandomInterval(this->simulationLambda);
	c->SetArrivalTime(this->time);
	this->time = this->time + interval;

	return c;
}

void Simulation::PopulatePQueue()
{
	Customer* c;
	for(int i = 0; i < 200; i++)
	{
		c = this->MakeCustomer();
		this->priorityQueue.Insert(c);
	}
}

void Simulation::ProcessNextEvent()
{
	//this->eventIndex++;
	Customer* c;
	
	c = this->priorityQueue.Dequeue();
	
	//Event is Arrival
	if(c->GetDepartureTime() == 0.0)
	{
		this->numOfArrivals++;
		if(this->serverAvailableCnt > 0)
		{
			this->serverAvailableCnt--;
			c->SetStartOfServiceTime(c->GetArrivalTime());
			float interval = this->GetNextRandomInterval(this->simulationMu);
			c->SetDepartureTime(c->GetArrivalTime() + interval);
			c->SetPriority(c->GetDepartureTime());
			this->priorityQueue.Insert(c);
			if(this->serverAvailableCnt == this->maxServers - 1)
			{
				this->totalIdleTime = this->totalIdleTime + (this->time - this->idleInterval);
			}
		}
		else
		{
			this->fifoQueue.Enqueue(c);
		}
	}
	
	//Event is Departure
	else
	{
		this->serverAvailableCnt++;
		this->ProcessStatistics(c);
		if(this->fifoQueue.GetSize() != 0)
		{
			Customer* f;
			f = this->fifoQueue.Dequeue();
			f->SetStartOfServiceTime(c->GetDepartureTime());
			float interval = this->GetNextRandomInterval(this->simulationMu);
			f->SetDepartureTime(f->GetStartOfServiceTime() + interval);
			this->priorityQueue.Insert(f);
			this->serverAvailableCnt--;
		}
	}
}

void Simulation::ProcessStatistics(Customer* c)
{
	if((c->GetStartOfServiceTime() - c->GetArrivalTime()) != 0)
	{
		this->customerWaitCount++;
		float waitInterval = c->GetStartOfServiceTime() - c->GetArrivalTime();
		this->totalWaitTime = this->totalWaitTime + (waitInterval);
	}
	if(this->serverAvailableCnt == this->maxServers)
	{
		this->idleInterval = this->time;
	}
	this->totalServiceTime = this->totalServiceTime + (c->GetDepartureTime() - c->GetStartOfServiceTime());
}

float Simulation::GetNextRandomInterval(float avg)
{
	float randomNum = 0;
	float logNum = -10000.0;
	
	//To ensure logNum != -inf
	do
	{
		randomNum = (rand() % 10000) / 10000.0;
		logNum = log(randomNum);
	}while(logNum < -1000.0);

	float interval = 0.0;
	interval = -1 * (1.0/avg) * logNum;

	return interval;
}

int Simulation::GetPriorityQueueSize()
{
	return this->priorityQueue.GetSize();
}

int Simulation::GetNumOfArrivals()
{
	return this->numOfArrivals;
}

float Simulation::GetTotalIdleTime()
{
	return this->totalIdleTime;
}

int Simulation::GetCustomerWaitCount()
{
	return this->customerWaitCount;
}

float Simulation::GetSimulatedPo()
{
	return (this->totalIdleTime/this->time);
}

float Simulation::GetSimulatedL()
{
	float top = (this->simulationLambda * this->simulationMu) *(pow((this->simulationLambda/this->simulationMu),this->maxServers));
	float bot = this->GetFactorial((this->maxServers -1)) * (pow(((this->maxServers * this->simulationMu)-this->simulationLambda),2));
	float L =  (top/bot) * this->GetSimulatedPo() + (this->simulationLambda/this->simulationMu);
	return L;
}

float Simulation::GetSimulatedW()
{
	float top = (this->simulationMu) * pow((this->simulationLambda/this->simulationMu),this->maxServers);
	float bot = this->GetFactorial((this->maxServers -1)) * (pow(((this->maxServers * this->simulationMu)-this->simulationLambda),2));
	float W = (top/bot) * this->GetSimulatedPo() + (1/this->simulationMu);
	return W;
}

float Simulation::GetSimulatedLq()
{
	float Lq = this->GetSimulatedL() - (this->simulationLambda/this->simulationMu);
	return Lq;
}

float Simulation::GetSimulatedWq()
{
	float Wq = this->GetSimulatedW() - (1/this->simulationMu);
	return Wq;
}

float Simulation::GetSimulatedRho()
{
	float Rho = this->totalServiceTime / (this->maxServers * this->time);
	return Rho;
}

void Simulation::PrintSimulatedModel()
{
	std::cout << "P0 = " << this->GetSimulatedPo() << std::endl;
	std::cout << "L = " << this->GetSimulatedL() << std::endl;
	std::cout << "W = " << this->GetSimulatedW() << std::endl;
	std::cout << "Lq = " << this->GetSimulatedLq() << std::endl;
	std::cout << "Wq = " << this->GetSimulatedWq() << std::endl;
	std::cout << "Rho = " << this->GetSimulatedRho() << std::endl << std::endl;
}

int Simulation::GetFactorial(int number)
{
	int factorial = 1;
	for(int i = 1; i < number + 1; i++)
	{
		factorial = factorial * i;
	}
	return factorial;
}