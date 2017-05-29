#include <cstdio>
#include <algorithm>
using namespace std;
int o[1010];
int main() {
    int i, n;
    int sum = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&o[i]);
    sort(o,o+n);
    for(i=0;i<n;i++) {
        if (o[i]-1 <= sum) sum += o[i];
        else break;
    }
    printf("%d\n",sum + 1);
    return 0;
}