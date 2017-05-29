#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
typedef pair<int, int> pr;

#define mp(x, y) make_pair(x, y);

struct bung {
	int x;
	int y;
	int num;
}o[100001];
vector<int> u[100001];
pr stk[100001];
long double stkp[100001];
int trs[100001];
bool ccw(int ax, int ay, int bx, int by, int cx, int cy) {
	long long d = ((long long)ax * by + (long long)bx * cy + (long long)cx * ay) - ((long long)ay * bx + (long long)by * cx + (long long)cy * ax);
	if(d <= 0) return false;
	return true;
}
long double dist(int x1, int y1, int x2, int y2) {
	return sqrt(((long double)x1 - x2)*((long double)x1 - x2) + ((long double)y1 - y2)*((long double)y1 - y2));
}
int main() {
	int t;
	int i, j, n, m;
	int k, go;
	int top;
	int tx, ty, mx, my;
	int e;
	bool sw;
	short p;
	long double sum, path;
	pr tmp1, tmp2;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		for(i=0;i<n;i++) {
			scanf("%d %d",&o[i].x,&o[i].y);
			o[i].num = i;
		}
		reverse(o+1, o+n);
		for(i=0;i<n;i++) {
			u[i].clear();
			trs[o[i].num] = i;
		}
		scanf("%d",&m);
		sum = path = 0;
		for(i=0;i<m;i++) {
			scanf("%d %d", &k, &go);
			if(k == 0) {
				sum += (long double)go;
				continue;
			}
			e = abs(o[trs[k]].x - o[trs[k]-1].x != 0 ? o[trs[k]].x - o[trs[k]-1].x : o[trs[k]].y - o[trs[k]-1].y);
			u[trs[k]-1].push_back(e - go);
		}
		for(i=0;i<n;i++) sort(u[i].begin(), u[i].end());
		top = 0;
		for(i=0;i<n-1;i++) {
			while(top > 1) {
				tmp1 = stk[top-1];
				tmp2 = stk[top-2];
				if(ccw(tmp2.first, tmp2.second, tmp1.first, tmp1.second, o[i].x, o[i].y)) break;
				top--;
				path -= stkp[top];
			}
			stk[top++] = mp(o[i].x, o[i].y);
			if(top > 1) {
				tmp1 = stk[top-1];
				tmp2 = stk[top-2];
				stkp[top-1] = dist(tmp1.first, tmp1.second, tmp2.first, tmp2.second);
				path += stkp[top-1];
			}
			tx = o[i].x;
			ty = o[i].y;
			if(tx == o[i+1].x) {
				sw = false;
				if(ty > o[i+1].y) p = -1;
				else p = 1;
			}
			else {
				sw = true;
				p = 1;
			}
			for(j=0;j<(int)u[i].size();j++) {
				mx = tx;
				my = ty;
				if(sw) mx += p * u[i][j];
				else my += p * u[i][j];
				while(top > 1) {
					tmp1 = stk[top-1];
					tmp2 = stk[top-2];
					if(ccw(tmp2.first, tmp2.second, tmp1.first, tmp1.second, mx, my)) break;
					top--;
					path -= stkp[top];
				}
				stk[top++] = mp(mx, my);
				if(top > 1) {
					tmp1 = stk[top-1];
					tmp2 = stk[top-2];
					stkp[top-1] = dist(tmp1.first, tmp1.second, tmp2.first, tmp2.second);
					path += stkp[top-1];
				}
				sum += path;
			}
		}
		printf("%.1Lf\n",sum);
	}
	return 0;
}