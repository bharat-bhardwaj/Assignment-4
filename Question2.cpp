#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front =-1,rear=-1;

bool isEmpty() {
    return front==-1;
}

bool isFull() {
    return(rear+1)%SIZE==front;
}

void enqueue(int value) {
    if(isFull()){
        cout<<"Queue is full\n";
        return;
    }
    if(isEmpty()){
        front=rear=0;
    }else{
        rear=(rear+1)%SIZE;
    }
    queue[rear]=value;
    cout<<"Enqueued: "<<value<<endl;
}

void dequeue(){
    if(isEmpty()){
        cout<<"Queue is empty\n";
        return;
    }
    cout<<"Dequeued: "<<queue[front]<<endl;
    if (front==rear) {
        front=rear=-1; 
    } else {
        front=(front+1)%SIZE;
    }
}

void peek(){
    if(isEmpty()){
        cout<<"Queue is empty\n";
    }else{
        cout <<"Front item: "<<queue[front]<<endl;
    }
}

void display(){
    if(isEmpty()){
        cout<<"Queue is empty.\n";
        return;
    }
    cout <<"Queue contents: ";
    int i=front;
    while(true){
        cout<<queue[i]<<" ";
        if(i==rear)break;
        i=(i+1)%SIZE;
    }
    cout<<endl;
}

int main() {
    int choice,value;

    do {
        cout << "\nCircular Queue Menu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            cout<<(isEmpty()?"Queue is empty.\n":"Queue is not empty.\n");
            break;
        case 6:
            cout<<(isFull()?"Queue is full.\n":"Queue is not full.\n");
            break;
        case 7:
            cout<<"Exiting program.\n";
            break;
        default:
            cout<<"Invalid choice\n";
        }
    } while (choice != 7);

    return 0;
}
/*Circular Queue Menu
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Check if Empty
6. Check if Full
7. Exit
Enter your choice: 4
Queue is empty.

Circular Queue Menu
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Check if Empty
6. Check if Full
7. Exit
Enter your choice: 2
Queue is empty

Circular Queue Menu
1. Enqueue
2. Dequeue
3. Peek
4. Display
5. Check if Empty
6. Check if Full
7. Exit
Enter your choice:*/