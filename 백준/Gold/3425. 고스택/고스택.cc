#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define CHECK_STACK_SIZE(s, n) if (s < n) { error = true; return; }
#define CHECK_OVERFLOW(x) if (llabs(x) > MAX) { error = true; return; }
#define CHECK_ZERO_DIVISOR(x) if (x == 0) { error = true; return; }
typedef long long ll;

const ll MAX = 1000000000LL;
vector<string> cmd;
bool error;
ll res;

void program(ll v) {
	stack<ll> s;
	s.push(v);

	for (int i = 0; i < cmd.size(); i++) {
		string cur = cmd[i];

		/*
		에러
		1. 연산할 숫자 부족
		2. div, mod 0으로 나누기
		3. 연산결과 절댓값 1e9 초과
		4. 모든 수행 종료 후 스택에 숫자 1개 아닐때
		*/
		if (cur.substr(0, 3) == "NUM") {
			ll x = stoll(cur.substr(4));
			s.push(x);
		}
		else if (cur == "POP") {
			CHECK_STACK_SIZE(s.size(), 1);

			s.pop();
		}
		else if (cur == "INV") {
			CHECK_STACK_SIZE(s.size(), 1);

			ll x = s.top();
			s.pop();
			s.push(x * (-1));
		}
		else if (cur == "DUP") {
			CHECK_STACK_SIZE(s.size(), 1);

			ll x = s.top();
			s.push(x);
		}
		else if (cur == "SWP") {
			CHECK_STACK_SIZE(s.size(),2);

			ll op1 = s.top(); // top
			s.pop();
			ll op2 = s.top();
			s.pop();

			s.push(op1);
			s.push(op2); // top
		}
		else if (cur == "ADD") {
			CHECK_STACK_SIZE(s.size(), 2);

			ll op1 = s.top();
			s.pop();
			ll op2 = s.top();
			s.pop();

			ll x = op1 + op2;
			CHECK_OVERFLOW(x);

			s.push(x);
		}
		else if (cur == "SUB") {
			CHECK_STACK_SIZE(s.size(), 2);

			ll op1 = s.top();
			s.pop();
			ll op2 = s.top();
			s.pop();

			ll x = op2 - op1;
			CHECK_OVERFLOW(x);

			s.push(x);
		}
		else if (cur == "MUL") {
			CHECK_STACK_SIZE(s.size(), 2);

			ll op1 = s.top();
			s.pop();
			ll op2 = s.top();
			s.pop();

			ll x = op1 * op2;
			CHECK_OVERFLOW(x);

			s.push(x);
		}
		else if (cur == "DIV") {
			CHECK_STACK_SIZE(s.size(), 2);

			// op2 div op1
			ll op1 = s.top();
			s.pop();
			CHECK_ZERO_DIVISOR(op1);

			ll op2 = s.top();
			s.pop();

			ll x = llabs(op2) / llabs(op1);
			CHECK_OVERFLOW(x);

			if (op1 * op2 > 0) s.push(x);
			else s.push(x * (-1));
		}
		else if (cur == "MOD") {
			CHECK_STACK_SIZE(s.size(), 2);

			// op2 mod op1
			ll op1 = s.top();
			s.pop();
			CHECK_ZERO_DIVISOR(op1);

			ll op2 = s.top();
			s.pop();

			ll x = llabs(op2)% llabs(op1);
			CHECK_OVERFLOW(x);

			if (op2 > 0) s.push(x);
			else s.push(x * (-1));
		}
	}

	if (s.size() != 1) error = true;
	else res = s.top();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;

	while (1) {
		// 프로그램 영역
		cmd.clear();
		while (1) {
			getline(cin, str);
			if (str == "QUIT") return 0;

			if (str == "END") break;
			cmd.push_back(str);
		}

		// 입력영역
		int n;
		cin >> n;
		while (n--) {
			ll x;
			cin >> x;
			error = false;
			program(x);
			if (error == true) cout << "ERROR\n";
			else cout << res << "\n";
		}
	
		cout << "\n";
	}

	return 0;
}
