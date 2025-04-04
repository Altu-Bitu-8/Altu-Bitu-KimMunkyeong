#include <iostream>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string n;

	while(1){
		stack<char>s;
		bool isBalanced = true;

		getline(cin, n);
		if (n == ".") break;

		for (char& ch : n) {
			if (ch == '(' || ch == '[') {
				s.push(ch);
			}
			else if (ch == ')') {
				if (!s.empty() && s.top() == '(') {
					s.pop();
				}
				else {
					isBalanced = false;
					break;
				}
			}
			else if (ch == ']') {
				if (!s.empty() && s.top() == '[') {
					s.pop();
				}
				else {
					isBalanced = false;
					break;
				}
			}
		}
		
		if (isBalanced && s.empty()) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}

	}
}