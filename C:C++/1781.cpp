#include <stdio.h>
#include <algorithm>
#include <functional>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > q;
struct bung {
	int x;
	int y;
}o[200100];
bool cmp(bung a, bung b) {
	return a.x < b.x;
}
int main() {
	int i, n;
	int k = 0;
	long long ans = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++) scanf("%d %d", &o[i].x, &o[i].y);
	sort(o, o + n, cmp);
	for (i = 0; i < n; i++) {
		if(q.size() > 0) while (q.size() >= o[i].x && q.top() < o[i].y) q.pop();
		if (q.size() < o[i].x) q.push(o[i].y);
	}
	while (q.size()) {
		ans += q.top();
		q.pop();
	}
	printf("%lld", ans);
	return 0;
}