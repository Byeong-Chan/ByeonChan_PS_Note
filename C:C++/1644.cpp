#include <stdio.h>
#include <list>
#include <algorithm>
using namespace std;
bool chk[4000001];
list<int> q;
int main() {
	int n;
	int i, j;
	int sum = 0;
	int ans = 0;
	scanf("%d",&n);
	sum += 2;
	q.push_back(2);
	if(sum == n) ans++;

	for(i=3;i<=n;i+=2) {
		if(!chk[i]) {
			for(j=i*2;j<=n;j+=i) chk[j] = true;
			sum += i;
			q.push_back(i);
			while(sum > n) {
				sum -= q.front();
				q.pop_front();
			}
			if(sum == n) ans++;
		}
	}
	printf("%d",ans);
	return 0;
}