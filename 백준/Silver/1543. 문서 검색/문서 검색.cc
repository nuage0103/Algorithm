#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s, target;
	getline(cin, s);
	getline(cin, target);

	vector<int> pos; // target 시작 위치
	int p = -1;
	while (1) {
		p = s.find(target, p + 1);
		if (p == string::npos) break;
		pos.push_back(p);
	}

	int s_len = s.length();
	int t_len = target.length();
	int p_size = pos.size();
	int max_cnt = 0;
	for (int start = 0; start < p_size; start++) {
		int cnt = 1;
		int cur = start;
		for (int next = cur + 1; next < p_size; next++) {
			if (pos[cur] + t_len > pos[next]) continue;
			else {
				cnt++;
				cur = next;
			}
		}
		
		max_cnt = max(max_cnt, cnt);
	}
	
	cout << max_cnt << '\n';

	return 0;
}