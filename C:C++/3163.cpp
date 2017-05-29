#include <stdio.h>
#include <algorithm>
using namespace std;
struct bung {
	int l;
	int id;
}o[100001];
struct seo {
	int l;
	int t;
	bool sw;
}u[100001];
int nowant[100001];
int n, m, k;
bool fsort(seo a, seo b) {
	return a.t < b.t;
}
int find(int key, int sw) {
	int i;
	int p;
	if(sw) {
		int tail = 0, head = 0;
		for(i=n-1;i>=0;i--) {
			if(key == o[i].l) {
				p = o[i].id;
				break;
			}
			if(o[i].id > 0) {
				if(tail > head) {
					head++;
					nowant[tail++] = o[i].id;
				}
			}
			else nowant[tail++] = o[i].id;
		}
		if(tail == head) nowant[0] = p;
		return nowant[head];
	}
	else {
		int tail = 0, head = 0;
		for(i=0;i<n;i++) {
			if(key == o[i].l) {
				p = o[i].id;
				break;
			}
			if(o[i].id < 0) {
				if(tail > head) {
					head++;
					nowant[tail++] = o[i].id;
				}
			}
			else nowant[tail++] = o[i].id;
		}
		if(tail == head) nowant[0] = p;
		return nowant[head];
	}
}
int main() {
	int i, t;
	int x1, x2;
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d %d",&n,&m,&k);
		for(i=0;i<n;i++) scanf("%d %d",&o[i].l, &o[i].id);
		for(i=0;i<n;i++) {
			if(o[i].id < 0) {
				u[i].l = o[i].l;
				u[i].t = o[i].l;
				u[i].sw = false;
			}
			else {
				u[i].l = o[i].l;
				u[i].t = m - o[i].l;
				u[i].sw = true;
			}
		}
		sort(u, u+n, fsort);

		x1 = find(u[k-1].l, u[k-1].sw);

		x2 = 0x7fffffff;
		if(k-2 >= 0 && u[k-2].t == u[k-1].t) {
			x2 = find(u[k-2].l, u[k-2].sw);
			printf("%d\n",x1>x2 ? x1 : x2);
			continue;
		}
		else if(k < n && u[k].t == u[k-1].t) {
			x2 = find(u[k].l, u[k].sw);
			printf("%d\n",x1<x2 ? x1 : x2);
			continue;
		}
		printf("%d\n",x1<x2 ? x1 : x2);
	}
	return 0;
}