#include <iostream>
using namespace std;

#define SIZE 5

int CQueue[SIZE];
int front = -1, rear = -1;

bool isFull() {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        return true;
    }
    return false;
}

bool isEmpty() {
    if (front == -1) {
        return true;
    }
    return false;
}

void enQueue() {
    if (isFull()) {
        cout << "Queue is ful\n";
    } else {
        int val;
        cout << "Enter value to enque: ";
        cin >> val;
        
        if (front == -1) 
            front = 0;
        
        rear = (rear + 1) % SIZE;
        CQueue[rear] = val;
        cout << val << " enqueued\n";
    }
}

void deQueue() {
    int element;
    if (isEmpty()) {
        cout << "Queue is emty\n";
        
    } else {
        element = CQueue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % SIZE;
        }
        cout << "Element " << element << " dequeued\n";
    }
}

void peek() {
    if (isEmpty()) {
        cout << "Queue is emty\n";
    } else {
        cout << "Front element is: " << CQueue[front] << endl;
    }
}

void display() {
    int i;
    if (isEmpty()) {
        cout << "Queue is emty\n";
    } else {
        cout << "Queue elements ar: ";
        
        for (i = front; i != rear; i = (i + 1) % SIZE)
            cout << CQueue[i] << " ";
        
        cout << CQueue[i];
        cout << endl;
    }
}

int main() {
    int ch;
    
    while(1) {
        cout << "\n--- CIRCULR QUEUE MENU ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. IsEmpty\n";
        cout << "4. IsFull\n";
        cout << "5. Peek\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choise: ";
        cin >> ch;

        switch (ch) {
            case 1:
                enQueue();
                break;
            case 2:
                deQueue();
                break;
            case 3:
                if(isEmpty()) cout << "Queue is emty\n";
                else cout << "Queue is not emty\n";
                break;
            case 4:
                if(isFull()) cout << "Queue is ful\n";
                else cout << "Queue is not ful\n";
                break;
            case 5:
                peek();
                break;
            case 6:
                display();
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choise\n";
        }
    }

    return 0;
}
