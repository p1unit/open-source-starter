int f[N], invf[N] ;

void comp()
{
	f[0] = f[1] = 1 ;
	invf[0] = invf[1] = 1 ;
	for(int i = 2 ; i < N ; i++)
	{
		f[i] = (i * f[i-1]) % mod ;
		invf[i] = modExpo(f[i], mod - 2) ;
	}
}
