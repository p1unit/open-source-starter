#include<bits/stdc++.h>
#define ll long long int
#define vl vector<ll>
#define pb push_back
using namespace std;


struct segtree{
    ll size;
    vl sums;
    void init(int n)
    {
        size=1;
        while(size<n)
        {
            size*=2;
        }
        sums.assign(2*size,0LL);
    }
    
    void build(vl &a,ll x,ll lx,ll rx)
    {
        if(rx-lx==1)
        {
            if(lx<(ll)a.size())
            {
                sums[x]=a[lx];
            }
            return;
        }
        ll m=(lx+rx)/2;
        build(a,2*x + 1,lx,m);
        build(a,2*x + 2,m,rx);
        sums[x]=min(sums[2*x + 1],sums[2*x + 2]);
    
    }
    
    void build(vl &a)
    {
        build(a,0,0,size);
    }
    
    void set(ll i,ll v,ll x,ll lx,ll rx)
    {
        if(rx-lx==1)
        {
        sums[x]=v;
        return;
        }
        ll m=(lx+rx)/2;
        if(i<m)
        set(i,v,2*x + 1,lx,m);
        else
        set(i,v,2*x + 2,m,rx);
        sums[x]=min(sums[2*x + 1],sums[2*x + 2]);
    }
    
    void set(int i,int v)
    {
        set(i,v,0,0,size);
    }
    
    ll minim(ll l,ll r,ll x,ll lx,ll rx)
    {
        if(lx>=r || l>=rx)
        return 10000000000;
        if(lx>=l && rx<=r)
        return sums[x];
        ll m=(lx+rx)/2;
        ll s1=minim(l,r,2*x + 1,lx,m);
        ll s2=minim(l,r,2*x + 2,m,rx);
        return min(s1 , s2);
    }
    
    ll minim(ll l,ll r)
    {
        return minim(l,r,0,0,size);
    }
    
};



int main()
{
    segtree st;
    st.init(5);
    vl a={2,4,7,5,1};
    st.build(a); //creates a segment tree containing elements from vector a
    cout << st.minim(0,4) << "\n"; //prints the minimum from index 0(inclusive) to index 4(exclusive), output : "2" min(2,4,7,5)
    st.set(0,10); //sets the element at index 0 to 10
    cout << st.minim(0,4); //again prints the sum from index 0(inclusive) to index 4(exclusive), output : "4" min(10,4,7,5)
    return 0;
}