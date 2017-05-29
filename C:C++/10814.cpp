#include <stdio.h>
#include <algorithm>
using namespace std;
struct bung {
	int age;
	int num;
}o[100011];
bool cmp(bung a, bung b) {
	if(a.age != b.age) return a.age < b.age;
	return a.num < b.num;
}
char name[100011][2101];
int n;
int main() {
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d %s",&o[i].age, name[i]);
		o[i].num = i;
	}
	sort(o,o+n,cmp);
	for(i=0;i<n;i++) printf("%d %s\n",o[i].age,name[o[i].num]);
	return 0;
}