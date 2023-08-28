/***************************************************************
  Student Name: Adam Prusiecki
  File Name: Customer.hpp
  DSA2-Project2

Header file for my customer class
***************************************************************/

#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_

class Customer
{
	private:
		float arrivalTime;
		float startOfServiceTime;
		float departureTime;
		Customer* nextCust;
		float priority;
	public:
		//Constructor
		Customer();

		//Simulation functions
		void SetArrivalTime(float arrivalTime);
		float GetArrivalTime();
		void SetStartOfServiceTime(float startOfServiceTime);
		float GetStartOfServiceTime();
		void SetDepartureTime(float departureTime);
		float GetDepartureTime();
		
		//FIFO functions
		void SetNext(Customer* nextCust);
		Customer* GetNext();

		//Priority functions
		void SetPriority(float priority);
		float GetPriority();

};

#endif // CUSTOMER_HPP_