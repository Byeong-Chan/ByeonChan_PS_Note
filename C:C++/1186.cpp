#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int, int> pr;
struct bung {
	int x1;
	int y1;
	int x2;
	int y2;
}o[101];
map<int, int> dx, dy, tx, ty;
int tmpx[202], tmpy[202];
int n, k;
int e = 0, t = 0;
int chk[402][402];
int s[102];
pr p[101];
bool fsort(pr a, pr b) {
	if(a.first != b.first) return a.first > b.first;
	else return a.second < b.second;
}
int main() {
	int i, j, l;
	int x1, y1, x2, y2;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++) {
		scanf("%d %d %d %d",&o[i].x1,&o[i].y1,&o[i].x2,&o[i].y2);
		tmpx[i] = o[i].x1;
		tmpx[i+n] = o[i].x2;
		tmpy[i] = o[i].y1;
		tmpy[i+n] = o[i].y2;
	}
	sort(tmpx, tmpx+(n<<1));
	sort(tmpy, tmpy+(n<<1));
	dx[tmpx[0]] = ++e;
	dy[tmpy[0]] = ++t;
	tx[e] = tmpx[0];
	ty[t] = tmpy[0];
	for(i=1;i<(n<<1);i++) {
		if(tmpx[i-1] != tmpx[i]) {
			dx[tmpx[i]] = ++e;
			tx[e] = tmpx[i];
		}
		if(tmpy[i-1] != tmpy[i]) {
			dy[tmpy[i]] = ++t;
			ty[t] = tmpy[i];
		}
	}
	for(l=0;l<n;l++) {
		x1 = dx[o[l].x1];
		y1 = dy[o[l].y1];
		x2 = dx[o[l].x2];
		y2 = dy[o[l].y2];
		for(i=x1;i<x2;i++) {
			for(j=y1;j<y2;j++) {
				chk[i][j] = l+1;
			}
		}
	}
	for(i=1;i<e;i++) {
		for(j=1;j<t;j++) {
			if(chk[i][j] != 0) {
				s[chk[i][j]] += (tx[i+1] - tx[i]) * (ty[j+1] - ty[j]);
			}
		}
	}
	for(i=1;i<=n;i++) p[i-1] = make_pair(s[i], i);
	int ans[101];
	sort(p, p+n, fsort);
	for(i=0;i<k;i++) ans[i] = p[i].second;
	sort(ans, ans+k);
	for(i=0;i<k;i++) printf("%d ",ans[i]);
	return 0;
}