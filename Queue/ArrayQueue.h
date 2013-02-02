#include <iostream>
using namespace std;
#include "QueueExceptions.h"

const int MAX_SIZE = 15;

class ArrayQueue {

private:

	int data[MAX_SIZE];
	int front;
	int rear;

public:

	//default ctor
	ArrayQueue() {
		front = -1;
		rear = -1;
	}

	//Queue a new element
	void Enqueue(int element) {
		//Do not allow the queue to grow more tha MAX_SIZE-1
		if(Size() == MAX_SIZE - 1) {
			throw new QueueOverflowException();
		}
		else {

			data[rear] = ++rear % MAX_SIZE;	//Allocate space before inserting a new element.  Modulous operator is used here to facilitate the wrap around of the REAR element.
			data[rear] = element;			//insert user supplied date into newly allocated space

			//if inserting into a new array, front and rear refer to the same element of data (i.e. one element in queue)
			if(data[front] == -1) {
				data[front] = data[rear];
			}
		}
	}

	//Dequeue a new element
	int Dequeue() {
		
		
		int dequeuedData = 0;

		//Do not allow the queue to grow more tha MAX_SIZE-1
		if(isEmpty()) {
			throw new QueueUnderflowException();
			return 0;
		}
		else {
			
			dequeuedData = data[front+1];	//The +1 is to account for the fact that front starts with a -1 as its contained value.  In terms of an array, this will return an arbitrary number. 
			if(front == rear) {
				front = rear = -1;
			}
			else {
				front = ++front % MAX_SIZE;
			}
			/*Modulous operator is used here to facilitate the wrap around of the FRONT element AFTER dequeueing.*/
			//front = ++front % MAX_SIZE;
		}
		return dequeuedData;
		
	}


	int Front() {
		if(isEmpty()) {
			throw new QueueUnderflowException();
		}
		return data[front];
	}


	//Return the size of the queue
	int Size() {
		return abs(rear - front);
	}

	//Check if the queue is empty
	bool isEmpty() {
		return (front == rear) ? true : false;
	}

};