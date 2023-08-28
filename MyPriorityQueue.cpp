/***************************************************************
  Student Name: Adam Prusiecki
  File Name: MyPriorityQueue.cpp
  DSA2-Project2

My custom priority queue class

Basically a simple FIFO queue data structure with an Insert function
that always puts the event with the lowest time value, AKA the highest
priority, to the front of the queue.
***************************************************************/

#include "MyPriorityQueue.hpp"
#include <iostream>

MyPriorityQueue::MyPriorityQueue()
{
	this->head = nullptr;
	this->tail = nullptr; 
	this->size = 0;
}

/*
void MyPriorityQueue::Enqueue(Customer* node)
{
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
*/

void MyPriorityQueue::Insert(Customer* node)
{
	this->size++;
	if(this->head == nullptr)
	{
		this->head = node;
		this->tail = node;
	}
	else
	{
		Customer* tempNode = this->head;
		Customer* prevNode;
		while(node->GetPriority() < tempNode->GetPriority())
		{

			prevNode = tempNode;
			tempNode = tempNode->GetNext();
			if(tempNode == nullptr)
			{
				break;
			}
		
		}
		//Insert in middle
		if(tempNode == this->head)
		{
			node->SetNext(tempNode);
			this->head = node;
		}
		//Insert top of the queue
		else if (tempNode == nullptr)
		{
			prevNode->SetNext(node);
			this->tail = node;
		}
		//Insert bottom of the queue
		else
		{
			prevNode->SetNext(node);
			node->SetNext(tempNode);
		}
	}
}

Customer* MyPriorityQueue::Dequeue()
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

int MyPriorityQueue::GetSize()
{
	return this->size;
}

/*

void MyPriorityQueue::PrintQueue()
{
	Customer* node = this->head;
	while(node != nullptr)
	{
		std::cout << node->GetPriority() << " | " << node << std::endl;
		node = node->GetNext();
	}

	std::cout << "Done Printing Priority Queue" << std::endl;
}
*/