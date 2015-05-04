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
	v.push_back(1);
	int carry = 0;
	for(int factorial = 1; factorial < 101 ; factorial++){
		carry = 0;
		for(std::vector<int>::size_type i = 0; i != v.size(); i++) {
			v[i] =v[i]*factorial + carry;
			
			if(v[i] >= 10){
				carry = v[i]/10;
				v[i] = v[i]%10;
			}else{
				carry = 0;
			}
		}
		while(carry > 0){
			v.push_back(carry%10);
			carry/=10;
		}
		
//		for(std::vector<int>::size_type i = 0; i != v.size(); i++)
//			cout << v[i]<< "   ";
//		cout << endl;

	}
	int sum = 0;
	for (vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); ++i ){
		sum += *i;
		cout << *i;
	}
	cout << endl << sum << endl;
}