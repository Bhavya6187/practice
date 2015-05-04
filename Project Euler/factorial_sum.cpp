#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int main(){
	int factorials[10] = {1,1,2,6,24,120,720,5040,40320,362880};
	for(int i = 10; i < 2540160; i++){
		int curr = i;
		int sum = 0;
		while(curr > 0){
			sum += factorials[curr%10];
			curr/=10;
		}

		if(sum == i)
			cout << i << endl;
	}
}