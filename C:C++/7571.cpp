#include <stdio.h>
#include <algorithm>
#define _abs(a) (a < 0 ? -a : a)
using namespace std;
int x[110000], y[110000];
int main() {
	int i, n, m;
	int mx, my;
	int tmpx, tmpy;
	int e = 0, t = 0;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++) scanf("%d %d",&x[i], &y[i]);
	std::sort(x, x+m);
	std::sort(y, y+m);
	mx = x[m/2];
	my = y[m/2];
	for(i=0;i<m;i++) {
		tmpx = mx-x[i];
		tmpy = my-y[i];
		e += _abs(tmpx);
		e += _abs(tmpy);
	}
	if(m & 1) {
		printf("%d",e);
		return 0;
	}
	mx = x[m/2-1];
	my = y[m/2-1];
	for(i=0;i<m;i++) {
		tmpx = mx-x[i];
		tmpy = my-y[i];
		t += _abs(tmpx);
		t += _abs(tmpy);
	}
	printf("%d",(e < t ? e : t));
	return 0;
}