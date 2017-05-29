#include <stdio.h>
int u[110000];
bool a[2][2] = {true, false, false, true};
bool _prev, _next;
int main()
{
	int i, n, e = 0;
	bool sw;
	int max1 = 0, tmp;
	scanf("%d",&n);

	scanf("%d",&sw);
	_prev = a[0][sw];
	u[e++] = 1;
	for(i=1;i<n;i++) {
		scanf("%d",&sw);
		_next = a[i&1][sw];
		if(_next == _prev) u[e-1]++;
		else {
			u[e]++;
			e++;
		}
		_prev = _next;
	}
	for(i=0;i<3;i++) {
		if(i == e) break;
		max1 += u[i];
	}
	for(i=1;i<e-2;i++) {
		tmp = u[i] + u[i+1] + u[i+2];
		if(max1 < tmp) max1 = tmp;
	}
	printf("%d",max1);
	return 0;
}