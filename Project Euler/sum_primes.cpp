#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int main(){
	long long int sum = 2;
	long long int primes[160000];
	primes[0] = 2;
	int count = 1;
	for(long long int i = 3; i < 10; i+=2)
	{
		bool is_prime = true;
		int root = sqrt(i);
		for(int j = 0; j < count && primes[j] <= root; j++){
			if(i%primes[j] == 0){
				is_prime = false;
				break;
			}
		}
		if(is_prime){
			primes[count] = i;
			cout << primes[count] << endl;
			count++;
			sum += i;
		}
	}
	cout << sum << endl;
}