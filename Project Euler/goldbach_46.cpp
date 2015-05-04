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
vector<int> sq;
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
	pv.push_back(3);
	pv.push_back(5);
	pv.push_back(7);
	int count = 4;
	for(int i = 11; i < 1000000; i+=2)
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
			pv.push_back(i);
			count++;
		}
	}
	for(int i = 1; i < 1000; i++){
		sq.push_back(i*i);
	}

	for(int i = 35; i < 1000000; i+=2){
		bool valid = true;

		if(!is_prime(i)){
			for(int j = 0; j < count && pv[j] < i; j++)
			{
				if(binary_search(sq.begin(),sq.end(),(i - pv[j])/2,myfunction))
				{
					valid = false; 
					//cout << i << "   " << pv[j] << endl;
					break;
				}
			}
			if(valid)
				cout << i << "invalidates goldbach " << endl;
		}
	}

}