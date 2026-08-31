#include <bits/stdc++.h>
using namespace std;
#define MAX 105

struct Box {
    int id, r, c, w, h;
};

int N, M;
int a[MAX][MAX];
int height[MAX]; // 각 열의 현재 쌓인 높이
map<int, Box> boxes;
set<int> box_ids;

// [Gravity] 창고 전체에 대해 떨어질 수 있는 모든 택배를 바닥으로 내림
void apply_gravity() {
    while (true) {
        bool moved = false;
        // 바닥(N행)에 가까운 택배부터 검사해야 연쇄 이동이 정확함
        vector<int> sorted_ids(box_ids.begin(), box_ids.end());
        sort(sorted_ids.begin(), sorted_ids.end(), [](int id1, int id2) {
            return boxes[id1].r + boxes[id1].h > boxes[id2].r + boxes[id2].h;
        });

        for (int id : sorted_ids) {
            Box &b = boxes[id];
            if (b.r + b.h > N) continue; // 이미 바닥

            // 한 칸 아래가 모두 비어있는지 확인
            bool can_drop = true;
            for (int col = b.c; col < b.c + b.w; col++) {
                if (a[b.r + b.h][col] != 0) { can_drop = false; break; }
            }

            if (can_drop) {
                // 현재 위치 지우기
                for (int i = b.r; i < b.r + b.h; i++)
                    for (int j = b.c; j < b.c + b.w; j++) a[i][j] = 0;
                // 좌표 이동
                b.r++;
                // 새 위치 그리기
                for (int i = b.r; i < b.r + b.h; i++)
                    for (int j = b.c; j < b.c + b.w; j++) a[i][j] = b.id;
                moved = true;
            }
        }
        if (!moved) break; // 더 이상 움직임이 없으면 종료
    }
}

// [Exit Check] 왼쪽 혹은 오른쪽으로 장애물 없이 나갈 수 있는지 확인
bool can_exit(int id, bool is_left) {
    Box &b = boxes[id];
    for (int i = b.r; i < b.r + b.h; i++) {
        if (is_left) {
            for (int j = 1; j < b.c; j++) if (a[i][j] != 0) return false;
        } else {
            for (int j = b.c + b.w; j <= N; j++) if (a[i][j] != 0) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    if (!(cin >> N >> M)) return 0;

    // 1. 택배 투입
    for (int i = 0; i < M; i++) {
        int k, h, w, c;
        cin >> k >> h >> w >> c;
        
        // 투입 시점에는 맨 위에서부터 떨어지므로 apply_gravity와 동일한 원리 적용
        int mh = 0;
        for (int col = c; col < c + w; col++) mh = max(mh, height[col]);
        
        int start_r = N - (mh + h) + 1;
        for (int r = start_r; r < start_r + h; r++) {
            for (int col = c; col < c + w; col++) a[r][col] = k;
        }
        boxes[k] = {k, start_r, c, w, h};
        box_ids.insert(k);
        // 해당 열의 높이 업데이트
        for (int col = c; col < c + w; col++) height[col] = mh + h;
    }

    // 2 & 3. 하차 과정 (교대 반복)
    while (!box_ids.empty()) {
        bool removed_in_this_cycle = false;

        // 과정 2: 좌측 하차 시도 (번호 작은 순서)
        int target_l = -1;
        for (int id : box_ids) {
            if (can_exit(id, true)) { target_l = id; break; }
        }
        if (target_l != -1) {
            Box &b = boxes[target_l];
            for (int i = b.r; i < b.r + b.h; i++)
                for (int j = b.c; j < b.c + b.w; j++) a[i][j] = 0;
            cout << target_l << "\n";
            box_ids.erase(target_l);
            boxes.erase(target_l);
            apply_gravity(); // 하차 후 즉시 중력 적용
            removed_in_this_cycle = true;
        }

        if (box_ids.empty()) break;

        // 과정 3: 우측 하차 시도 (번호 작은 순서)
        int target_r = -1;
        for (int id : box_ids) {
            if (can_exit(id, false)) { target_r = id; break; }
        }
        if (target_r != -1) {
            Box &b = boxes[target_r];
            for (int i = b.r; i < b.r + b.h; i++)
                for (int j = b.c; j < b.c + b.w; j++) a[i][j] = 0;
            cout << target_r << "\n";
            box_ids.erase(target_r);
            boxes.erase(target_r);
            apply_gravity(); // 하차 후 즉시 중력 적용
            removed_in_this_cycle = true;
        }

        // 만약 한 바퀴 돌았는데 아무것도 못 뺐다면 더 이상 진행 불가
        if (!removed_in_this_cycle) break;
    }

    return 0;
}