//Sorting an n element array using queues

#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>
#include "queue.hxx"

int main(){

    Queue data[10];
    std::vector<int> v1;
    int input, i;

    //data to sort
	while(std::cin >> input){
		v1.push_back(input);
	}
    
    int max_num = *std::max_element(v1.begin(), v1.end());
    //find max number of digits
    int max_digit = 1;
    while (max_num /= 10) max_digit++;

    int spot = 1;
    int pos, digit;

    //sorting
    auto start = std::chrono::high_resolution_clock::now();

    for(i = 1; i <= max_digit; i++){
        for(int j = 0; j < v1.size(); j++){
            digit = (v1[j]/spot % 10);
            data[digit].push(v1[j]);
        }

        pos = 0;
        for(int k = 0; k < 10; k++){ //number of queues k = 10
            while(!data[k].empty()){
                v1[pos] = data[k].front();
                data[k].pop();
                pos++;
            }
        }
        spot *= 10;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cerr << "Elapsed time[s] = " << elapsed.count() << std::endl;

    //after sorting
    for(i = 0; i < v1.size(); i++){
		std::cout << v1[i] << '\n';
	}
}