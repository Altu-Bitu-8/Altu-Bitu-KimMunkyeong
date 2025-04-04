#include <iostream>
#include <vector>

using namespace std;

vector<bool> getPrimes(int n) { //소수 여부 반환 함수: 에라토스테네스의 체 이용
	vector<bool> is_prime(n + 1, true); 
	is_prime[0] = is_prime[1] = false;
	for(int i = 2; i * i < = n; i++) { // 0과 1은 소수가 아니고 2부터 소수인지 판별함
		if (!is_prime[i]) {
			continue; // 소수면 continue
		}
		for (int j = i * i; j <= n; j += i) {
			is_prime[j] = false; // i의 배수들은 소수가 아니니까 false
		}
	}
	return is_prime; // 소수 여부 return
}

int goldbach(int n, vector<bool>& is_prime) {
	for (int a = 3; a <= n / 2; a += 2) { // 홀수만 탐색을 한다 (2부터면 무조건 다 짝수라서)
		if (is_prime[a] && is_prime[n - a]) { // 둘 다 소수라면 a를 반환함
			return a;
		}
	}

	return 0;
}

int main() {
	vector<int> num; // 입력 받을 벡터 선언
	int input;
	while (1) {
		cin >> input;
		if (input == 0) { // 0 입력시 그만 입력 받음
			break;
		}
		num.push_back(input); // 벡터에 값 넣기
	}

	// 연산
	int max_num = *max_element(num.begin(), num.end()); // 벡터의 최댓값
	vector<bool> is_prime = getPrimes(max_num); // 소수 여부를 저장 by 에라토스테네스의 체

	for (int i = 0; i < num.size(); i++) {
		int a = goldbach(num[i], is_prime); // 소수 탐색

		// 출력
		if (a != 0) { // n = a + b를 만족하는 a, b가 존재하면
			cout << num[i] << " = " << a << " + " << num[i] - a << "\n";
		}
		else {      // 존재하지 않으면
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}
	return 0;
	


}