#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;

// 최단거리의 모든 유한한 값은 이 값보다 작아야 합니다.
constexpr ll INF = numeric_limits<ll>::max() / 4;
constexpr int dr[4] = {-1, 1, 0, 0};
constexpr int dc[4] = {0, 0, -1, 1};

// 2.1 누적합
vector<ll> prefix1D(const vector<int>& a) {
    vector<ll> p(a.size() + 1, 0);
    for (int i = 0; i < int(a.size()); ++i)
        p[i + 1] = p[i] + a[i]; // p[0]은 빈 구간의 합
    return p;
}
ll rangeSum(const vector<ll>& p, int l, int r) {
    return p[r] - p[l]; // 0 <= l <= r <= 원본 크기
}
vector<vector<ll>> prefix2D(const vector<vector<int>>& a) {
    int n = int(a.size()), m = n ? int(a[0].size()) : 0;
    vector<vector<ll>> p(n + 1, vector<ll>(m + 1));
    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; ++c)
            p[r+1][c+1] = a[r][c] + p[r][c+1]
                         + p[r+1][c] - p[r][c];
    return p;
}
ll rectSum(const vector<vector<ll>>& p, int r1, int c1, int r2, int c2) {
    // 행 [r1,r2), 열 [c1,c2)
    return p[r2][c2] - p[r1][c2] - p[r2][c1] + p[r1][c1];
}

// 2.2 구현 / 시뮬레이션
pair<int,int> simulate(const vector<string>& board, int r, int c,
                       const vector<int>& commands) {
    // 전제: 비어 있지 않은 직사각형 격자, 시작점은 이동 가능한 칸
    int n = int(board.size()), m = int(board[0].size());
    for (int dir : commands) {
        if (dir < 0 || dir >= 4) continue; // 유효하지 않은 명령 무시
        int nr = r + dr[dir], nc = c + dc[dir];
        // 배열 접근보다 경계 검사가 먼저입니다.
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (board[nr][nc] == '#') continue;
        r = nr; c = nc; // 검사를 모두 통과한 뒤 상태 반영
    }
    return {r, c};
}

// 2.3 그리디
int maxNonOverlapping(vector<pair<ll,ll>> intervals) {
    // 각 구간 [시작,끝), 시작 < 끝. 가중치 없이 개수를 최대화합니다.
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second < b.second;
        return a.first < b.first;
    });
    ll lastEnd = numeric_limits<ll>::lowest();
    int answer = 0;
    for (auto [start, finish] : intervals) {
        if (start >= lastEnd) { // 끝과 다음 시작이 같아도 선택 가능
            ++answer;
            lastEnd = finish;
        }
    }
    return answer;
}

// 3.1 그래프 탐색: 표현과 연결 요소
vector<vector<int>> makeGraph(int n, const vector<pair<int,int>>& edges,
                              bool directed = false) {
    vector<vector<int>> g(n);
    for (auto [u, v] : edges) { // 정점 번호는 [0,n)
        g[u].push_back(v);
        if (!directed) g[v].push_back(u);
    }
    return g;
}
vector<int> componentIds(const vector<vector<int>>& g) {
    // 무방향 그래프 전용 연결 요소 분류
    int n = int(g.size()), id = 0;
    vector<int> comp(n, -1);
    for (int s = 0; s < n; ++s) {
        if (comp[s] != -1) continue;
        stack<int> st;
        st.push(s); comp[s] = id;
        while (!st.empty()) {
            int u = st.top(); st.pop();
            for (int v : g[u]) {
                if (comp[v] != -1) continue;
                comp[v] = id; // 넣을 때 방문 표시하여 중복 삽입 방지
                st.push(v);
            }
        }
        ++id;
    }
    return comp;
}

// 3.2 BFS
vector<int> bfs(const vector<vector<int>>& g, int start) {
    vector<int> dist(g.size(), -1); // -1: 도달하지 못함
    queue<int> q;
    dist[start] = 0; q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u] + 1; // 큐에 넣는 시점에 방문 확정
            q.push(v);
        }
    }
    return dist;
}

// 3.3 DFS
pair<vector<int>, vector<int>> dfsOrders(const vector<vector<int>>& g, int start) {
    vector<char> seen(g.size(), false);
    vector<int> enter, leave;
    vector<pair<int,int>> st; // {정점, 다음에 확인할 인접 리스트 인덱스}
    seen[start] = true; enter.push_back(start);
    st.push_back({start, 0});
    while (!st.empty()) {
        int u = st.back().first;
        int next = st.back().second;
        if (next == int(g[u].size())) {
            leave.push_back(u); // 재귀 함수가 반환하는 시점
            st.pop_back();
            continue;
        }
        ++st.back().second;
        int v = g[u][next];
        if (seen[v]) continue;
        seen[v] = true; enter.push_back(v);
        st.push_back({v, 0});
    }
    return {enter, leave};
}

// 3.4 완전탐색
ll tspBrute(const vector<vector<ll>>& cost) {
    // 완전 유향 그래프의 비용 행렬. 모든 비용·합이 표현 가능해야 함
    int n = int(cost.size());
    if (n <= 1) return 0;
    vector<int> order(n - 1);
    iota(order.begin(), order.end(), 1); // 정렬된 초기 순열
    ll answer = INF;
    do {
        ll sum = 0;
        int prev = 0;
        for (int v : order) {
            sum += cost[prev][v];
            prev = v;
        }
        sum += cost[prev][0]; // 시작점으로 복귀
        answer = min(answer, sum);
    } while (next_permutation(order.begin(), order.end()));
    return answer;
}

// 3.5 백트래킹
vector<vector<int>> combinations(int n, int k) {
    vector<vector<int>> result;
    if (k < 0 || k > n) return result;
    vector<int> path;
    function<void(int)> dfs = [&](int start) {
        if (int(path.size()) == k) {
            result.push_back(path); // 현재 조합 복사
            return;
        }
        int need = k - int(path.size());
        // x를 선택한 뒤 필요한 숫자들을 남겨둘 수 있는 범위까지만
        for (int x = start; x <= n - need + 1; ++x) {
            path.push_back(x);
            dfs(x + 1); // 증가 순서로만 선택하여 순서 중복 제거
            path.pop_back(); // 다음 분기를 위해 상태 복구
        }
    };
    dfs(1);
    return result;
}

// 4.1 비트연산 / 비트마스킹
uint64_t addBit(uint64_t mask, int i) { return mask | (1ULL << i); }
uint64_t removeBit(uint64_t mask, int i) { return mask & ~(1ULL << i); }
bool hasBit(uint64_t mask, int i) { return (mask & (1ULL << i)) != 0; }
uint64_t toggleBit(uint64_t mask, int i) { return mask ^ (1ULL << i); }
int bitCount(uint64_t mask) { // 표준 C++17만 사용하는 구현
    int count = 0;
    while (mask) {
        mask &= mask - 1; // 가장 낮은 1비트 제거
        ++count;
    }
    return count;
}
vector<ll> subsetSums(const vector<int>& a) {
    // 모든 부분집합 결과를 저장하므로 작은 N 전용
    int n = int(a.size());
    assert(n <= 20); // 이 예제의 실용적 메모리 제한
    vector<ll> sums(1ULL << n, 0);
    for (uint64_t mask = 0; mask < (1ULL << n); ++mask)
        for (int i = 0; i < n; ++i)
            if (hasBit(mask, i)) sums[mask] += a[i];
    return sums;
}
vector<uint64_t> submasks(uint64_t mask) {
    vector<uint64_t> result;
    uint64_t sub = mask;
    while (true) {
        result.push_back(sub); // 공집합 0도 포함
        if (sub == 0) break;
        sub = (sub - 1) & mask;
    }
    return result;
}

// 4.2 이분탐색 / 매개변수 탐색
template<class Predicate>
ll firstTrue(ll lo, ll hi, Predicate ok) {
    // 전제: lo <= hi, hi-lo가 ll 범위 이내, 판정은 false ... true
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (ok(mid)) hi = mid; // mid도 정답 후보
        else lo = mid + 1;     // mid까지는 정답 아님
    }
    return lo;
}
ll minimumCapacity(const vector<int>& weights, int days) {
    // 순서를 유지하며 days일 이내에 운반. 무게는 양수, days >= 1
    if (weights.empty()) return 0;
    ll lo = *max_element(weights.begin(), weights.end());
    ll total = accumulate(weights.begin(), weights.end(), 0LL);
    auto feasible = [&](ll cap) {
        int used = 1;
        ll load = 0;
        for (int w : weights) {
            if (load + w > cap) { ++used; load = 0; }
            load += w;
        }
        return used <= days;
    };
    // total은 항상 가능. total+1은 배타적 상한이며 오버플로 없어야 함
    return firstTrue(lo, total + 1, feasible);
}

// 5.1 라인스위핑
pair<ll,int> sweepIntervals(const vector<pair<ll,ll>>& intervals) {
    // [l,r), l <= r. 빈 구간은 제외. 길이의 합은 ll 범위 이내
    vector<pair<ll,int>> events;
    for (auto [l, r] : intervals) {
        if (l == r) continue;
        events.push_back({l, +1});
        events.push_back({r, -1});
    }
    if (events.empty()) return {0, 0};
    sort(events.begin(), events.end());
    ll length = 0, prev = events[0].first;
    int active = 0, peak = 0;
    size_t i = 0;
    while (i < events.size()) {
        ll x = events[i].first;
        if (active > 0) length += x - prev; // [prev,x)는 이전 상태
        int delta = 0;
        while (i < events.size() && events[i].first == x)
            delta += events[i++].second;
        active += delta; // x 이후의 활성 구간 수
        peak = max(peak, active);
        prev = x;
    }
    return {length, peak};
}

// 5.2 투포인터 / 슬라이딩 윈도우
int minLengthAtLeast(const vector<int>& a, ll target) {
    // 전제: 모든 a[i] > 0, target > 0
    int n = int(a.size()), left = 0, answer = n + 1;
    ll sum = 0;
    for (int right = 0; right < n; ++right) {
        sum += a[right]; // 오른쪽 끝 포함
        while (sum >= target) {
            answer = min(answer, right - left + 1);
            sum -= a[left++]; // 조건을 만족하는 동안 왼쪽 축소
        }
    }
    return answer == n + 1 ? 0 : answer; // 불가능하면 0
}
bool hasPairSum(vector<int> a, ll target) {
    sort(a.begin(), a.end());
    int l = 0, r = int(a.size()) - 1;
    while (l < r) {
        ll sum = ll(a[l]) + a[r];
        if (sum == target) return true;
        if (sum < target) ++l; // 더 큰 합이 필요
        else --r;
    }
    return false;
}

// 5.3 LIS: 최장 증가 부분 수열
int lisLength(const vector<int>& a) {
    vector<int> tails;
    for (int x : a) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x; // 길이는 유지하면서 끝 값을 작게 만듦
    }
    return int(tails.size());
}
vector<int> lisSequence(const vector<int>& a) {
    int n = int(a.size());
    vector<int> tails, tailIndex, parent(n, -1);
    for (int i = 0; i < n; ++i) {
        int p = int(lower_bound(tails.begin(), tails.end(), a[i]) - tails.begin());
        if (p > 0) parent[i] = tailIndex[p - 1]; // 이전 길이의 마지막 위치
        if (p == int(tails.size())) {
            tails.push_back(a[i]); tailIndex.push_back(i);
        } else {
            tails[p] = a[i]; tailIndex[p] = i;
        }
    }
    vector<int> result;
    if (tails.empty()) return result;
    for (int i = tailIndex.back(); i != -1; i = parent[i])
        result.push_back(a[i]);
    reverse(result.begin(), result.end());
    return result;
}

// 6.1 DP: 상태·전이·초기화·순서
ll knapsack01(const vector<int>& weight, const vector<ll>& value, int capacity) {
    // 각 물건은 최대 한 번. 양의 무게, capacity >= 0, 같은 배열 길이
    vector<ll> dp(capacity + 1, 0); // 아무것도 고르지 않는 선택 허용
    for (int i = 0; i < int(weight.size()); ++i) {
        // 역순: dp[c-weight[i]]가 이번 물건을 아직 사용하지 않은 상태
        for (int c = capacity; c >= weight[i]; --c)
            dp[c] = max(dp[c], dp[c - weight[i]] + value[i]);
    }
    return dp[capacity];
}
int minCoins(const vector<int>& coins, int target) {
    // 양의 동전, 각 동전 무한 사용. target은 메모리에 들어오는 작은 값
    const int BAD = target + 1;
    vector<int> dp(target + 1, BAD);
    dp[0] = 0; // 합 0을 만드는 데 필요한 동전은 0개
    for (int sum = 1; sum <= target; ++sum)
        for (int coin : coins)
            if (coin <= sum && dp[sum - coin] != BAD)
                dp[sum] = min(dp[sum], dp[sum - coin] + 1);
    return dp[target] == BAD ? -1 : dp[target];
}

// 7.1 Dijkstra
using WeightedGraph = vector<vector<pair<int,ll>>>; // {다음 정점, 가중치}
vector<ll> dijkstra(const WeightedGraph& g, int start) {
    vector<ll> dist(g.size(), INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    dist[start] = 0; pq.push({0, start});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue; // 이미 개선된 과거 후보 건너뛰기
        for (auto [v, w] : g[u]) {
            // 전제: w >= 0, d+w가 범위 내이며 유한 거리는 INF 미만
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist; // INF는 도달 불가능
}

// 7.2 Floyd-Warshall
vector<vector<ll>> floydWarshall(int n, const vector<tuple<int,int,ll>>& edges) {
    vector<vector<ll>> d(n, vector<ll>(n, INF));
    for (int i = 0; i < n; ++i) d[i][i] = 0;
    for (auto [u, v, w] : edges)
        d[u][v] = min(d[u][v], w); // 방향 간선, 중복이면 최소 비용
    for (int k = 0; k < n; ++k) // 중간 정점 루프가 반드시 가장 바깥
        for (int i = 0; i < n; ++i) {
            if (d[i][k] == INF) continue;
            for (int j = 0; j < n; ++j) {
                if (d[k][j] == INF) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    return d;
}
vector<vector<char>> negativeCyclePairs(const vector<vector<ll>>& d) {
    int n = int(d.size());
    vector<vector<char>> bad(n, vector<char>(n, false));
    for (int k = 0; k < n; ++k) if (d[k][k] < 0)
        for (int i = 0; i < n; ++i) if (d[i][k] != INF)
            for (int j = 0; j < n; ++j) if (d[k][j] != INF)
                bad[i][j] = true; // 음수 사이클을 거쳐 갈 수 있는 쌍
    return bad;
}

// 7.3 Bellman-Ford
struct Edge { int u, v; ll w; };
struct BellmanResult {
    vector<ll> dist;
    vector<char> negative; // true이면 최단거리가 음의 무한대
};
BellmanResult bellmanFord(int n, const vector<Edge>& edges, int start) {
    vector<ll> d(n, INF);
    d[start] = 0;
    for (int round = 0; round < n - 1; ++round) {
        bool changed = false;
        for (auto [u, v, w] : edges) {
            if (d[u] == INF) continue; // 시작점에서 도달한 간선만 완화
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                changed = true;
            }
        }
        if (!changed) break;
    }
    vector<vector<int>> g(n);
    vector<char> negative(n, false);
    queue<int> q;
    for (auto [u, v, w] : edges) {
        g[u].push_back(v);
        // 여기서는 d를 변경하지 않고 개선 가능한 정점만 표시
        if (d[u] != INF && d[u] + w < d[v] && !negative[v]) {
            negative[v] = true; q.push(v);
        }
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (!negative[v]) {
            negative[v] = true; q.push(v);
        }
    }
    return {d, negative};
}

// 8.1 Fenwick Tree / Binary Indexed Tree
struct Fenwick {
    int n;
    vector<ll> tree;
    explicit Fenwick(int n) : n(n), tree(n + 1, 0) {}
    void add(int index, ll delta) {
        // 외부는 0-based, 내부는 1-based. 0 <= index < n
        assert(0 <= index && index < n);
        for (int i = index + 1; i <= n; i += i & -i)
            tree[i] += delta;
    }
    ll prefix(int r) const {
        // 원본 배열 [0,r)의 합. 0 <= r <= n
        assert(0 <= r && r <= n);
        ll sum = 0;
        for (int i = r; i > 0; i -= i & -i)
            sum += tree[i];
        return sum;
    }
    ll query(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return prefix(r) - prefix(l); // [l,r)
    }
};

int main() {
    assert(rangeSum(prefix1D({3,-2,5,1}),1,4)==4);
    assert(rangeSum(prefix1D({}),0,0)==0);
    auto p=prefix2D({{1,2},{3,4}});
    assert(rectSum(p,0,0,2,2)==10 && rectSum(p,1,0,2,2)==7);
    assert((simulate({"..", ".#"},0,0,{3,1,2,1})==pair<int,int>{1,0}));
    assert(maxNonOverlapping({{0,3},{1,2},{2,4}})==2);
    assert(maxNonOverlapping({})==0);
    auto g=makeGraph(4,{{0,1},{1,2}});
    auto comp=componentIds(g);
    assert(comp[0]==comp[2] && comp[0]!=comp[3]);
    assert((bfs(g,0)==vector<int>{0,1,2,-1}));
    auto [enter,leave]=dfsOrders(g,0);
    assert((enter==vector<int>{0,1,2}) && (leave==vector<int>{2,1,0}));
    assert(tspBrute({{0,1,10},{10,0,2},{3,10,0}})==6);
    assert(tspBrute({})==0);
    assert(combinations(4,2).size()==6);
    assert(combinations(4,0).size()==1 && combinations(2,3).empty());
    assert(addBit(1,2)==5 && removeBit(5,2)==1 && toggleBit(5,2)==1);
    assert(hasBit(1ULL<<63,63) && bitCount(5)==2);
    assert((subsetSums({2,3})==vector<ll>{0,2,3,5}));
    assert((submasks(5)==vector<uint64_t>{5,4,1,0}));
    assert(submasks(0).size()==1);
    assert(firstTrue(0,10,[](ll x){return x>=3;})==3);
    assert(firstTrue(0,10,[](ll){return false;})==10);
    assert(firstTrue(0,10,[](ll){return true;})==0);
    assert(minimumCapacity({1,2,3,4,5},2)==9);
    assert((sweepIntervals({{1,3},{3,5}})==pair<ll,int>{4,1}));
    assert((sweepIntervals({{1,4},{2,5},{2,2}})==pair<ll,int>{4,2}));
    assert((sweepIntervals({})==pair<ll,int>{0,0}));
    assert(minLengthAtLeast({2,3,1,2,4,3},7)==2);
    assert(minLengthAtLeast({1,2},9)==0);
    assert(hasPairSum({-3,2,5},2) && !hasPairSum({1},2));
    assert(lisLength({10,20,10,30,20,50})==4);
    assert(lisLength({2,2,2})==1 && lisLength({})==0);
    assert((lisSequence({10,20,10,30,20,50})==vector<int>{10,20,30,50}));
    assert(lisSequence({}).empty());
    assert(knapsack01({2},{3},4)==3);
    assert(knapsack01({2,3,4},{3,4,5},5)==7);
    assert(minCoins({1,3,4},6)==2 && minCoins({2},3)==-1);
    assert(minCoins({2},0)==0);
    WeightedGraph wg(4);
    wg[0]={{1,5},{2,1}}; wg[2]={{1,1}};
    assert((dijkstra(wg,0)==vector<ll>{0,2,1,INF}));
    auto fw=floydWarshall(4,{{0,1,5},{0,1,2},{1,2,-1}});
    assert(fw[0][2]==1 && fw[2][0]==INF && fw[3][3]==0);
    auto neg=negativeCyclePairs(floydWarshall(4,{{0,1,1},{1,2,-2},{2,1,1}}));
    assert(neg[0][2] && !neg[2][0] && !neg[3][3]);
    auto bf=bellmanFord(4,{{0,1,5},{0,2,1},{2,1,-2}},0);
    assert(bf.dist[1]==-1 && bf.dist[3]==INF && !bf.negative[1]);
    bf=bellmanFord(5,{{0,1,0},{1,2,-2},{2,1,1},{2,3,0},{4,4,-1}},0);
    assert(bf.negative[1] && bf.negative[2] && bf.negative[3]);
    assert(!bf.negative[0] && !bf.negative[4]);
    Fenwick ft(3); ft.add(0,2); ft.add(1,3); ft.add(2,5);
    assert(ft.query(1,3)==8 && ft.query(0,0)==0);
    ft.add(1,4); assert(ft.query(1,3)==12);
    cout << "All template checks passed.\n";
}
