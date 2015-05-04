#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int main(){
	vector<int> v;
	v.push_back(2);
	int carry = 0;
	for(int power = 1; power < 1000 ; power++){
		carry = 0;
		for(std::vector<int>::size_type i = 0; i != v.size(); i++) {
			v[i] =v[i]*2 + carry;
			
			if(v[i] >= 10){
				carry = v[i]/10;
				v[i] = v[i]%10;
			}else{
				carry = 0;
			}
		}

		if(carry > 0){
			v.push_back(carry);
		}
	}

	cout << v.size()<<endl;
	int sum = 0;
	for (vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); ++i ){
		sum += *i;
		cout << *i;
	}
	cout << endl << sum << endl;
//	for(std::vector<int>::size_type i = v.size()-1; i >= 0; i--)
//		cout << v[i]<< "   ";
}