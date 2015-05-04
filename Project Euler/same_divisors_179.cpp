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

bool myfunction (int i,int j) { return (i<j); }

bool is_prime(int a){
	
	if(a == 1)
		return false;
	if(binary_search(pv.begin(),pv.end(),a,myfunction)){
		return true;
	}

	int limit = int(sqrt(a));

	for (vector<int>::iterator i = pv.begin(); i != pv.end(); ++i ){
		int curr = *i;
		if(curr > limit)
			return true;
		if(a%curr == 0)
			return false;
	}
	return true;
}


int main(){
	pv.push_back(2);
	int count = 1;
	for(long long int i = 3; i < 3200; i+=2)
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

	int prev = 2;
	int total = 0;
	for(int i = 3 ; i <= 10000000; i++){
	
		int curr = (i);
		int divisors = 1;
	
		for(int j = 0; j < count && pv[j] <= curr; j++){
			int temp = 1;
			while(curr%pv[j] == 0){
				temp++;
				curr/=pv[j];
			}
			divisors*=temp;
			if(is_prime(curr)){
				divisors*=2;
				break;				
			}

		}
		if(divisors == prev){
			//cout << i << endl;
			total++;
		}
		if(i%1000000 == 0){
			cout << total <<endl;
		}
		prev = divisors;
		//cout << divisors << endl;
	}
	cout << total << endl;
}