Program is written and compiled in Linux platform.

"makefile" is the makefile of compiling:
1) list.cpp	- The benchmark program of STL std::list 
2) map.cpp 	- The benchmark program of STL std::map
3) umap.cpp	- The benchmark program of STL std::unordered_map

with the optimization level of O2 in g++.

The listed .cpp program listed above will compile into:
1) list.cpp -> list
2) map.cpp -> map
3) umap.cpp -> umap

They are executable by providing command line argument as shown below

./list 100000
./map 2000000
./umap 40000000

It accepts only one argument, and it is the number of element you wish to generate 
into the choice of container. 

Take note that the number will be multiplied by 3 times simply because of the operation 
done in the benchmark program.

For example, feeding 1000000 into the program in command line will generate 3000000 
elements because the same number was used to generate in these operations:

1) Insert ascending values - 1000000
2) Insert descending values - 1000000
3) Insert randomized values - 1000000
                              =======
                              3000000
			      =======

A bash shell script "benchmarkScript", was written in order to ease the 
benchmarking process. Call the script by

./benchmarkScript 1000000

where the number is the number of element wish to generate. 

This script simply calls the 3 executables and feed the argument into the program
execution. And will also time the program run time. 

To redirect all the output of "benchmarkScript" into a file. Run command below

./benchmarkScript 1000000 &> filename

Output will be redirected into the file.

======================================================================================