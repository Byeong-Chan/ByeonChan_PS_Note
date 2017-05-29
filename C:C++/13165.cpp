#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
vector<long long> A[256];
long long r[15][258];
long long p[258], q[258];
int main() {
    int i, j, k, l;
    int n, m;
    int x, y, z, w;
    int ans = 0;
    scanf("%d %d",&n, &m);
    srand(31241331);
    for(i=0;i<15;i++) {
        for(j=0;j<n;j++) {
            r[i][j] = rand() & 1;
        }
    }
    for(i=0;i<n;i++) {
        A[i].resize(m);
        for(j=0;j<m;j++) scanf("%lld",&A[i][j]);
    }
    for(k=0;k<m;k++) {
        if(k + 3*n > m) break;
        x = k;
        y = x + n;
        z = y + n;
        w = z + n;
        for(l=0;l<15;l++) {
            for(i=0;i<n;i++) {
                p[i] = 0;
                for(j=y;j<z;j++) p[i] += A[i][j] * r[l][j-y];
            }
            for(i=0;i<n;i++) {
                q[i] = 0;
                for(j=x;j<y;j++) q[i] += A[i][j] * p[j-x];
            }
            for(i=0;i<n;i++) {
                p[i] = 0;
                for(j=z;j<w;j++) p[i] += A[i][j] * r[l][j-z];
            }
            for(i=0;i<n;i++) if(p[i] != q[i]) break;
            if(i < n) break;
        }
        if(l == 15) {
            ans++;
            k += n * 3 - 1;
        }
    }
    printf("%d\n",ans*n*n*3);
    return 0;
}