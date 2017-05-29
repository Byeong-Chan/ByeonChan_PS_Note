#include <stdio.h>
#include <algorithm>
#include <set>
#include <string.h>
#include <math.h>
using namespace std;
typedef long double ld;
typedef pair<ld, int> pr;
multiset<pr> cmp;
int n;
int max1 = 1;
int maxpos[102];
ld d;
bool chk[102];
int pointset[102];
struct bung {
	ld x;
	ld y;
}o[102];
ld distxy;
ld calcdist(ld x1, ld y1, ld x2, ld y2) {
	return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}
ld calck(ld x1, ld y1, ld x2, ld y2, ld x, ld y) {
	ld xd = (x1+x2)/2;
	ld yd = (y1+y2)/2;
	ld alpha = xd - x;
	ld beta = yd - y;
	ld a = x2 - x1;
	ld b = y2 - y1;
	ld xm = xd - x1;
	ld ym = yd - y1;

	return (xm*xm - alpha*alpha + ym*ym - beta*beta) / (2*a*(alpha-xm) + 2*b*(beta-ym));
}
void expand_circle(ld x1, ld y1, ld x2, ld y2) {
	int e = 2;
	ld k;
	ld xd = (x1+x2)/2;
	ld yd = (y1+y2)/2;

	int i;
	for(i=0;i<n;i++) {
		if(chk[i] == false) {
			if(calcdist(o[i].x, o[i].y, xd, yd) <= distxy/2) {
				chk[i] = true;
				pointset[e++] = i;
			}
		}
	}
	for(i=0;i<n;i++) {
		if(chk[i] == false) {
			k = calck(x1, y1, x2, y2, o[i].x, o[i].y);
			cmp.insert(make_pair(k, i));
		}
	}

	pr tmp;
	while(cmp.size()) {
		tmp = *cmp.begin();
		cmp.erase(cmp.begin());

		if(tmp.first < 0) continue;

		for(i=0;i<e;i++) if(calcdist(o[pointset[i]].x, o[pointset[i]].y, o[tmp.second].x, o[tmp.second].y) > d) break;
		if(i == e) {
			chk[tmp.second] = true;
			pointset[e++] = tmp.second;
		}
	}

	if(max1 < e) {
		max1 = e;
		for(i=0;i<max1;i++) maxpos[i] = pointset[i];
	}
}
int main() {
	int i, j;
	maxpos[0] = 1;
	scanf("%d %Lf",&n,&d);
	for(i=0;i<n;i++) scanf("%Lf %Lf",&o[i].x,&o[i].y);
	for(i=0;i<n;i++) {
		for(j=i+1;j<n;j++) {
			distxy = calcdist(o[i].x, o[i].y, o[j].x, o[j].y);
			if(distxy <= d) {
				cmp.clear();
				memset(chk, false, sizeof(chk));
				chk[i] = true;
				chk[j] = true;
				pointset[0] = i;
				pointset[1] = j;
				expand_circle(o[i].x, o[i].y, o[j].x, o[j].y);

				cmp.clear();
				memset(chk, false, sizeof(chk));
				chk[i] = true;
				chk[j] = true;
				pointset[0] = i;
				pointset[1] = j;
				expand_circle(o[j].x, o[j].y, o[i].x, o[i].y);
			}
		}
	}
	printf("%d\n",max1);
	for(i=0;i<max1;i++) printf("%d ",maxpos[i]+1);
	return 0;
}