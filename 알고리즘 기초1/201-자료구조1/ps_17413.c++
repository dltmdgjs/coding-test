// 문제 : 단어 뒤집기2
// 알고리즘 분류 : 스택

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<char> s;
    int i=0;
    bool istag = false;
    string st;

    getline(cin, st);

    while (i!=st.length()) {
        // tag
        if (st[i] == '<') {
            // cout << st[i];
            istag = true;
            if (!s.empty()) {
                while(true) {
                    if (s.empty()) break;
                    cout << s.top();
                    s.pop();
                }
            }
        }

        // stack or print
        if (!istag) {
            if (st[i] == ' ') {
                while(true) {
                    if (s.empty()) break;
                    cout << s.top();
                    s.pop();
                }
                cout << st[i];
            }
            else {
                s.push(st[i]);
            }
            if (i==st.length()-1) {
                while(true) {
                    if (s.empty()) break;
                    cout << s.top();
                    s.pop();
                }
            }
        }
        else {
            cout << st[i];
            // end of tag
            if (st[i] == '>') {
                istag = false;
            }
        }

        i++;
    }
    return 0;
}
