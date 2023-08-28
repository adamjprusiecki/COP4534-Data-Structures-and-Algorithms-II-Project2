/***************************************************************
  Student Name: Adam Prusiecki
  File Name: Customer.cpp
  DSA2-Project2

The customer class

Holds an arrival time, departure time, start of service time, a pointer
to the next cusomter object, and a priority time. The priority time gets
overwritten depending on if the event is an arrival or departure. 
Prioriry time is what is used to determine priority in the priority queue.
***************************************************************/

#include "Customer.hpp"

Customer::Customer()
{
	this->arrivalTime = 0.0;
	this->startOfServiceTime = 0.0;
	this->departureTime = 0.0;
	this->nextCust = nullptr;
}

void Customer::SetArrivalTime(float arrivalTime)
{
	this->arrivalTime = arrivalTime;
	this->SetPriority(arrivalTime);
}

float Customer::GetArrivalTime()
{
	return this->arrivalTime;
}

void Customer::SetStartOfServiceTime(float startOfServiceTime)
{
	this->startOfServiceTime = startOfServiceTime;
}

float Customer::GetStartOfServiceTime()
{
	return this->startOfServiceTime;
}

void Customer::SetDepartureTime(float departureTime)
{
	this->departureTime = departureTime;
}

float Customer::GetDepartureTime()
{
	return this->departureTime;
}

void Customer::SetNext(Customer* nextCust)
{
	this->nextCust = nextCust;
}

Customer* Customer::GetNext()
{
	return this->nextCust;
}

void Customer::SetPriority(float priority)
{
	this->priority = priority;
}

float Customer::GetPriority()
{
	return this->priority;
}
