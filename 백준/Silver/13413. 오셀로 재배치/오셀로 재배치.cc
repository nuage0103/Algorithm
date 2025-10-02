#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n; // str len
		cin >> n;
		string src, dst;
		cin >> src >> dst;

		if (src == dst) {
			cout << "0\n";
			continue;
		}

		int w_cnt = 0;
		int b_cnt = 0;
		// swap : b, w 동일 개수만큼
		// toggle : swap 이후 남은 개수
		for (int i = 0; i < n; i++) {
			if (src[i] == dst[i]) continue;

			if (src[i] == 'W') w_cnt++;
			else b_cnt++;
		}

		// swap = min(w_cnt, b_cnt)
		// toggle = max - min
		// sum = max
		cout << max(w_cnt, b_cnt) << '\n';
	}
	
	return 0;
}