#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int n, m;
    scanf("%d",&n);
    vector<vector<int> > o(n, vector<int>());
    for(int i=0;i<n;i++) {
        int k;
        scanf("%d",&k);
        o[i].resize(k);
        for(int j=0;j<k;j++) scanf("%d",&o[i][j]);
    }
    scanf("%d",&m);
    vector<int> chk(52);
    for(int i=0;i<m;i++) {
        int p;
        int cnt = 0;
        scanf("%d",&p);
        for(int j=0;j<p;j++) {
            int q;
            scanf("%d",&q);
            chk[q] = i + 1;
        }
        for(int j=0;j<n;j++) {
            if(o[j].size() > p) continue;
            cnt++;
            for(auto &v : o[j]) {
                if(chk[v] != i + 1) {
                    cnt--;
                    break;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}