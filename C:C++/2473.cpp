#include <stdio.h>
#include <algorithm>
#define _abs(x) ((x) < 0 ? -(x) : (x))
using namespace std;
long long o[5002];
int main() {
	int i, n;
	int a, b;
	long long d;
	long long min1 = 0x7fffffff;
	long long tmp[3];
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%lld",o+i);
	std::sort(o,o+n);
	min1 *= 2;
	for(i=0;i<n-2;i++) {
		a = i + 1;
		b = i + 2;
		while (b < n) {
			d = o[i] + o[a] + o[b];
			if(min1 > _abs(d)) {
				min1 = _abs(d);
				tmp[0] = i;
				tmp[1] = a;
				tmp[2] = b;
			}
			if(d > 0) break;
			else b++;
		}
		if(b == n) b--;
		while (a < n && b > a) {
			a++;
			while(1) {
				if(b <= a) break;
				d = o[i] + o[a] + o[b];
				if(min1 > _abs(d)) {
					min1 = _abs(d);
					tmp[0] = i;
					tmp[1] = a;
					tmp[2] = b;
				}
				if(d <= 0) break;
				b--;
			}
		}
	}
	printf("%lld %lld %lld",o[tmp[0]],o[tmp[1]],o[tmp[2]]);
	return 0;
}