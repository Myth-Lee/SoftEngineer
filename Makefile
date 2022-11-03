Judge:main.o Platform.o creat_input.o run_OJ.o equal_judge.o
	g++ -o Judge main.o Platform.o creat_input.o run_OJ.o equal_judge.o -g
main.o:main.cpp
	g++ -c -o main.o main.cpp
Platform.o:Platform.cpp
	g++ -c -o Platform.o Platform.cpp
creat_input.o: creat_input.cpp
	g++ -c -o creat_input.o creat_input.cpp
run_OJ.o: run_OJ.cpp
	g++ -c -o run_OJ.o run_OJ.cpp
equal_judge.o: equal_judge.cpp
	g++ -c -o equal_judge.o equal_judge.cpp 

clean: 
	rm Judge main.o Platform.o creat_input.o run_OJ.o equal_judge.o