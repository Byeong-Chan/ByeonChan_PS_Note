#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct bung {
	int x;
	int y;
	long long cst;
}o[100003];
int n, m;
long long e = 0;
long long pt = 0;
vector<int> sub[100003];
int _index[100003];
bool fsort(bung a, bung b) {
	return a.cst > b.cst;
}
void _in() {
	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) scanf("%d %d %lld", &o[i].x, &o[i].y, &o[i].cst);
	for (i = 1; i <= n; i++) {
		sub[i].push_back(i);
		_index[i] = i;
	}
	std::sort(o, o + m, fsort);
}
void solv() {
	int i;
	int x, y;
	int tmp;
	int szx, szy;
	int hap;
	for (i = 0; i < m; i++) {
		x = _index[o[i].x];
		y = _index[o[i].y];
		if (x != y) {
			szx = sub[x].size();
			szy = sub[y].size();
			hap = szx + szy;

			pt -= (long long)szx * (szx - 1) / 2;
			pt -= (long long)szy * (szy - 1) / 2;
			pt += (long long)hap * (hap - 1) / 2;
			pt %= 1000000000;

			if (sub[x].size() > sub[y].size()) {
				while (sub[y].size()) {
					tmp = sub[y].back();
					_index[tmp] = x;
					sub[x].push_back(tmp);
					sub[y].pop_back();
				}
			}
			else {
				while (sub[x].size()) {
					tmp = sub[x].back();
					_index[tmp] = y;
					sub[y].push_back(tmp);
					sub[x].pop_back();
				}
			}
		}
		e += pt * o[i].cst;
		e %= 1000000000;
	}
}
void _out() {
	printf("%d", e);
}
int main() {
	_in();
	solv();
	_out();
	return 0;
}