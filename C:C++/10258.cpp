#include <stdio.h>
#include <string.h>
typedef long long ll;
int n;
char inp[33];
bool a[33], b[33];
ll x[33];
ll e;
void _in() {
	scanf("%s",inp);
	n = strlen(inp);
}
void solv() {
	int i, k;
	int first1, last1;
	bool sw = false;
	for(i=0;i<n;i++) {
		k = n - i - 1;
		a[k] = inp[i] - '0';
		if(a[k] != sw) {
			b[k] = sw;
			if(sw == false) sw = true;
		}
		else {
			b[k] = a[k];
			if(sw == true) sw = false;
		}
	}
	last1 = first1 = -1;
	for(i=0;i<n;i++) {
		if(a[i] != b[i]) {
			a[i] = b[i];
			e += 1;
			if(last1 > -1) {
				e += x[last1];
				a[last1] = false;
				last1 = -1;
			}
		}
		if(a[i] == true) {
			last1 = first1;
			first1 = i;
		}
	}
	e += x[first1];
}
int main() {
	int m;
	int i;
	ll d;
	x[0] = 1;
	for(i=1, d = 2;i<=31;i++, d <<= 1) x[i] = x[i-1] + d;
	scanf("%d",&m);
	while(m--) {
		_in();
		e = 0;
		solv();
		printf("%lld\n",e);
	}
	return 0;
}