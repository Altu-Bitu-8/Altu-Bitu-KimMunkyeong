#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	string loc;

	cin >> loc;

	vector<int> bur, per;
	for (int i = 0; i < n; i++) {
		if (loc[i] == 'H') {
			bur.push_back(i);
		}

		if (loc[i] == 'P') {
			per.push_back(i);
		}
	}

	// 사람: 2 4 6 9 10 12
	// 버거: 1 3 5 7 8 11

	int cnt = 0;
	int burOr = 0;
	int perOr = 0;

	while (perOr < per.size() && burOr < bur.size()) {
		if (abs(per[perOr] - bur[burOr]) <= k) {
			cnt++;
			perOr++;
			burOr++;
		}
		else if(per[perOr] > bur[burOr]) {
			burOr++;
		}
		else {
			perOr++;
		}
	}

	cout << cnt;

}