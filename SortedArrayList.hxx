#include <iostream>
#include <cstdio>
#define SIZE 100000

using namespace std;

class SortedArrayList {
private:
	int* tab;
	int counter, tail;
public:
    SortedArrayList(int size);
    void push(int x);
    int pop();          // delete first (smallest) element
    int erase(int i);   // delete element on i-th position
    int find(int x);    // return the position of x or -1 if x is not found
    int size();         // return size of the list
    void remove(int x); // delete all elements equal to x
    static SortedArrayList merge(const SortedArrayList& a, const SortedArrayList& b);
                        // merge two sorted lists into a new sorted list
    void unique();      // Usuwa sąsiadujące duplikaty
    void print();       // delete neighbouring duplicates
    bool empty() const;
    void moveRight(int pos);
    void moveLeft(int pos);
};

SortedArrayList::SortedArrayList(int size){
    tab = new int[size];
	counter = 0;
	tail = -1;
}

void SortedArrayList::moveRight(int pos){
    for(int i = counter; i >= pos; i--){
		tab[i+1] = tab[i];
	}
}

void SortedArrayList::moveLeft(int pos){
    for(int i = pos; i < counter; i++){
		tab[i] = tab[i+1];
	}

}

void SortedArrayList::push(int x){
    if(empty()) tab[0] = x;
    else{
        int pos = counter;
        for(int i = 0; i < counter; i++){
            if(x < tab[i]){
                pos = i;
                break;
            }
        }
        moveRight(pos);
        tab[pos] = x;
    }
    tail++;
    counter++;
}

int SortedArrayList::pop(){
    if(empty()) return -1;

    int temp = tab[0];
    moveLeft(0);

    counter--;
    tail--;
    return temp;
}

int SortedArrayList::erase(int i){
    if(empty()) return -1;
    int temp = tab[i];
    moveLeft(i);
    counter--;
    tail--;
    return temp;
}

int SortedArrayList::find(int x){
    for(int i = 0; i < counter; i++){
        if(tab[i] == x) return i;
    }
    return -1;
}

int SortedArrayList::size(){
    return counter;
}

void SortedArrayList::remove(int x){
    for(int i = 0; i < counter; i++){
        if(tab[i] == x){
            erase(i);
            i--;
        }
    }
}

void SortedArrayList::unique(){
    for(int i = 0; i < counter; i++){
        if(tab[i] == tab [i+1]){
            erase(i+1);
            i--;
        }
    }
}

SortedArrayList SortedArrayList::merge(const SortedArrayList& a, const SortedArrayList& b){
    if(a.empty()) return b;
    if(b.empty()) return a;

    SortedArrayList newlist(SIZE);
    int posA = 0;
    int posB = 0;

    while(posA < a.counter && posB < b.counter){
        if(a.tab[posA] < b.tab[posB]){
            newlist.push(a.tab[posA]);
            posA++;
        }
        else{
            newlist.push(b.tab[posB]);
            posB++;
        }
    }
    while(posA <= a.counter-1){
        newlist.push(a.tab[posA]);
        posA++;
    }
    while(posB <= b.counter-1){
        newlist.push(b.tab[posB]);
        posB++;
    }


    return newlist;
}

bool SortedArrayList::empty() const{
    return (counter == 0);
}

void SortedArrayList::print(){
	for(int i = 0; i < counter; i++){
		cout << tab[i] << " ";
	}
    cout << endl;
}
