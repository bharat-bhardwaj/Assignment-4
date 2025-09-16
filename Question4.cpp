#include <iostream>
#include <string>
using namespace std;

const int SIZE = 100;
char queueArr[SIZE];
int front = -1, rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (rear + 1) % SIZE == front;
}

void enqueue(char value) {
    if (isFull()) return;
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queueArr[rear] = value;
}

char dequeue() {
    if (isEmpty()) return '\0';
    char val = queueArr[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    return val;
}

char getFront() {
    if (isEmpty()) return '\0';
    return queueArr[front];
}

void firstNonRepeating(string str) {
    int freq[256] = {0};
    front = rear = -1;

    cout << "Output: ";
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        freq[(int)ch]++;
        enqueue(ch);

        while (!isEmpty() && freq[(int)getFront()] > 1) {
            dequeue();
        }

        if (isEmpty())
            cout << -1 << " ";
        else
            cout << getFront() << " ";
    }
    cout << endl;
}

int main() {
    string str;
    cout << "Enter string (use _ for spaces): ";
    cin >> str;

   
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '_')
            str[i] = ' ';
    }

    firstNonRepeating(str);

    return 0;
}
 
//Enter string (use _ for spaces): a_a_b_c
//Output: a a   -1 b b b