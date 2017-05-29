#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair<int, int> pr;
struct bung {
	int x;
	int y;
	int cst;
}road[1000002];
struct seo {
	int num;
	int cst[3];
};
seo min1[100002];
bool chk[3][100002];
bool cant[100002];
int marts[3];
bool fsort(bung a, bung b) {
	return a.x < b.x;
}
bool gsort(seo a,seo b) {
	if(a.cst[0] != b.cst[0]) return a.cst[0] < b.cst[0];
	else return a.cst[2] < b.cst[2];
}
struct ksort {
	bool operator() (pr a, pr b) {
		return a.first > b.first;
	}
};
priority_queue<pr, vector<pr>, ksort > find_min;
int n, m;
int cut[100002];
int t = 1;
void mergncomp() {
	seo tmp[100002];
	int minc[100002] = {0,};
	int mina[100002] = {0,};
	int k = 1;
	int i, j;
	int x, y;
	int nx, ny;
	int tmpsize;
	for(i=1;i<=n;i++) {
		minc[i] = min1[i].cst[2];
		mina[i] = min1[i].cst[0];
	}
	while(k < n) {
		k <<= 1;
		for(i=1;i<=n;i+=k) {
			x = i;
			y = nx = i + (k >> 1);
			if(nx >= n+1) continue;
			ny = nx + (k >> 1);
			if(ny >= n+1) ny = n+1;
			tmpsize = 0;
			while(x < nx || y < ny) {
				if(x == nx) tmp[tmpsize++] = min1[y++];
				else if(y == ny) tmp[tmpsize++] = min1[x++];
				else {
					if(min1[x].cst[1] < min1[y].cst[1]) {
						if(mina[x] < min1[y].cst[0] && minc[x] < min1[y].cst[2]) cant[min1[y].num] = true;
						tmp[tmpsize++] = min1[y++];
					}
					else tmp[tmpsize++] = min1[x++];
				}
			}
			tmpsize--;
			min1[ny-1] = tmp[tmpsize];
			mina[ny-1] = tmp[tmpsize].cst[0];
			minc[ny-1] = tmp[tmpsize].cst[2];
			for(j=ny-2;j>=i;j--) {
				tmpsize--;
				min1[j] = tmp[tmpsize];
				if(mina[j+1] > tmp[tmpsize].cst[0]) mina[j] = tmp[tmpsize].cst[0];
				else mina[j] = mina[j+1];
				if(minc[j+1] > tmp[tmpsize].cst[2]) minc[j] = tmp[tmpsize].cst[2];
				else minc[j] = minc[j+1];
			}
		}
	}
}
void solv() {
	pr outtmp, intmp;
	int k;
	int i;
	int st, ed;
	for(k=0;k<3;k++) {
		intmp = make_pair(0, marts[k]);
		find_min.push(intmp);
		while(find_min.size()) {
			outtmp = find_min.top();
			find_min.pop();
			if(chk[k][outtmp.second]) continue;
			chk[k][outtmp.second] = true;
			st = cut[outtmp.second - 1];
			ed = cut[outtmp.second];
			for(i=st;i<ed;i++) {
				intmp = make_pair(outtmp.first+road[i].cst, road[i].y);
				if(chk[k][intmp.second] || (min1[intmp.second].cst[k] > 0 && min1[intmp.second].cst[k] < intmp.first)) continue;
				find_min.push(intmp);
				min1[intmp.second].cst[k] = intmp.first;
			}
		}
	}
	std::sort(min1+1, min1+n+1, gsort);
	mergncomp();
}
void _out() {
	int c;
	int _in;
	scanf("%d",&c);
	while(c--) {
		scanf("%d",&_in);
		if(cant[_in]) printf("NO\n");
		else printf("YES\n");
	}
}
int main() {
	int i;
	scanf("%d",&n);
	scanf("%d %d %d", &marts[0], &marts[1], &marts[2]);
	scanf("%d",&m);
	for(i=0;i<m;i++) {
		scanf("%d %d %d",&road[i].x,&road[i].y,&road[i].cst);
		road[i+m].x = road[i].y;
		road[i+m].y = road[i].x;
		road[i+m].cst = road[i].cst;
	}
	m *= 2;
	std::sort(road, road+m, fsort);
	for(i=0;i<m;i++) while(t <= n && t != road[i].x) cut[t++] = i;
	while(t <= n) cut[t++] = i;
	for(i=1;i<=n;i++) min1[i].num = i;
	solv();
	_out();
	return 0;
}