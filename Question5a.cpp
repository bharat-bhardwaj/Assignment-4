#include <iostream>
using namespace std;

#define SIZE 5


int q1[SIZE], q2[SIZE];
int front1=-1, rear1=-1;
int front2=-1, rear2=-1;

bool isEmpty1() { return front1==-1; }
bool isEmpty2() { return front2==-1; }
bool isFull1() { return (rear1+1)%SIZE==front1; }
bool isFull2() { return (rear2+1)%SIZE==front2; }

void enqueue1(int val) {
    if(isFull1()) { cout<<"Queue1 full\n";return; }
    if(isEmpty1()) front1=rear1=0;
    else rear1=(rear1+1)%SIZE;
    q1[rear1]=val;
}
void enqueue2(int val) {
    if(isFull2()) {cout<<"Queue2 full\n"; return; }
    if(isEmpty2()) front2=rear2=0;
    else rear2=(rear2+1)%SIZE;
    q2[rear2]=val;
}

int dequeue1() {
    if(isEmpty1()) return -1;
    int x=q1[front1];
    if(front1==rear1) front1=rear1=-1;
    else front1=(front1+1)%SIZE;
    return x;
}
int dequeue2() {
    if(isEmpty2()) return -1;
    int x=q2[front2];
    if(front2==rear2) front2=rear2=-1;
    else front2=(front2+1)%SIZE;
    return x;
}


void push(int val) {
    enqueue2(val);
    while(!isEmpty1()) {
        enqueue2(dequeue1());
    }
 
    int tempQ[SIZE]; for(int i=0;i<SIZE;i++) tempQ[i]=q1[i];
    int tf=front1, tr=rear1;
    for(int i=0;i<SIZE;i++) q1[i]=q2[i];
    front1=front2; rear1=rear2;
    for(int i=0;i<SIZE;i++) q2[i]=tempQ[i];
    front2=tf; rear2=tr;
}

int pop() {
    if(isEmpty1()) { cout<<"Stack empty\n"; return -1; }
    return dequeue1();
}

void displayStack() {
    if(isEmpty1()) { cout<<"Stack empty\n"; return; }
    cout<<"Stack (top to bottom): ";
    int i=front1;
    while(true) {
        cout<<q1[i]<<" ";
        if(i==rear1) break;
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