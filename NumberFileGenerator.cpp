/**
*	@file NumberFileGenerator.h
* @author Will Ashley
*	@date 2015.11.03
*	@Description: Generates either random, ascending, descending or signle values fof the number file depending on the 
*	user's choice. 
*	*	*/

#include "NumberFileGenerator.h"

void NumberFileGenerator::ascending(std::string fileName, int amount)
{
	std::ofstream write(fileName);

	if(write.good())
	{
		if(amount > 0)
		{
			write << amount << "\n";
			for(int i = 1; i < amount; i++)
				write << i << "\n";
		}
	}
	else
	{
	}
	
	write.close();
}

void NumberFileGenerator::descending(std::string fileName, int amount)
{
	std::ofstream write(fileName);
	
	if(write.good())
	{
		if(amount > 0)
		{
			write << amount << "\n";
			for(int i = 1; i < amount; i++)
				write << amount - i << "\n";
		}
	}
	else
	{
	}
	
	write.close();
	
}


void NumberFileGenerator::random(std::string fileName, int amount, int min, int max)
{
	//Declare and seed a generator
	std::default_random_engine generator(time(nullptr));

	//Declare a distribution and define the range of the random numbers
	std::uniform_int_distribution<int> distribution(min, max);

	std::ofstream write(fileName);
	
	if(write.good())
	{
		if(amount > 0)
		{
			write << amount << "\n";
			for(int i = 1; i < amount; i++)
				write << distribution(generator) << "\n";
		}
	}
	else
	{
	}
	
	write.close();
}

void NumberFileGenerator::singleValue(std::string fileName, int amount, int value)
{	
	std::ofstream write(fileName);
	
	if(write.good())
	{
		if(amount > 0)
		{
			write << amount << "\n";
			for(int i = 1; i < amount; i++)
				write << value << "\n";
		}
	}
	else
	{
	}
	
	write.close();
	
}
