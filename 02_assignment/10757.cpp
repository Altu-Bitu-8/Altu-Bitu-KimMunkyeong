#include <iostream>
#include <string>

using namespace std;

string addBigNumbers(string a, string b) {
	string result = "";
	int carry = 0;

	int lenA = a.length(), int lenB = b.();
	int i = lenA - 1, j = lenB - 1;

	while (i >= 0 || j >= 0 || carry) {
		int numA = (i >= 0) ? a[i] - '0' : 0;
		int numB = (j >= 0) ? b[i] - '0' : 0;

		int sum = numA + numB + carry;
		carry = sum / 10;
		result += (sum % 10) + '0';

		i--; j--;
	}
	
	reverse(result.begin(), result.end());
	return result;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string a, b;
	cin >> a >> b;

	cout << addBigNumbers(a, b) << "\n";

	return 0;
}