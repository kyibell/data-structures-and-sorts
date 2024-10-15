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
        return front == -1 || front > rear; // check if the front is undefined
    }
    // isFull
    bool isFull() {
        return rear == MAX_CAPACITY - 1; // check if rear = max capacity
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
            if (front == -1) {
            front = 0;
            }
            rear++; // increment rear
            queue[rear] = element; // Set the new rear to the element
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
        if (isEmpty()) {
        return 0;
        }        
        return rear - front + 1;
    }

    void display() {
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }

    void bubblesort() {
        int length = size();
        for (int i = 0; i < length - 1; i++) {
            for (int j = front; j < rear - i; j++) {
                if(queue[j] > queue[j+1]) {
                    swap(queue[j], queue[j+1]);
                }
            }
        }
    }

    void selectionsort() {
        int length = size(); // set length = size of queue

        for (int i = front; i < rear; i++) {
            int minIndex = i; // assume minIndex = currIndex


            for (int j = i + 1; j < length; j++) {
                if (queue[j] < queue[minIndex]) { // if j < minIndex
                    minIndex = j; // minIndex = j
                }
            }
            if (minIndex != i) {
                swap(queue[i], queue[minIndex]); // swap indexes
            }
        }
    }

    void insertionsort() {
        
    }
};


int main() {

    Queue myQueue;

    myQueue.dequeue();
    myQueue.enqueue(4);
    myQueue.enqueue(6);
    myQueue.enqueue(3);
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    cout << "Front is " << myQueue.head() << endl;
    cout << "Back is " << myQueue.back() << endl;
    cout << "Size is: " << myQueue.size() << endl;
    myQueue.display();
    cout << "Selection Sort: " << endl;
    myQueue.selectionsort();
    myQueue.display();
}