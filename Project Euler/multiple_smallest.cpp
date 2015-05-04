#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int main(){
	int primes[8] = {2,3,5,7,11,13,17,19};
	int factors[8] = {};
	int mul_factors[8] = {};
	int mul = 1;

	for(int i = 2; i < 20; i++){
		int num = i;

		for(int j = 0; j < 8 ; j++){
			while(num%primes[j] == 0){
				factors[j]++;
				num/=primes[j];
			}
		}

		for(int j = 0; j < 8 ; j++){
			if(mul_factors[j] < factors[j])
				mul_factors[j] = factors[j];
		}
		for(int j = 0; j < 8 ; j++){
			factors[j] = 0;
		}
		cout << endl;

	}

	for(int j = 0; j < 8 ; j++){
		cout << mul_factors[j] << "   ";
		cout << pow(primes[j],mul_factors[j]) << " "; 
		mul *= pow(primes[j],mul_factors[j]);
	}
	cout<< endl;
	cout << mul << endl;
}