#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;
pair<long long, int> fibo[100007];
list<char> x;
int main() {
	long long a = 1, b = 1;
	long long h;
	long long tmp;
	int i = 0;
	int t;
	int e = 0;
	int st, ed;
	int mid;
	int m;
	char p;
	fibo[e++] = make_pair(b, 2);
	for (i = 0; i < 100003; i++) {
		tmp = b;
		b = (a + b) % 10000000000;
		a = tmp;
		fibo[e++] = make_pair(b, 3 + i);
	}
	sort(fibo, fibo + e);
	scanf("%d%c", &t, &p);
	while (t--) {
		while (1) {
			if (scanf("%c", &p) == -1) break;
			if (p == '\n') break;
			x.push_back(p);
			if (x.size() > 10) x.pop_front();
		}
		h = 0;
		while (x.size()) {
			h = (h << 3) + (h << 1) + x.front() - '0';
			x.pop_front();
		}

		st = 0;
		ed = e - 1;
		while (st < ed) {
			mid = (st + ed) / 2;
			if (fibo[mid].first >= h) ed = mid;
			else st = mid + 1;
		}
		printf("%d\n", fibo[st].second);
	}
	return 0;
}