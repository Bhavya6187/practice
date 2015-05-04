#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	long long int num = 600851475143;
	long long int primes[80000];
	primes[0] = 2;
	int count = 1;
	for(long long int i = 3; i < 1000000; i+=2)
	{
		bool is_prime = true;
		for(int j = 0; j < count; j++){
			if(i%primes[j] == 0){
				is_prime = false;
				break;
			}
		}
		if(is_prime){
			primes[count] = i;
			count++;
		}
	}

	for(int j = count-1; j >= 0 ; j--){
		if(num%primes[j] == 0){
			cout << primes[j] << endl;
		}
	}
}