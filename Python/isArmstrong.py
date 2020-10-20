""" 
Input : 153
Output : Yes
153 is an Armstrong number.
1*1*1 + 5*5*5 + 3*3*3 = 153
"""

def isArmstrong(x): 
	
	n = x 
	temp = x 
	sum1 = 0
	
	while (temp != 0): 
		r = temp % 10
		sum1 = sum1 + r**3 
		temp = temp // 10


	return (sum1 == x) 

# Driver code 
x = 153
print(isArmstrong(x)) 


