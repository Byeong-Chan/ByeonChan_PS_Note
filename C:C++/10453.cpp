#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int index1[262144];
char o[100001], u[100001];
vector<int> s[2];
int main() {
	int t;
	int n, k;
	int i;
	int d;
	long long ans;
	scanf("%d",&t);
	while(t--) {
		scanf("%s %s", o, u);
		n=strlen(o);
		for(k=1;k<n;k<<=1);
		for(i=k;i<k+n;i++) {
			d = i;
			while(d > 0) {
				index1[d]++;
				d >>= 1;
			}
			if(o[i-k] == 'a') s[0].push_back(i);
			if(o[i-k] == 'b') s[1].push_back(i);
		}
		ans = 0;
		for(i=n-1;i>=0;i--) {
			if(u[i] == 'a') {
				d = s[0].back();
				s[0].pop_back();
			}
			if(u[i] == 'b') {
				d = s[1].back();
				s[1].pop_back();
			}
			while(d > 0) {
				index1[d]--;
				if((d&1) == 0) ans += index1[d+1];
				d >>= 1;
			}
		}
		printf("%lld\n",ans);
	}
    return 0;
}