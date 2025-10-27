#include <iostream>
#include <queue>
#include <string>

#define MAX_CHAR 26

using namespace std;

void firstnonrepeating() {
    
    int charCount[MAX_CHAR] = {0};
    queue<char> q;
    string str;

    cout << "Enter string (a-z), enter '.' to stop: ";
    
    char c;
    while(cin >> c && c != '.')
    {
        str += c;
        q.push(c);
        charCount[c - 'a']++;

        while (!q.empty()) {
            if (charCount[q.front() - 'a'] > 1)
                q.pop();
            else {
                cout << "First non-repeating char is: " << q.front() << endl;
                break;
            }
        }

        if (q.empty())
            cout << "No non-repeating char so far.\n";
    
        cout << "Current str: " << str << endl;
    }
}

int main() {
    firstnonrepeating();
    return 0;
}
