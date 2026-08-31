// v = 1-(1-v)*(1-A_i)
// v_기본값 = 0


#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void calculate_ignore_defense(int N, vector<int>& potions) {
    double V = 0.0;
    
    for (int A : potions) {
        V = 1 - (1 - V) * (1 - A / 100.0);
        cout << fixed << setprecision(6) << V * 100 << "\n";
    }
}

int main() {
    int N;
    cin >> N;
    
    vector<int> potions(N);
    for (int i = 0; i < N; i++) {
        cin >> potions[i];
    }
    
    calculate_ignore_defense(N, potions);
    
    return 0;
}
