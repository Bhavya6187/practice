def get_primes(n):
    """
    Get all the primes smaller than n
    """
    primes = [0] * n
    for i in xrange(2, n):
        if primes[i] == 0:
            yield i
        else:
            continue
        for j in xrange(1, n // i):
            primes[j * i] = 1

def get_prime_limit(power, lim):
    return int(lim ** (1.0/power)) + 1

limit = 5 * 10 ** 7 # 50 million limit
primes = {} # the primes array for all power
numbers = set() # using a set to avoid duplicates

for i in range(2, 5):
    primes[i] = get_primes(get_prime_limit(i, limit))

for i in primes[2]:
    for j in primes[3]:
        for k in primes[4]:
            n = i ** 2 + j ** 3 + k ** 4
            if n <= limit:
                numbers.add(n) # we are adding the number to the set to avoid duplicates