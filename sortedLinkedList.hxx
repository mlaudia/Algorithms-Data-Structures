#include <iostream>
#include <cstdio>

using namespace std;

class SortedLinkedList{
    public:
    struct node {       
        int x;          
        node* prev;
        node* next;
    };

    node* tab;
    node* head;
    int counter;

	SortedLinkedList();
    void push(int x);
    int pop();          // delete first (smallest) element
    int erase(int i);   // delete element on i-th position
    int find(int x);    // return the position of x or -1 if x is not found
    int size();         // return size of the list
    void remove(int x); // delete all elements equal to x
    static SortedLinkedList merge(const SortedLinkedList& a, const SortedLinkedList& b);
                        // merge two sorted lists into a new sorted list
    void unique();      // delete neighbouring duplicates
    void print();
	bool empty() const;

};

SortedLinkedList::SortedLinkedList(){
    head = nullptr;
    counter = 0;
}

void SortedLinkedList::push(int x){
    tab = new node();
    tab->x = x;

    if(empty()){
        head = new node();
        head = tab;
    }
    else if(head->x > x){
        head->prev = tab;
        tab->next = head;
        head = tab;
    }
    else{
        node* pos = head;
        while(pos->next != nullptr){
            if(pos->next->x > x) break;
            pos = pos->next;
        }

        tab->next = pos->next;
        if(pos->next != nullptr) tab->next->prev = tab;
        pos->next = tab;
        tab->prev = pos;

    }
	counter++;
}

int SortedLinkedList::pop(){
    if(empty()) return -1;

    int temp = head->x;
    
    if(head->next == nullptr){
        delete head;
        head = nullptr;
    }
    else{
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }

    counter--;
    return temp;
}

int SortedLinkedList::erase(int i){
    if(empty()) return -1;
    int temp;
    if(i == 0){
        temp = pop();
        return temp;
    }

    int it = 0;
    node* a = head;
    
    while(a != nullptr){
        if(it == i){
            temp = a->x;
            if(a->next != nullptr) a->next->prev = a->prev;
            a->prev->next = a->next;
            delete a;
        }
        a = a->next;
        it++;
    }
    counter--;
    return temp;
}

int SortedLinkedList::size(){
	return counter;
}

void SortedLinkedList::remove(int x){
    if(empty()) return;
    node* a;
    a = head;
    int pos = 0;
    while(a != nullptr){
        if(a->x == x){
            erase(pos);
            pos--;
        }
        a = a->next;
        pos++;
    }
}

SortedLinkedList SortedLinkedList::merge(const SortedLinkedList& a, const SortedLinkedList& b){
    if(a.empty()) return b;
    if(b.empty()) return a;

    SortedLinkedList newlist;
    SortedLinkedList::node *posA, *posB;
    posA = a.head;
    posB = b.head;

    while(posA && posB){
        if(posA->x < posB->x){
            newlist.push(posA->x);
            posA = posA->next;
        }
        else{
            newlist.push(posB->x);
            posB = posB->next;
        }
    }
    while(posA != nullptr){
        newlist.push(posA->x);
        posA = posA->next;
    }
    while(posB != nullptr){
        newlist.push(posB->x);
        posB = posB->next;
    }
    
    return newlist;
}

void SortedLinkedList::unique(){
    if(empty()) return;
    node* a;
    a = head->next;
    int pos = 1;
    while(a != nullptr){
        if(a->x == a->prev->x){
            erase(pos);
            pos--;
        }
        a = a->next;
        pos++;
    }
}

bool SortedLinkedList::empty() const{
    return (head == nullptr);
}

void SortedLinkedList::print(){
    node* a = head;

    while(a != nullptr){
        cout << a->x << " ";
        a = a->next;
    }
    cout << endl;
}












