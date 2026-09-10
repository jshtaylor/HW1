// Author: Jamie Taylor

#include <iostream> // need these for functionality
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <numeric>
#include <cmath>



bool isPositiveNumber(const std::string& str); // name functions before main
unsigned long long int power(unsigned int a, unsigned int b);
unsigned int digitSum( unsigned long long int expo);
std::vector<int> vectorize_digits(unsigned long long n);
int sum_vector(const std::vector<int> v);
std::string vec_to_string(const std::vector<int> vec);


	int main(int argc, char* argv[]){
		//make sure the command line arg is within limits
	if (argc <= 2){
		std::cout<< "Error: input two numbers\n";
		return 1;
		}
	else if (argc > 3){
		std::cout<<"Error: too many inputs, enter only two numbers \n";
		return 1;
		}
		
	std::string inputA = argv[1]; // gets it from command line (c string?) to a std str
	std::string inputB = argv[2];
		
	
	if (isPositiveNumber(inputA) && isPositiveNumber(inputB)){ // checks both are numeric and if so converts them to positive shorts
		
		unsigned int a = static_cast<unsigned int>(std::stoi(inputA)); // string to int
        unsigned int b = static_cast<unsigned int>(std::stoi(inputB));
       if( b == 0 || a == 0 || b * log10(a) < 64 * log10(2)){
		
			unsigned long long int expoVal = power(a, b); //calculate expo
			//short sum = digitSum(expoVal); old code, leave for posterities sake
			std::vector<int> vecResult = vectorize_digits(expoVal);
			//std::cout << vec_to_string(vecResult) << " result of vecorize_digits\n"; test string
			int sum = sum_vector(vecResult);

			std::cout << a << " ^ " << b << " = " << expoVal << "\n"; // prints out the a ^ b = n
			std::cout << "Digit sum: " << sum << "\n"; // prints out the sum of the digits
		} else{
				std::cout << "Error: Integer overflow, try smaller values. \n"; // incase of over flow
		}
    } else {
        std::cout << "Error: Inputs must be positive integers.\n"; // other type of error is addressed
        return 1;
    }
	
	
	return 0;
	}
	
bool isPositiveNumber(const std::string& str) {
    // An empty string gets a false and causes a error to be "thrown"
    if (str.empty()) return false;

    // checks if all characters are 0-9, true if yes false if no, uses in line lambda function
    return std::all_of(str.begin(), str.end(), [](unsigned char c) { 
        return std::isdigit(c);
    });
}


unsigned long long int power(unsigned int a, unsigned int b) {
	//simple recursive power function
    if (b == 0) return 1;
    
    unsigned long long int halfPower = power(a, b / 2);
    unsigned long long int square = halfPower * halfPower;
    
    return (b % 2 == 0) ? square : a * square;
}
	

unsigned int digitSum( unsigned long long int expo){
	//does some math and added the digits by pulling them apart back to front
	//no longer in use
	int sum =0; // inital at 0
	while (expo != 0){
		sum += (expo % 10);
		expo /= 10;
		}
	return sum;
	}
	
std::vector<int> vectorize_digits(unsigned long long n){
	std::vector<int> vec;
	while(n != 0){
		vec.push_back(n % 10);
		n /= 10;
		}
	//std::cout << vec_to_string(vec) << " unflipped\n";
	std::reverse(vec.begin(),vec.end());
	//std::cout << vec_to_string(vec) << " flipped\n";
	return vec;
	}
	
int sum_vector(const std::vector<int> v){
	int sum = std::accumulate(v.begin(),v.end(),0);
	return sum;
	}
	
std::string vec_to_string(const std::vector<int> vec){
	std::string str ="[";
	for(long unsigned int i =0; i < vec.size(); i++){
		if(i != vec.size() - 1){
			str += std::to_string(vec[i]) + "," + " ";
		}else{
			str += std::to_string(vec[i]);
			}
		}
	str += "]";
	return str;
	}

	




