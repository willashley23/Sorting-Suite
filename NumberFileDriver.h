/**
*	@file NumberFileDriver.h
* @author Will Ashley
*	@date 2015.11.3
*	@Description:This contains all the methods necessary to run the file generator. It will use the run function which will
*	create the file
*	*	*/


#ifndef NUMBERFILEDRIVER_H
#define NUMBERFILEDRIVER_H

#include <iostream>
#include "NumberFileGenerator.h"


class NumberFileDriver

{


  public:


    //@pre arguments are a valid 2-D array and the args within are valid
    //@post runs the driver responsible for making the file
    static void run(int argc, char** argv);

    //@pre none
    //@post prints a help menu if the user is unfamiliar with command line operations
    static void printHelpMenu();

  private:


    //@pre none
    //@post returns true if the input is one of the valid options
    static bool isValidOption(std::string option);



};

#endif
