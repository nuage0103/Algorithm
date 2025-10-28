#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	/*
	TXY: T 모양 PKHT, XY 숫자 01~13
	*/
	string s;
	cin >> s;

	int shape_num[4][14] = { 0 }; // [t][xy] = 0/1, 2 이상이면 중복
	shape_num[0][0] = 13;
	shape_num[1][0] = 13;
	shape_num[2][0] = 13;
	shape_num[3][0] = 13; // [t][0] = 모양 별로 없는 숫자 개수
	
	// p0, k1, h2, t3
	for (int i = 0; i <= s.length() - 3; i += 3) {
		int t = 0;
		if (s[i] == 'K') t = 1;
		else if (s[i] == 'H') t = 2;
		else if (s[i] == 'T') t = 3;

		int x = s[i + 1] - '0';
		int y = s[i + 2] - '0';
		int n = x * 10 + y;

		if (!shape_num[t][n]) {
			shape_num[t][n] = 1;
			shape_num[t][0]--;
		}
		else {
			cout << "GRESKA\n";
			return 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		cout << shape_num[i][0] << ' ';
	}
	cout << '\n';

	return 0;
}