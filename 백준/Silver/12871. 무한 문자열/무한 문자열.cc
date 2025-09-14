#include <iostream>
using namespace std;

int gcd(int a, int b) {
	while (b) {
		int r = a % b;
		a = b;
		b = r;
	}
	
	return a;
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, t;
	cin >> s >> t;

	// 최소공배수
	int len = lcm(s.length(), t.length());

	// 최소공배수로 길이 맞추기
	string origin = s;
	while (s.length() < len) {
		s += origin;
	}

	origin = t;
	while (t.length() < len) {
		t += origin;
	}

	// 비교
	if (s == t) cout << "1\n";
	else cout << "0\n";
	
	return 0;
}