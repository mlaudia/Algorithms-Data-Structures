#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

int main(){
	
	std::vector<int> data, count, sorted;
	int i, input, temp;

	while(std::cin >> input){
		data.push_back(input);
	}

	for(i = 0; i < data.size(); i++){
		sorted.push_back(0);
	}
	
	for(i = 0; i < data.size(); i++){
		count.push_back(0);
	}

	auto start = std::chrono::high_resolution_clock::now();
	for(i = 0; i < data.size(); i++){
		count[data[i]]++;	
	}

	for(i = 1; i <= count.size(); i++){
		count[i] += count[i-1];	
	}

	for(i = data.size(); i >= 0 ; i--){
		sorted[count[data[i]]-1] = data[i];
		count[data[i]]--; 
	}
	auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;

	for(i = 0; i < sorted.size(); i++){
		std::cout << sorted[i] << '\n';
	}
}
