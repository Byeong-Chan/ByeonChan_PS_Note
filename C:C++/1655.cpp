#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

int t[100002], h[100002];
int key[100002];
int index[200001];
int e = 0;
map<int, int> tx;
int main() {
	int n;
	int i;
	int x;
	int k;
	int d;
	int s;
	int le, ri;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",&x);
		t[i] = h[i] = x;
	}
	sort(h, h+n);
	tx[h[0]] = ++e;
	for(i=1;i<n;i++) if(tx[h[i]] == 0) tx[h[i]] = ++e;
	for(k=1;k<e;k<<=1);
	for(i=0;i<n;i++) {
		d = tx[t[i]];
		key[d] = t[i];
		t[i] = d;
	}
	for(i=0;i<n;i++) {
		d = k + t[i] - 1;
		index[d]++;
		s = i >> 1;
		while(d > 1) {
			d>>=1;
			index[d]++;
		}
		while(d < k) {
			le = d << 1;
			ri = le + 1;
			if(s - index[le] >= 0) {
				s -= index[le];
				d = ri;
			}
			else d = le;
		}
		printf("%d\n",key[d-k+1]);
	}
	return 0;
}