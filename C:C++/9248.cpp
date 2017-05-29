#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int gap;
int n;
int tmp[500003];
int o[500003];
int lcp[500003];
int sa[500003];
int R[500003];
char s[500003];
bool cmp(int a, int b) {
	if(o[a] != o[b]) return o[a] < o[b];
	a += gap;
	b += gap;
	return (a<n && b<n) ? o[a] < o[b] : a > b;
}
void makeSA() {
	int i;
	for(i=0;i<n;i++) o[i] = s[i]-97, sa[i] = i;
	for(gap=1;;gap<<=1) {
		sort(sa, sa+n, cmp);
		tmp[0] = 0;
		for(i=0;i<n-1;i++) tmp[i+1] = tmp[i] + cmp(sa[i], sa[i+1]);
		if(tmp[n-1] == n-1) break;
		for(i=0;i<n;i++) o[sa[i]] = tmp[i];
	}
}
void makeLCP() {
	int i, j, k = 0;
	for(i=0;i<n;i++) R[sa[i]] = i;
	for(i=0;i<n;lcp[R[i++]] = k) {
		for(k?k--:0, j=(R[i]?sa[R[i]-1]:n);i+k<n&&j+k<n&&s[i+k]==s[j+k];k++);
	}
}
int main() {
	int i;
	scanf("%s",s);
	n = strlen(s);
	makeSA();
	makeLCP();
	for(i=0;i<n;i++) printf("%d ",sa[i]+1);
	printf("\nx ");
	for(i=1;i<n;i++) printf("%d ",lcp[i]);
	return 0;
}