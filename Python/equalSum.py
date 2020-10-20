# equalSum
# input: a=[1,5,11,5]
# Output: True 
# Explain : [1,5,5] and [11] is equal


a=[1,5,11,9,4]
sm=sum(a)
t=[[True if i==0 else False for i in range(sm//2+1)] for _ in range(len(a)+1)]
if sm%2!=0:
	print('False')

else:

	for i in range(1,len(a)+1):
		for j in range(1,sm//2+1):
			if a[i-1]<=j:
				t[i][j] = t[i-1][j] or t[i-1][j-a[i-1]]
			else:
				t[i][j] = t[i-1][j]

	if t[len(a)][sm//2]:
		print("True")
	else:
		print("False")







