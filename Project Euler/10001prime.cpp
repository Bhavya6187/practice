#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
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
		if(count == 10001){
			cout<<primes[10000] <<endl;
			break;
		}
	}
}