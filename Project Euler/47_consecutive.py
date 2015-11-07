import math;
primes = [2,3]

for i in range(5,10000, 2):
	cond = True;
	for j in range(0,len(primes)):
		if((i%primes[j]) == 0 ):
			cond = False;
			break;
	if(cond):
		primes.append(i);


def get_prime_factors(a):
	factors = [];
	if(a == 1):
		return [];
	if(a < primes[-1] and a in primes):
		factors.append(a);
		return factors;
	for j in range(0,len(primes)):
		if((a%primes[j]) == 0 ):
			factors.append(primes[j])
			return factors+get_prime_factors(a/primes[j]);
		if(primes[j] >= int(math.sqrt(a))+1):
			factors.append(a);
			return factors;


streak = 0;
for i in range(100000,1000000):
	if(i%100000 == 0):
		print i;
	length = len(set(get_prime_factors(i)));
	if(length == 4):
		streak+=1;
	else:
		streak = 0;
	if(streak == 4):
		print i;
		break;