/***************************************************************
  Student Name: Adam Prusiecki
  File Name: Fifo.cpp
  DSA2-Project2

My custom queue class

A simple fifo queue data structure

A singly linked list, with a head and tail
***************************************************************/

#include "Fifo.hpp"
#include <iostream>

Fifo::Fifo()
{
	this->head = nullptr;
	this->tail = nullptr; 
	this->size = 0;
}

void Fifo::Enqueue(Customer* node)
{
	this->size++;
	if(this->head == nullptr)
	{
		this->head = node;
		this->tail = node;
	}
	else
	{
		node->SetNext(this->head);
		this->head = node;
	}
}

Customer* Fifo::Dequeue()
{
	this->size--;
	Customer* thisNode = this->tail;
	
	if(thisNode == this->head)
	{
		this->head = nullptr;
		this->tail = nullptr;
	}
	else
	{
		Customer* tempNode = this->head;
		while(tempNode->GetNext() != this->tail)
		{
			tempNode = tempNode->GetNext();
		}
		tempNode->SetNext(nullptr);
		this->tail = tempNode;
	}
	
	return thisNode;
}

int Fifo::GetSize()
{
	return this->size;
}

/*
void Fifo::PrintQueue()
{
	for(Customer* node = this->head; node != nullptr; node = node->GetNext())
	{
		std::cout << node->GetPriority() << " | " << node << std::endl;
	}
}
*/