all:
	g++ -Wall -O3 -g -std=c++17 power-digit-sum.cpp -o pds
clean:
	rm -f pds
