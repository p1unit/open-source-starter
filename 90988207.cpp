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
 
int a, b, p, f, wta, wtb ;
 
 
void solve()
{
	cin >> p >> f ;
	cin >> a >> b ;
	cin >> wta >> wtb ;
	if(wta > wtb)
	{
		swap(a, b) ;
		swap(wta, wtb) ;
	}
	if(!a)
	{
		swap(a, b) ;
		swap(wta, wtb) ;
	}
	int ans = 0 ;
	
	//pii r = {0, 0} ;
	for(int i = 0 ; i <= a ; i++)
	{
		int aa = a, bb = b ;
		int pp = p, ff = f ;
		if(i * wta > p)
			break ;
		
		pp -= i * wta ;
		int res = i ;
		int q2 = pp / wtb ; q2 = min(q2, bb) ;
		aa -= i, bb -= q2 ; res += q2 ;
		
		int q1 = ff / wta ; q1 = min(q1, aa) ;
		ff -= q1 * wta ; res += q1 ;
		q2 = ff / wtb ; q2 = min(q2, bb) ;
		res += q2 ;
		ans = max(res, ans) ;
	}
	swap(p, f) ;
	for(int i = 0 ; i <= a ; i++)
	{
		int aa = a, bb = b ;
		int pp = p, ff = f ;
		if(i * wta > p)
			break ;
		
		pp -= i * wta ;
		int res = i ;
		int q2 = pp / wtb ; q2 = min(q2, bb) ;
		aa -= i, bb -= q2 ; res += q2 ;
		
		int q1 = ff / wta ; q1 = min(q1, aa) ;
		ff -= q1 * wta ; res += q1 ;
		q2 = ff / wtb ; q2 = min(q2, bb) ;
		res += q2 ;
		ans = max(res, ans) ;
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
