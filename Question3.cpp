#include <iostream>
using namespace std;

#define SIZE 20   

int queueArr[SIZE];
int front=-1,rear =-1;

bool isEmpty() {
    return front==-1;
}

bool isFull() {
    return (rear + 1) % SIZE == front;
}

void enqueue(int value) {
    if (isFull()) {
        cout << "Queue is full\n";
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queueArr[rear] = value;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return -1;
    }
    int val = queueArr[front];
    if (front == rear) {
        front = rear = -1; 
    } else {
        front = (front + 1) % SIZE;
    }
    return val;
}

int size() {
    if (isEmpty()) return 0;
    if (rear >= front) return rear - front + 1;
    return SIZE - (front - rear - 1);
}

void display() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
    int i = front;
    while (true) {
        cout << queueArr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}


void interleave() {
    int n = size();
    if (n % 2 != 0) {
        cout << "Queue must have even number of elements\n";
        return;
    }

    int half = n / 2;
    int temp[SIZE];

    
    for (int i = 0; i < half; i++) {
        temp[i] = dequeue();
    }

    
    for (int i = 0; i < half; i++) {
        enqueue(temp[i]);      
        enqueue(dequeue());    
    }
}

int main() {
    int n, val;
    cout << "Enter even number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        enqueue(val);
    }

    cout << "Original queue: ";
    display();

    interleave();

    cout << "Interleaved queue: ";
    display();

    return 0;
}
/*Enter even number of elements: 6
Enter 6 elements:
1
2
3
4
5
6
Original queue: 1 2 3 4 5 6 
Interleaved queue: 1 4 2 5 3 6*/