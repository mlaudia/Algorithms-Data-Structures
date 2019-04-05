#include <iostream>
#include <vector>
#include <chrono>

int main(){
	
	std::vector<int> data;
	int input, temp;

	while(std::cin >> input){
		data.push_back(input);
	}

	auto start = std::chrono::high_resolution_clock::now();

	for(int i = 0; i < data.size(); i++){
		for(int j = data.size()-1; j >= i+1; j--){
			if(data[j-1] > data[j]) std::swap(data[j-1], data[j]);
		}
	}
	auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;
	
	for(int i = 0; i < data.size(); i++){
		std::cout << data[i] << '\n';
	}
	
}
