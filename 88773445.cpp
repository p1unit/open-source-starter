// Problem : A. PolandBall and Hypothesis
// Contest : Codeforces - 8VC Venture Cup 2017 - Elimination Round
// URL : https://codeforces.com/problemset/problem/755/A
 
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
 
bool prime(int n)
{
	for(int i = 2 ; i * i <= n ; i++)
	{
		if(n % i == 0)
			return false ;
	}
	return true ;
}
 
void solve()
{
	int n ;
	cin >> n ;
	
	for(int i = 1 ; i < 1001 ; i++)
	{
		if(not prime(n * i + 1))
		{
			cout << i ;
			return ;
		}
	}
}
 
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1 ;
    //cin >> t ;
    while(t--)
    {
        solve() ;
    }
    return 0 ;
}
