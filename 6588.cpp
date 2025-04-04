#include <iostream>
#include <vector>

using namespace std;

vector<bool> getPrimes(int n) { //�Ҽ� ���� ��ȯ �Լ�: �����佺�׳׽��� ü �̿�
	vector<bool> is_prime(n + 1, true); 
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i * i < = n; i++) { // 0�� 1�� �Ҽ��� �ƴϰ� 2���� �Ҽ����� �Ǻ���
		if (!is_prime[i]) {
			continue; // �Ҽ��� continue
		}
		for (int j = i * i; j <= n; j += i) {
			is_prime[j] = false; // i�� ������� �Ҽ��� �ƴϴϱ� false
		}
	}
	return is_prime; // �Ҽ� ���� return
}

int goldbach(int n, vector<bool>& is_prime) {
	for (int a = 3; a <= n / 2; a += 2) { // Ȧ���� Ž���� �Ѵ� (2���͸� ������ �� ¦����)
		if (is_prime[a] && is_prime[n - a]) { // �� �� �Ҽ���� a�� ��ȯ��
			return a;
		}
	}

	return 0;
}

int main() {
	vector<int> num; // �Է� ���� ���� ����
	int input;
	while (1) {
		cin >> input;
		if (input == 0) { // 0 �Է½� �׸� �Է� ����
			break;
		}
		num.push_back(input); // ���Ϳ� �� �ֱ�
	}

	// ����
	int max_num = *max_element(num.begin(), num.end()); // ������ �ִ�
	vector<bool> is_prime = getPrimes(max_num); // �Ҽ� ���θ� ���� by �����佺�׳׽��� ü

	for (int i = 0; i < num.size(); i++) {
		int a = goldbach(num[i], is_prime); // �Ҽ� Ž��

		// ���
		if (a != 0) { // n = a + b�� �����ϴ� a, b�� �����ϸ�
			cout << num[i] << " = " << a << " + " << num[i] - a << "\n";
		}
		else {      // �������� ������
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}
	return 0;
	


}