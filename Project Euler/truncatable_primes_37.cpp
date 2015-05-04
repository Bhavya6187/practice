#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#include <set>

using namespace std;

int maxim = 0;
vector<int> pv;
vector<int> pv2;
vector<int> pv3;
vector<int> pv4;
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

bool is_truncatable(int a){
	int curr = a;
	int divisor = 1;
	while(curr > 0){
		if(!is_prime(curr))
			return false;
		curr/=10;
		divisor*=10;
	}
	divisor /= 10;

	curr = a;
//	cout << "Checking truncation for - " << a << "  - ";
	
	while(curr > 0){
		curr = curr - (divisor*int(curr/divisor));
//		cout << curr << "  ";
		if(!is_prime(curr))
			return false;
		divisor /= 10;
	}

	return true;

}

int main(){

	int sum = 0;
	pv.push_back(2);
	pv.push_back(3);
	pv.push_back(5);
	pv.push_back(7);
	int count = 4;
	for(long long int i = 11; i < 1000000; i+=2)
	{
		bool is_prime = true;
		int limit = sqrt(i);
		for(int j = 0; j < count; j++){
			if(i%pv[j] == 0){
				is_prime = false;
				break;
			}
			if(pv[j]  > limit)
				break;
		}
		if(is_prime){
			if(is_truncatable(i)){
				cout << i << endl;
				sum += i;
			}
			pv.push_back(i);
			count++;
		}
	}
	cout << sum << endl;
}