// 비트마스킹으로도 풀 수 있음...

#include<bits/stdc++.h>
using namespace std;

int N;
int S[50][50];
vector<int> v;
int team_s, team_l;
int res = 987654321;


// 팀 조합
void combi(int start, vector<int> b) { // 벡터로 안하고 bool 배열로 했으면 더 간단히 구현했을지도..
    if (b.size() == N/2) {
        // 로직 - 각 팀의 능력치 구해 차를 구하고 결과 갱신
        int sum = 0, sum1 = 0;
        for (int i=0; i<N/2-1; i++) {
            for (int j=i+1; j<N/2; j++) {
                sum+= (S[b[i]][b[j]] + S[b[j]][b[i]]);
            }
        }
        bool a[50] = {0, };
        for (int i=0; i<N/2; i++) {
            a[b[i]] = 1;
        }
        vector<int> b1;
        for (int i=0; i<N; i++) {
            if (a[i] == 0) {
                b1.push_back(i);
            }
        }
        for (int i=0; i<N/2-1; i++) {
            for (int j=i+1; j<N/2; j++) {
                sum1+= (S[b1[i]][b1[j]] + S[b1[j]][b1[i]]);
            }
        }
        res = min(res, abs(sum1 - sum));
        return;
    }
    for (int i=start; i<N; i++) {
        b.push_back(i);
        combi(i+1, b);
        b.pop_back();
    }
}

int main() {

    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> S[i][j];
        }
    }

    // N명 중 N/2 명을 뽑는 경우의 수
    vector<int> b;
    combi(0, b);

    cout << res;
    return 0;
}