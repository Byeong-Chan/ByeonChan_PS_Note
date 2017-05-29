#include <cstdio>
int main() {
    long long n;
    scanf("%lld", &n);
    if (n % 5 == 0 || n % 5 == 2) printf("CY");
    else printf("SK");
    return 0;
}