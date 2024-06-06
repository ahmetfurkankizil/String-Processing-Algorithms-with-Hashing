all: subtask1 subtask2

subtask1: Subtask1.cpp
	g++ Subtask1.cpp -o subtask1

subtask2: Subtask2.cpp
	g++ Subtask2.cpp -o subtask2

run: all
	./subtask1 log1.txt > output1.txt
	./subtask2 log2.txt > output2.txt
