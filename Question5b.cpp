#include <iostream>
using namespace std;

#define SIZE 5

int q[SIZE];
int front=-1, rear=-1;

bool isEmpty() { return front==-1; }
bool isFull() { return (rear+1)%SIZE==front; }

void enqueue(int val) {
    if(isFull()) { cout<<"Queue full\n"; return; }
    if(isEmpty()) front=rear=0;
    else rear=(rear+1)%SIZE;
    q[rear]=val;
}

int dequeue() {
    if(isEmpty()) return -1;
    int x=q[front];
    if(front==rear) front=rear=-1;
    else front=(front+1)%SIZE;
    return x;
}


void push(int val) {
    enqueue(val);
    int n=(rear-front+SIZE)%SIZE+1;
    for(int i=0;i<n-1;i++) {
        enqueue(dequeue());
    }
}

int pop() {
    if(isEmpty()) { cout<<"Stack empty\n"; return -1; }
    return dequeue();
}

void displayStack() {
    if(isEmpty()) { cout<<"Stack empty\n"; return; }
    cout<<"Stack (top to bottom): ";
    int i=front;
    while(true) {
        cout<<q[i]<<" ";
        if(i==rear) break;
        i=(i+1)%SIZE;
    }
    cout<<endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    displayStack();
    cout<<"Popped: "<<pop()<<endl;
    displayStack();
}
/*Stack (top to bottom): 30 20 10 
Popped: 30
Stack (top to bottom): 20 10*/
