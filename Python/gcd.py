def gcd1(a,b):
  if not a:return b
  else: return gcd(b%a,a)


def gcd2(a,b):
    while b:a,b=b,a%b
    return a

