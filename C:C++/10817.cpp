#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	if (x > y) swap(x, y);
	if (x > z) swap(x, z);
	if (y > z) swap(y, z);
	printf("%d", y);
	return 0;
}