#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cal(int a, int b) {
	return (a + b - 1) / b;
}

int main() {
	int n;

	cin >> n;

	vector<int> planet(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> planet[i];
	}

	int minS = planet[n - 1];

	for (int i = n - 2; i >= 0; i--) {
		minS = cal(minS, planet[i]) * planet[i];
	}
	cout << minS;

	return 0;
}