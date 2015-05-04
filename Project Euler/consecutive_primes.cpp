#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool myfunction (int i,int j) { return (i<j); }

int main(){
	long long int primes[80000];
	long long int sum_primes[80000];

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

	sum_primes[0] = 0;
	for(int i = 1 ; i <= count ; i++){
		sum_primes[i] = primes[i-1] + sum_primes[i-1];
	}

	cout << count << endl;
	cout << sum_primes[0]<< "  " << sum_primes[1]<< "  " << sum_primes[2]<< "  " << sum_primes[3]<< "  " << sum_primes[4]<< "  " << sum_primes[5] << endl;
	vector<int> pv(primes,primes+count);

	int max = 0;
	for(int i = 0 ; i < count; i++){
		for(int j = i; j <= count; j++){
			long long int curr = sum_primes[j]-sum_primes[i];
			if(curr < 1000000){
				if(binary_search(pv.begin(),pv.end(),curr,myfunction)){
					
					if(j-i > max){
						cout << i <<"  "<<j<< "  "<< curr << endl;
						max = j -i;
					}

				}
			}
		}
	}
}