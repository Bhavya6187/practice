#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

string itos(int i){
    stringstream ss;
    ss<<i;
    return ss.str();
}

string reverse (string s) { 
	string result="";
	for (int i=0; i<s.length( ) ; i++) {
		result = s[ i ] + result ;
	}
	return result; 
}

int stoi(string a){
	int Number;
	if ( ! (istringstream(a) >> Number) ) Number = 0;
	return Number;
}

bool is_palindrome(int x){
	string temp = itos(x);
	string temp2 = reverse(temp);
	int comp = stoi(temp2);
	if(x == comp)
		return true;
	return false;
}
int main(){

	int max = 0;
	for(int i = 999; i > 100; i--)
	{
		bool is_prime = true;
		if(max > i * 999)
			break;
		for(int j = 999; j > 100; j--){
			int curr = i*j;
			if(is_palindrome(curr) && curr > max){
					max = curr;
					cout << max<< endl;
			}
		}
	}
	cout << max<< endl;
}
