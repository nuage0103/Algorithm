#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
len
0 ~ p1 / p1+1 ~ p2 / p2+1 ~ len-1
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string inp;
	cin >> inp;

	vector<string> res;
	int len = inp.length();
	for (int p1 = 0; p1 < len - 2; p1++) {
		for (int p2 = p1 + 1; p2 < len - 1; p2++) {
			string s1 = inp.substr(0, p1 + 1);
			string s2 = inp.substr(p1 + 1, p2 - p1);
			string s3 = inp.substr(p2 + 1);

			reverse(s1.begin(), s1.end());
			reverse(s2.begin(), s2.end());
			reverse(s3.begin(), s3.end());

			res.push_back(s1 + s2 + s3);
		}
	}

	sort(res.begin(), res.end());
	cout << res[0] << '\n';

	return 0;
}