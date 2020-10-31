#include<bits/stdc++.h>
#define ll int
using namespace std;

bool bins(ll v[],ll lo,ll hi,ll x)
{
	while(lo<=hi)
	{
    ll mid=lo + (hi-lo)/2;
    if(v[mid]==x)
    return true;
    if(v[mid]<x)
    lo=mid+1;
    if(v[mid]>x)
    hi=mid-1;
    }
    return false;
    
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll v[5];
    v[0]=2;
    v[1]=3;
    v[2]=10;
    v[3]=32;
    v[4]=45;
    
    //Array must be in sorted order
    
    if(bins(v,0,4,10))
    cout << "Contains 10\n";
    else
    cout << "Does not contain 10\n";

    if(bins(v,0,4,22))
    cout << "Contains 22\n";
    else
    cout << "Does not contain 22\n";
    
    return 0;
}