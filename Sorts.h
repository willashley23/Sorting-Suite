/**
*	@file Sorts.h
* @author Will Ashley
*	@date 2015.11.03
*	@Description:This contains all the sorting methods, a timer, a shuffler, and a function to create the user array. This new 
*	and improved version contains new sorting mehtods, such as quick and merge sort.  
*	*/


#ifndef SORTS_H
#define SORTS_H
#include <random>
#include <chrono>
#include <ctime>
#include <iostream>
#include <cassert>
#include <functional>
#include "Test.h"

template <typename T>
class Sorts

{

  public:


    //@pre array created
    //@post uses buble sort to sort the array
    static void bubbleSort(T arr[], int size);

    //@pre array created
    //@post uses insertion sort to sort the array
    static void insertionSort(T arr[], int size);

    //@pre array created
    //@post uses selection sort to sort the array
    static void selectionSort(T arr[], int size);

    //@pre array created
    //@post sorts the array by randomly shuffling elements
    static void bogoSort(T arr[], int size);

    //@array created
    //determines if the array is sorted
    static bool isSorted(T arr[], int size);

    //@pre none
    //@post shuffles random integers 
    static void shuffle(T arr[], int size, std::default_random_engine& generator);

    //@pre none
    //@post creates the user array
    static int* createTestArray(int size, int min, int max);

    //@none
    //@post calculates the time taken to sort by each method
    static double sortTimer(std::function<void(T[],int)>sort, T arr[], int size);

    //@pre valid array created
    //@post uses merge sort to sort the array
    static void mergeSort(T arr[], int size); 

    //@pre valid array created
    //@post calls quicksort with the median flag set to FALSE
    static void quickSort(T arr[], int size); 

    //@pre valid array created
    //@post calls quick sort with the median flag set to TRUE
    static void quickSortWithMedian(T arr[], int size); 

      
  private:

    //@pre Arrays created
    //@post combines two sorted arrays
    static void merge(T* a1, T* a2, int size1, int size2); 
    
    //@pre Valid array created
    //@post Sorts the array by partitioning it and sorting about the pivot
    static void quickSortRec(T arr[], int first, int last, bool median); 

    //@pre valid array created
    //@post determines the pivot value to be used by quicksortrec
    static void setMedianPivot(T arr[], int first, int last); 

    //@pre valid array created
    //@post partitions the array for use in the quicksort method
    static int partition(T arr[], int first, int lst, bool median); 

    //@pre valid array created
    //@post for each index in the array, swait it with the value at another random index
    static void shuffle(T arr[], int size); 
    



};
#include "Sorts.hpp"
#endif



