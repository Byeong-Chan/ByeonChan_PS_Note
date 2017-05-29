#include <stdio.h>
#include <algorithm>
using namespace std;
int o[1003];
int main() {
    int i, n;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&o[i]);
    sort(o,o+n);
    for(i=0;i<n;i++) printf("%d\n",o[i]);
    return 0;
}