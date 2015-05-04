#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	int sum = 0;
	for(int i = 3; i < 1000; i++){
		if(i%3 == 0 || i%5==0){
			sum+=i;
		}
	}
	cout << sum <<endl;
}