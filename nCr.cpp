int nCr(int n, int r)
{
	if(n < 0 or r < 0 or n < r)
		return 0 ;
	int num = f[n] ;         			
	int den = invf[r] * invf[n - r] ;
	den %= mod ;
	int res = num * den ;
	res %= mod ;
	return num ;
}
