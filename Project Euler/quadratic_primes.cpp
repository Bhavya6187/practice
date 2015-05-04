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

	vector<int> pv(primes,primes+count);
	int max = 0;

	for(int a  = -1000 ; a < 1000 ; a++){
		for(int b  = -1000 ; b < 1000 ; b++){
			int curr = b;
			int count = 0;
			while(binary_search(pv.begin(),pv.end(),curr,myfunction)){
				curr = (count*count) + (a*count) + (b);
				count++;
			}
			if(count > max){
				max = count;
				cout << count << "  " << a <<"   " << b << endl;
			}
		}
	}
}