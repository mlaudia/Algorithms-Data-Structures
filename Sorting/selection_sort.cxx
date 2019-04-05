#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

int main(){

    std::vector<int> data;
	int i, j, temp, input;

	while(std::cin >> input){
		data.push_back(input);
	}

	auto start = std::chrono::high_resolution_clock::now();

    for(i = 0; i < data.size(); i++){
        temp=i;
        for(j = i+1; j < data.size(); j++){
            if(data[j] < data[temp]) temp=j;
        }
         std::swap(data[temp], data[i]);
    }
	
	auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;


	for(i = 0; i < data.size(); i++){
		std::cout << data[i] << '\n';
	}


}