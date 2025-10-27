#include <iostream>
#include <queue>

using namespace std;

queue<int> q;


void pushStack(int val) {
    
    int s = q.size();
    
    
    q.push(val);
    
    
    for (int i=0; i<s; i++) {
        
        q.push(q.front());
        q.pop();
    }
    cout << val << " pushed to stack.\n";
}


void popStack() {
    if (q.empty())
        cout << "Stack is emty\n";
    else {
        cout << "Element " << q.front() << " poped\n";
        q.pop();
    }
}


int topStack() {
    if (q.empty())
        return -1;
    return q.front();
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
