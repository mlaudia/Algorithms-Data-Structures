#ifndef QUEUE_HXX
#define QUEUE_HXX

#define QUEUE_SIZE 10000

class Queue{
private:
	int *tab;
	int head, tail, counter;
public:
	Queue();	
	Queue(int size);
	void push(int x);
	int pop();
	int& front();
	int size();
	bool empty();
};

Queue::Queue(){
	tab = new int[QUEUE_SIZE];
	counter = 0;
	head = tail = -1;
}	

Queue::Queue(int size){
	tab = new int[size];
	counter = 0;
	head = tail = -1;
}

void Queue::push(int x){
	if(head == tail+1 || (head == 0 && tail == QUEUE_SIZE-1)) return;
	if(head == -1)head = tail = 0;
	else if(tail == QUEUE_SIZE-1) tail = 0;
	else tail++;

	tab[tail] = x;
	counter++;
	}

int Queue::pop(){
	if(empty() == true){
		std::cout << "EMPTY" << std::endl;
		return -1;
	}
	int removed = tab[head];
	if(head == tail) head = tail = -1;
	else if(head == QUEUE_SIZE-1) head = 0;
	else head++;
	counter--;
	
	return removed;
}

int& Queue::front(){
	return tab[head];
}

int Queue::size(){
	return counter;
}

bool Queue::empty(){
	if(counter == 0) return true;
	else return false;
}

#endif