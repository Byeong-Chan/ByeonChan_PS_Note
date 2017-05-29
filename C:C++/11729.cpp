#include <cstdio>
void hanoi(int size, int src, int wait, int dest) {
    if(size == 1) {
        printf("%d %d\n", src, dest);
        return;
    }
    hanoi(size-1, src, dest, wait);
    printf("%d %d\n", src, dest);
    hanoi(size-1, wait, src, dest);
}
int main() {
    int n;
    scanf("%d",&n);
    printf("%d\n",(1<<n)-1);
    hanoi(n, 1, 2, 3);
    return 0;
}