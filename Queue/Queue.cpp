#include <iostream>
using namespace std;

const int MAX_CAPACITY = 100; 

// Queue class
class Queue {
    public:

    int queue[MAX_CAPACITY];
    int front = -1;
    int rear = -1;

    // isEmpty
    bool isEmpty() {
        return front == rear; // check if the front is undefined
    }
    // isFull
    bool isFull() {
        return rear == MAX_CAPACITY; // check if rear = max capacity
    }

    // front 
    int head() {
        return queue[front];
    }
    // back
    int back() {
        return queue[rear];
    }

    //Enqueue
    void enqueue(int element) {
        if (isFull()) {
            cout << "Could not enqueue. Queue is full." << endl;
        }
        else {
            if (front = -1) {
            front = 0;
            rear++; // increment rear
            queue[rear] = element; // Set the new rear to the element
            }
        }
    }
    // Dequeue
    void dequeue() {
        if (isEmpty()) {
            cout << "Could not dequeue. Queue is empty." << endl;
        }
        else {
            cout << "Element dequeued is: " << queue[front] << endl;
            front++;
        }
    }
    // size
    int size() {
        return rear + 1;
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};


int main() {

    Queue myQueue;

    myQueue.dequeue();
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    cout << "Front is " << myQueue.head() << endl;
    cout << "Back is " << myQueue.back() << endl;
    cout << "Size is: " << myQueue.size() << endl;
    myQueue.display();
    myQueue.dequeue();
    myQueue.display();
}