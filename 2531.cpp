#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, d, k, c;

int calMaxfish(const vector<int>& fish) {
    vector<int> kind(d + 1, 0);
    int cnt = 0;

    
    for (int i = 0; i < k; i++) {
        if (kind[fish[i]] == 0) cnt++;
        kind[fish[i]]++;
    }

    int max_cnt = cnt + (kind[c] == 0 ? 1 : 0);

    
    for (int i = 1; i < n; i++) {
        int out = fish[(i - 1) % n];           
        int in = fish[(i + k - 1) % n];

        kind[out]--;
        if (kind[out] == 0) cnt--;

        if (kind[in] == 0) cnt++;
        kind[in]++;

        int coup = cnt + (kind[c] == 0 ? 1 : 0);
        max_cnt = max(max_cnt, coup);
    }

    return max_cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> d >> k >> c;
    vector<int> fish(n);

    for (int i = 0; i < n; i++) {
        cin >> fish[i];
    }

    cout << calMaxfish(fish);
    return 0;
}
