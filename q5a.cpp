#include <iostream>
#include <queue>

using namespace std;

queue<int> q1, q2;

void pushStack(int val) {
    
    q2.push(val);

    
    while(!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }

    
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
    
    cout << val << " pushed to stack.\n";
}

void popStack() {
    if (q1.empty()) {
        cout << "Stack is emty\n";
    } else {
        cout << "Element " << q1.front() << " poped\n";
        q1.pop();
    }
}

int topStack() {
    if (q1.empty())
        return -1;
    return q1.front();
}

int main() {
    
    pushStack(10);
    pushStack(20);
    pushStack(30);

    popStack();
    
    cout << "Top element is: " << topStack() << endl;
    
    popStack();
    
    cout << "Top element is: " << topStack() << endl;
    
    return 0;
}
