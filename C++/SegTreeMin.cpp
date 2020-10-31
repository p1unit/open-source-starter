#include<bits/stdc++.h>
#define ll long long int
#define vl vector<ll>
#define pl pair<ll,ll>
#define vp vector<pl>
#define pb push_back
#define F first
#define S second
using namespace std;


struct segtree{
    ll size;
    vp sums;
    void init(int n)
    {
        size=1;
        while(size<n)
        {
            size*=2;
        }
        sums.assign(2*size,{0LL,0LL});
    }
    
    void build(vl &a,ll x,ll lx,ll rx)
    {
        if(rx-lx==1)
        {
            if(lx<(ll)a.size())
            {
                sums[x].F=a[lx];
                sums[x].S=1;
            }
            return;
        }
        ll m=(lx+rx)/2;
        build(a,2*x + 1,lx,m);
        build(a,2*x + 2,m,rx);
        sums[x].F=min(sums[2*x + 1].F,sums[2*x + 2].F);
        if(sums[2*x + 1].F<sums[2*x + 2].F)
        sums[x].S=sums[2*x + 1].S;
        else if(sums[2*x + 1].F>sums[2*x + 2].F)
        sums[x].S=sums[2*x + 2].S;
        else
        sums[x].S=sums[2*x + 1].S + sums[2*x + 2].S;
    }
    
    void build(vl &a)
    {
        build(a,0,0,size);
    }
    
    void set(ll i,ll v,ll x,ll lx,ll rx)
    {
        if(rx-lx==1)
        {
        sums[x].F=v;
        sums[x].S=1;
        return;
        }
        ll m=(lx+rx)/2;
        if(i<m)
        set(i,v,2*x + 1,lx,m);
        else
        set(i,v,2*x + 2,m,rx);
        sums[x].F=min(sums[2*x + 1].F,sums[2*x + 2].F);
        if(sums[2*x + 1].F<sums[2*x + 2].F)
        sums[x].S=sums[2*x + 1].S;
        else if(sums[2*x + 1].F>sums[2*x + 2].F)
        sums[x].S=sums[2*x + 2].S;
        else
        sums[x].S=sums[2*x + 1].S + sums[2*x + 2].S;
    }
    
    void set(int i,int v)
    {
        set(i,v,0,0,size);
    }
    
    pl minim(ll l,ll r,ll x,ll lx,ll rx)
    {
        if(lx>=r || l>=rx)
        return {10000000000,0};
        if(lx>=l && rx<=r)
        return sums[x];
        ll m=(lx+rx)/2;
        pl s1=minim(l,r,2*x + 1,lx,m);
        pl s2=minim(l,r,2*x + 2,m,rx);
        if(s1.F==s2.F)
        return {s1.F,s1.S + s2.S};
        return min(s1 , s2);
    }
    
    pl minim(ll l,ll r)
    {
        return minim(l,r,0,0,size);
    }
    
};



int main()
{
    segtree st;
    st.init(5);
    vl a={3,4,3,5,2};
    st.build(a);
    cout << "Minimum element: " << st.minim(0,4).F << ", Frequency: " << st.minim(0,4).S << "\n";
    st.set(1,2);
    cout << "Minimum element: " << st.minim(0,5).F << ", Frequency: " << st.minim(0,5).S << "\n";
    return 0;
}