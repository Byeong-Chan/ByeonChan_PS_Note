#include <stdio.h>
#include <algorithm>
#define comp(p, q) ((p.x < q.x && p.y > q.y) || (p.x < q.x && p.y > q.y))
using namespace std;
struct bung {
	int x;
	int y;
};
bung o[100002];
bung a[100002], b[100002];
bool fsort(bung a,bung b) {
	return a.x < b.x;
}
int n;
int asize = 0, bsize = 0;
int main() {
	int i;
	int lasty;
	int e, t;
	int l;
	int max1 = 1;
	short sw;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d %d",&o[i].x,&o[i].y);
	std::sort(o,o+n,fsort);
	a[asize++] = o[0];
	lasty = o[0].y;
	for(i=1;i<n;i++) {
		if(lasty < o[i].y) {
			a[asize++] = o[i];
			lasty = o[i].y;
		}
		else b[bsize++] = o[i];
	}
	e = t = l = 0;
	sw = 0;
	while(e < asize && t < bsize) {
		if (a[e].x < b[t].x) {
			if(a[e].y > b[t].y) {
				if(sw == 0) l += 2;
				else l++;
				if(max1 < l) max1 = l;
				if(e+1 < asize && t+1 < bsize && comp(a[e+1], b[t]) && comp(a[e], b[t+1])) {
					if(sw == 1) {
						t++;
						sw = 2;
						continue;
					}
					if(sw == 2) {
						e++;
						sw = 1;
						continue;
					}
					sw = 0;
					e++;
					t++;
				}
				else if(e+1 < asize && comp(a[e+1], b[t])) {
					if(sw == 1) {
						e++;
						l--;
						continue;
					}
					e++;
					sw = 1;
				}
				else if(t+1 < bsize && comp(a[e], b[t+1])) {
					if(sw == 2) {
						t++;
						l--;
						continue;
					}
					t++;
					sw = 2;
				}
				else {
					sw = 0;
					l = 0;
					e++;
					t++;
				}
			}
			else {
				sw = 0;
				l = 0;
				e++;
			}
		}
		else {
			if(a[e].y < b[t].y) {
				if(sw == 0) l += 2;
				else l++;
				if(max1 < l) max1 = l;
				if(e+1 < asize && t+1 < bsize && comp(a[e+1], b[t]) && comp(a[e], b[t+1])) {
					if(sw == 1) {
						t++;
						sw = 2;
						continue;
					}
					if(sw == 2) {
						e++;
						sw = 1;
						continue;
					}
					sw = 0;
					e++;
					t++;
				}
				else if(e+1 < asize && comp(a[e+1], b[t])) {
					if(sw == 1) {
						e++;
						l--;
						continue;
					}
					e++;
					sw = 1;
				}
				else if(t+1 < bsize && comp(a[e], b[t+1])) {
					if(sw == 2) {
						t++;
						l--;
						continue;
					}
					t++;
					sw = 2;
				}
				else {
					sw = 0;
					l = 0;
					e++;
					t++;
				}
			}
			else {
				sw = 0;
				l = 0;
				t++;
			}
		}
	}
	printf("%d",max1);
	return 0;
}