// 2615�� ����: https://www.acmicpc.net/problem/2615
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;
const int SIZE = 20, EMPTY = 0;

// ���⿡ ���� ��ǥ ������
// �� ���� �� ���� �������� �˻��ϱ� ������ ������+�Ʒ������� ���ϴ� ���⸸ ����
const vector<int> dx = { -1, 0, 1, 1 };
const vector<int> dy = { 1, 1, 1, 0 };

/**
 * ������ ���� ������ ��ȿ���� Ȯ���Ѵ�.
*/
bool isValid(matrix& board, int x, int y, int color) {
	return (x > 0 && x < SIZE&& y > 0 && y < SIZE&& board[x][y] == color);
}

/**
 * �ش� ��ǥ(x, y)���� ���������� 5���� ���̴��� Ȯ���Ѵ�.
*/
bool checkWin(matrix& board, int x, int y) {
	int color = board[x][y]; // ���� ��

	// 4 ���⿡ ���� �˻�
	for (int idx = 0; idx < 4; idx++) {
		int cnt = 1;    // cnt: ���� ���⿡ ���� ���� �� ���� ��
		int prev_x = x - dx[idx], prev_y = y - dy[idx]; // �� x ��ǥ, y ��ǥ
		int next_x = x + dx[idx], next_y = y + dy[idx]; // �� x ��ǥ, y ��ǥ

		// ���� ���⿡�� �� �������� ���� �� ���� �־��ٸ� �н� (-> ���� �� �̻� ���̴� ��츦 �����ϱ� ����)
		if (isValid(board, prev_x, prev_y, color)) {
			continue;
		}

		// ���������� ���� 5���� ���� ������ Ȯ��
		while (isValid(board, next_x, next_y, color) && cnt < 6) {
			next_x += dx[idx];
			next_y += dy[idx];
			cnt++;
		}
		// cnt�� 5�� ���� true ���� (-> �ټ� �˺��� ���ų� �ټ� �˺��� ���� ���̴� ��츦 ����)
		if (cnt == 5) {
			return true;
		}
	}
	return false;
}

int main() {
	// �Է�
	matrix board(SIZE, vector<int>(SIZE, 0)); // �ٵ���
	for (int i = 1; i < SIZE; i++)
		for (int j = 1; j < SIZE; j++)
			cin >> board[i][j]; // �ٵ��� �Է�

	// ���� �� ���
	for (int y = 1; y < SIZE; y++) {
		for (int x = 1; x < SIZE; x++) {
			// �� ĭ�̸� �н�
			if (board[x][y] == EMPTY) {
				continue;
			}
			// �ش� ��ǥ(x, y)���� ���������� 5���� �����ٸ� ���� ���
			if (checkWin(board, x, y)) {
				cout << board[x][y] << '\n'
					<< x << ' ' << y;
				return 0;
			}
		}
	}
	cout << 0;

	return 0;
}