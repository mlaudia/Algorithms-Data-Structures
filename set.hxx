#include <iostream>
#include <vector>
#include <algorithm>

class Set{
    public:
        std::vector<float> data;
        int counter;

        Set();
        Set(const Set& s);
        int size();
        void add(float x);
        void remove(float x);
        void print();
        Set suma(Set s);
        Set roznica(Set s);
        Set czescWspolna(Set s);
        Set roznicaSymetryczna(Set s);


};

Set::Set(){
    counter = 0;
}

Set::Set(const Set& s){
    data = s.data;
    counter = s.counter;
}

int Set::size(){
    return counter;
}

void Set::add(float x){
    std::vector<float>::iterator it = std::find(data.begin(), data.end(), x);

    if(it == data.end()){
        data.push_back(x);
        counter++;
    }
        
}

void Set::remove(float x){
    for(int i = 0; i < data.size(); i++){
        if(data[i] == x){
            data.erase(data.begin()+i);
            counter--;
            return;
        }
    }
}

void Set::print(){
    for(int i = 0; i < counter; i++){
        std::cout << data[i] << " ";
    }
    std::cout << '\n';
}

Set Set::suma(Set s){   //sum
    Set result(s);
    for(int i = 0; i < counter; i++) result.add(data[i]);

    return result;
}

Set Set::czescWspolna(Set s){   //intersection
    Set result;
    std::vector<float>::iterator it; 

    for(int i = 0; i < counter; i++){
        it = std::find(s.data.begin(), s.data.end(), data[i]);
        if(it != s.data.end()) result.add(data[i]);
    }

    return result;
}

Set Set::roznica(Set s){    //difference
    Set result;
    std::vector<float>::iterator it; 

    for(int i = 0; i < counter; i++){
        it = std::find(s.data.begin(), s.data.end(), data[i]);
        if(it == s.data.end()) result.add(data[i]);
    }

    return result;
}

Set Set::roznicaSymetryczna(Set s){ //symmetric difference
    Set s1 = roznica(s);
    Set s2 = s.roznica(*this);

    Set result(s1);
    for(int i = 0; i < s2.size(); i++) result.add(s2.data[i]);
    return result;

}


