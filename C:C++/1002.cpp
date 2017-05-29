#include <stdio.h>
#include <math.h>
#define _abs(a) ((a) < 0 ? -(a) : (a))
typedef long double ld;
ld calcdist(ld x1, ld y1, ld x2, ld y2) {
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
int main() {
	int t;
	ld x1, y1, x2, y2, r1, r2, d;
	scanf("%d",&t);
	while(t--) {
		scanf("%Lf %Lf %Lf %Lf %Lf %Lf", &x1, &y1, &r1, &x2, &y2, &r2);
		d = calcdist(x1, y1, x2, y2);
		if(d == 0) {
			if(r1 == r2) printf("-1\n");
			else printf("0\n");
		}
		else {
			if(d == _abs(r1 - r2)) printf("1\n");
			else if(d < _abs(r1 - r2)) printf("0\n");
			else if(d == r1 + r2) printf("1\n");
			else if(d < r1 + r2) printf("2\n");
			else printf("0\n");
		}
	}
	return 0;
}