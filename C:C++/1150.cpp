#include <stdio.h>
#include <set>
#include <algorithm>
using namespace std;
typedef pair<long long , int> pr;
int left[100004], right[100004];
long long p[100004];
multiset<pr> q;
int main() {
	int n, m;
	int i;
	int pre, last;
	int l, r;
	int pos;
	long long ans = 0;
	pr tmp;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &pre);
		if (i) {
			tmp = make_pair(pre - last, i);
			q.insert(tmp);
			p[i] = pre - last;
			left[i] = i - 1;
			right[i] = i + 1;
		}
		last = pre;
	}
	p[0] = -1;
	p[n] = -1;
	for (i = 0; i < m; i++) {
		tmp = *q.begin();
		q.erase(q.begin());

		pos = tmp.second;
		ans += p[pos];

		l = left[pos];
		r = right[pos];

		if (p[l] != -1 && p[r] != -1) {
			left[pos] = left[l];
			right[pos] = right[r];

			p[pos] = p[l] + p[r] - p[pos];
			tmp = make_pair(p[pos], pos);
			q.insert(tmp);
		}
		else {
			p[pos] = -1;
			pos = 0;
		}

		if (p[right[r]] != -1) left[right[r]] = pos;
		if (p[left[l]] != -1) right[left[l]] = pos;

		if (p[l] != -1) {
			tmp = make_pair(p[l], l);
			q.erase(tmp);

			p[l] = -1;
		}
		if (p[r] != -1) {
			tmp = make_pair(p[r], r);
			q.erase(tmp);

			p[r] = -1;
		}
	}
	printf("%lld", ans);
	return 0;
}