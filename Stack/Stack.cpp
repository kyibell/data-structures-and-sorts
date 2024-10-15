#include <iostream>
using namespace std;

const int MAX_CAPACITY = 100; // Max Capacity

// Stack Class
class Stack {
    public:

    int stack[MAX_CAPACITY];
    int top = -1;

// isEmpty function
    bool isEmpty() {
    return (top == -1); // if top is -1 (undefined), return True
    }

    bool isFull() {
        return (top == MAX_CAPACITY - 1); // if top == 99, return True
    }

    // push function    
    void push(int element) {
        if (isFull()) {
            cout << "Stack is full. Cannot Push." << endl; // Check if Stack is full 
        }
        else {
            top++; // Increment Top
            stack[top] = element; // top is new element
        }
    }
    // pop function
    void pop() {
        if (isEmpty()) { // Check if Empty
            cout << "Nothing to pop. Stack is empty." << endl;
        }
        else {
            int poppedElement = stack[top]; // top element gets popped
            top--; // decrement top
        }
    }
    // peek function
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }

        return stack[top]; // return the top element
    }
    // size function
    int size() {
        return top + 1;
    }

    // print function
    void print() {
        if (top >= 0) {
            cout << "Elements are: " << endl;
            for (int i = top; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
        else {
            cout << "Stack is Empty." << endl;
        }

    }

    void bubblesort() {
        int length = size();
        bool swapped;
        for (int i = 0; i <= top; i++) {
            swapped = false;

            for  (int j = 0; j < top - i; j++) {
                if (stack[j] < stack[j + 1]) {
                    swap(stack[j], stack[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }

    void selectionsort() {
        int length = size();

        for (int i = 0; i < top; i++) {
            int minIndex = i;

            for (int j = i + 1; j <= top; j++) {
                if (stack[j] > stack[minIndex]) {
                    minIndex = j;
                }
            }
            if (i != minIndex) {
                swap(stack[i], stack[minIndex]);
            }
        }
    }

    void insertionsort() {
        for (int i = 1; i <= top; i++) {
            int key = stack[i];
            int j = i - 1;

            while (j >= 0 && stack[j] < key) {
                stack[j + 1] = stack[j];
                j--;
            }
        stack [j + 1] = key;
        }
    }
};



int main() {

    Stack myStack;
    myStack.pop();
    myStack.push(4);
    myStack.push(3);
    myStack.push(5);
    myStack.push(10);
    // myStack.print();
    // cout << myStack.peek() << endl;
    // cout << myStack.size() << endl;

    myStack.print();
    cout << "After sort: " << endl;
    myStack.selectionsort();
    myStack.print();

}