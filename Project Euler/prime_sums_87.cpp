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
	for(long long int i = 3; i < 7100; i+=2)
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

	int count2 = 0;
	for(int i = 0; i < count && pv[i]*pv[i] < 50000000; i++){
		pv2.push_back(pv[i]*pv[i]);
		count2++;
	}

	int count3 = 0;
	for(int i = 0; i < count && pv[i]*pv[i]*pv[i] < 50000000; i++){
		pv3.push_back(pv[i]*pv[i]*pv[i]);
		count3++;
	}

	int count4 = 0;
	for(int i = 0; i < count && pv[i]*pv[i]*pv[i]*pv[i] < 50000000; i++){
		pv4.push_back(pv[i]*pv[i]*pv[i]*pv[i]);
		count4++;
	}

	cout << count << "   " <<count2 <<"   " << count3<< "  " << count4<<endl;
	cout << pv[count-1] << "   " <<pv[count2-1] << "  "<< pv[count3-1] << "  "<< pv[count4-1]<<endl;
	cout << pv[0] << "   " <<pv2[0] << "  "<< pv3[0] << "  "<< pv4[0]<<endl;

	count = 0;

	set<int> nums;
	for(int i = 0; i < count2; i++){
		for(int j = 0; j < count3; j++){
			for(int k = 0; k < count4; k++){
				int curr = pv2[i] + pv3[j] + pv4[k];
				if(curr < 50000000){
					//cout << curr << "   " << pv[i] << "   " <<pv[j] << "  "<< pv[k]<<endl;
					nums.insert(curr);
				}
			}
		}
	}

	set<int>::iterator it;
	for (it=nums.begin(); it!=nums.end(); ++it){
		count++;
    }
	cout << count << endl;
}