#include <stdio.h>
#include <algorithm>
using namespace std;
struct bung
{
	int x;
	int y;
	int num;
}o[510000];
bool fsort(bung a, bung b) {
	if(a.x < b.x) return true;
	if(a.x <= b.x && a.y > b.y) return true;
	return false;
}
bool chk[510000];
int n;
int m;
void in() {
	int i;
	scanf("%d",&m);
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d %d",&o[i].x,&o[i].y);
		o[i].num = i+1;
		if(o[i].y < o[i].x) o[i].y += m;
		else {
			o[i].x += m;
			o[i].y += m;
		}
	}
}
void solv() {
	int i, maxy;
	maxy = o[0].y;
	for(i=1;i<n;i++) {
		if(o[i].y <= maxy) chk[o[i].num] = 1;
		else maxy = o[i].y;

		if(o[i].x >= m && o[i].y >= m) {
			o[i].x -= m;
			o[i].y -= m;
		}
	}
}
void out() {
	int i;
	for(i=1;i<=n;i++) if(!chk[i]) printf("%d ",i);
}
int main() {
	in();
	std::sort(o,o+n,fsort);
	solv();
	std::sort(o,o+n,fsort);
	solv();
	out();
	return 0;
}