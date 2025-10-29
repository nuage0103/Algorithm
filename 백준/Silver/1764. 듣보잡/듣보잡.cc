#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<string> n_name(n);
	
	for (int i = 0; i < n; i++) {
		cin >> n_name[i];
	}
	sort(n_name.begin(), n_name.end());

	vector<string> res;
	string m_name;
	for (int i = 0; i < m; i++) {
		cin >> m_name;
		if (binary_search(n_name.begin(), n_name.end(), m_name)) res.push_back(m_name);
	}
	sort(res.begin(), res.end());

	cout << res.size() << '\n';
	for (auto x : res) cout << x << '\n';

	return 0;
}