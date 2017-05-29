#include <stdio.h>
#include <string.h>
int table[42];
int main() {
    int k;
    int n;
    int i;
    scanf("%d",&k);
    while(k--) {
        scanf("%d", &n);
        memset(table, 0, sizeof(table));
        table[n] = 1;
        for(i=n;i>=2;i--) {
        	table[i-1] += table[i];
        	table[i-2] += table[i];
        }
        printf("%d %d\n",table[0],table[1]);
    }
}