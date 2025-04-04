#include <iostream>
#include <vector>

using namespace std;

int main() {
	int e, s, m;
	cin >> e >> s >> m;

	int year = 0;

	for (int i = 1; i < 7981; i++) {
		if (i % 15 == e && i % 28 == s && i % 19 == m) {
			year = i;
			break;
		}
	}

	cout << year;

	return 0;
}