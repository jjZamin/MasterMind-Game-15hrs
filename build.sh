#!/bin/bash

running=1

while [ $running == 1 ]; do
	echo [1]Compile and Play, [2]Just compile, [3]Exit
	read input
	SUCCESS=$? 

	if [[ $input == 1 ]]; then
		echo [ Compiling... ]
		g++ -c Src/*.cpp -std=c++11 -Werror
		g++ *.o -o bin/MasterMindX -lsfml-graphics -lsfml-window -lsfml-system
		echo [ Running... ]
		./bin/MasterMindX
		if [ SUCCESS == 0 ]; then
			echo [ Something went wrong... ]
		else
			echo [ DONE ]
			exit
		fi
	elif [[ $input == 2 ]]; then
		echo [ Compiling... ]
		g++ -c Src/*.cpp -std=c++11 -Werror
		g++ *.o -o bin/MasterMindX -lsfml-graphics -lsfml-window -lsfml-system
		if [ SUCCESS == 0 ]; then
			echo [ Something went wrong... ]
		else
			echo [ DONE ]
			exit
		fi
	elif [[ $input == 3 ]]; then
		exit
	else
		echo [ No such option... ]
	fi
done