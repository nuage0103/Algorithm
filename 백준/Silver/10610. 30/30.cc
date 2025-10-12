#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> digit;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string n;
	cin >> n;
	/*
	30의 배수: 3의 배수, 10의 배수
	3의 배수: 각 자리수 합이 3의 배수
	10의 배수: 일의자리 0
	*/
	if (n.find('0') == string::npos) {
		cout << "-1\n";
		return 0;
	}

	int len = n.length();
	int sum = 0;
	for (int i = 0; i < len; i++) {
		digit.push_back(n[i] - '0');
		sum += digit[i];
	}
	if (sum % 3) {
		cout << "-1\n";
		return 0;
	}

	sort(digit.begin(), digit.end(), greater<>()); // 내림차순 정렬
	for (int i = 0; i < len; i++) {
		cout << digit[i];
	}
	cout << '\n';
	
	return 0;
}