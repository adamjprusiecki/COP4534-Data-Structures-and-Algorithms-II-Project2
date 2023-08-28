/***************************************************************
  Student Name: Adam Prusiecki
  File Name: MyPriorityQueue.hpp
  DSA2-Project2

Header file for my custom priority queue class
***************************************************************/

#ifndef MPQ_HPP_
#define MPQ_HPP_

#include "Customer.hpp"

class MyPriorityQueue
{
	private:
		Customer* head;
		Customer* tail;
		int size;
	public:
		MyPriorityQueue();
		//void Enqueue(Customer* node);
		void Insert(Customer* node);
		Customer* Dequeue();
		int GetSize();
		//void PrintQueue();
};

#endif // MPQ_HPP_