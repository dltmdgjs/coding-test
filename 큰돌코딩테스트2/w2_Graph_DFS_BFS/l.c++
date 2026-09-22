// NBA 농구 - BOJ 2852

// 각 팀이 이기고 있던 시간을 구하기
// 각 팀의 골 기록이 주어짐. (48:00 이내임)

#include <bits/stdc++.h>
using namespace std;

int N;
int team1_cnt, team2_cnt, cur_winner; // 각 팀의 승점, 현재 승자
int team1_mm, team1_ss, team2_mm, team2_ss; // 각 팀의 시간 합산.
vector<pair<int, pair<int, int> > > v; // [팀, {분, 초}]

int main() {
    int team_number; string goal_time;


    cin >> N;
    while (N--) {
        cin >> team_number >> goal_time;
        int mm = stoi(goal_time.substr(0, 2));
        int ss = stoi(goal_time.substr(3, 2));
        v.push_back({team_number, {mm, ss}});
    }

    int prev_team = v[0].first;
    int prev_time_mm = v[0].second.first;
    int prev_time_ss = v[0].second.second;
    if (prev_team == 1) team1_cnt++; else team2_cnt++;
    // cur_winner = v[0].first;
    int sub_mm, sub_ss;

    for (int i=1; i<v.size(); i++) {
        // 두 시간의 차를 구한다.
        sub_mm = v[i].second.first - prev_time_mm; sub_ss = v[i].second.second - prev_time_ss;
        if (sub_ss < 0) {sub_ss = 60 + sub_ss; sub_mm--;}
        // 승점을 비교해 현재 승리자에게 시간을 업데이트 한다.
        if (team1_cnt > team2_cnt) {
            team1_mm += sub_mm;
            team1_ss += sub_ss;
            if (team1_ss >= 60) {team1_ss = team1_ss - 60; team1_mm++;}
        } else if (team1_cnt < team2_cnt) {
            team2_mm += sub_mm;
            team2_ss += sub_ss;
            if (team2_ss >= 60) {team2_ss = team2_ss - 60; team2_mm++;}
        }
        // 승점을 업데이트한다.
        if (v[i].first == 1) {team1_cnt++;} else {team2_cnt++;}
        // prev값을 업데이트 한다.
        prev_team = v[i].first;
        prev_time_mm = v[i].second.first;
        prev_time_ss = v[i].second.second;
    }
    // 마지막 경기 종료 시간과 비교 - 업데이트
    sub_mm = 48 - prev_time_mm; sub_ss = 0 - prev_time_ss;
    if (sub_ss < 0) {sub_ss = 60 + sub_ss; sub_mm--;}
    if (team1_cnt > team2_cnt) {
        team1_mm += sub_mm;
        team1_ss += sub_ss;
        if (team1_ss >= 60) {team1_ss = team1_ss - 60; team1_mm++;}
    } else if (team1_cnt < team2_cnt) {
        team2_mm += sub_mm;
        team2_ss += sub_ss;
        if (team2_ss >= 60) {team2_ss = team2_ss - 60; team2_mm++;}
    }
    if (team1_mm < 10) cout << 0;
    cout <<  team1_mm << ":" ;
    if (team1_ss < 10) cout << 0; 
    cout << team1_ss << "\n";
    if (team2_mm < 10) cout << 0;
    cout << team2_mm << ":" ;
    if (team2_ss < 10) cout << 0; 
    cout << team2_ss << "\n";
    return 0;
}