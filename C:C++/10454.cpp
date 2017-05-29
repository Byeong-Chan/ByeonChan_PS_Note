#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
struct bung {
	long long x;
	long long y;
}o[100001];
int n;
int side;
bool sw;
short chk[100001];
void sub(long long minx, long long miny, long long maxx, long long maxy, short cnt, short num) {
	if (maxx - minx <= side && maxy - miny <= side) {
		sw = true;
		return;
	}
	if (cnt == 2) {
		return;
	}
	int i;
	long long savminx, savminy;
	long long savmaxx, savmaxy;

	// right upside
	if (sw) return;
	savminx = 0x7fffffff, savminy = 0x7fffffff;
	savmaxx = -0x7fffffff, savmaxy = -0x7fffffff;
	for (i = 0; i < n; i++) {
		if (chk[i] == num) continue;
		if (o[i].x - minx <= side && o[i].y - miny <= side) {
			if(cnt == 0) chk[i] = 1;
		}
		else {
			if (o[i].x > savmaxx) savmaxx = o[i].x;
			if (o[i].x < savminx) savminx = o[i].x;
			if (o[i].y > savmaxy) savmaxy = o[i].y;
			if (o[i].y < savminy) savminy = o[i].y;
		}
	}
	if (savminx == 0x7fffffff && savmaxx == -0x7fffffff) savminx = savmaxx = 0;
	if (savminy == 0x7fffffff && savmaxy == -0x7fffffff) savminy = savmaxy = 0;
	sub(savminx, savminy, savmaxx, savmaxy, cnt + 1, 1);

	// left upside
	if (sw) return;
	savminx = 0x7fffffff, savminy = 0x7fffffff;
	savmaxx = -0x7fffffff, savmaxy = -0x7fffffff;
	for (i = 0; i < n; i++) {
		if (chk[i] == num) continue;
		if (maxx - o[i].x <= side && o[i].y - miny <= side) {
			if (cnt == 0) chk[i] = 2;
		}
		else {
			if (o[i].x > savmaxx) savmaxx = o[i].x;
			if (o[i].x < savminx) savminx = o[i].x;
			if (o[i].y > savmaxy) savmaxy = o[i].y;
			if (o[i].y < savminy) savminy = o[i].y;
		}
	}
	if (savminx == 0x7fffffff && savmaxx == -0x7fffffff) savminx = savmaxx = 0;
	if (savminy == 0x7fffffff && savmaxy == -0x7fffffff) savminy = savmaxy = 0;
	sub(savminx, savminy, savmaxx, savmaxy, cnt + 1, 2);

	// right downside
	if (sw) return;
	savminx = 0x7fffffff, savminy = 0x7fffffff;
	savmaxx = -0x7fffffff, savmaxy = -0x7fffffff;
	for (i = 0; i < n; i++) {
		if (chk[i] == num) continue;
		if (o[i].x - minx <= side && maxy - o[i].y <= side) {
			if (cnt == 0) chk[i] = 3;
		}
		else {
			if (o[i].x > savmaxx) savmaxx = o[i].x;
			if (o[i].x < savminx) savminx = o[i].x;
			if (o[i].y > savmaxy) savmaxy = o[i].y;
			if (o[i].y < savminy) savminy = o[i].y;
		}
	}
	if (savminx == 0x7fffffff && savmaxx == -0x7fffffff) savminx = savmaxx = 0;
	if (savminy == 0x7fffffff && savmaxy == -0x7fffffff) savminy = savmaxy = 0;
	sub(savminx, savminy, savmaxx, savmaxy, cnt + 1, 3);

	// left downside
	if (sw) return;
	savminx = 0x7fffffff, savminy = 0x7fffffff;
	savmaxx = -0x7fffffff, savmaxy = -0x7fffffff;
	for (i = 0; i < n; i++) {
		if (chk[i] == num) continue;
		if (maxx - o[i].x <= side && maxy - o[i].y <= side) {
			if (cnt == 0) chk[i] = 4;
		}
		else {
			if (o[i].x > savmaxx) savmaxx = o[i].x;
			if (o[i].x < savminx) savminx = o[i].x;
			if (o[i].y > savmaxy) savmaxy = o[i].y;
			if (o[i].y < savminy) savminy = o[i].y;
		}
	}
	if (savminx == 0x7fffffff && savmaxx == -0x7fffffff) savminx = savmaxx = 0;
	if (savminy == 0x7fffffff && savmaxy == -0x7fffffff) savminy = savmaxy = 0;
	sub(savminx, savminy, savmaxx, savmaxy, cnt + 1, 4);
}
bool fsort(bung a, bung b) {
	if (a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}
int main() {
	int t, i;
	int er;
	long long maxx, minx;
	long long maxy, miny;
	long long st, ed, mid;
	scanf("%d", &t);
	while (t--) {
		maxx = -0x7fffffff, minx = 0x7fffffff;
		maxy = -0x7fffffff, miny = 0x7fffffff;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			scanf("%lld %lld", &o[i].x, &o[i].y);
			if (o[i].x > maxx) maxx = o[i].x;
			if (o[i].x < minx) minx = o[i].x;
			if (o[i].y > maxy) maxy = o[i].y;
			if (o[i].y < miny) miny = o[i].y;
		}
		sort(o, o + n, fsort);
		er = 0;
		for (i = 1; i < n; i++) {
			if (o[i].x == o[i - 1].x && o[i].y == o[i - 1].y) {
				o[i].x = 0x7fffffff;
				o[i].y = 0x7fffffff;
				er++;
			}
		}
		sort(o, o + n, fsort);
		n -= er;
		st = 0;
		ed = maxy - miny > maxx - minx ? maxy - miny : maxx - minx;
		while (st < ed) {
			mid = (st + ed) / 2;
			sw = false;
			side = (int)mid;
			for (i = 0; i < n; i++) chk[i] = 0;
			sub(minx, miny, maxx, maxy, 0, -1);

			if (sw) ed = mid;
			else st = mid + 1;
		}
		printf("%lld\n", ed);
	}
	return 0;
}