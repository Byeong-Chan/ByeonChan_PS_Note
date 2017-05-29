#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct bung {
	long long x;
	long long y;
	long long r;
}o[1010];
vector<int> con[1010];
bool chk[1010];
int moth[1010];
short rota[1010];
long long dist(long long x1, long long y1, long long x2, long long y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
pair<int, short> que[1010];
long long uclid(long long a, long long b) {
	if (a % b == 0) return b;
	else return uclid(b, a%b);
}
int main() {
	int i, j;
	long long r1, r2;
	long long d;
	int n;
	int tail, head;
	int a, b;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%lld %lld %lld", &o[i].x, &o[i].y, &o[i].r);
	for (i = 1; i < n; i++) {
		for (j = i+1; j <= n; j++) {
			d = (o[i].r + o[j].r);
			if (d * d == dist(o[i].x, o[i].y, o[j].x, o[j].y)) {
				con[i].push_back(j);
				con[j].push_back(i);
			}
		}
	}
	tail = head = 0;
	que[tail].first = 1;
	que[tail++].second = -1;
	chk[1] = true;
	moth[1] = -1;
	rota[1] = -1;
	int tmp;
	while (tail > head) {
		a = que[head].first;
		b = que[head].second;
		head++;
		for (i = 0; i < con[a].size(); i++) {
			tmp = con[a][i];
				if (chk[tmp]) {
					if (rota[tmp] == b) {
						printf("The input gear cannot move.");
						return 0;
					}
					else continue;
				}
				else {
					chk[tmp] = true;
					moth[tmp] = a;
					que[tail].first = tmp;
					que[tail++].second = rota[tmp] = b * -1;
				}
		}
	}
	if (chk[n]) {
		r1 = o[1].r;
		r2 = o[n].r;
		d = uclid(r1, r2);
		r1 /= d;
		r2 /= d;
		r1 *= rota[1];
		r2 *= rota[n];

		if (r1 < 0 && r2 < 0) {
			r1 *= -1;
			r2 *= -1;
		}

		printf("%lld:%lld", r1, r2);
	}
	else printf("The input gear is not connected to the output gear.");
	return 0;
}