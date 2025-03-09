#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void getNum(int n, int s, vector<int>& dongs) {
    for (int i = 0; i < n; i++) {
        dongs[i] = abs(dongs[i] - s);
    }
}

int getGcd(int n, vector<int>& dongs) {
    int result = dongs[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, dongs[i]);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s;
    cin >> n >> s;

    vector<int> dongs(n);
    for (int i = 0; i < n; i++) {
        cin >> dongs[i];
    }

    getNum(n, s, dongs);
    int gcd = getGcd(n, dongs);

    cout << gcd << '\n';

    return 0;
}
