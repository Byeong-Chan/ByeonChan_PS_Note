#include <stdio.h>
#include <list>
#include <algorithm>
using namespace std;
list<int> q;
int main() {
	int n, m;
	int x;
	int ans = 0;
	int sum = 0;
	scanf("%d %d",&n,&m);
	while(n--) {
		scanf("%d",&x);
		sum += x;
		q.push_back(x);

		while(sum > m) {
			sum -= q.front();
			q.pop_front();
		}
		if(sum == m) ans++;
	}
	printf("%d",ans);
	return 0;
}