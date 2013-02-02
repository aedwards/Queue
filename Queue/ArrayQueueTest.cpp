#include "ArrayQueue.h";


void main() {

	ArrayQueue myQueue;


	try {
		if(myQueue.isEmpty()) {
			cout << "Queue is empty." << endl;
		}

		//Enqueue elements
		myQueue.Enqueue(23);
		myQueue.Enqueue(123);
		myQueue.Enqueue(300);
		myQueue.Enqueue(84);
		myQueue.Enqueue(93);
		myQueue.Enqueue(10);
		myQueue.Enqueue(994);
		
		
		
		if(myQueue.isEmpty()) {
			cout << "Queue is empty." << endl;
		}
		else {
			cout << "Queue has been initialized with " << myQueue.Size() << " items." << endl;
		}

		
		cout << "Dequeued item: " << myQueue.Dequeue() << endl;
		cout << "Dequeued item: " << myQueue.Dequeue() << endl;
		cout << "Dequeued item: " << myQueue.Dequeue() << endl;

		cout << "Queue now has " << myQueue.Size() << " items." << endl;

	}
	catch(exception ex) {
		cout << "Some exception occurred." << endl;
	}

	getchar();

}