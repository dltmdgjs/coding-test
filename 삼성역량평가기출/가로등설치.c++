#include <bits/stdc++.h>
using namespace std;

// 최대 쿼리 수와 초기 가로등 수를 고려하여 넉넉하게 설정
#define MAX 400005 

int Q, C, N, M, X, D;
bool active[MAX];      // 가로등 고유 번호(ID)의 활성화 여부 (Delete 체크용)
int pos[MAX];         // 가로등 고유 번호(ID)별 설치 위치(Position) 저장
int s, e, id_cnt = 1; // s: 가장 왼쪽 위치, e: 가장 오른쪽 위치, id_cnt: 고유 번호 생성기
set<int> st;          // 설치된 가로등 위치를 정렬된 상태로 유지 (Binary Search Tree 기반)

// priority_queue에서 간격(Gap)을 관리하기 위한 구조체
struct Gap {
    int l, r;
    // Max-heap을 위한 비교 연산자 정의
    bool operator<(const Gap& other) const {
        int d1 = r - l, d2 = other.r - other.l;
        if (d1 != d2) return d1 < d2; // 1. 간격(Distance)이 큰 것이 우선순위가 높음
        return l > other.l;           // 2. 간격이 같다면 시작 좌표(l)가 작은 것이 우선순위가 높음
    }
};

// 간격 정보를 담는 priority_queue
priority_queue<Gap> pq;

// Lazy Deletion을 위한 유효성 검사 함수
// priority_queue에서 꺼낸 간격 {l, r}이 현재 set 상태에서도 인접한지 확인
bool isValid(int l, int r) {
    auto it = st.find(l);
    if (it == st.end()) return false; // l 위치의 가로등이 이미 삭제된 경우
    auto nxt = next(it);
    if (nxt == st.end()) return false; // l이 마지막 가로등이라 뒤에 아무것도 없는 경우
    return *nxt == r; // l의 바로 다음 가로등이 r인지 확인
}




int main() {
    // 입출력 속도 향상을 위한 Fast I/O
    ios::sync_with_stdio(0); cin.tie(0);

    if (!(cin >> Q)) return 0; // 명령 수(Q) 입력
    cin >> C >> N >> M;       // 도로 길이(N), 초기 가로등 수(M) 입력

    int last_pos;
    for (int i = 1; i <= M; i++) {
        cin >> X;
        st.insert(X);
        pos[id_cnt] = X;
        active[id_cnt++] = true;
        
        if (i == 1) s = X; // 가장 왼쪽 가로등 갱신
        else pq.push({last_pos, X}); // 이전 가로등과의 간격을 pq에 삽입
        
        if (i == M) e = X; // 가장 오른쪽 가로등 갱신
        last_pos = X;
    }

    // 나머지 Q-1개의 명령 처리
    for (int i = 1; i < Q; i++) {
        cin >> C;


        // [설치 명령]
        if (C == 200) {
            // 1. 유효하지 않은 간격은 pop하여 제거 (Lazy Deletion)
            while (!pq.empty() && !isValid(pq.top().l, pq.top().r)) pq.pop();
            
            Gap top = pq.top(); pq.pop();
            
            // 2. 가장 먼 간격의 중앙에 새 가로등 설치
            int mid = (top.l + top.r) / 2;
            if ((top.l + top.r) % 2) mid++; // 거리가 홀수일 때 오른쪽으로 치우치게 설정

            st.insert(mid);
            pos[id_cnt] = mid;
            active[id_cnt++] = true;

            // 3. 새로 생긴 두 개의 간격을 pq에 삽입
            pq.push({top.l, mid});
            pq.push({mid, top.r});
        } 


        // [제거 명령]
        else if (C == 300) {
            cin >> D; // 제거할 가로등의 ID 입력
            if (!active[D]) continue; // 이미 제거된 경우 무시
            
            int cur_p = pos[D];
            auto it = st.find(cur_p);
            
            // 1. 제거될 가로등의 양옆 가로등을 연결하여 새로운 간격 생성
            if (it != st.begin() && next(it) != st.end()) {
                pq.push({*prev(it), *next(it)});
            }
            
            // 2. 양 끝 가로등(s, e)이 제거되는 경우 위치 갱신
            if (cur_p == s) {
                auto nxt = next(it);
                s = (nxt != st.end()) ? *nxt : -1;
            }
            if (cur_p == e) {
                e = (it != st.begin()) ? *prev(it) : -1;
            }

            // 3. 실제 데이터 삭제 및 비활성화
            active[D] = false;
            st.erase(it);
        } 


        // [조회 명령]
        else if (C == 400) {
            // 1. 현재 시점에서 유효한 가장 큰 내부 간격 확보
            while (!pq.empty() && !isValid(pq.top().l, pq.top().r)) pq.pop();
            int max_internal = pq.empty() ? 0 : (pq.top().r - pq.top().l);
            
            // 2. 도로 양 끝(Boundary)과 첫/마지막 가로등 사이의 간격 계산
            // 가로등 반경의 지름(Diameter)을 기준으로 비교하기 위해 2를 곱함
            int edge_left = (s != -1) ? (s - 1) * 2 : 0;
            int edge_right = (e != -1) ? (N - e) * 2 : 0;
            
            // 3. 내부 간격과 양 끝 간격 중 최댓값 출력
            cout << max({max_internal, edge_left, edge_right}) << "\n";
        }
    }
    return 0;
}