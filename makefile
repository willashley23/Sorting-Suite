lab07: Test.o main.o SortDriver.o NumberFileDriver.o NumberFileGenerator.o
	g++ -g -Wall -std=c++11 main.o Test.o SortDriver.o NumberFileDriver.o NumberFileGenerator.o -o lab07

Test.o: Test.h Test.cpp Sorts.h Sorts.hpp
	g++ -g -Wall -std=c++11 -c Test.cpp

main.o: main.cpp Sorts.h Sorts.hpp
	g++ -g -Wall -std=c++11 -c main.cpp

SortDriver.o: SortDriver.h SortDriver.cpp Sorts.h Sorts.hpp
	g++ -g -Wall -std=c++11 -c SortDriver.cpp 

NumberFileDriver.o: NumberFileDriver.h NumberFileDriver.cpp Sorts.h Sorts.hpp
	g++ -g -Wall -std=c++11 -c NumberFileDriver.cpp 

NumberFileGenerator.o: NumberFileGenerator.h NumberFileGenerator.cpp Sorts.h Sorts.hpp
	g++ -g -Wall -std=c++11 -c NumberFileGenerator.cpp 
	
clean:
	rm *.o lab07
