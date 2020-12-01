all: all.out 
all.out : main.o bunny.o functions.o 
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
main.o: main.cpp functions.h bunny.h 
	g++ $< -c
bunny.o: bunny.cpp bunny.h
	g++ $< -c
functions.o: functions.cpp functions.h
	g++ $< -c
