#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;
int chain[1000000];

int main(){

chain[1] = 1;
chain[2] = 2;
int maxim = 0;
for(int i = 3; i < 1000000 ; i++){
	if(i%2 == 0)
		chain[i] = chain[i/2] + 1;
	else{
		long long int curr = (long long int)i;
		int temp = 0;
		while(curr >= i){
			if(curr%2 == 0)
				curr /= 2;
			else
				curr = 3*curr + 1;
			temp++;
		}
		chain[i] = temp + chain[curr];
	}

	if(chain[i] > maxim){
		cout << i << "   "  << chain[i] << endl;
		maxim = chain[i];
	}
}
}