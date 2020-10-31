// Problem : D. Zigzags
// Contest : Codeforces - Educational Codeforces Round 94 (Rated for Div. 2)
// URL : http://codeforces.com/contest/1400/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
 
/* winners never quit and quitters never win. */
 
#include<bits/stdc++.h>
using namespace std ;
 
#define int     long long int
#define pii     pair<int, int>
#define vi      vector<int>
#define vii     vector<pair<int, int>>
#define pb      push_back
#define all(a)  (a).begin(),(a).end()
#define f       first
#define s       second
#define endl    '\n'
#define mod     1000000007    		
 
void solve()
{
	int n ;
	cin >> n ;
	vi a(n) ;
	for(int i = 0 ; i < n ; i++)
		cin >> a[i] ;
	vi left(n + 1, 0) ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++)
	{
		vi right(n + 1, 0) ;
		for(int j = n - 1 ; j > i ; j--)
		{
			ans += left[a[j]] * right[a[i]] ;
			right[a[j]]++ ;
		}
		left[a[i]]++ ;
	}
	cout << ans << endl ;
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1 ;
    cin >> t ;
    while(t--)
    {
        solve() ;
    }
    return 0 ;
}
