/**
*	@file SortDriver.h
* @author Will Ashley
*	@date 2015.11.03
*	@Description:This file acts as the manager of the program. It is in charge of creating arrays, determining if parameters are valid, if the file is accessible, and so on. 
*	*/


#ifndef SORT_DRIVER_H
#define SORT_DRIVER_H


#include <iostream>
#include <fstream>
#include "Sorts.h"



class SortDriver 
{

 public:

   //@pre argument is valid 2-D array and args within are valid
   //@post A file is created containing the timing information
   static void run(int argc, char** argv);

   //@pre none
   //@post prints a help menu for the user
   static void printHelpMenu();


 private: 

   //@pre The input file was created by a number file generator
   //@post returns true if the file exists, otherwise will return false
   static bool isFileAccessible(std::string fileName);

   //@pre none
   //@post none
   static bool isSortValid(std::string sortParameter);

   //@pre none
   //@post none
   static bool areParametersValid(std::string sortName, std::string inputFileName);

   //@pre The input file was created with the NFG
   //@post The first line of the file is read in, containing the count
   static int getFileCount(std::ifstream& inputFile);

   //@pre The input file was created with NFG, the size was read in, and the size is correct
   //@post The remainder of the iput file numbers are read in. Note: the file is NOT closed. 
   static int* createArray(std::ifstream& inputFile, int size);

   //@pre Original and copy are valid arrays of correct size
   //@post All values from original are copied into copy
   static void copyArray(int original[], int copy[], int size);


};
#endif






