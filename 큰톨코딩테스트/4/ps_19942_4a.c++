// 다이어트 - 골드 4
// 알고리즘 분류 : 브루트 포스, 백트래킹

// 조합 + 비트마스킹

// 주의 : 값이 동일할 경우 사전순으로 빠른 벡터를 선택하기 위해 
// 비교하는 로직이 필요함. (비어있는지도 체크)

// 일반적인 combi함수의 구현을 통해서 nCk 의 조합을 순서대로 다 구하는 방식으로
// 풀이를 진행할 경우, 오래 걸림 -> 프루닝을 해야함

// 풀이 : 
// i를 순차적으로 커지게 하면서 포함시킬지, 제외할지 둘로 나눠가며, i가 N에 도달한 경우 
// 기준을 충족하는지 체크하고, 코스트와 벡터를 갱신하면 됨.
// -> 비트마스킹으로 재귀호출 없이, 빠르게 구현가능함.




// 일반적인 combi 구현을 통한 풀이
#include <bits/stdc++.h>
using namespace std;

int N, mp, mf, ms, mv;
int p[16], f[16], s[16], v[16], c[16];
int mn = 987654321;
int k;
bool flag = false; // 기준 충족 체크용
vector<int> res;

// 최소 영양 기준을 충족하는지 체크
bool check(vector<int> b) {
    int tp=0, tf=0, ts=0, tv=0; // 검사용 임시 저장 공간
    for (auto i : b) {
        tp+=p[i], tf+=f[i], ts+=s[i], tv+=v[i];
    }
    if (mp > tp || mf > tf || ms > ts || mv > tv) {
        return false;
    }
    return true;
}

// 조합 생성 nCk (k=1~N)
void combi(int start, vector<int> b) {
    if (b.size() == k){
        // 최소 영양 기준을 충족한다면..
        if (check(b)) {
            flag = true;
            int tc = 0; // temp cost
            for (auto i:b) {
                tc+=c[i];
            }
            // 최솟값 갱신
            if (mn > tc) {
                mn = tc;
                res = b;
            } else if (mn == tc) { // 같을 경우. 사전순 갱신
                if (res.empty() || res > b) {
                    res = b;
                }
            }
        }
        return;
    }
    for (int i=start; i<N; i++) {
        b.push_back(i);
        combi(i+1, b);
        b.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for (int i=0; i<N; i++) {
        cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
    }

    for (int i=1; i<=N; i++) {
        k=i;
        vector<int> b;
        combi(0, b);
    }

    if (!flag) {cout << -1;}
    else {
        cout << mn << '\n';
        sort(res.begin(), res.end());
        for (auto i : res) {
            cout << i+1 << " ";
        }
    }

    return 0;
}





// 비트마스킹을 이용한 풀이
#include <bits/stdc++.h>
using namespace std;

int N, mp, mf, ms, mv;
int p[16], f[16], s[16], v[16], c[16];
int mn = 987654321;
vector<int> res;

int main() {
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < N; i++) {
        cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
    }

    // 1 << N 은 2^N과 같습니다. 모든 부분집합을 순회합니다.
    for (int i = 1; i < (1 << N); i++) {
        int tp = 0, tf = 0, ts = 0, tv = 0, tc = 0;
        vector<int> b;

        for (int j = 0; j < N; j++) {
            // i의 j번째 비트가 1인지 확인 (j번째 식재료 선택 여부)
            if (i & (1 << j)) {
                tp += p[j], tf += f[j], ts += s[j];
                tv += v[j], tc += c[j];
                b.push_back(j + 1);
            }
        }

        // 영양 기준 만족 여부 확인
        if (tp >= mp && tf >= mf && ts >= ms && tv >= mv) {
            // 최솟값 갱신
            if (tc < mn) {
                mn = tc;
                res = b;
            } else if (tc == mn) {
                // 비용이 같을 경우 사전순 비교
                if (res.empty() || b < res) {
                    res = b;
                }
            }
        }
    }

    if (mn == 987654321) {
        cout << -1 << endl;
    } else {
        cout << mn << "\n";
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << (i == res.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}




// 조합 combi 코드 수정 개선 - 프루닝 활용
#include <bits/stdc++.h>
using namespace std;

int N, mp, mf, ms, mv, tp, tf, ts, tv;
int p[16], f[16], s[16], v[16], c[16];
int mn = 987654321;
int k;
vector<int> res;
vector<int> tmp;

// 조합 생성 nCk (k=1~N)
void combi(int start, int cost) {
    if (mn <= cost) return; // 프루닝 적용 -> 애초에 안되는 것은 제외 -> 시간단축
    if (mp <= tp && mf <= tf && ms <= ts && mv <= tv) {
        if (mn > cost) {
            res = tmp;
            mn = cost;
        }
        return;
    }
    for (int i=start; i<N; i++) {
        tmp.push_back(i);
        tp+=p[i], tf+=f[i], ts+=s[i], tv+=v[i];
        combi(i+1, cost+c[i]);
        tp-=p[i], tf-=f[i], ts-=s[i], tv-=v[i];
        tmp.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> N;
    cin >> mp >> mf >> ms >> mv;
    for (int i=0; i<N; i++) {
        cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
    }

    combi(0, 0);

    if (mn == 987654321) {cout << -1;}
    else {
        cout << mn << '\n';
        // sort(res.begin(), res.end());
        for (auto i : res) {
            cout << i+1 << " ";
        }
    }

    return 0;
}
// 위 코드는 사전순으로 빠른 조합을 먼저 방문하기 떄문에 따로 사전순 비교가 필요 없음