#include <stdio.h>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
map<string, int> o;
long long p[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
int main() {
	string s;
	char tmp[13];
	long long ans = 0;
	o["black"] = 0;
	o["brown"] = 1;
	o["red"] = 2;
	o["orange"] = 3;
	o["yellow"] = 4;
	o["green"] = 5;
	o["blue"] = 6;
	o["violet"] = 7;
	o["grey"] = 8;
	o["white"] = 9;

	scanf("%s", tmp);
	s = tmp;
	ans = o[s];
	ans = (ans << 3) + (ans << 1);

	scanf("%s", tmp);
	s = tmp;
	ans += o[s];

	scanf("%s", tmp);
	s = tmp;
	ans *= p[o[s]];
	printf("%lld", ans);
	return 0;
}