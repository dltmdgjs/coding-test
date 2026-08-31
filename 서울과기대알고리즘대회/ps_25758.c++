#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N;
set<char> s;
vector<string> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 입력
    cin >> N;
    cin.ignore();
    for (int i=0; i<N; i++) {
        string s1;
        cin >> s1;
        v.push_back(s1);
    }

    // 표현형 입력
    // 시간 초과를 방지하기 위해서, 각 알파벳을 기준으로 조건을 나누어서 처리한다.
    // (일일이 비교하면 시간초과)
    for (char x = 'A'; x <= 'Z'; x++) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (v[i][0] == x) cnt++;
		}

		if (cnt > 1) {
			for (int i = 0; i < N; i++) {
				s.insert(max(x, v[i][1]));
			}
		}
		else if (cnt == 1) {
			for (int i = 0; i < N; i++) {
				if (v[i][0] == x) continue;
				s.insert(max(x, v[i][1]));
			}
		}
	}

    // 출력
    cout << s.size() << "\n";
    for (char i : s) {
        cout << i << " ";
    }
    return 0;
}