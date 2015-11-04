/**
*	@file SortDriver.cpp
* @author Will Ashley
*	@date 2015.11.03
*	@Description:This file acts as the manager of the program. It is in charge of creating arrays, determining if parameters are valid, if the file is accessible, and so on. 
*	*/


#include "SortDriver.h"

void SortDriver::run(int argc, char** argv)
{
		
	if(argc == 5)
	{
		std::string sort = argv[2]; 
		std::string filename = argv[3];

		if(areParametersValid(sort, filename))
		{
		
			int nums; 
			std::string outfileName = argv[4];

			std::ifstream read(filename);
			nums = getFileCount(read);
	
			int* array = createArray(read, nums);
			int* array2 = new int[nums]; 
			
		
			std::ofstream write(outfileName);
			double time; 
				
			if(sort == "-bubble")
			{	
				time = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, array, nums);
				write << "bubble " << nums << " " << time;
			}
			else if(sort == "-insertion")
			{
				time = Sorts<int>::sortTimer(Sorts<int>::insertionSort, array, nums);
				write << "insertion " << nums << " " << time;
			}
			else if(sort == "-selection")
			{
				time = Sorts<int>::sortTimer(Sorts<int>::selectionSort, array, nums);
				write << "selection " << nums << " " << time;
			}
			else if(sort == "-merge")
			{
				time = Sorts<int>::sortTimer(Sorts<int>::mergeSort, array, nums);
				write << "merge " << nums << " " << time;
			}
			else if(sort == "-quick")
			{
				time = Sorts<int>::sortTimer(Sorts<int>::quickSort, array, nums);
				write << "quick " << nums << " " << time;
			}
			else if(sort == "-quick3")
			{
				time = Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian, array, nums);
				write << "quick3 " << nums << " " << time;
			}
			else if(sort == "-all")
			{
				copyArray(array, array2, nums);
				time = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, array, nums);
				write<<"bubble "<<nums<< " "<<time;
				
				write<<"\n";
				copyArray(array2, array, nums);
				time = Sorts<int>::sortTimer(Sorts<int>::insertionSort, array, nums);
				write<<"insertion "<<nums<< " "<<time;
				
				write << "\n";
				copyArray(array, array2, nums);
				time = Sorts<int>::sortTimer(Sorts<int>::selectionSort, array, nums);
				write<<"selection "<<nums<<" "<<time;
				
				write << "\n";
				copyArray(array2, array, nums);
				time = Sorts<int>::sortTimer(Sorts<int>::mergeSort, array, nums);
				write<<"merge "<<nums<<" "<<time;
				
				write << "\n";
				copyArray(array, array2, nums);
				time = Sorts<int>::sortTimer(Sorts<int>::quickSort, array, nums);
				write<<"quick "<<nums<<" "<<time;
				
				write << "\n";
				copyArray(array2, array, nums);
				time = Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian, array, nums);
				write<<"quick3 "<<nums<<" "<<time;
			}	

      //prevent memory leaks
		write.close();			
		delete array;
		delete array2;
		array=nullptr; 
    array2=nullptr;
		
		}
	}
	else
	{
		printHelpMenu();
	}
}

void SortDriver::printHelpMenu()
{
	std::cout << "\nSorting is done one of the following ways:\n\n"
			<< "./prog -sort -bubble inputFile outputFile\n"
			<< "./prog -sort -selection inputFile outputFile\n"
			<< "./prog -sort -insertion inputFile outputFile\n"
			<< "./prog -sort -quick inputFile outputFile\n"
			<< "./prog -sort -quick3 inputFile outputFile\n"
			<< "./prog -sort -merge inputFile outputFile\n"
			<< "./prog -sort -all inputFile outputFile\n"
			<< "Option explainations:\n"
			<< "\t-bubble to time bubble sort and store all timing results in outputFile\n"
			<< "\t-selection to time selection sort and store all timing results in outputFile\n"
			<< "\t-insertion to time insertion sort and store all timing results in outputFile\n"
			<< "\t-quick to time quick sort and store all timing results in outputFile\n"
			<< "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
			<< "\t-merge to time merge sort  and store all timing results in outputFile\n"
			<< "\t-all to time all of the sorts and store all timing results in outputFile\n"
			<< "\tinputFile must be file created by a NumberFileGenerator\n"
			<< "\toutputFile must be to a valid path. It will hold the timing results\n";

}

bool SortDriver::isFileAccessible(std::string fileName)
{
	std::ifstream read(fileName);
	
	if(read.good())
  {
		return true;
  }
	else
  {
		return false;
  }

}


void SortDriver::copyArray(int original[], int copy[], int size)
{
	for(int i = 0; i < size; i++)
  {
		copy[i] = original[i];
  }

}

int* SortDriver::createArray(std::ifstream& inputFile, int size)
{	
	std::string word;
	int* createArr = new int[size];
	for(int i=0; i<size; i++)
	{
		inputFile>>word;
		createArr[i]=std::stoi(word);
	}	

	return createArr;
}

bool SortDriver::isSortValid(std::string sortParameter)
{
	if( sortParameter == "-bubble")
  {
		return true;
  }
	else if( sortParameter == "-insertion")
  {
		return true;
  }
	else if( sortParameter == "-selection")
  {
		return true;
  }
	else if( sortParameter == "-merge")
  {
		return true;
  }
	else if( sortParameter == "-quick")
  {
		return true;
  }
	else if( sortParameter == "-quick3")
  {
		return true;
  }
	else if( sortParameter == "-all")
  {
		return true;
  }
	else
  {
		return false;
  }
}

bool SortDriver::areParametersValid(std::string sortName, std::string inputFileName)
{
	if(isSortValid(sortName) && isFileAccessible(inputFileName))
  {
		return true;
  }
	else
  {
		return false;
  }
}

int SortDriver::getFileCount(std::ifstream& inputFile)
{
	std::string str;
	inputFile>>str;
	return(std::stoi(str)); 
}


