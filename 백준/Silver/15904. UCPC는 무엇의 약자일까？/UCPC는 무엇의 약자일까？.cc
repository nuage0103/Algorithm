#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string s;
	getline(cin, s);

	string target = "UCPC";
	int t_i = 0;
	string res = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == target[t_i]) {
			res += s[i];
			t_i++;
		}
	}

	if(res == "UCPC") cout << "I love UCPC\n";
	else cout << "I hate UCPC\n";
	
	return 0;
}