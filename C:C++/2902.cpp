//
//  main.cpp
//  stringperiod
//
//  Created by 서병찬 on 2016. 8. 21..
//  Copyright © 2016년 서병찬. All rights reserved.
//

#include <cstdio>
#include <cstring>
char o[110];
int main() {
    int i, n;
    scanf("%s",o);
    n = strlen(o);
    printf("%c",o[0]);
    for(i=1;i<n;i++) if(o[i-1] == '-') printf("%c",o[i]);
    printf("\n");
    return 0;
}