#include <stdio.h>
#include <algorithm>
using namespace std;
struct bung {
	int x;
	int y;
};
bung o[100003], tmp[100003];
int chk[100003];
int hapc[100003];
int hap1[100003];
int all[100003];
int cn[100003];
int dt[100003];
int m, k, n;
int e = 0;
bool sw = false;
bool fsort(bung a,bung b) {
	if(a.x != b.x) return (a.x < b.x);
	else return (a.y > b.y);
}
void _clear();
void _in() {
	int i;
	int x, y;
	int c;
	int cnt = 0;
	scanf("%d %d %d",&m, &k, &n);
	for(i=1;i<=n;i++) {
		scanf("%d %d",&x,&y);
		scanf("%d",&c);
		if(c) {
			o[++cnt].x = x;
			o[cnt].y = y;
		}
		else {
			chk[x]++;
			chk[y+1]--;
		}
	}
	n = cnt;
	std::sort(o+1,o+n+1,fsort);
	_clear();
}
void _clear() {
	int i;
	for(i=1;i<=m;i++) chk[i] += chk[i-1];
	for(i=1;i<=m;i++) {
		all[i] = all[i-1];
		if(!chk[i]) all[i] = i;

		if(chk[i] > 1) chk[i] = 1;
		hap1[i] = hap1[i-1] + (!chk[i]);
	}
}
void del() {
	int i;
	int cnt = 0;
	int last = 0x7fffffff;
	for(i=n;i>=1;i--) {
		if(o[i].y >= last) continue;
		tmp[cnt].x = o[i].x;
		tmp[cnt++].y = o[i].y;
		last = o[i].y;
	}
	for(i=0;i<cnt;i++) o[cnt - i] = tmp[i];
	n = cnt;
}
void del2() {
	int i;
	int pos;
	int cnt = 0;
	for(i=1;i<=n;i++) {
		pos = all[o[i].y];
		if(!chk[pos] && hap1[o[i].y] - hap1[o[i].x - 1] == 1) {
			chk[pos] = 1;
			hapc[pos] = 1;
			cn[e++] = pos;
			k--;
		}
		else o[++cnt] = o[i];
	}
	for(i=1;i<=m;i++) hapc[i] += hapc[i-1];
	n = cnt;
}
void del3() {
	int i;
	int cnt = 0;
	for(i=1;i<=n;i++) if(!(hapc[o[i].y] - hapc[o[i].x - 1])) o[++cnt] = o[i];
	n = cnt;
}
void solv() {
	if(hap1[m] == k) {
		int i;
		sw = true;
		for(i=1;i<=m;i++) {
			if(chk[i] == 0) printf("%d\n",i);
		}
		return;
	}
	del();
	del2();
	del3();
    o[n+1].x = o[n].x + 1;
    int i;
    int st, ed;
    int p;
    int qz;
    int mid;
    for(i=n;i>=1;i--) {
    	p = all[o[i].y];
    	st = i+1;
    	ed = n+1;
    	while(st < ed) {
    		mid = (st + ed) / 2;
    		if(p >= o[mid].x) st = mid + 1;
    		else ed = mid;
    	}
    	dt[i] = dt[st] + 1;
    }
    int _next = -1;
    int how = 0;
    for(i=1;i<=n;i++) {
    	if(o[i].x <= _next) continue;
    	p = all[o[i].y];
    	qz = all[p-1];
    	st = i+1;
    	ed = n+1;
    	while(st < ed) {
    		mid = (st + ed) / 2;
    		if(qz >= o[mid].x) st = mid + 1;
    		else ed = mid;
    	}
    	if(how + 1 + dt[st] > k) cn[e++] = p;
    	_next = p;
    	how ++;
    }
}
void _out() {
	if(sw) return;
	if(e == 0) {
		printf("-1");
		return;
	}
	std::sort(cn, cn + e);
	int i;
	for(i=0;i<e;i++) printf("%d\n",cn[i]);
}
int main() {
	_in();
	solv();
	_out();
	return 0;
}