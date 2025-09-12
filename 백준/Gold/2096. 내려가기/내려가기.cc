#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> dp_min(3);
	vector<int> dp_max(3);
	cin >> dp_min[0] >> dp_min[1] >> dp_min[2];
	for (int i = 0; i < 3; i++) {
		dp_max[i] = dp_min[i];
	}

	for (int i = 1; i < n; i++) {
		int l, m, r;
		cin >> l >> m >> r;

		int tmp0, tmp1, tmp2;
		tmp0 = dp_min[0]; tmp1 = dp_min[1], tmp2 = dp_min[2];
		dp_min[0] = min(tmp0, tmp1) + l;
		dp_min[1] = min(min(tmp0, tmp1), tmp2) + m;
		dp_min[2] = min(tmp1, tmp2) + r;

		tmp0 = dp_max[0]; tmp1 = dp_max[1]; tmp2 = dp_max[2];
		dp_max[0] = max(tmp0, tmp1) + l;
		dp_max[1] = max(max(tmp0, tmp1), tmp2) + m;
		dp_max[2] = max(tmp1, tmp2) + r;
	}

	int min_score = min(min(dp_min[0], dp_min[1]), dp_min[2]);
	int max_score = max(max(dp_max[0], dp_max[1]), dp_max[2]);
	cout << max_score << ' ' << min_score << '\n';

	return 0;
}