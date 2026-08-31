#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;


struct Point { int x, y; }; // 점 구조체

// 두 점 사이 거리 제곱
int dist(const Point& a, const Point& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx*dx + dy*dy;
}

// x값 비교 
bool cmpX(const Point& a, const Point& b) {
    if (a.x != b.x) 
        return a.x < b.x;
    return a.y < b.y;
}
// y값 비교
bool cmpY(const Point& a, const Point& b) {
    if (a.y != b.y) 
        return a.y < b.y;
    return a.x < b.x;
}

// 가장 가까운 점 간 거리 제곱 반환
int solve(vector<Point>& pts, int l, int r, vector<Point>& buf) {
    int n = r - l + 1; // 구간 내 점 개수
    // 점이 3개 이하인 경우 완전 탐색
    if (n <= 3) {
        int d = INT_MAX;
        // 완전 탐색
        for (int i = l; i <= r; ++i)
            for (int j = i + 1; j <= r; ++j)
                d = min(d, dist(pts[i], pts[j]));
        return d;
    }

    int m = (l + r) / 2; // 구간 중간 점의 인덱스
    int midx = pts[m].x; // 중간 점의 x좌표

    // 재귀 호출
    int dL = solve(pts, l, m, buf); // 왼쪽 절반
    int dR = solve(pts, m + 1, r, buf); // 오른쪽 절반
    int d = min(dL, dR); // 둘 중 작은 값

    // 중간 영역 구성 (x 차이 제곱 < d)
    vector<Point> cen;
    for (int t = l; t <= r; ++t) {
        int dx = pts[t].x - midx;
      	// d보다 작으면 중간영역임.
        if (dx*dx < d) {
            cen.push_back(pts[t]);
        }
    }
	
  	// y기준 정렬
    sort(cen.begin(), cen.end(), cmpY);

    // 중간 영역 내 이웃 비교 y기준.
    for (int a = 0; a < cen.size(); ++a) {
        for (int b = a + 1; b < cen.size(); ++b) {
            int dy = cen[b].y - cen[a].y; // y 간격
            if (dy*dy >= d) 
                break;
            // d보다 작은 경우 갱신
            int cur = dist(cen[a], cen[b]); 
            if (cur < d)
                d = cur;
        }
    }
    return d;
}

int main() {
    int N; // 점 개수
    cin >> N;

    // 점 입력
    vector<Point> pts(N);
    for (int i = 0; i < N; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }

    // x를 기준으로 점 벡터를 오름차순 정렬
    sort(pts.begin(), pts.end(), cmpX);   

    vector<Point> buf(N);

    int ans = solve(pts, 0, N - 1, buf);
    cout << ans << "\n";
    return 0;
}
// https://www.acmicpc.net/problem/2261