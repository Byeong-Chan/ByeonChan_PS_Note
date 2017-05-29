#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;
int o[100010];
int main() {
	int n, i;
	long long ans = 0;
	scanf("%d", &n);
	for (i = 0; i<n; i++) scanf("%d", &o[i]);
	sort(o, o + n, greater<int>());
	for (i = 0; i<n; i++) if (i % 3 != 2) ans += o[i];
	printf("%lld\n", ans);
	return 0;
}