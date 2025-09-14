#include <iostream>
#include <vector>
using namespace std;

vector<int> pre; // 전위순회 입력,모두 다른 값
int n;

void post(int start, int end) {
	if (start >= end) return;

	int root = pre[start];
	int i = start + 1;
	for (; i < end; i++) {
		if (root < pre[i]) break;
	}
	// post: left - right - root
	post(start + 1, i); // left
	post(i, end); // right
	cout << root << '\n'; // root
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int x;
	while (cin >> x) {
		pre.push_back(x);
	}

	post(0, pre.size());
	
	return 0;
}
