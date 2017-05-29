#include <iostream>
#include <algorithm>
using namespace std;
int color[1001][3];
int dp[1001][3];
int main() {
	int i, j, n;
	scanf("%d",&n);
	for(i=0;i<n;i++) for(j=0;j<3;j++) scanf("%d",&color[i][j]);
	dp[0][0] = color[0][0];
	dp[0][1] = color[0][1];
	dp[0][2] = color[0][2];
	for(i=1;i<n;i++) {
		dp[i][0] = color[i][0] + min(dp[i-1][1], dp[i-1][2]);
		dp[i][1] = color[i][1] + min(dp[i-1][0], dp[i-1][2]);
		dp[i][2] = color[i][2] + min(dp[i-1][0], dp[i-1][1]);
	}
	printf("%d\n",min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2])));
	return 0;
}