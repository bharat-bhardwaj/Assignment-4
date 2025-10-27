#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void interLeaveQueue(queue<int>& q) {
    if (q.size() % 2 != 0) {
        cout << "Queue must be evn size.\n";
        return;
    }

    stack<int> s;
    int halfSize = q.size() / 2;

    
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    
    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    cout << "Orignl queue: 4 7 11 20 5 9\n";

    interLeaveQueue(q);

    cout << "Interleavd queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
