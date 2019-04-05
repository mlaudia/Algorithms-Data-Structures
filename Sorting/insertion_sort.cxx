#include <iostream>
#include <chrono>
#include <vector>

int main(){

	std::vector<int> data;
	int input, temp, j;

	while(std::cin >> input){
		data.push_back(input);
	}

 	auto start = std::chrono::high_resolution_clock::now();
	for(int i = 1; i < data.size(); i++){
		temp = data[i];
		j = i;
		while(temp < data[j-1]){
			data[j] = data[j-1];
			j--;
		}
		data[j] = temp;
	}
	auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;

	for(int i = 0; i < data.size(); i++){
		std::cout << data[i] << '\n';
	}





}
