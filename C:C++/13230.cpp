#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int wrong[4];
char o[110], u[110];
int main() {
    int i, j, n;
    int m;
    int ans;
    int tmp;
    scanf("%d",&n);
    for(j=0;j<n;j++) {
        ans = 0;
        scanf("%s",o);
        scanf("%s",u);
        if(strlen(o) != strlen(u)) {
            printf("Case %d: -1\n",j+1);
            wrong[0] = wrong[1] = wrong[2] = wrong[3] = 0;
            continue;
        }
        m = (int)strlen(o);
        for(i=0;i<m;i++) {
            if(o[i] != u[i]) {
                if(o[i] == '?') {
                    if(u[i] == '0') wrong[0]++;
                    if(u[i] == '1') wrong[1]++;
                }
                else if(o[i] == '1') wrong[2]++;
                else wrong[3]++;
            }
        }
        if(wrong[2] > wrong[3]) {
            if(wrong[2] - wrong[3] > wrong[1]) {
                printf("Case %d: -1\n",j+1);
                wrong[0] = wrong[1] = wrong[2] = wrong[3] = 0;
                continue;
            }
            tmp = wrong[2] - wrong[3];
            wrong[1] -= tmp;
            
            ans += tmp;
            wrong[3] = wrong[2];
        }
        if(wrong[3] > wrong[2]) {
            ans += wrong[3] - wrong[2];
            wrong[3] = wrong[2];
        }
        if(wrong[2] == wrong[3]) {
            ans += wrong[2];
            wrong[2] = 0;
            wrong[3] = 0;
        }
        ans += wrong[0] + wrong[1];
        wrong[0] = wrong[1] = wrong[2] = wrong[3] = 0;
        printf("Case %d: %d\n",j+1,ans);
    }
    return 0;
}


/*
 ? 0     0
 ? 1     1
 1 0     2
 0 1     3
*/