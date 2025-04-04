#include <iostream>
#include <vector>

using namespace std;

pair<int, int> position(string thing) {
	return { thing[0] - 'A' + 1, thing[1] - '0' };
}

string positionToString(pair<int, int> pos) {
	return string(1, 'A' + pos.first - 1) + to_string(pos.second);
}

void calPoint(pair<int, int>& kingPos, pair<int, int>& stonePos, vector<pair<int, int>>& chess) {
	int x = chess[0].first;
	int y = chess[0].second;

	pair<int, int> newKing = { kingPos.first + x, kingPos.second + y };

	if (newKing == stonePos) {
		pair<int, int> newStone = { stonePos.first + x, stonePos.second + y };
		
		if (newStone.first < 1 || newStone.first > 8 || newStone.second < 1 || newStone.second > 8) {
			return;
		}
		stonePos = newStone;
	}

	
	if (newKing.first >= 1 && newKing.first <= 8 && newKing.second >= 1 && newKing.second <= 8) {
		kingPos = newKing;
	}
}

int main() {
	vector<pair<int, int>> chess(1, { 0, 0 });
	string king, stone;
	int N;
	string lc;

	cin >> king >> stone >> N;

	pair<int, int>kingPos = position(king);
	pair<int, int>stonePos = position(stone);

	for (int i = 0; i < N; i++) {
		cin >> lc;
		if (lc == "R") {
			chess[0].first += 1;
		}
		else if (lc == "L") {
			chess[0].first -= 1;
		}
		else if (lc == "B") {
			chess[0].second -= 1;
		}
		else if (lc == "T") {
			chess[0].second += 1;
		}
		else if (lc == "RT") {
			chess[0].first += 1;
			chess[0].second += 1;
		}
		else if (lc == "LT") {
			chess[0].first -= 1;
			chess[0].second += 1;
		}
		else if (lc == "RB") {
			chess[0].first += 1;
			chess[0].second -= 1;
		}
		else if (lc == "LB") {
			chess[0].first -= 1;
			chess[0].second -= 1;
		}
	}

	calPoint(kingPos, stonePos, chess);

	cout << positionToString(kingPos) << "\n";
	cout << positionToString(stonePos) << "\n";

	return 0;
}