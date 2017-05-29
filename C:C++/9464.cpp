#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> chk[2000001];
int o[1000001], n = 0;
int sub(int a, int b) {
	if(a%b == 0) return b;
	else return sub(b, a%b);
}
int main() {
	int x, y;
	int tx, ty, d;
	int t;
	int L, ans;
	int h;
	int s;
	for(x=1;x<=1000;x++) {
		for(y=x+1;y<=1000;y++) {
			tx = 2*x*y;
			ty = y*y - x*x;
			d = sub(tx, ty);
			tx /= d;
			ty /= d;
			if(tx > ty) swap(tx, ty);

			h = chk[tx][ty];
			s = 2*(y*y - x*x + 2*x*y);

			if(h == 0 || o[h-1] > s) {
				if(h == 0) {
					o[n++] = s;
					chk[tx][ty] = n;
				}
				else {
					o[h-1] = s;
					chk[tx][ty] = h;
				}
			}
		}
	}
	sort(o,o+n);

	scanf("%d",&t);
	while(t--) {
		scanf("%d",&L);
		for(ans=0;ans<n;ans++) {
			L -= o[ans];
			if(L < 0) break;
		}
		printf("%d\n",ans);
	}
	return 0;
}