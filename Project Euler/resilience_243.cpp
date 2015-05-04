#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> pv;
bool myfunction (int i,int j) { return (i<j); }

int get_totem(int a){
	
	if(binary_search(pv.begin(),pv.end(),a,myfunction)){
		return a-1;
	}

	int limit = int(sqrt(a));
	float ret = a;

	for (vector<int>::iterator i = pv.begin(); i != pv.end(); ++i ){
		int curr = *i;
		if(a%curr == 0)
			ret *= (1-(1/(float)curr));
	}
	return ret;
}

int main(){

	pv.push_back(2);
	int count = 1;
	for(long long int i = 3; i < 30000; i+=2)
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
	float target = 15499/94744;
	float min = 1;
	cout << get_totem(12)<<endl;
	for(int i = 840000000; i < 900000000; i+=210){
		int totem = get_totem(i);
		float curr = (float)totem/(float)(i-1);
		if(curr < min){
			min = curr;
			cout << i << "   " << min << "   " << get_totem(i) << endl;
			if(min < target)
				break;
		}
	}
}

