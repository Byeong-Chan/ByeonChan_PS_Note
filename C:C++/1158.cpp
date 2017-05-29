#include <stdio.h>
int _tree[21000];
int o[5100];
int main() {
	int i;
	int k;
	int key;
	int n, m;
	int _next;
	int _front;
	scanf("%d %d",&n, &m);
	m--;
	for(k=1;k<n;k<<=1);
	for(i=1;i<=n;i++) {
		key = k+i-1;
		while(key > 0) {
			_tree[key]++;
			key /= 2;
		}
	}
	_next = 0;
	printf("<");
	for(i=0;i<n;i++) {
		_next += m;
		_next %= _tree[1];
		key = 1;
		_front = _next;
		_tree[key]--;
		while(key < k) {
			key *= 2;
			if(_tree[key] > _front) {
				_tree[key]--;
				continue;
			}
			_front -= _tree[key];
			key++;
			_tree[key]--;
		}
		printf("%d",key - k + 1);
		if(i < n-1) printf(", ");
	}
	printf(">");
	return 0;
}