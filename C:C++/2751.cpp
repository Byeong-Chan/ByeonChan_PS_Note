#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1000010];
void quick(int l, int r) {
	int pivot = (l + r) / 2;
	int lp = l+1, rp = r; 
	if(l >= r) return;
	else if(r - l == 1) {
		if(arr[l] > arr[r]) swap(arr[l], arr[r]);
		return;
	}
	
	swap(arr[l], arr[pivot]);
	while(lp <= rp) {
		if(arr[lp] < arr[l]) lp++;
		else if(arr[lp] == arr[l]) {
			if((rp - pivot) > (pivot - lp)) {
				if(arr[rp] <= arr[l]) {
					swap(arr[lp], arr[rp]);
					rp--;
				}
				else rp--;
			}
			else lp++;
		}
		else if(arr[rp] <= arr[l]) {
			swap(arr[lp], arr[rp]);
			rp--;
		}
		else rp--;
	}
	swap(arr[l], arr[rp]);
	quick(l, rp-1);
	quick(rp+1, r);
}
int main() {
	int i;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&arr[i]);
	quick(0, n-1);
	for(i=0;i<n;i++) printf("%d\n",arr[i]);
	return 0;
}