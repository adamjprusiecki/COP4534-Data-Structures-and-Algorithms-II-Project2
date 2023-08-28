/***************************************************************
  Student Name: Adam Prusiecki
  File Name: main.cpp
  DSA2-Project2

File that includes the main function
***************************************************************/

#include <iostream>
#include "Customer.hpp"
#include "Fifo.hpp"
#include "MyPriorityQueue.hpp"
#include "Driver.hpp"
#include <cstdlib>

int main()
{
	srand(time(0)); //Seeding for the random number generation
	Driver d;
	d.RunSimulation();	

	return 0;
}