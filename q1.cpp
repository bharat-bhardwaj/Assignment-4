#include <iostream>
using namespace std;

#define SIZE 5

int A[SIZE];
int front = -1;
int rear = -1;

bool isfull(){
    if(rear == SIZE - 1){
        return true;
    }
    return false;
}

bool isempty(){
    if(front == -1 || front > rear){
        return true;
    }
    return false;
}

void enqueue(){
    if(isfull()){
        cout << "Queue is ful\n";
    }
    else{
        int val;
        cout << "Enter value: ";
        cin >> val;
        
        if(front == -1)
            front = 0;
        
        rear++;
        A[rear] = val;
        cout << val << " added\n";
    }
}

void dequeue(){
    if(isempty()){
        cout << "Queue is emty\n";
    }
    else{
        cout << "Element " << A[front] << " removed\n";
        front++;
    }
}

void peek(){
    if(isempty()){
        cout << "Queue is emty\n";
    }
    else{
        cout << "Front element is: " << A[front] << endl;
    }
}

void display(){
    if(isempty()){
        cout << "Queue is emty\n";
    }
    else{
        cout << "Queue elements ar: ";
        for(int i = front; i <= rear; i++)
            cout << A[i] << " ";
        cout << endl;
    }
}

int main()
{
    int ch;
    
    while(1) {
        cout << "\n--- SIMPLE QUEUE MENU ---\n";
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
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                if(isempty()) cout << "Queue is emty\n";
                else cout << "Queue is not emty\n";
                break;
            case 4:
                if(isfull()) cout << "Queue is ful\n";
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
