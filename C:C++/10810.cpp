#include <stdio.h>
struct bung {
	bool sw;
	int p;
}index[257];
int k;
int n, m;
void change(int d) {
	if(index[d].sw && d < k) {
		index[d<<1] = index[(d<<1)+1] = index[d];
		index[d].sw = false;
	}
}
void up(int d) {
	int follow;
	int moth[11], e = 0;
	follow = d;
	while(follow > 1) {
		follow >>= 1;
		moth[e++] = follow;
	}
	while(e--) change(moth[e]);
}
void made(int st, int ed, int ball) {
	int all[11], e = 0;
	while(1) {
		if(st == ed) {
			all[e++] =st;
			break;
		}
		if(st&1) all[e++] = st++;
		if(!(ed&1)) all[e++] = ed--;
		if(st > ed) break;
		st >>= 1;
		ed >>= 1;
	}
	int tmp;
	while(e--) {
		tmp = all[e];
		up(tmp);
		index[tmp].p = ball;
		index[tmp].sw = true;
		change(tmp);
	}
	return;
}
int main() {
	int i;
	int x, y, z;
	scanf("%d %d",&n,&m);
	for(k=1;k<n;k<<=1);
	for(i=0;i<m;i++) {
		scanf("%d %d %d",&x,&y,&z);
		x += k-1;
		y += k-1;
		made(x, y, z);
	}
	for(i=0;i<n;i++) {
		up(i+k);
		printf("%d ",index[i+k].p);
	}
	return 0;
}