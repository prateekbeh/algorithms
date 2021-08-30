#include<bits/stdc++.h>

using namespace std;


class Queue{
	public:
		int front, rear , sz;
		int capacity;
		int* arr;
};

Queue* createQueue(int capacity)
{
	Queue *q = new Queue();
	q->capacity = capacity;
	q->front = q->sz = 0;
	q->rear = capacity - 1;
	q->arr = new int[q->capacity];
	return q;
}

bool isFull(Queue* q){
	return (q->sz == q->capacity);
}

bool isEmpty(Queue* q){
	return (q->sz = 0); 
}

void enqueue(Queue* q,int element){
	if(isFull(q)){
		return;
	}
	q->rear = (q->rear + 1)%q->capacity;
	q->arr[q->rear] = element;
	q->sz = q->sz + 1;
	
}

int dequeue(Queue* q){
	if(isEmpty(q))
		return -1;
	int item = q->arr[q->front];
	q->front = (q->front + 1)%q->capacity;
	q->sz = q->sz - 1;
	return item;
}

int front(Queue* q)
{
	if(isEmpty(q))
		return -1;
	return q->arr[q->front];
}

	
int rear(Queue* q)
{
	if(isEmpty(q))
		return -1;
	return q->arr[q->rear];
}

int main()
{
	Queue *q = createQueue(10);
	enqueue(q,2);
	enqueue(q,3);
	enqueue(q,4);
	cout<<"Print Start"<<endl;
	cout<<"front="<<front(q)<<endl;
	cout<<"rear="<<rear(q)<<endl;
	dequeue(q);
	cout<<front(q)<<endl;
	cout<<rear(q)<<endl;
	dequeue(q);
	cout<<front(q)<<endl;
	cout<<rear(q)<<endl;
	
	return 0;

}
