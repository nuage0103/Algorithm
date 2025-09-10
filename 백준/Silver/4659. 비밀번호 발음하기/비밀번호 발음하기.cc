#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(string str) {
	int v_cnt = 0; // 모음 연속 개수
	int c_cnt = 0; // 자음 연속 개수
	bool v_check = false;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			v_cnt++;
			v_check = true;
			c_cnt = 0;
		}
		else {
			c_cnt++;
			v_cnt = 0;
		}

		if (v_cnt >= 3 || c_cnt >= 3) return false;
		if (i != 0 && ((str[i] != 'e' && str[i] != 'o') && str[i - 1] == str[i])) return false;
	}

	return v_check;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		string str;
		cin >> str;
		if (str == "end") break;

		if (check(str)) cout << '<' << str << "> is acceptable." << '\n';
		else cout << '<' << str << "> is not acceptable." << '\n';
	}

	return 0;
}