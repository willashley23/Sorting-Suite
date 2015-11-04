/**
*	@file Sorts.hpp
* @author Will Ashley
*	@date 2015.11.03
*	@Description:This contains all the sorting methods, a timer, a shuffler, and a function to create the user array. In this
*	new and enhanced version of the sorting suite, we have added two new sorting options: merge and quick. 
*	*/


template<typename T>
bool Sorts<T>::isSorted(T arr[], int size)
{

  for(int i=0; i<size-1; i++)
  {
    if(arr[i]>arr[i+1])
      return(false);
  }

return(true);

}

//SORT TIMER
template<typename T>
double Sorts<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
{

double time;
  
std::chrono::system_clock::time_point start;
std::chrono::system_clock::time_point end;
std::chrono::duration<double> elapsed;


start = std::chrono::system_clock::now();

sort(arr,size);

end = std::chrono::system_clock::now();
elapsed = (end - start);
time = elapsed.count();
return(time);

}


//***SORTING METHODS***//


//SHUFFLE 
template <typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator)
{		
	int temparr;
	int temp;
	

	std::uniform_int_distribution<int> distribution(0, size - 1);

	for(int i = 0; i < size; i++)
	{
		temparr = distribution(generator);
		//temp = arr[i];
		arr[i] = arr[temparr];
		arr[temparr] = temp;
	} 

}

//INSERTION
template<typename T>
void Sorts<T>::insertionSort(T arr[], int size)
{

int a;

	for(int i = 1; i < size; i++)
	{
		a=i;
		while(a>0 && arr[a-1]>arr[a])
		{
			int tempArr=arr[a];
			arr[a]=arr[a-1];
			arr[a-1]=tempArr;
			a--;
		}
	}   
  
assert( Sorts<T>::isSorted(arr, size) );


}

//BOGO
template <typename T>
void Sorts<T>::bogoSort(T arr[], int size)
{
  
	std::default_random_engine generator;
	
	while(!isSorted(arr, size))
  {
		shuffle(arr, size, generator); 
  }

	assert(Sorts<T>::isSorted(arr, size));
	
}


//SELECTION
template<typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{

for(int i=0;i<size-1;i++)
	{
		int smallest=arr[i];
		int subIndex=i;  
		
		for(int j=i;j<size-1;j++)
		{


			if(j!=size-1)
			{

				if(arr[j+1]<smallest)
				{
					  smallest=arr[j+1];
				  	subIndex=j+1;
				}
			}
		}
		
		arr[subIndex]=arr[i];
		arr[i]=smallest;


		}
	assert(Sorts<T>::isSorted(arr, size));

}


//BUBBLE 
template<typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{

  std::string choice;
  
  while(!isSorted(arr,size)){
 
    for(int i=0;i<size-1;i++)
    {
    	if(arr[i]>arr[i+1])
    	{
	    	int temp=arr[i];
	    	arr[i]=arr[i+1];
	    	arr[i+1]=temp;
    	}

    }
  }

assert( Sorts<T>::isSorted(arr, size) );
  
}


template<typename T>
int* Sorts<T>::createTestArray(int size, int min, int max)
{

    std::default_random_engine generator(time(nullptr));
    std::uniform_int_distribution<int> distribution(min,max);

    int* userArray = new int[size];
    for(int i=0; i<size-1; i++)
    {
      userArray[i]=distribution(generator);
    }

    return(userArray);
}

//***NEW SORTING METHODS***//


//QUICK SORT//

template <typename T>
void Sorts<T>::quickSort(T arr[], int size)
{

  quickSortRec(arr, 0, size-1, false);

}

//QUICK SORT WITH MEDIAN//

template <typename T>
void Sorts<T>::quickSortWithMedian(T arr[], int size)

{

  quickSortRec(arr, 0, size-1, true);


}


template <typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last)

{
T temp;
int median = (first+last)/2;


  if(arr[first]>arr[median])
  {
    temp = arr[first];
	  arr[first] = arr[median];
	  arr[median] = temp;
  }

  if(first>last)
  {
    temp = arr[first];
	  arr[first] = arr[last];
	  arr[last] = temp;
  }

  if(median>last)
  {
    temp = arr[median];
    arr[median] = arr[last];
    arr[last] = temp;
  }
 //Swap once more
    temp = arr[median];
    arr[median] = arr[last];
    arr[last] = temp;



}

template <typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median)
{

int pivot;
setMedianPivot(arr, first, last);

if(first<last)
    {
      pivot = partition(arr, first, last, median);
      quickSortRec(arr, first, pivot-1, median);
      quickSortRec(arr, pivot+1, last, median);
    }


}
template <typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median)
{

int pivotIndex; 
int currentLeft = first;
int currentRight = last-1;


if(median)
{
setMedianPivot(arr, first, last);
}

pivotIndex=last;

while(currentLeft<currentRight) 
{

 while(arr[currentLeft]<=pivotIndex && currentLeft<currentRight)
 {
      currentLeft++;
 }
     while(arr[currentRight]>pivotIndex && currentLeft<currentRight) //do i need that here?
     {
       currentRight--;
     }
     
         T temp = arr[currentLeft];
	       arr[currentLeft] = arr[currentRight];
	       arr[currentRight] = temp;


}



currentRight=pivotIndex;
return(pivotIndex);
}



template<typename T>	
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2){

  if(size1+size2<=1)
  {
		return;
	}
	//Keep track of left and right indeces 
  int dex1=0;
	int dex2=0;
	int currentIndex = 0;
	T* temp = new T[size1+size2];   
	
  while(dex1<size1 && dex2<size2)
  {
		if(*(a1+dex1)>*(a2+dex2)){
			temp[currentIndex] = *(a2+dex2);
			dex2++;
		}
		else{
			temp[currentIndex] = *(a1 +dex1);
			dex1++;
		}
		currentIndex++;
	}

	while(dex1<size1)
  {
    temp[currentIndex] = *(a1+dex1);
		dex1++;
		currentIndex++;
	}
	while(dex2<size2)
  {
    temp[currentIndex] = *(a2+dex2);
		dex2++;
		currentIndex++;
	}
	for(int i = 0; i<(size1+size2); i++)
  {
		a1[i] = temp[i];

	}
  //Prevent memory leak! 
	delete []temp;

}


//MERGE//

template <typename T>
void Sorts<T>::mergeSort(T arr[], int size)
{
  T* left = arr+0;
  int middle = size/2;
  T* right = arr+middle; //cd?

    if(size==0||size==1)
    {
      return;
    }

    else
    {
        mergeSort(left, middle);
        mergeSort(right, size-middle);
        merge(left, right, middle, size-middle);
    }

  assert(Sorts<T>::isSorted(arr,size));

}


  








