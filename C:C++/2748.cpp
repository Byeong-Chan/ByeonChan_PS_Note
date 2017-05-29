#include <iostream>
using namespace std;
long long memo[100] = {0, 1, 0,};
long long f(int n) {
	if(n == 0) return 0;
	if(n == 1) return 1;
	if(memo[n] != 0) return memo[n];
	return memo[n] = f(n-1) + f(n-2);
}

int main() {
	int n;
	scanf("%d",&n);
	printf("%lld",f(n));
	return 0;
}