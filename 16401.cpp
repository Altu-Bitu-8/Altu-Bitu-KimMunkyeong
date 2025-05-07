#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool joka(int mid, int m, vector<int>& gaga) {
    int cnt = 0;
    for (int i = 0; i < gaga.size(); i++) {
        cnt += gaga[i] / mid;
    }
    return cnt >= m;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> gaga(n);
    for (int i = 0; i < n; i++) {
        cin >> gaga[i];
    }

    int left = 1;
    int right = *max_element(gaga.begin(), gaga.end());
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (joka(mid, m, gaga)) {
            result = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << result;
}