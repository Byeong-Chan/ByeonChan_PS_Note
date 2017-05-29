//
//  main.cpp
//  stringperiod
//
//  Created by 서병찬 on 2016. 8. 21..
//  Copyright © 2016년 서병찬. All rights reserved.
//

#include <cstdio>
#include <algorithm>
using namespace std;
int fail[1000100];
int min1[1000100];
char o[1000100];
int main() {
    int i, j, n;
    long long ans = 0;
    scanf("%d",&n);
    scanf("%s",o);
    
    for (i=1;i<=n;i++) min1[i] = i;
    min1[0] = 0x7fffffff;
    
    i = -1;
    j = 0;
    fail[0] = -1;
    while (j < n) {
        if (i == -1 || (i >= 0 && o[i] == o[j])) {
            i++;
            j++;
            
            fail[j] = i;
            
            min1[j] = min(min1[i], min1[j]);
            if (i > 0) ans += j - min1[j];
        }
        else i = fail[i];
    }
    printf("%lld\n",ans);
    return 0;
}