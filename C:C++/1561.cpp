#include <stdio.h>
int o[10001];
int main() {
	int i;
	int n;
	long long st = 1, ed = 0, mid;
	long long e = 0, m;
	scanf("%lld %d",&m,&n);
	for(i=0;i<n;i++) {
		scanf("%d",&o[i]);
		ed = o[i] > ed ? o[i] : ed;
	}
	ed *= m;
	while(st < ed) {
		mid = (st + ed) / 2;
		e = 0;
		for(i=0;i<n;i++) e += mid / o[i] + 1;
		if(e >= m) ed = mid;
		else st = mid + 1;
	}
	e = 0;
	for(i=0;i<n;i++) {
		e += (ed-1) / o[i] + 1;
	}
	m -= e;
	for(i=0;i<n;i++) {
		if(ed % o[i] == 0) {
			m--;
			if(m == 0) {
				printf("%d",i+1);
				break;
			}
		}
	}
	return 0;
}