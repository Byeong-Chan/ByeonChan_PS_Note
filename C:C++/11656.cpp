#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char o[1010];
short gap = 1;
short chk[1010];
short tmp[1010];
short sa[1010];
short n;
bool cmp(int a, int b) {
	if (chk[a] != chk[b]) return chk[a] < chk[b];

	int x = a + gap, y = b + gap;
	return x < n && y < n ? chk[x] < chk[y] : a > b;
}
void SAsort() {
	int i;
	for (i = 0; i < n; i++) {
		chk[i] = o[i] - 96;
		sa[i] = i;
	}
	for (;; gap <<= 1) {
		sort(sa, sa + n, cmp);
		tmp[0] = 1;
		for (i = 1; i < n; i++) tmp[i] = tmp[i - 1] + cmp(sa[i - 1], sa[i]);
		if (tmp[n - 1] == n) break;
		for (i = 0; i < n; i++) chk[sa[i]] = tmp[i];
	}
}
int main() {
	int i;
	fgets(o, 1010, stdin);
	n = strlen(o);
	if (o[n - 1] == '\n') o[--n] = 0;
	SAsort();
	for (i = 0; i < n; i++) puts(o + sa[i]);
	return 0;
}