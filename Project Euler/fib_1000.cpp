#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

vector<int> add_vecs(vector<int> a, vector<int> b){

	vector<int> c;
	while(a.size() < b.size()){
		a.push_back(0);
	}
	while(b.size() < a.size()){
		b.push_back(0);
	}
	int carry = 0;
	for(std::vector<int>::size_type i = 0; i != a.size(); i++) {
		c.push_back(a[i]+ b[i]+carry);
		if(c[i] >= 10){
			carry = c[i]/10;
			c[i] = c[i]%10;
		}else{
			carry = 0;
		}
	}
	while(carry > 0){
		c.push_back(carry%10);
		carry/=10;
	}
	return c;
}

int main(){
	vector<int> l1;
	l1.push_back(1);
	vector<int> l2;
	l2.push_back(1);
	int term = 2;
	vector<int> v;

	//for(int i = 0; i < 100 ; i++){
	while(v.size() < 1000){
		v = add_vecs(l1,l2);
/*		for (vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); ++i ){
			cout << *i;
		}
		cout << endl;
*/
		l2 = l1;
		l1 = v;
		term++;
	}
	cout << v.size() << "    " << term << endl;

}
