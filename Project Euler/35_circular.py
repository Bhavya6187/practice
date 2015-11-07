import math;
primes = [2,3]

for i in range(5,1000, 2):
	cond = True;
	for j in range(0,len(primes)):
		if((i%primes[j]) == 0 ):
			cond = False;
			break;
	if(cond):
		primes.append(i);
def is_prime(a):
	for j in range(0,len(primes)):
		if((a%primes[j]) == 0 ):
			return False;
		if(primes[j] >= int(math.sqrt(a))+1):
			return True;
	return True;
def rotate_int(a):
	arr = []
	ind = [];
	temp = 1;
	while a > 0:
		arr.insert(0,a%10)
		a/=10
		ind.insert(0,temp)
		temp *= 10;
	for i in range(0,len(arr)):
		temp = arr.pop()
		arr.insert(0,temp)
		number = 0;
		for j in range(0,len(arr)):
			number = number + (ind[j]*arr[j])
		if(not is_prime(number)):
			return False;
	return True;

count = 0;
for i in range(2,1000000):
	if(is_prime(i) and rotate_int(i)):
		print i
		count += 1
print count