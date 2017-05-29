#include <stdio.h>
#include <set>
#include <functional>
#include <algorithm>
using namespace std;
typedef long long lli;
multiset<int, greater<int> > how[100002];
int _index[100002];
struct bung {
	int moth;
	lli cst;
	lli lea;
}o[100002];
int n, m;
int bud;
int tail, head;
int son[100002];
int que[100002];
lli hcst[100002];
lli max1 = 0;
void merg(int, int);
void del(int);
void solv() {
	int xh;
	int tmp;
	lli gap;
	while (tail > head) {
		tmp = que[head];
		head++;

		del(tmp);
		gap = o[tmp].lea * (lli)how[_index[tmp]].size();
		if (max1 < gap) max1 = gap;

		if (tmp == 1) break;

		xh = o[tmp].moth;
		merg(xh, tmp);

		if (--son[xh] == 0) que[tail++] = xh;
	}
}
void merg(int mo, int so) {
	hcst[mo] += hcst[so];
	hcst[so] = 0;

	int x = _index[so], y = _index[mo];
	std::multiset<int, greater<int> >::iterator it;
	if (how[x].size() > how[y].size()) {
		_index[mo] = x;
		while (how[y].size()) {
			it = how[y].begin();
			how[x].insert(*it);
			how[y].erase(it);
		}
	}
	else {
		while (how[x].size()) {
			it = how[x].begin();
			how[y].insert(*it);
			how[x].erase(it);
		}
	}
}
void del(int pos) {
	int x = _index[pos];
	std::multiset<int, greater<int> >::iterator it;
	while (how[x].size() && hcst[pos] > bud) {
		it = how[x].begin();
		hcst[pos] -= (lli)(*it);
		how[x].erase(it);
	}
}
void _in() {
	int i;
	scanf("%d %d", &n, &bud);
	for (i = 1; i <= n; i++) {
		scanf("%d %lld %lld", &o[i].moth, &o[i].cst, &o[i].lea);
		son[o[i].moth]++;
		_index[i] = i;
	}
	for (i = 1; i <= n; i++) {
		hcst[i] = o[i].cst;
		how[i].insert((int)o[i].cst);
		if (son[i] == 0) que[tail++] = i;
	}
}
void _out() {
	printf("%lld\n", max1);
}
int main() {
	tail = head = 0;
	_in();
	solv();
	_out();
	return 0;
}