/**
*	@file NumberFileDriver.cpp
* @author Will Ashley
*	@date 2015.11.03
*	@Description: This is the driver for the number file. It will use run to create a number file and print a 
*	help menu for the user if necessary. 
*	*	*/


#include "NumberFileDriver.h"



void NumberFileDriver::run(int argc, char** argv)
{

  std::string option = argv[2];


//First must check to see if args are valid
  if(isValidOption(option))
	{
		
		std::string order = argv[2];
		std::cout<<order<<"\n";
		
		if(order == "-a" && argc >= 5)
    {
			NumberFileGenerator::ascending(argv[3], std::stoi(argv[4]));
    }

		else if(order == "-d" && argc >= 5)
    {
			NumberFileGenerator::descending(argv[3], std::stoi(argv[4]));
    }

		else if(order == "-s" && argc >= 6)
    {
			NumberFileGenerator::singleValue(argv[3], std::stoi(argv[4]), std::stoi(argv[5]));
    }

		else if(order == "-r" && argc >= 7)
    {
			NumberFileGenerator::random(argv[3], std::stoi(argv[4]), std::stoi(argv[5]), std::stoi(argv[6]));
    }
		else
    {
      //If user needs help
			printHelpMenu();
    }
		
	}
	


}


void NumberFileDriver::printHelpMenu()
{
	std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
			<< "./prog -create -a filename amount\n"
			<< "./prog -create -d filename amount\n"
			<< "./prog -create -s filename amount value\n"
			<< "./prog -create -r filename amount min max\n"
			<< "Option explainations:\n"
			<< "\t-a for ascending\n"
			<< "\t-d for descending\n"
			<< "\t-s for a single value\n"
			<< "\t-r for random values\n"
			<< "\tfilename is the ouput file name\n"
			<< "\tamount is the amount of random numbers to place in the file\n"
			<< "\tvalue is the single number that will be written to file in -s mode\n"
			<< "\tmin is the low end of the range of random numbers\n"
			<< "\tmax is the high end (non-inclusive) of the range of random numbers\n";

}

bool NumberFileDriver::isValidOption(std::string option)
{
	if(option == "-a"||option == "-d"||option == "-s"||option == "-r")
  {
		return true;
  }
	else
	{
		printHelpMenu();
		return false;
	}			
}
