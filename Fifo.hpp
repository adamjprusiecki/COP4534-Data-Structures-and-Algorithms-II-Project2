/***************************************************************
  Student Name: Adam Prusiecki
  File Name: Fifo.hpp
  DSA2-Project2

Header file for my custom fifo queue class
***************************************************************/

#ifndef FIFO_HPP
#define FIFO_HPP

#include "Customer.hpp"

//Fifo Queue, AKA singly linked list with a head and tail
class Fifo
{
	private:
		Customer* head;
		Customer* tail;
		int size = 0;
	public:
		Fifo();
		void Enqueue(Customer* node);
		Customer* Dequeue();
		int GetSize();
		//void PrintQueue();
};

#endif //FIFO_HPP