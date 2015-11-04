/**
*	@file NumberFileGenerator.h
* @author Will Ashley
*	@date 2015.11.03
*	@Description: Generates either random, ascending, descending or signle values fof the number file depending on the 
*	user's choice. 
*	*	*/



#ifndef NUMBERFILEGENERATOR_H
#define NUMBERFILEGENERATOR_H

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>


class NumberFileGenerator
{
	public:
		
      //@pre file name is valid path. amount must be >0.
      //@post A file is created with the amount of number in ascending order 
		  static void ascending(std::string fileName, int amount);

      //@pre file name and path is valid and must be >0
      //@post A file is created with the amount descending
		  static void descending(std::string fileName, int amount); 

      //@pre file name and path is valid
      //@post A file is created with the specified amount of numbers at random
			static void random(std::string fileName, int amount, int min, int max); 

      //@pre filename is valid along with path name
      //@post A file is created with a single number, specified by value, and amount of times.
		  static void singleValue(std::string fileName, int amount, int value); 	

};

#endif

    
