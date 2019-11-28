make:
	g++ -g -std=c++11 *.cpp -o list
	
mem:
	g++ --leak-check=full -std=c++11 *.cpp -o list
	