#include <stdio.h>
#include <string.h>
struct bung {
	int moth;
	int son;
	char p;
}o[700001];
char s[600001];
int main() {
	int i, n, m;
	int e;
	char x;
	char _in;
	int now, pre, nex;
	scanf("%s",s);
	n = strlen(s);

	o[0].moth = -1;
	o[0].son = 2;
	o[0].p = 0;
	for(i=2;i<=n+1;i++) {
		if(i > 2) o[i].moth = i-1;
		else o[i].moth = 0;
		o[i].son = i+1;
		o[i].p = s[i-2];
	}

	o[1].moth = n+1;
	o[n+1].son = 1;

	e = n+1;
	now = n+1;

	scanf("%d\n",&m);
	while(m--) {
		scanf("%c\n",&_in);
		if(_in == 'P') {
			scanf("%c\n",&x);
			pre = now;
			nex = o[now].son;

			e++;
			o[e].p = x;
			o[e].moth = pre;
			o[e].son = nex;

			o[nex].moth = e;
			o[pre].son = e;

			now = e;
		}
		if(_in == 'B') {
			if(now == 0) continue;

			pre = o[now].moth;
			nex = o[now].son;

			o[pre].son = nex;
			if(nex != -1) o[nex].moth = pre;
			o[now].moth = o[now].son = o[now].p = 0;
			now = pre;
		}
		if(_in == 'L') {
			if(now != 0) now = o[now].moth;
		}
		if(_in == 'D') {
			if(o[now].son != 1) now = o[now].son;
		}
	}
	now = 0;
	while(o[now].son != 1) {
		now = o[now].son;
		printf("%c",o[now].p);
	}
	return 0;
}