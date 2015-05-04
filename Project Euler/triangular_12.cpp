#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

vector<int> pv;

int main(){
	pv.push_back(2);
	int count = 1;
	for(long long int i = 3; i < 10000; i+=2)
	{
		bool is_prime = true;
		for(int j = 0; j < count; j++){
			if(i%pv[j] == 0){
				is_prime = false;
				break;
			}
		}
		if(is_prime){
			pv.push_back(i);
			count++;
		}
	}

	for(int i = 1; i < 14000; i++){
	
		int curr = (i)*(i+1);
		curr/=2;
		int divisors = 1;
	
		for(int j = 0; j < count ; j++){
			int temp = 1;
			while(curr%pv[j] == 0){
				temp++;
				curr/=pv[j];
			}
			divisors*=temp;
		}
		if(divisors > 500){
			cout << i << "   " << divisors <<endl;
			break;
		}
	}
}