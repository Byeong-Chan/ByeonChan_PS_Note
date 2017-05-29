#include <stdio.h>
#include <algorithm>
using namespace std;
struct bung {
	int x;
	int y;
}o[2004];
int n, m;
int cut[104];
int can[104];
int chk[104];
bool fsort(bung a, bung b) {
	return a.x < b.x;
}
void _in() {
	int i, t, tmp;
	scanf("%d", &n);
	scanf("%d", &m);
	for (i = 0; i < m; i++) scanf("%d %d", &o[i].x, &o[i].y);
	std::sort(o, o + m, fsort);
	t = 1;
	for (i = 0; i < m; i++) {
		tmp = o[i].x;
		while (tmp != t) cut[t++] = i;
	}
	tmp = n + 1;
	while (tmp != t) cut[t++] = i;
}
void solv() {
	int i;
	int st, ed;
	int k;
	int a;
	int f;
	int tail, head, que[104];
	for (k = 1; k <= n; k++) {
		tail = head = 0;
		que[tail++] = k;
		while (tail > head) {
			a = que[head++];
			st = cut[a - 1];
			ed = cut[a];
			for (i = st; i < ed; i++) {
				f = o[i].y;
				if (chk[f] != k) {
					chk[f] = k;
					can[k] ++;
					can[f] ++;
					que[tail++] = f;
				}
			}
		}
	}
}
void _out() {
	int i;
	for (i = 1; i <= n; i++) printf("%d\n", n - can[i] - 1);
}
int main() {
	_in();
	solv();
	_out();
	return 0;
}