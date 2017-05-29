#include <cstdio>
#include <vector>
using namespace std;
int main() {
    int i, j, l;
    int n, m, k;
    scanf("%d %d",&n,&m);
    vector<vector<int> > a(n, vector<int>(m));
    for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%d",&a[i][j]);
    
    scanf("%*d %d",&k);
    vector<vector<int> > b(m, vector<int>(k));
    for(i=0;i<m;i++) for(j=0;j<k;j++) scanf("%d",&b[i][j]);
    
    vector<vector<int> > ans(n, vector<int>(k, 0));
    for(i=0;i<n;i++) for(j=0;j<k;j++) for(l=0;l<m;l++) ans[i][j] += a[i][l] * b[l][j];
    for(i=0;i<n;i++) {
        for(j=0;j<k;j++) printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}