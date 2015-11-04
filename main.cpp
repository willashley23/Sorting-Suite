/**
*	@file main.cpp
* @author Will Ashley
*	@date 2015.11.03
*	@Description: Main acts as a driver for the program. It verifies that there are at least 2 commandline arguments
*	verifies parameters, prints help menu if required by both NFG and SortDriver. 
*	*	*/




#include "Sorts.h"
#include "SortDriver.h"
#include "NumberFileDriver.h"
#include "NumberFileGenerator.h"
#include "Test.h"
#include <iostream>


int main(int argc, char** argv)
{

	for(int i = 0; i < argc; i++)
  {
		std::cout << argv[i] << " ";
  } 

	if(argc >= 2)
	{

		std::string n = argv[1];
		

		if(n == "-create"||n == "-sort"||n == "-test")
		{
			

			Test test(std::cout);

			
			if(n =="-create")
			{
				NumberFileDriver::run(argc, argv);		
			}

			
			else if (n=="-sort")
			{
				SortDriver::run(argc, argv);
			}

			
			else if (n=="-test")
			{
				test.runTests();
			}	
      
		}
		else
		{
			NumberFileDriver::printHelpMenu();
			SortDriver::printHelpMenu();
		}
	}
	else
	{	
		NumberFileDriver::printHelpMenu();
		SortDriver::printHelpMenu();
	}

return (0);
}


