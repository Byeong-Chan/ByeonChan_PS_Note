#include <stdio.h>
#include <string.h>
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
char o[501];
int main() {
	int t;
	int n;
	int i;
	int x, y;
	int d;
	int s;
	int maxx, maxy, minx, miny;
	scanf("%d",&t);
	while(t--) {
		scanf("%s",o);
		n = strlen(o);
		d = x = y = 0;
		minx = maxx = miny = maxy = 0;
		for(i=0;i<n;i++) {
			if(o[i] == 'L') {
				d--;
				if(d < 0) d = 3;
				continue;
			}
			if(o[i] == 'R') {
				d++;
				if(d > 3) d = 0;
				continue;
			}
			s = 1;
			if(o[i] == 'B') s = -1;
			x += dx[d]*s;
			y += dy[d]*s;

			if(x < 0) {if(minx > x) minx = x;}
			else {if(maxx < x) maxx = x;}
			if(y < 0) {if(miny > y) miny = y;}
			else {if(maxy < y) maxy = y;}
		}
		printf("%d\n",(maxx-minx)*(maxy-miny));
	}
	return 0;
}