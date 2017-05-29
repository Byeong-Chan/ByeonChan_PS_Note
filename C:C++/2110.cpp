#include <stdio.h>
#include <algorithm>
using namespace std;
int o[200001];
int main() {
	int n, m;
	int st = 1, ed = 0, mid;
	int i;
	int t;
	int tmp;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++) {
		scanf("%d",&o[i]);
		ed = ed < o[i] ? o[i] : ed;
	}
	sort(o,o+n);
	while(st < ed) {
		mid = (st + ed) / 2;
		t = 1;
		tmp = 0;
		for(i=1;i<n;i++) {
			if(o[i] - o[tmp] > mid) {
				t++;
				tmp = i;
			}
		}
		if(t < m) ed = mid;
		else st = mid + 1;
	}
	printf("%d",ed);
	return 0;
}