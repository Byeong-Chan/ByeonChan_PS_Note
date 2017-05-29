#include <stdio.h>
#define _abs(_in) ((_in) < 0 ? -(_in) : (_in))
struct bung {
	int x;
	int y;
}o[110000];
int a[110000];
long long min1;
int main() {
	int i, n;
	long long e = 0;
	long long d;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d %d",&o[i].x,&o[i].y);
		if(i > 0) {
			a[i] = _abs(o[i].x - o[i-1].x) + _abs(o[i].y - o[i-1].y);
			e += a[i];
		}
	}
	min1 = e - a[1] - a[2] + (_abs(o[2].x - o[0].x) + _abs(o[2].y - o[0].y));
	for(i=1;i<n-2;i++) {
		d = e - a[i+1] - a[i+2] + (_abs(o[i+2].x - o[i].x) + _abs(o[i+2].y - o[i].y));
		if(min1 > d) min1 = d;
	}
	printf("%lld",min1);
	return 0;
}