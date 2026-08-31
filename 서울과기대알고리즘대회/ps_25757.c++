#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set<string> s;
    int N;
    char game;
    cin >> N >> game;
    cin.ignore();
    for (int i=0; i<N; i++) {
        string temp;
        cin >> temp;
        s.insert(temp);
    }
    int player = s.size();
    if (game == 'Y') cout << player << "\n";
    if (game == 'F') cout << player/2 << "\n";
    if (game == 'O') cout << player/3 << "\n";

    return 0;
}