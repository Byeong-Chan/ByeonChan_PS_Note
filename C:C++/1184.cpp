#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;
map<int, short> dt[53][53];
int table[4][53][53];
int o[53][53];
int main() {
    int i, j, k, l, n;
    int m;
    long long ans = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) scanf("%d", &o[i][j]);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            table[0][i][j] = o[i][j] + table[0][i - 1][j] + table[0][i][j - 1] - table[0][i - 1][j - 1];
            table[1][i][n - j + 1] = o[i][n - j + 1] + table[1][i][n - j + 2] + table[1][i - 1][n - j + 1] - table[1][i - 1][n - j + 2];
            table[2][n - i + 1][j] = o[n - i + 1][j] + table[2][n - i + 2][j] + table[2][n - i + 1][j - 1] - table[2][n - i + 2][j - 1];
            table[3][n - i + 1][n - j + 1] = o[n - i + 1][n - j + 1] + table[3][n - i + 2][n - j + 1] + table[3][n - i + 1][n - j + 2] - table[3][n - i + 2][n - j + 2];
        }
    }
    for (i = n; i >= 1; i--) {
        for (j = n; j >= 1; j--) {
            for (k = n; k >= i; k--) {
                for (l = n; l >= j; l--) {
                    m = table[3][i][j] - table[3][k+1][j] - table[3][i][l+1] + table[3][k+1][l+1];
                    dt[i][j][m]++;
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            for (k = 1; k <= i; k++) {
                for (l = 1; l <= j; l++) {
                    m = table[0][i][j] - table[0][k-1][j] - table[0][i][l-1] + table[0][k-1][l-1];
                    if (dt[i+1][j+1].find(m) != dt[i+1][j+1].end()) ans += dt[i+1][j+1][m];
                }
            }
        }
    }
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) dt[i][j].clear();
    for (i = n; i >= 1; i--) {
        for (j = 1; j <= n; j++) {
            for (k = n; k >= i; k--) {
                for (l = 1; l <= j; l++) {
                    m = table[2][i][j] - table[2][k+1][j] - table[2][i][l-1] + table[2][k+1][l-1];
                    dt[i][j][m]++;
                }
            }
        }
    }
    for (i = 1; i <= n; i++) {
        for (j = n; j >= 1; j--) {
            for (k = 1; k <= i; k++) {
                for (l = n; l >= j; l--) {
                    m = table[1][i][j] - table[1][k-1][j] - table[1][i][l+1] + table[1][k-1][l+1];
                    if (dt[i+1][j-1].find(m) != dt[i+1][j-1].end()) ans += dt[i+1][j-1][m];
                }
            }
        }
    }
    printf("%lld", ans);
    return 0;
}