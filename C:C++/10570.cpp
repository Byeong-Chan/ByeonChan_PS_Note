#include<iostream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
void test_case()
{
   int n;
   map<int, int> m;
   cin >> n;
   int x; 
   int arr[2000];
   int cnt = 0;
   for (int i = 0; i < n; i++)
   {
      cin >> x;
      bool check = false;
      for (int j = 0; j < cnt; j++)
      {
         if (arr[j] == x)
         {
            check = true;
            break;
         }
      }
      if (!check)
         arr[cnt++] = x;
      m[x]++;
   }
   sort(arr, arr + cnt);
   int maxv = -1;
   int ans;
   for (int i = 0; i < cnt; i++)
   {
      if (m[arr[i]] > maxv)
      {
         maxv = m[arr[i]];
         ans = arr[i];
      }
   }
   cout << ans << endl;
}
int main()
{
   int t;
   cin >> t;
   while (t--)
      test_case();
   return 0;
}