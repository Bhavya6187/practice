#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	int sum = 2;
	int prev,prev_prev;
	prev = 2;
	prev_prev = 1;
	int curr = 3;
	while( curr < 4000000){
		curr = prev + prev_prev;
		if(curr%2 == 0){
			sum+=curr;
		}
		prev_prev = prev;
		prev = curr;
		//cout<<curr<< "    ";

	}
	cout << sum <<endl;
}