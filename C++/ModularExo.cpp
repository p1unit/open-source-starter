int modExpo(int a, int b, int mod = MOD)
{
    int res = 1 ;
    while(b > 0)
    {
        if(b & 1)
        {
            res = res * a % mod ;
        }
        a = a * a % mod ;
        b >>= 1 ;
    }
    return res ;
}
